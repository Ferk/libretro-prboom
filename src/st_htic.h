


#ifndef __ST_HTIC_H__
#define __ST_HTIC_H__

#include "doomtype.h"


// Called by main loop.
//boolean ST_Responder(event_t* ev);

// Called by main loop.
void ST_HTIC_Ticker(void);

// Called by main loop.
void ST_HTIC_Drawer(boolean st_statusbaron, boolean refresh, boolean fullmenu);

// Called when the console player is spawned on each level.
void ST_HTIC_Start(void);

// Called by startup code.
void ST_HTIC_Init(void);


#endif
