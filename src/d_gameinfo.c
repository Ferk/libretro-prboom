
#include "d_gameinfo.h"
#include "v_video.h"
#include "st_doom.h"
#include "st_htic.h"

// Doom menu skull cursor
const char *doomcursorpatches[] = {"M_SKULL1","M_SKULL2"};
static menucursor_t giSkullCursor =
{
   doomcursorpatches,  // patches
   2,                  // numpatches
   8,                  // blinktime
};

// heretic menu arrow cursor
const char *hticcursorpatches[] = {"M_SLCTR1","M_SLCTR2"};
static menucursor_t giArrowCursor =
{
   hticcursorpatches, // patches
   2,                 // numpatches
   16,                // blinktime
};

//////////////////////////////////////////
// Status bars

statusbar_t doomstatusbar =
{
  32,      // height
  ST_D_Ticker,
  ST_D_Drawer,
  ST_D_Start,
  ST_D_Init,
};

statusbar_t hticstatusbar =
{
  32,      // height
  ST_HTIC_Ticker,
  ST_HTIC_Drawer,
  ST_HTIC_Start,
  ST_HTIC_Init,
};

/////////////////////////////////////////

//
// DOOM Shareware
//
static gamemodeinfo_t giDoomSW =
{
   shareware,        // id
   "DOOM Shareware Startup",   // startupBanner

   demostates_doom,  // demoStates
   170,              // titleTics
   0,                // advisorTics
   11*TICRATE,       // pageTics
   //mus_intro,        // titleMusNum

   "FLOOR4_6",     // menuBackground
   "NUKAGE1",      // creditBackground
   20,               // creditY
   12,               // creditTitleStep
   &giSkullCursor,   // menuCursor
   "M_DOOM",          // mainMenuHeader
   //&menu_main,       // mainMenu
   //&menu_savegame,   // saveMenu
   //&menu_loadgame,   // loadMenu
   //&menu_newgame,    // newGameMenu
   0,//doomMenuSounds,   // menuSounds
   0,//S_TBALL1,         // transFrame
   0,//sfx_shotgn,       // skvAtkSound
   CR_RED,           // unselectColor
   CR_GRAY,          // selectColor
   CR_GREEN,         // variableColor
   CR_RED,           // titleColor
   CR_GOLD,          // itemColor
   CR_RED,           // bigFontItemColor
   0,                // menuOffset
   NULL,//MN_DoomNewGame,   // OnNewGame
   "STCFN0",        // menufontprefix
   0,               // menufontoffset

   "FLOOR7_2",     // borderFlat
   0,//&giDoomBorder,    // border

   &doomstatusbar, // statusbar
/*
   CR_RED,           // defTextTrans
   CR_RED,           // colorNormal
   CR_GRAY,          // colorHigh
   CR_GOLD,          // colorError
   40,               // c_numCharsPerLine
   sfx_tink,         // c_BellSound
   sfx_tink,         // c_ChatSound
   CONBACK_DEFAULT,  // consoleBack
   0,                // blackIndex
   4,                // whiteIndex
   NUMCARDS,         // numHUDKeys
   DOOMCardNames,    // cardNames
   mapnames,         // levelNames
   P_DoomDefaultLevelName, // GetLevelName

   &DoomStatusBar,   // StatusBar

   DOOMMARKS,        // markNumFmt

   "M_PAUSE",        // pausePatch

   1,                // numEpisodes
   DoomExitRules,    // exitRules
   "BulletPuff",     // puffType
   "DoomTeleFog",    // teleFogType
   0,                // teleFogHeight
   sfx_telept,       // teleSound
   100,              // thrustFactor
   GI_GIBFULLHEALTH, // defaultGibHealth
   "DoomMarine",     // defPClassName
   NULL,             // defTranslate
   DoomBossSpecs,    // bossRules
   LI_TYPE_DOOM,     // levelType
   "DoomBlood",      // bloodDefaultNormal
   "DoomBlood",      // bloodDefaultImpact
   "DoomBlood",      // bloodDefaultRIP
   "DoomBlood",      // bloodDefaultCrush
   bloodTypeForActionDOOM, // default behavior for action array

   INTERPIC_DOOM,     // interPic
   mus_inter,         // interMusNum
   P_DoomParTime,     // GetParTime
   &giDoomFText,      // fTextPos
   &DoomIntermission, // interfuncs
   DEF_DOOM_FINALE,   // teleEndGameFinaleType
   &DoomFinale,       // finaleData
   CAST_DEFTITLEY,    // castTitleY
   CAST_DEFNAMEY,     // castNameY

   S_music,           // s_music
   S_MusicForMapDoom, // MusicForMap
   S_DoomMusicCheat,  // MusicCheat
   mus_None,          // musMin
   NUMMUSIC,          // numMusic
   mus_e1m1,          // randMusMin
   mus_e1m9,          // randMusMax
   "D_",              // musPrefix
   "e1m1",            // defMusName
   DOOMDEFSOUND,      // defSoundName
   doom_skindefs,     // skinSounds
   doom_soundnums,    // playerSounds

   1,                  // switchEpisode
   &DoomSkyData,       // skyData
   R_DoomTextureHacks, // TextureHacks
   DoomSkyFlats,       // skyFlats
   &giPsprNoScale,     // pspriteGlobalScale

   NULL,             // defaultORs

   "ENDOOM",         // endTextName
   quitsounds,       // exitSounds
   */
};

