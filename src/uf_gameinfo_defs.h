

#ifndef __UF_GAMEINFO_DEFS_H__
#define __UF_GAMEINFO_DEFS_H__


// definitions

#define MAP01        "MAP01"
#define E1M1         "E1M1"

static const char *doomSkullCursorPatches[] =
{
   "M_SKULL1",
   "M_SKULL2",
};
static const blinkpatches_t doomSkullCursor = {
  8, // blinktime
  2, // numpatches
  doomSkullCursorPatches // patches
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
  &doomSkullCursor,
 },
 {
  "Final DOOM: Plutonia Experiment",
  "plutonia.wad",
  NULL,
  MAP01,
  HAS_MAP32,
  commercial,
  pack_plut,
  &doomSkullCursor,
 },
 {
  "Final DOOM: TNT - Evilution",
  "tnt.wad",
  NULL,
  MAP01,
  HAS_MAP32,
  commercial,
  pack_tnt,
  &doomSkullCursor,
 },
 {
  "Freedoom Phase 2",
  "freedoom2.wad",
  NULL,
  MAP01,
  HAS_MAP32,
  commercial,
  doom2,
  &doomSkullCursor,
 },
 {
  "DOOM Registered version",
  "doom.wad",
  NULL,
  E1M1,
  HAS_EPISODE1|HAS_EPISODE2,
  registered,
  doom,
  &doomSkullCursor,
 },
 {
  "The Ultimate DOOM",
  "doomu.wad",
  NULL,
  E1M1,
  HAS_EPISODE1|HAS_EPISODE2|HAS_EPISODE4,
  retail,
  doom,
  &doomSkullCursor,
 },
 {
  "Freedoom: Phase 1",
  "freedoom1.wad",
  NULL,
  E1M1,
  HAS_EPISODE1|HAS_EPISODE2|IS_FREEDOOM,
  retail,
  doom,
  &doomSkullCursor,
 },
 {
  "Freedoom: Phase 1",
  "freedoom.wad",
  NULL,
  E1M1,
  HAS_EPISODE1|HAS_EPISODE2|HAS_EPISODE4,
  retail,
  doom,
  &doomSkullCursor,
 },
 {
  "DOOM Shareware version",
  "doom1.wad",
  NULL,
  E1M1,
  HAS_EPISODE1,
  commercial,
  doom,
  &doomSkullCursor,
 },
 {
  "Heretic Shareware version",
  "heretic.wad",
  NULL,
  E1M1,
  HAS_EPISODE1|HAS_RAVEN_LUMPS,
  shareware,
  doom,
  &doomSkullCursor,
 },
 {
  "Heretic Registered version",
  "heretic.wad",
  NULL,
  E1M1,
  HAS_EPISODE1|HAS_EPISODE2|HAS_RAVEN_LUMPS,
  shareware,
  doom,
  &doomSkullCursor,
 },
 {
  "Heretic: Shadow of the Serpent Riders",
  "heretic.wad",
  NULL,
  E1M1,
  HAS_EPISODE1|HAS_EPISODE2|HAS_EPISODE4|HAS_RAVEN_LUMPS,
  shareware,
  doom,
  &doomSkullCursor,
  },
};
static const int nstandard_iwads = sizeof standard_iwads/sizeof*standard_iwads;


#endif
