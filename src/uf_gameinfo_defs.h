

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
 },
 {
  "Final DOOM: Plutonia Experiment",
  "plutonia.wad",
  NULL,
  MAP01,
 },
 {
  "Final DOOM: TNT - Evilution",
  "tnt.wad",
  NULL,
  MAP01,
 },
 {
  "Freedoom Phase 2",
  "freedoom2.wad",
  NULL,
  MAP01,
 },
 {
  "DOOM Registered version",
  "doom.wad",
  NULL,
  E1M1,
 },
 {
  "The Ultimate DOOM",
  "doomu.wad",
  NULL,
  E1M1,
 },
 {
  "Freedoom: Phase 1",
  "freedoom1.wad",
  NULL,
  E1M1,
 },
 {
  "Freedoom: Phase 1",
  "freedoom.wad",
  NULL,
  E1M1,
 },
 {
  "DOOM Shareware version",
  "doom1.wad",
  NULL,
  E1M1,
 },
};
static const int nstandard_iwads = sizeof standard_iwads/sizeof*standard_iwads;


#endif