//
// DOOM Registered
//
static gamemodeinfo_t giDoomReg =
{
   registered,       // id
   BANNER_DOOM_REG,  // startupBanner

   demostates_doom,  // demoStates
   170,              // titleTics
   0,                // advisorTics
   11*TICRATE,       // pageTics
   //mus_intro,        // titleMusNum

   "FLOOR4_6",     // menuBackground
   "NUKAGE1",     // creditBackground
   20,               // creditY
   12,               // creditTitleStep
   &giSkullCursor,   // menuCursor
   "M_DOOM",          // mainMenuHeader
   //&menu_main,       // mainMenu
   //&menu_savegame,   // saveMenu
   //&menu_loadgame,   // loadMenu
   //&menu_newgame,    // newGameMenu
   0,//doomMenuSounds,   // menuSounds
   0,//S_TBALL1,         // transFrame
   0,//sfx_shotgn,       // skvAtkSound
   CR_RED,           // unselectColor
   CR_GRAY,          // selectColor
   CR_GREEN,         // variableColor
   CR_RED,           // titleColor
   CR_GOLD,          // itemColor
   CR_RED,           // bigFontItemColor
   0,                // menuOffset
   NULL,//MN_DoomNewGame,   // OnNewGame
   "STCFN0",        // menufontprefix
   0,               // menufontoffset

   "FLOOR7_2",     // borderFlat
   0,//&giDoomBorder,    // border

   &doomstatusbar, // statusbar
/*
   CR_RED,           // defTextTrans
   CR_RED,           // colorNormal
   CR_GRAY,          // colorHigh
   CR_GOLD,          // colorError
   40,               // c_numCharsPerLine
   sfx_tink,         // c_BellSound
   sfx_tink,         // c_ChatSound
   CONBACK_DEFAULT,  // consoleBack
   0,                // blackIndex
   4,                // whiteIndex
   NUMCARDS,         // numHUDKeys
   DOOMCardNames,    // cardNames
   mapnames,         // levelNames
   P_DoomDefaultLevelName, // GetLevelName

   &DoomStatusBar,   // StatusBar

   DOOMMARKS,        // markNumFmt

   "M_PAUSE",        // pausePatch

   3,                // numEpisodes
   DoomExitRules,    // exitRules
   "BulletPuff",     // puffType
   "DoomTeleFog",    // teleFogType
   0,                // teleFogHeight
   sfx_telept,       // teleSound
   100,              // thrustFactor
   GI_GIBFULLHEALTH, // defaultGibHealth
   "DoomMarine",     // defPClassName
   NULL,             // defTranslate
   DoomBossSpecs,    // bossRules
   LI_TYPE_DOOM,     // levelType
   "DoomBlood",      // bloodDefaultNormal
   "DoomBlood",      // bloodDefaultImpact
   "DoomBlood",      // bloodDefaultRIP
   "DoomBlood",      // bloodDefaultCrush
   bloodTypeForActionDOOM, // default behavior for action array

   INTERPIC_DOOM,     // interPic
   mus_inter,         // interMusNum
   P_DoomParTime,     // GetParTime
   &giDoomFText,      // fTextPos
   &DoomIntermission, // interfuncs
   DEF_DOOM_FINALE,   // teleEndGameFinaleType
   &DoomFinale,       // finaleData
   CAST_DEFTITLEY,    // castTitleY
   CAST_DEFNAMEY,     // castNameY

   S_music,           // s_music
   S_MusicForMapDoom, // MusicForMap
   S_DoomMusicCheat,  // MusicCheat
   mus_None,          // musMin
   NUMMUSIC,          // numMusic
   mus_e1m1,          // randMusMin
   mus_e3m9,          // randMusMax
   "D_",              // musPrefix
   "e1m1",            // defMusName
   DOOMDEFSOUND,      // defSoundName
   doom_skindefs,     // skinSounds
   doom_soundnums,    // playerSounds

   2,                  // switchEpisode
   &DoomSkyData,       // skyData
   R_DoomTextureHacks, // TextureHacks
   DoomSkyFlats,       // skyFlats
   &giPsprNoScale,     // pspriteGlobalScale

   NULL,             // defaultORs

   "ENDOOM",         // endTextName
   quitsounds,       // exitSounds
   */
};

