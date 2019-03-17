#ifndef LIBRETRO_FS_H__
#define LIBRETRO_FS_H__

#include "../src/w_wad.h"

char* I_FindFile(const char* wfname, const char* ext);
void init_save_dir(char* save_dir, char* wadname);
void init_config_dir(char* save_dir, char* wadname);
char *FindIWADFile(void);
char* FindFileInDir(const char* dir, const char* wfname, const char* ext);
void ExtractFileBasename(char *buf, const char *path, size_t size);
void ExtractFileDirectory(char *buf, const char *path, size_t size);
void RemoveFileExtension(char *buf, const char *path, size_t size);

wadinfo_t get_wadinfo(const char *path);


/* libretro */
char g_wad_dir[1024];
char g_basename[1024];
char g_save_dir[1024];

#endif
