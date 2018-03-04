/* Emacs style mode select   -*- C++ -*-
 *-----------------------------------------------------------------------------
 *
 *
 *  PrBoom: a Doom port merged with LxDoom and LSDLDoom
 *  based on BOOM, a modified and improved DOOM engine
 *  Copyright (C) 2018 by
 *  Fernando Carmona Varo
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 *  02111-1307, USA.
 *
 * DESCRIPTION:
 *      Status bar code for Heretic.
 *
 *-----------------------------------------------------------------------------*/


#include "st_htic.h"
#include "doomdef.h"
#include "doomstat.h"
#include "m_random.h"
#include "i_video.h"
#include "w_wad.h"
#include "st_lib.h"
#include "r_main.h"
#include "am_map.h"
#include "m_cheat.h"
#include "s_sound.h"
#include "sounds.h"
#include "dstrings.h"
#include "r_draw.h"



// main player in game
static player_t *plyr;


// used for timing
static unsigned int st_clock;

// ST_Start() has just been called
static boolean st_firsttime;

// whether left-side main status bar is active
static boolean st_statusbaron;

// used to execute ST_Init() only once
static int veryfirsttime = 1;

static int oldarti = 0;
static int oldartiCount = 0;
static int oldfrags = -9999;
static int oldammo = -1;
static int oldarmor = -1;
static int oldweapon = -1;
static int oldhealth = -1;
static int oldlife = -1;
static int oldkeys = -1;
static int oldweaponsowned[NUMWEAPONS];

int playerkeys = 0;

// --- Patches

static patchnum_t stbarbg;
static patchnum_t ltface, rtface;

// status, inventory and stat bar backgrounds
static patchnum_t stbarbg, invbarbg, statbarbg;
// chain & lifegem
static patchnum_t chain, chainbg, lifegem;

static patchnum_t ltfctop, rtfctop;

static patchnum_t selectbox;
static patchnum_t invlfgem1, invrtgem1, invlfgem2, invrtgem2;

static patchnum_t negative, tallnum[10], shortnum[10];
static patchnum_t blacksq;
static patchnum_t armclear;

static patchnum_t fontbnumbase;
static patchnum_t spinbooklump;
static patchnum_t spinflylump;

static patchnum_t playpalette;

boolean st_stopped = TRUE;


// --- Widgets


static st_number_t w_ammo, w_armor, w_health;

// ---

//static int HealthMarker;
//static int ChainWiggle;
//static player_t *CPlayer;

//byte *ShadeTables;


static void ST_HTIC_createWidgets(void)
{
  int i;

  // ready weapon ammo
  STlib_initNum(&w_ammo,
                109,
                162,
                tallnum,
                &plyr->ammo[weaponinfo[plyr->readyweapon].ammo],
                &st_statusbaron,
                3);
  //V_DrawPatch(111, 172,W_CacheLumpName(DEH_String(ammopic[CPlayer->readyweapon - 1]),PU_CACHE));

  // Armor
  STlib_initNum(&w_armor,
                228,
                170,
                tallnum,
                &plyr->armorpoints,
                &st_statusbaron,
                3);
  //V_DrawPatch(224, 171, PatchARMCLEAR);
}

// Called every Tick
void ST_HTIC_updateWidgets(void)
{

  w_ammo.data = plyr->readyweapon;
  //if (weaponinfo[plyr->readyweapon].ammo == AM_NOAMMO)
  //  w_ammo.num = &largeammo;
  //else
    w_ammo.num = &plyr->ammo[weaponinfo[plyr->readyweapon].ammo];

}


static void ST_HTIC_drawWidgets(boolean refresh)
{


  STlib_updateNum(&w_ammo, CR_GREEN, refresh);

  STlib_updateNum(&w_armor, CR_GREEN, refresh);

  // Frags
  /*
  if (deathmatch)
  {
      temp = 0;
      for (i = 0; i < MAXPLAYERS; i++)
      {
          temp += plyr->frags[i];
      }
      if (temp != oldfrags)
      {
          V_DrawPatch(57, 171, PatchARMCLEAR);
          DrINumber(temp, 61, 170);
          oldfrags = temp;
          UpdateState |= I_STATBAR;
      }
  }
  else
  {
      temp = HealthMarker;
      if (temp < 0)
      {
          temp = 0;
      }
      else if (temp > 100)
      {
          temp = 100;
      }
      if (oldlife != temp)
      {
          oldlife = temp;
          V_DrawPatch(57, 171, PatchARMCLEAR);
          DrINumber(temp, 61, 170);
          UpdateState |= I_STATBAR;
      }
  }


  // Keys
  if (oldkeys != playerkeys)
  {
      if (CPlayer->keys[key_yellow])
      {
          V_DrawNamePatch(153, 164, "ykeyicon", CR_DEFAULT);
      }
      if (CPlayer->keys[key_green])
      {
          V_DrawNamePatch(153, 172, "gkeyicon", PU_CACHE);
      }
      if (CPlayer->keys[key_blue])
      {
          V_DrawNamePatch(153, 180, "bkeyicon", PU_CACHE);
      }
      oldkeys = playerkeys;
      UpdateState |= I_STATBAR;
  }
  */

}

