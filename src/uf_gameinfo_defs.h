

#ifndef __UF_GAMEINFO_DEFS_H__
#define __UF_GAMEINFO_DEFS_H__


// definitions

#define MAP01        "MAP01"
#define E1M1         "E1M1"


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
 },
 {
  "Final DOOM: Plutonia Experiment",
  "plutonia.wad",
  NULL,
  MAP01,
  HAS_MAP32,
  commercial,
  pack_plut,
 },
 {
  "Final DOOM: TNT - Evilution",
  "tnt.wad",
  NULL,
  MAP01,
  HAS_MAP32,
  commercial,
  pack_tnt,
 },
 {
  "Freedoom Phase 2",
  "freedoom2.wad",
  NULL,
  MAP01,
  HAS_MAP32,
  commercial,
  doom2,
 },
 {
  "DOOM Registered version",
  "doom.wad",
  NULL,
  E1M1,
  HAS_EPISODE1|HAS_EPISODE2,
  registered,
  doom,
 },
 {
  "The Ultimate DOOM",
  "doomu.wad",
  NULL,
  E1M1,
  HAS_EPISODE1|HAS_EPISODE2|HAS_EPISODE4,
  retail,
  doom,
 },
 {
  "Freedoom: Phase 1",
  "freedoom1.wad",
  NULL,
  E1M1,
  HAS_EPISODE1|HAS_EPISODE2|IS_FREEDOOM,
  retail,
  doom,
 },
 {
  "Freedoom: Phase 1",
  "freedoom.wad",
  NULL,
  E1M1,
  HAS_EPISODE1|HAS_EPISODE2|HAS_EPISODE4,
  retail,
  doom,
 },
 {
  "DOOM Shareware version",
  "doom1.wad",
  NULL,
  E1M1,
  HAS_EPISODE1,
  commercial,
  doom,
 },
 {
  "Heretic Shareware version",
  "heretic.wad",
  NULL,
  E1M1,
  HAS_EPISODE1|HAS_RAVEN_LUMPS,
  shareware,
  doom,
 },
 {
  "Heretic Registered version",
  "heretic.wad",
  NULL,
  E1M1,
  HAS_EPISODE1|HAS_EPISODE2|HAS_RAVEN_LUMPS,
  shareware,
  doom,
 },
 {
  "Heretic: Shadow of the Serpent Riders",
  "heretic.wad",
  NULL,
  E1M1,
  HAS_EPISODE1|HAS_EPISODE2|HAS_EPISODE4|HAS_RAVEN_LUMPS,
  shareware,
  doom,
  },
};
static const int nstandard_iwads = sizeof standard_iwads/sizeof*standard_iwads;


#endif
