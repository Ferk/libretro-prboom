/* Emacs style mode select   -*- C++ -*-
 *-----------------------------------------------------------------------------
 *
 *
 *  PrBoom: a Doom port merged with LxDoom and LSDLDoom
 *  based on BOOM, a modified and improved DOOM engine
 *  Copyright (C) 1999 by
 *  id Software, Chi Hoang, Lee Killough, Jim Flynn, Rand Phares, Ty Halderman
 *  Copyright (C) 1999-2000 by
 *  Jess Haas, Nicolas Kalkhof, Colin Phipps, Florian Schulze
 *  Copyright 2005, 2006 by
 *  Florian Schulze, Colin Phipps, Neil Stevens, Andrey Budko
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
 *  Provides a logical console output routine that allows what is
 *  output to console normally and when output is redirected to
 *  be controlled..
 *
 *-----------------------------------------------------------------------------*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "doomtype.h"
#include "lprintf.h"
#include "i_main.h"
#include "m_argv.h"

#ifndef __LIBRETRO__
#include "libretro.h"
#endif

/* cphipps - enlarged message buffer and made non-static
 * We still have to be careful here, this function can be called after exit
 */
#define MAX_MESSAGE_SIZE 2048

int lprintf(OutputLevels pri, const char *s, ...)
{
  int r=0;
  char msg[MAX_MESSAGE_SIZE];

  va_list v;
  va_start(v,s);
#ifdef HAVE_VSNPRINTF
  vsnprintf(msg,sizeof(msg),s,v);         /* print message in buffer  */
#else
  vsprintf(msg,s,v);
#endif
  va_end(v);

  r=fprintf(stderr,"%s",msg);           /* select output at console */

  return r;
}

/*
 * I_Error
 *
 * cphipps - moved out of i_* headers, to minimise source files that depend on
 * the low-level headers. All this does is print the error, then call the
 * low-level safe exit function.
 * killough 3/20/98: add const
 */
bool I_Error(const char *error, ...)
{
  char errmsg[MAX_MESSAGE_SIZE];
  va_list argptr;
  va_start(argptr,error);
#ifdef HAVE_VSNPRINTF
  vsnprintf(errmsg,sizeof(errmsg),error,argptr);
#else
  vsprintf(errmsg,error,argptr);
#endif
  va_end(argptr);
  lprintf(LO_ERROR, "%s\n", errmsg);
  return false;
}

#ifndef __LIBRETRO__
/* Meant to notify user, in libretro it uses the OSD */
void I_Message(const char *str, ...)
{
  char msg[MAX_MESSAGE_SIZE];
  va_list argptr;
  va_start(argptr,str);
#ifdef HAVE_VSNPRINTF
  vsnprintf(msg,sizeof(msg),str,argptr);
#else
  vsprintf(msg,str,argptr);
#endif
  va_end(argptr);
  lprintf(LO_ERROR, "Message: %s\n", msg);
}
#endif