static void ST_refreshBackground(void)
{
  int y=0;

  if (st_statusbaron)
    {
      // proff 05/17/2000: draw to the frontbuffer in OpenGL
      V_DrawNumPatch(0, 158, BG, stbarbg.lumpnum, CR_DEFAULT, VPT_STRETCH);
      //if (plyr.cheats & CF_GODMODE)
      //{
      //    V_DrawNamePatch(16, 167,"GOD1", PU_CACHE));
      //    V_DrawNamePatch(287, 167,"GOD2", PU_CACHE));
      //}
      // killough 3/7/98: make face background change with displayplayer
//      if (netgame)
//      {
//        V_DrawNumPatch(ST_FX, y, BG, faceback.lumpnum,
//           displayplayer ? CR_LIMIT+displayplayer : CR_DEFAULT,
//           displayplayer ? (VPT_TRANS | VPT_STRETCH) : VPT_STRETCH);
//      }
//      V_CopyRect(ST_X, y, BG, ST_SCALED_WIDTH, ST_SCALED_HEIGHT, ST_X, ST_SCALED_Y, FG, VPT_NONE);
    }
}

static void ST_Stop(void)
{
  if (st_stopped)
    return;
  //V_SetPalette(0);
  st_stopped = TRUE;
}

// ------------------------------

// Called by startup code.
void ST_HTIC_Init(void)
{
  int i;
  char namebuf[9];

  R_SetPatchNum(&ltface,"LTFACE");
  R_SetPatchNum(&ltface,"LTFACE");
  R_SetPatchNum(&stbarbg,"BARBACK");
  R_SetPatchNum(&invbarbg,"INVBAR");
  R_SetPatchNum(&chain,"CHAIN");
  R_SetPatchNum(&chainbg,"CHAINBACK");

  if(deathmatch)
    R_SetPatchNum(&statbarbg,"STATBAR"); // deathmatch only
  else
    R_SetPatchNum(&statbarbg,"LIFEBAR"); // non-deathmatch

  if(netgame)
    R_SetPatchNum(&statbarbg,"LIFEGEM0"); // multiplayer changes gem color
  else
    R_SetPatchNum(&statbarbg,"LIFEGEM2"); // singleplayer uses red gem

  R_SetPatchNum(&ltfctop,"LTFCTOP");
  R_SetPatchNum(&rtfctop,"RTFCTOP");
  R_SetPatchNum(&selectbox,"SELECTBOX");
  R_SetPatchNum(&invlfgem1,"INVGEML1");
  R_SetPatchNum(&invrtgem1,"INVGEMR1");
  R_SetPatchNum(&invlfgem2,"INVGEML2");
  R_SetPatchNum(&invrtgem2,"INVGEMR2");
  R_SetPatchNum(&blacksq,"BLACKSQ");
  R_SetPatchNum(&armclear,"ARMCLEAR");

  // Load the numbers, tall and short
  for (i=0;i<10;i++)
  {
    sprintf(namebuf, "IN%d", i);
    R_SetPatchNum(&tallnum[i],namebuf);
    sprintf(namebuf, "SMALLIN%d", i);
    R_SetPatchNum(&shortnum[i],namebuf);
  }
  R_SetPatchNum(&negative,"NEGNUM");

  R_SetPatchNum(&fontbnumbase,"FONTB16");

  //R_SetPatchNum(&playpalette,"PLAYPAL");
  R_SetPatchNum(&spinbooklump,"SPINBK0");
  R_SetPatchNum(&spinflylump,"SPFLY0");
}

// Called by main loop.
void ST_HTIC_Ticker(void)
{
    st_clock++;
    //st_randomnumber = M_Random();
    ST_HTIC_updateWidgets();
    oldhealth = plyr->health;
}

// Called by main loop.
void ST_HTIC_Drawer(boolean statusbaron, boolean refresh, boolean fullmenu)
{
  st_firsttime = st_firsttime || refresh || fullmenu;

  //ST_D_doPaletteStuff();  // Do red-/gold-shifts from damage/items

  if (statusbaron) {
    if (st_firsttime)
    {
      /* If just after ST_Start(), refresh all */
      st_firsttime = FALSE;
      ST_refreshBackground(); // draw status bar background to off-screen buff
      if (!fullmenu)
        ST_HTIC_drawWidgets(TRUE); // and refresh all widgets
    }
    else
    {
      /* Otherwise, update as little as possible */
      if (!fullmenu)
        ST_HTIC_drawWidgets(FALSE); // update all widgets
    }
  }
}

// Called when the console player is spawned on each level.
void ST_HTIC_Start(void)
{
  if (!st_stopped)
    ST_Stop();

  //ST_initData();
  int i;

  st_firsttime = TRUE;
  plyr = &players[displayplayer];

  st_clock = 0;
  //st_chatstate = StartChatState;
  //st_gamestate = FirstPersonState;

  //st_statusbaron = TRUE;
  //st_oldchat = st_chat = FALSE;
  //st_cursoron = FALSE;

  //st_faceindex = 0;
  //st_palette = -1;

  oldhealth = -1;
  oldarti = 0;
  oldammo = -1;
  oldarmor = -1;
  oldweapon = -1;
  oldfrags = -9999;       //can't use -1, 'cuz of negative frags
  oldlife = -1;
  oldkeys = -1;

  for (i=0;i<NUMWEAPONS;i++)
    oldweaponsowned[i] = plyr->weaponowned[i];

  //for (i=0;i<3;i++)
  //  keyboxes[i] = -1;

  STlib_init();
  ST_HTIC_createWidgets();

  st_stopped = FALSE;
}
