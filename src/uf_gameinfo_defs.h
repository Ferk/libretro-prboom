

#ifndef __UF_GAMEINFO_DEFS_H__
#define __UF_GAMEINFO_DEFS_H__

#include "uf_gameinfo.h"

extern const demostate_t demostates_doom[];
extern const demostate_t demostates_doom2[];
extern const demostate_t demostates_udoom[];
extern const demostate_t demostates_hsw[];
extern const demostate_t demostates_hreg[];

// definitions

#define MAP01 "MAP01"
#define E1M1  "E1M1"

static const char *doomSkullCursorPatches[] =
{
   "M_SKULL1",
   "M_SKULL2",
};
static blinkpatches_t doomSkullCursor = {
  8, // blinktime
  2, // numpatches
  doomSkullCursorPatches // patches
};

static const char *arrowCursorPatches[] =
{
   "M_SLCTR1",
   "M_SLCTR2",
};

static blinkpatches_t arrowCursor =
{
   16,                // blinktime
   2,                 // numpatches
   arrowCursorPatches // patch array
};


// list of standard IWAD information
const gameinfo_t standard_iwads[]=
{
 {
  "DOOM 2: Hell on Earth",
  "doom2.wad",
  NULL,
  MAP01,
  HAS_MAP32,
  commercial,
  doom2,
  "M_DOOM",
  &doomSkullCursor,
  demostates_doom2,
  "MFLR8_4",
 },
 {
  "Final DOOM: Plutonia Experiment",
  "plutonia.wad",
  NULL,
  MAP01,
  HAS_MAP32,
  commercial,
  pack_plut,
  "M_DOOM",
  &doomSkullCursor,
  demostates_doom2,
  "MFLR8_4",
 },
 {
  "Final DOOM: TNT - Evilution",
  "tnt.wad",
  NULL,
  MAP01,
  HAS_MAP32,
  commercial,
  pack_tnt,
  "M_DOOM",
  &doomSkullCursor,
  demostates_doom2,
  "MFLR8_4",
 },
 {
  "Freedoom Phase 2",
  "freedoom2.wad",
  NULL,
  MAP01,
  HAS_MAP32,
  commercial,
  doom2,
  "M_DOOM",
  &doomSkullCursor,
  demostates_doom2,
  "MFLR8_4",
 },
 {
  "DOOM Registered version",
  "doom.wad",
  NULL,
  E1M1,
  HAS_EPISODE1|HAS_EPISODE2,
  registered,
  doom,
  "M_DOOM",
  &doomSkullCursor,
  demostates_doom,
  "MFLR8_4",
 },
 {
  "The Ultimate DOOM",
  "doomu.wad",
  NULL,
  E1M1,
  HAS_EPISODE1|HAS_EPISODE2|HAS_EPISODE4,
  retail,
  doom,
  "M_DOOM",
  &doomSkullCursor,
  demostates_udoom,
  "MFLR8_4",
 },
 {
  "Freedoom: Phase 1",
  "freedoom1.wad",
  NULL,
  E1M1,
  HAS_EPISODE1|HAS_EPISODE2|IS_FREEDOOM,
  retail,
  doom,
  "M_DOOM",
  &doomSkullCursor,
  demostates_udoom,
  "MFLR8_4",
 },
 {
  "Freedoom: Phase 1",
  "freedoom.wad",
  NULL,
  E1M1,
  HAS_EPISODE1|HAS_EPISODE2|HAS_EPISODE4,
  retail,
  doom,
  "M_DOOM",
  &doomSkullCursor,
  demostates_udoom,
  "MFLR8_4",
 },
 {
  "DOOM Shareware version",
  "doom1.wad",
  NULL,
  E1M1,
  HAS_EPISODE1,
  commercial,
  doom,
  "M_DOOM",
  &doomSkullCursor,
  demostates_doom,
  "CEIL5_1",
 },
 {
  "Heretic Shareware version",
  "heretic.wad",
  NULL,
  E1M1,
  HAS_EPISODE1|HAS_RAVEN_LUMPS,
  shareware,
  doom,
  "M_HTIC",
  &arrowCursor,
  demostates_hsw,
  "FLTWAWA1",
 },
 {
  "Heretic Registered version",
  "heretic.wad",
  NULL,
  E1M1,
  HAS_EPISODE1|HAS_EPISODE2|HAS_RAVEN_LUMPS,
  shareware,
  doom,
  "M_HTIC",
  &arrowCursor,
  demostates_hreg,
  "FLTWAWA1",
 },
 {
  "Heretic: Shadow of the Serpent Riders",
  "heretic.wad",
  NULL,
  E1M1,
  HAS_EPISODE1|HAS_EPISODE2|HAS_EPISODE4|HAS_RAVEN_LUMPS,
  shareware,
  doom,
  "M_HTIC",
  &arrowCursor,
  demostates_hreg,
  "FLTWAWA1",
 },
};
static const int nstandard_iwads = sizeof standard_iwads/sizeof*standard_iwads;


#endif
