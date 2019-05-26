// Copyright 2019 Fernando Carmona Varo
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/

#include <string.h>

#include "uf_scanner.h"
#include "m_argv.h"
#include "lprintf.h"
#include "w_wad.h"
#include "g_game.h"
#include "i_system.h"

#include "uf_gameinfo.h"
#include "uf_gameinfo_defs.h"


// Gameinfo
gameinfo_t gameinfo;

// -----------------------------------------------
// Parses a standard property that is already known
// These do not get stored in the property list
// but in dedicated struct member variables.
// -----------------------------------------------
static int ParseGameProperty(uf_scanner_t* s, gameinfo_t *ginfo)
{
  char *pname;
  UF_GetNextToken(s, TRUE);
  if (s->token != TK_Identifier) {
    UF_Error(s, " Expected game property, but found '%s'", s->string);
    return 0;
  }
  pname = strdup(s->string);
  UF_MustGetToken(s, '=');

  if (!strcasecmp(pname, "iwad"))
  {
    UF_MustGetToken(s, TK_StringConst);
    UF_ReplaceString(&(ginfo->iwadFile), s->string);
  }
  else if (!strcasecmp(pname, "load"))
  {
    do {
        UF_MustGetToken(s, TK_StringConst);
        //myargv[myargc++] = strdup(s->string);
    } while (UF_CheckToken(s, ','));
  }
  else if (!strcasecmp(pname, "wadfile"))
  {
    UF_MustGetToken(s, TK_StringConst);
    UF_MustGetToken(s, TK_StringConst);
  }
  else if (!strcasecmp(pname, "startuptitle"))
  {
    UF_MustGetToken(s, TK_StringConst);
    UF_ReplaceString(&(ginfo->banner), s->string);
  }
  else
  {
    // Unknown property, just skip everything that isn't an identifier
    while (!UF_CheckToken(s, TK_Identifier) && UF_HasTokensLeft(s))
      UF_GetNextToken(s, TRUE);
  }
  return 1;
}

// -----------------------------------------------
// Parses a complete GAMEINFO lump
// -----------------------------------------------

void UF_ParseGameInfo(const byte *buffer, size_t length)
{
  uf_scanner_t scanner = UF_Create(buffer, length);

  while (UF_HasTokensLeft(&scanner))
  {
    ParseGameProperty(&scanner, &gameinfo);
  }
  UF_Destroy(&scanner);
}


// -----------------------------------------------
// Apply values from IWAD into current gameinfo
// without overriding the previously loaded PWAD
// game configuration.
// -----------------------------------------------

void UF_ApplyIWADInfo(const gameinfo_t *iwadinfo)
{
  if (!gameinfo.banner)
    gameinfo.banner = iwadinfo->banner;
}


void UF_GameInfoInit(char* wadfilename)
{
  int i;
  gameinfo_t *iwadinfo = NULL;
  wadinfo_t wadheader;
  filelump_t *lump, *wadlumps = NULL;
  wadfile_info_t wadfile;
  wadfile.handle = NULL;
  wadfile.name = wadfilename;

  lprintf(LO_INFO, "UF_GameInfoInit: Analizing game definitions for %s\n", wadfilename);
  wadlumps = lump = W_OpenFile(&wadfile, &wadheader);

  // if it's an IWAD, automatically add it as the gamemode's iwadFile
  // it might still be overriden by the GAMEINFO lump, however.
  if(wadheader.identification != NULL && !strncmp("IWAD",wadheader.identification,4)) {
    gameinfo.iwadFile = strdup(wadfilename);
  }
  if (wadlumps != NULL) {
    int ep, map;
    for (i=0; (int)i<wadheader.numlumps ; i++,lump++)
    {
      if(G_ValidateMapName(lump->name, &ep, &map)) {
        if(!gameinfo.firstMap || (strncmp(lump->name, gameinfo.firstMap,8)) < 0)
          gameinfo.firstMap = lump->name;
      }
      if (!strncmp(lump->name, "GAMEINFO",8)) {
       const byte * data = wadfile.data + lump->filepos;
       lprintf(LO_INFO, "UF_GameInfoInit: parsing GAMEINFO lump\n");
       UF_ParseGameInfo(data, lump->size);
      }
    }
    if(gameinfo.firstMap)
      lprintf(LO_INFO,"UF_GameInfoInit: WAD's first map: %s\n", gameinfo.firstMap);

    free(wadlumps);
  }
  W_ReleaseWad(&wadfile);
  if(gameinfo.iwadFile) {
    // if an iwad was defined, check if it matches a known iwad
    char *iwadbasename = gameinfo.iwadFile;
    for (i=strlen(gameinfo.iwadFile)-1; i>=0; i--) {
      if (gameinfo.iwadFile[i] == '/' || gameinfo.iwadFile[i] == '\\' ) {
        iwadbasename = gameinfo.iwadFile + i + 1;
        break;
      }
    }
    for (i=0; i<nstandard_iwads; i++)
      if (!strcasecmp(iwadbasename, standard_iwads[i].iwadFile)) {
        iwadinfo = (gameinfo_t*)&standard_iwads[i];
        break;
      }
  }

  // If no iwad was set by now, search for one!
  if (!iwadinfo)
  {
    char* expectedFirstMap = MAP01;
    if (gameinfo.firstMap && gameinfo.firstMap[0] == 'E' )
      expectedFirstMap = E1M1; // The WAD is episodic

    // Search first among iwads with the expected first map
    for (i=0; !gameinfo.iwadFile && i<nstandard_iwads; i++) {
      if(standard_iwads[i].firstMap == expectedFirstMap) {
        gameinfo.iwadFile = I_FindFile(standard_iwads[i].iwadFile, NULL);
        if (gameinfo.iwadFile) {
          iwadinfo = (gameinfo_t*)&standard_iwads[i];
          break;
        }
      }
    }
    // Attempt to look for any other iwad
    if (!iwadinfo) for (i=0; !gameinfo.iwadFile && i<nstandard_iwads; i++) {
      if(standard_iwads[i].firstMap != expectedFirstMap) {
        gameinfo.iwadFile = I_FindFile(standard_iwads[i].iwadFile, NULL);
        if (gameinfo.iwadFile) {
          iwadinfo = (gameinfo_t*)&standard_iwads[i];
          break;
        }
      }
    }
  }
  if (iwadinfo)
  {
    lprintf(LO_INFO, "UF_GameInfoInit: using standard IWAD: '%s'\n", iwadinfo->iwadFile);
    UF_ApplyIWADInfo(iwadinfo);
  }
  else if (gameinfo.iwadFile)
    lprintf(LO_INFO, "UF_GameInfoInit: using non-standard IWAD: '%s'\n", gameinfo.iwadFile);
  else
    I_Error("UF_GameInfoInit: Couldn't find any suitable IWAD");
}