//
// The Ultimate DOOM (4 episodes)
//
static gamemodeinfo_t giDoomRetail =
{
   retail,           // id
   BANNER_DOOM_RET,  // startupBanner

   demostates_udoom, // demoStates
   170,              // titleTics
   0,                // advisorTics
   11*TICRATE,       // pageTics
   //mus_intro,        // titleMusNum

   "FLOOR4_6",     // menuBackground
   "NUKAGE1",     // creditBackground
   20,               // creditY
   12,               // creditTitleStep
   &giSkullCursor,   // menuCursor
   "M_DOOM",          // mainMenuHeader
   //&menu_main,       // mainMenu
   //&menu_savegame,   // saveMenu
   //&menu_loadgame,   // loadMenu
   //&menu_newgame,    // newGameMenu
   0,//doomMenuSounds,   // menuSounds
   0,//S_TBALL1,         // transFrame
   0,//sfx_shotgn,       // skvAtkSound
   CR_RED,           // unselectColor
   CR_GRAY,          // selectColor
   CR_GREEN,         // variableColor
   CR_RED,           // titleColor
   CR_GOLD,          // itemColor
   CR_RED,           // bigFontItemColor
   0,                // menuOffset
   NULL,//MN_DoomNewGame,   // OnNewGame
   "STCFN0",        // menufontprefix
   0,               // menufontoffset

   "FLOOR7_2",     // borderFlat
   0,//&giDoomBorder,    // border

   &doomstatusbar, // statusbar
/*
   CR_RED,           // defTextTrans
   CR_RED,           // colorNormal
   CR_GRAY,          // colorHigh
   CR_GOLD,          // colorError
   40,               // c_numCharsPerLine
   sfx_tink,         // c_BellSound
   sfx_tink,         // c_ChatSound
   CONBACK_DEFAULT,  // consoleBack
   0,                // blackIndex
   4,                // whiteIndex
   NUMCARDS,         // numHUDKeys
   DOOMCardNames,    // cardNames
   mapnames,         // levelNames
   P_DoomDefaultLevelName, // GetLevelName

   &DoomStatusBar,   // StatusBar

   DOOMMARKS,        // markNumFmt

   "M_PAUSE",        // pausePatch

   4,                // numEpisodes
   DoomExitRules,    // exitRules
   "BulletPuff",     // puffType
   "DoomTeleFog",    // teleFogType
   0,                // teleFogHeight
   sfx_telept,       // teleSound
   100,              // thrustFactor
   GI_GIBFULLHEALTH, // defaultGibHealth
   "DoomMarine",     // defPClassName
   NULL,             // defTranslate
   DoomBossSpecs,    // bossRules
   LI_TYPE_DOOM,     // levelType
   "DoomBlood",      // bloodDefaultNormal
   "DoomBlood",      // bloodDefaultImpact
   "DoomBlood",      // bloodDefaultRIP
   "DoomBlood",      // bloodDefaultCrush
   bloodTypeForActionDOOM, // default behavior for action array

   INTERPIC_DOOM,     // interPic
   mus_inter,         // interMusNum
   P_DoomParTime,     // GetParTime
   &giDoomFText,      // fTextPos
   &DoomIntermission, // interfuncs
   DEF_DOOM_FINALE,   // teleEndGameFinaleType
   &DoomFinale,       // finaleData
   CAST_DEFTITLEY,    // castTitleY
   CAST_DEFNAMEY,     // castNameY

   S_music,           // s_music
   S_MusicForMapDoom, // MusicForMap
   S_DoomMusicCheat,  // MusicCheat
   mus_None,          // musMin
   NUMMUSIC,          // numMusic
   mus_e1m1,          // randMusMin
   mus_e3m9,          // randMusMax
   "D_",              // musPrefix
   "e1m1",            // defMusName
   DOOMDEFSOUND,      // defSoundName
   doom_skindefs,     // skinSounds
   doom_soundnums,    // playerSounds

   2,                  // switchEpisode
   &DoomSkyData,       // skyData
   R_DoomTextureHacks, // TextureHacks
   DoomSkyFlats,       // skyFlats
   &giPsprNoScale,     // pspriteGlobalScale

   NULL,             // defaultORs

   "ENDOOM",         // endTextName
   quitsounds,       // exitSounds
   */
};

