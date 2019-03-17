#include <sys/stat.h>
#ifdef _WIN32
#include <direct.h>
#else
#include <unistd.h>
#endif
#include <errno.h>
#include <stdlib.h>

#include "libretro.h"
#include "libretro_fs.h"
#include <file/file_path.h>

#include "../src/w_wad.h"
#include "../src/m_fixed.h"
#include "../src/i_system.h"
#include "../src/lprintf.h"

#ifdef _WIN32
   #define DIR_SLASH '\\'
#else
   #define DIR_SLASH '/'
#endif




extern retro_log_printf_t log_cb;
extern retro_environment_t environ_cb;


/* Whether to search for IWADs on parent folders recursively */
extern boolean find_recursive_on;

const char *const known_iwads[]=
{
  "doom2f.wad",
  "doom2.wad",
  "plutonia.wad",
  "tnt.wad",
  "freedoom2.wad",
  "doom.wad",
  "doomu.wad",
  "freedoom1.wad",
  "freedoom.wad",
  "doom1.wad",
  NULL,
};

char *FindIWADFile(void)
{
  int   i;
  char  * iwad  = NULL;


  for (i=0; !iwad && known_iwads[i] != NULL; i++) {
    iwad = I_FindFile(known_iwads[i], NULL);
  }

  return iwad;
}


void ExtractFileBasename(char *buf, const char *path, size_t size)
{
   const char *base = strrchr(path, '/');
   if (!base)
      base = strrchr(path, '\\');
   if (!base)
      base = path;

   if (*base == '\\' || *base == '/')
      base++;

   strncpy(buf, base, size - 1);
   buf[size - 1] = '\0';
}

void ExtractFileDirectory(char *buf, const char *path, size_t size)
{
   char *base;
   strncpy(buf, path, size - 1);
   buf[size - 1] = '\0';

   base = strrchr(buf, '/');
   if (!base)
      base = strrchr(buf, '\\');

   if (base)
      *base = '\0';
   else
   {
      buf[0] = '.';
      buf[1] = '\0';
   }
}

void RemoveFileExtension(char *buf, const char *path, size_t size)
{
  char *base;
  strncpy(buf, path, size - 1);
  buf[size - 1] = '\0';

  base = strrchr(buf, '.');

  if (base)
     *base = '\0';
}


wadinfo_t get_wadinfo(const char *path)
{
   FILE* fp = fopen(path, "rb");
   wadinfo_t header;
   if (fp != NULL)
   {
      fread(&header, sizeof(header), 1, fp);
      fclose(fp);
   }
   return header;
}


const char *I_DoomExeDir(void)
{
   return g_save_dir;
}

/*
* HasTrailingSlash
*
* cphipps - simple test for trailing slash on dir names
*/
boolean HasTrailingSlash(const char* dn)
{
   return ( (dn[strlen(dn)-1] == '/') || (dn[strlen(dn)-1] == '\\'));
}

/**
 * FindFileInDir
 **
 * Checks if directory contains a file with given name and extension.
 * returns the path to the file if it exists and is readable or NULL otherwise
 */
char* FindFileInDir(const char* dir, const char* wfname, const char* ext)
{
   FILE * file;
   char * p;
   /* Precalculate a length we will need in the loop */
   size_t pl = strlen(wfname) + (ext && strlen(ext)) + 4;

   if( dir == NULL ) {
      p = malloc(pl);
      sprintf(p, "%s", wfname);
   }
   else {
     p = malloc(strlen(dir) + pl);
     sprintf(p, "%s%c%s", dir, DIR_SLASH, wfname);
   }

   if (ext && ext[0] != '\0')
   {
      strcat(p, ext);
   }
   file = fopen(p, "rb");

   if (file)
   {
      if (log_cb)
         log_cb(RETRO_LOG_INFO, "FindFileInDir: found %s\n", p);
      fclose(file);
      return p;
   }
   else if (log_cb)
      log_cb(RETRO_LOG_INFO, "FindFileInDir: not found %s in %s\n", wfname, dir);

   free(p);
   return NULL;
}


/*
* I_Filelength
*
* Return length of an open file.
*/

int I_Filelength(int handle)
{
   struct stat   fileinfo;
   if (fstat(handle,&fileinfo) == -1)
      I_Error("I_Filelength: %s",strerror(errno));
   return fileinfo.st_size;
}

void I_Read(int fd, void* vbuf, size_t sz)
{
   unsigned char* buf = vbuf;

   while (sz)
   {
      int rc = read(fd,buf,sz);
      if (rc <= 0)
         I_Error("I_Read: read failed: %s", rc ? strerror(errno) : "EOF");
      sz  -= rc;
      buf += rc;
   }
}


/*
 * I_FindFile
 **
 * Given a file name, search for it in g_wad_dir first, then the system folder
 * and then scan the parent folders of g_wad_dir.
 */
char* I_FindFile(const char* wfname, const char* ext)
{
   char *p, *dir, *system_dir;
   int i;
   if ((p = FindFileInDir(g_wad_dir, wfname, ext)) == NULL)
   {
     I_Error("not found %s/%s", g_wad_dir, wfname);
     environ_cb(RETRO_ENVIRONMENT_GET_SYSTEM_DIRECTORY, &system_dir);
       I_Error("looking %s/%s", system_dir, wfname);
     if ((!system_dir || (p = FindFileInDir(system_dir, wfname, ext)) == NULL)
        && find_recursive_on)
     { // Find recursively on parent directories
       I_Error("not found %s/%s", system_dir, wfname);
       dir = malloc(strlen(g_wad_dir));
       strcpy(dir, g_wad_dir);
       for (i = strlen(dir)-1; i > 1; dir[i--] = '\0')
       {
         if((dir[i] == '/' || dir[i] == '\\')
           && dir[i-1] != dir[i])
         {
           dir[i] = '\0'; // remove leading slash
             I_Error("looking %s/%s", dir, wfname);
           p = FindFileInDir(dir, wfname, ext);
           if(p != NULL) break;
         }
       }
       free(dir);
     }
   }
   return p;
}



void init_save_dir(char* save_dir, char* wadname) {
  const char *base_save_dir = NULL;
  bool use_external_savedir = false;
  // Get save directory
  if (environ_cb(RETRO_ENVIRONMENT_GET_SAVE_DIRECTORY, &base_save_dir) && base_save_dir)
  {
    if (strlen(base_save_dir) > 0)
    {
      // > Build save path
	   snprintf(g_save_dir, sizeof(g_save_dir), "%s%c%s", base_save_dir, DIR_SLASH, wadname);
	  use_external_savedir = true;

	  // > Create save directory, if required
	  if (!path_is_directory(g_save_dir))
	  {
	     use_external_savedir = path_mkdir(g_save_dir);
	  }
	}
  }
  if (!use_external_savedir)
  {
    // > Use WAD directory fallback...
	snprintf(save_dir, sizeof(g_save_dir), "%s", g_wad_dir);
  }
}

void init_config_file(char* save_dir, char* wadname, char* iwad) {
  /*
  if(iwad)
  {
   iwad[strlen(iwad) - 3] = '\0';
   get_save_dir(g_save_dir, iwad);
   M_LoadDefaults();
  }

  if(!iwad || pwad_config_on)
  {
   get_save_dir(g_save_dir, name_without_ext);
  }
 }
 */
}
