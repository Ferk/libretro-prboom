

#ifndef __D_GAMEINFO__
#define __D_GAMEINFO__

#include "doomdef.h"

// Startup banners
#define BANNER_DOOM_SW   "DOOM Shareware"
#define BANNER_DOOM_REG  "DOOM Registered"
#define BANNER_DOOM_RET  "The Ultimate DOOM"
#define BANNER_DOOM2     "DOOM 2: Hell on Earth"
#define BANNER_TNT       "DOOM 2: TNT - Evilution"
#define BANNER_PLUT      "DOOM 2: Plutonia Experiment"
#define BANNER_HACX      "HACX - Twitch 'n Kill"
#define BANNER_PSX       "DOOM: Custom PlayStation Edition"
#define BANNER_HTIC_SW   "Heretic Shareware Startup"
#define BANNER_HTIC_REG  "Heretic Registered Startup"
#define BANNER_HTIC_SOSR "Heretic: Shadow of the Serpent Riders"
#define BANNER_UNKNOWN   "Public DOOM"


// Menu cursor
typedef struct menucursor_struct
{
   const char **patches;
   int numpatches;
   int blinktime;
} menucursor_t;

typedef struct demostate_struct
{
  void (*func)(const char *);
  const char *name;
} demostate_t;

extern const demostate_t demostates_doom[];
extern const demostate_t demostates_doom2[];
extern const demostate_t demostates_udoom[];
extern const demostate_t demostates_hsw[];
extern const demostate_t demostates_hreg[];

typedef struct statusbar_struct
{
  int height;         // status bar height
  void (*tick)(void); // Called by main loop.
  void (*draw)(boolean,boolean,boolean); // Called by main loop.
  void (*start)(void); // Called when console player spawns on each level.
  void (*init)(void); // Called by startup code.
} statusbar_t;

typedef struct
{
  GameMode_t id;                 // id      - replaces "gamemode" variable
  const char *startupBanner;     // startup banner text

  // demo state information
  const demostate_t *demostates; // demostates table
  int titleTics;                 // length of time to show title
  int advisorTics;               // for Heretic, len. to show advisory
  int pageTics;                  // length of general demo state pages
  //int titleMusNum;               // music number to use for title

   // menu stuff
   const char *menuBackground;    // name of menu background flat
   const char *creditBackground;  // name of dynamic credit bg flat
   int   creditY;                 // y coord for credit text
   int   creditTitleStep;         // step-down from credit title
   menucursor_t *menuCursor;    // pointer to the big menu cursor
   char *mainMenuHeader;            // image lump name for the image header
   //menu_t *mainMenu;              // pointer to main menu structure
   //menu_t *saveMenu;              // pointer to save menu structure
   //menu_t *loadMenu;              // pointer to load menu structure
   //menu_t *newGameMenu;           // pointer to new game menu structure
   int *menuSounds;               // menu sound indices
   int transFrame;                // frame DEH # used on video menu
   int skvAtkSound;               // skin viewer attack sound
   int unselectColor;             // color of unselected menu item text
   int selectColor;               // color of selected menu item text
   int variableColor;             // color of variable text
   int titleColor;                // color of title strings
   int infoColor;                 // color of it_info items
   int bigFontItemColor;          // color of selectable items using big font
   int menuOffset;                // an amount to subtract from menu y coords
   void (*OnNewGame)(void);       // mn_newgame routine
   char *menufontprefix;          // menu font prefix for the patches
   int menufontoffset;          // number to start counting for

  // border stuff
  const char *borderFlat;        // name of flat to fill backscreen
  int *border;//giborder_t *border;            // pointer to a game border

  // Status bar
  statusbar_t *statusbar;
} gamemodeinfo_t;

// Global Game Mode Info Array
extern gamemodeinfo_t *GameModeInfoObjects[];

// Global Current Game Mode
extern gamemodeinfo_t *gamemodeinfo;

#endif