//
// DOOM II / Final DOOM
//
static gamemodeinfo_t giDoomCommercial =
{
   commercial,       // id
   BANNER_DOOM2,     // startupBanner

   demostates_doom2, // demoStates
   11*TICRATE,       // titleTics
   0,                // advisorTics
   11*TICRATE,       // pageTics
   //mus_dm2ttl,       // titleMusNum

   "FLOOR4_6",     // menuBackground
   "SLIME05",      // creditBackground
   20,               // creditY
   12,               // creditTitleStep
   &giSkullCursor,   // menuCursor
   "M_DOOM",          // mainMenuHeader
   //&menu_main_doom2, // mainMenu
   //&menu_savegame,   // saveMenu
   //&menu_loadgame,   // loadMenu
   //&menu_newgame,    // newGameMenu
   0,//doomMenuSounds,   // menuSounds
   0,//S_TBALL1,         // transFrame
   0,//sfx_shotgn,       // skvAtkSound
   CR_RED,           // unselectColor
   CR_GRAY,          // selectColor
   CR_GREEN,         // variableColor
   CR_RED,           // titleColor
   CR_GOLD,          // itemColor
   CR_RED,           // bigFontItemColor
   0,                // menuOffset
   NULL,//MN_Doom2NewGame,  // OnNewGame
   "STCFN0",        // menufontprefix
   0,               // menufontoffset

   "GRNROCK",      // borderFlat
   0,//&giDoomBorder,    // border

   &doomstatusbar, // statusbar

/*
   CR_RED,           // defTextTrans
   CR_RED,           // colorNormal
   CR_GRAY,          // colorHigh
   CR_GOLD,          // colorError
   40,               // c_numCharsPerLine
   sfx_tink,         // c_BellSound
   sfx_radio,        // c_ChatSound
   CONBACK_DEFAULT,  // consoleBack
   0,                // blackIndex
   4,                // whiteIndex
   NUMCARDS,         // numHUDKeys
   DOOMCardNames,    // cardNames
   mapnames2,        // levelNames
   P_Doom2DefaultLevelName, // GetLevelName

   &DoomStatusBar,   // StatusBar

   DOOMMARKS,        // markNumFmt

   "M_PAUSE",        // pausePatch

   1,                // numEpisodes
   Doom2ExitRules,   // exitRules
   "BulletPuff",     // puffType
   "DoomTeleFog",    // teleFogType
   0,                // teleFogHeight
   sfx_telept,       // teleSound
   100,              // thrustFactor
   GI_GIBFULLHEALTH, // defaultGibHealth
   "DoomMarine",     // defPClassName
   NULL,             // defTranslate
   Doom2BossSpecs,   // bossRules
   LI_TYPE_DOOM,     // levelType
   "DoomBlood",      // bloodDefaultNormal
   "DoomBlood",      // bloodDefaultImpact
   "DoomBlood",      // bloodDefaultRIP
   "DoomBlood",      // bloodDefaultCrush
   bloodTypeForActionDOOM, // default behavior for action array

   INTERPIC_DOOM,     // interPic
   mus_dm2int,        // interMusNum
   P_Doom2ParTime,    // GetParTime
   &giDoomFText,      // fTextPos
   &DoomIntermission, // interfuncs
   FINALE_TEXT,       // teleEndGameFinaleType
   &Doom2Finale,      // finaleData
   CAST_DEFTITLEY,    // castTitleY
   CAST_DEFNAMEY,     // castNameY

   S_music,            // s_music
   S_MusicForMapDoom2, // MusicForMap
   S_Doom2MusicCheat,  // MusicCheat
   mus_None,           // musMin
   NUMMUSIC,           // numMusic
   mus_runnin,         // randMusMin
   mus_ultima,         // randMusMax
   "D_",               // musPrefix
   "runnin",           // defMusName
   DOOMDEFSOUND,       // defSoundName
   doom_skindefs,      // skinSounds
   doom_soundnums,     // playerSounds

   3,              // switchEpisode
   &Doom2SkyData,  // skyData
   NULL,           // TextureHacks
   DoomSkyFlats,   // skyFlats
   &giPsprNoScale, // pspriteGlobalScale

   NULL,             // defaultORs

   "ENDOOM",         // endTextName
   quitsounds2,      // exitSounds
   */
};

//
// Heretic Shareware
//
static gamemodeinfo_t giHereticSW =
{
   hereticsw,        // id
   BANNER_HTIC_SW,   // startupBanner

   demostates_hsw,   // demoStates
   210,              // titleTics
   140,              // advisorTics
   200,              // pageTics
   //hmus_titl,        // titleMusNum

   "FLOOR16",     // menuBackground
   "FLTWAWA1",     // creditBackground
   8,                // creditY
   8,                // creditTitleStep
   &giArrowCursor,   // menuCursor
   "M_HTIC",          // mainMenuHeader
   //&menu_hmain,      // mainMenu
   //&menu_hsavegame,  // saveMenu
   //&menu_hloadgame,  // loadMenu
   //&menu_hnewgame,   // newGameMenu
   0,//hticMenuSounds,   // menuSounds
   0,//S_MUMMYFX1_1,     // transFrame
   0,//sfx_gldhit,       // skvAtkSound
   CR_GRAY,          // unselectColor
   CR_RED,           // selectColor
   CR_GREEN,         // variableColor
   CR_GREEN,         // titleColor
   CR_GOLD,          // itemColor
   CR_GREEN,         // bigFontItemColor
   4,                // menuOffset
   NULL,//MN_HticNewGame,   // OnNewGame
   "FONTB",        // menufontprefix
   -32,               // menufontoffset

   "FLOOR04",      // borderFlat
   0,//&giHticBorder,    // border

   &hticstatusbar,  // StatusBar

/*
   CR_GRAY,          // defTextTrans
   CR_GRAY,          // colorNormal
   CR_GOLD,          // colorHigh
   CR_RED,           // colorError
   40,               // c_numCharsPerLine
   sfx_chat,         // c_BellSound
   sfx_chat,         // c_ChatSound
   CONBACK_HERETIC,  // consoleBack
   0,                // blackIndex
   35,               // whiteIndex
   3,                // numHUDKeys
   HticCardNames,    // cardNames
   mapnamesh,        // levelNames
   P_HticDefaultLevelName, // GetLevelName

   &HticStatusBar,   // StatusBar

   HTICMARKS,        // markNumFmt

   "PAUSED",         // pausePatch

   1,                  // numEpisodes
   HereticExitRules,   // exitRules
   "HereticStaffPuff", // puffType
   "HereticTeleFog",   // teleFogType
   32*FRACUNIT,        // teleFogHeight
   sfx_htelept,        // teleSound
   150,                // thrustFactor
   GI_GIBHALFHEALTH,   // defaultGibHealth
   "Corvus",           // defPClassName
   DEFTL_HERETIC,      // defTranslate
   HereticBossSpecs,   // bossRules
   LI_TYPE_HERETIC,    // levelType
   "HereticBloodSplatter", // bloodDefaultNormal
   "HereticBloodSplatter", // bloodDefaultImpact
   "HereticBlood",         // bloodDefaultRIP
   "HereticBlood",         // bloodDefaultCrush
   bloodTypeForActionHtic, // default blood behavior for action array

   INTERPIC_DOOM,     // interPic
   hmus_intr,         // interMusNum
   P_NoParTime,       // GetParTime
   &giHticFText,      // fTextPos
   &HticIntermission, // interfuncs
   DEF_HTIC_FINALE,   // teleEndGameFinaleType
   &HereticFinale,    // finaleData
   CAST_DEFTITLEY,    // castTitleY
   CAST_DEFNAMEY,     // castNameY

   H_music,             // s_music
   S_MusicForMapHtic,   // MusicForMap
   S_HereticMusicCheat, // MusicCheat
   hmus_None,           // musMin
   NUMHTICMUSIC,        // numMusic
   hmus_e1m1,           // randMusMin
   hmus_e1m9,           // randMusMax
   "MUS_",              // musPrefix
   "e1m1",              // defMusName
   HTICDEFSOUND,        // defSoundName
   htic_skindefs,       // skinSounds
   htic_soundnums,      // playerSounds

   1,                  // switchEpisode
   &HereticSkyData,    // skyData
   R_HticTextureHacks, // TextureHacks
   DoomSkyFlats,       // skyFlats
   &giPsprNoScale,     // pspriteGlobalScale

   HereticDefaultORs, // defaultORs

   "ENDTEXT",        // endTextName
   NULL,             // exitSounds
   */
};

//
// Heretic Registered / Heretic: Shadow of the Serpent Riders
//
// The only difference between registered and SoSR is the
// number of episodes, which is patched in this structure at
// runtime.
//
static gamemodeinfo_t giHereticReg =
{
   hereticreg,       // id
   BANNER_HTIC_REG,  // startupBanner

   demostates_hreg,  // demoStates
   210,              // titleTics
   140,              // advisorTics
   200,              // pageTics
   //hmus_titl,        // titleMusNum

   "FLOOR16",     // menuBackground
   "FLTWAWA1",     // creditBackground
   8,                // creditY
   8,                // creditTitleStep
   &giArrowCursor,   // menuCursor
   "M_HTIC",          // mainMenuHeader
   //&menu_hmain,      // mainMenu
   //&menu_hsavegame,  // saveMenu
   //&menu_hloadgame,  // loadMenu
   //&menu_hnewgame,   // newGameMenu
   0,//hticMenuSounds,   // menuSounds
   0,//S_MUMMYFX1_1,     // transFrame
   0,//sfx_gldhit,       // skvAtkSound
   CR_GRAY,          // unselectColor
   CR_RED,           // selectColor
   CR_GREEN,         // variableColor
   CR_GREEN,         // titleColor
   CR_GOLD,          // itemColor
   CR_GREEN,         // bigFontItemColor
   4,                // menuOffset
   NULL,//MN_HticNewGame,   // OnNewGame
   "FONTB",        // menufontprefix
   -32,               // menufontoffset

   "FLAT513",     // borderFlat
   0,//&giHticBorder,    // border

   &hticstatusbar,  // StatusBar

/*
   CR_GRAY,          // defTextTrans
   CR_GRAY,          // colorNormal
   CR_GOLD,          // colorHigh
   CR_RED,           // colorError
   40,               // c_numCharsPerLine
   sfx_chat,         // c_BellSound
   sfx_chat,         // c_ChatSound
   CONBACK_HERETIC,  // consoleBack
   0,                // blackIndex
   35,               // whiteIndex
   3,                // numHUDKeys
   HticCardNames,    // cardNames
   mapnamesh,        // levelNames
   P_HticDefaultLevelName, // GetLevelName

   &HticStatusBar,   // StatusBar

   HTICMARKS,        // markNumFmt

   "PAUSED",         // pausePatch

   4,                  // numEpisodes -- note 6 for SoSR gamemission
   HereticExitRules,   // exitRules
   "HereticStaffPuff", // puffType
   "HereticTeleFog",   // teleFogType
   32*FRACUNIT,        // teleFogHeight
   sfx_htelept,        // teleSound
   150,                // thrustFactor
   GI_GIBHALFHEALTH,   // defaultGibHealth
   "Corvus",           // defPClassName
   DEFTL_HERETIC,      // defTranslate
   HereticBossSpecs,   // bossRules
   LI_TYPE_HERETIC,    // levelType
   "HereticBloodSplatter", // bloodDefaultNormal
   "HereticBloodSplatter", // bloodDefaultImpact
   "HereticBlood",         // bloodDefaultRIP
   "HereticBlood",         // bloodDefaultCrush
   bloodTypeForActionHtic, // default blood behavior for action array

   INTERPIC_DOOM,     // interPic
   hmus_intr,         // interMusNum
   P_NoParTime,       // GetParTime
   &giHticFText,      // fTextPos
   &HticIntermission, // interfuncs
   DEF_HTIC_FINALE,   // teleEndGameFinaleType
   &HereticFinale,    // finaleData
   CAST_DEFTITLEY,    // castTitleY
   CAST_DEFNAMEY,     // castNameY

   H_music,             // s_music
   S_MusicForMapHtic,   // MusicForMap
   S_HereticMusicCheat, // MusicCheat
   hmus_None,           // musMin
   NUMHTICMUSIC,        // numMusic
   hmus_e1m1,           // randMusMin
   hmus_e3m3,           // randMusMax
   "MUS_",              // musPrefix
   "e1m1",              // defMusName
   HTICDEFSOUND,        // defSoundName
   htic_skindefs,       // skinSounds
   htic_soundnums,      // playerSounds

   2,                  // switchEpisode
   &HereticSkyData,    // skyData
   R_HticTextureHacks, // TextureHacks
   DoomSkyFlats,       // skyFlats
   &giPsprNoScale,     // pspriteGlobalScale

   HereticDefaultORs,  // defaultORs

   "ENDTEXT",          // endTextName
   NULL,               // exitSounds
   */
};


// Game Mode Info Array
gamemodeinfo_t *GameModeInfoObjects[NumGameModes] =
{
   &giDoomSW,         // shareware
   &giDoomReg,        // registered
   &giDoomCommercial, // commercial
   &giDoomRetail,     // retail
   &giHereticSW,      // hereticsw
   &giHereticReg,     // hereticreg
   &giDoomReg,        // indetermined - act like Doom, mostly.
};

// Global Current Game Mode
gamemodeinfo_t *gamemodeinfo = &giDoomReg;
