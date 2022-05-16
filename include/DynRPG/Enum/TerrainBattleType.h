#ifndef DYNRPG_TERRAIN_BATTLE_TYPE_H
#define DYNRPG_TERRAIN_BATTLE_TYPE_H

namespace RPG
{
/*! \brief Possible values for RPG::Terrain::battleTypes

	\note Values can be combined up to 15 (meaning all 4 special battle types are checked off).
	The TBP_ALL enum has been added for convenience.
*/
enum TerrainBattleType
{
	TBP_NONE = 0,
	TBP_INITIATIVE = 1,
	TBP_BACK_ATK = 2,
	TBP_SURROUND_ATK = 4,
	TBP_PINCERS_ATK = 8,
	TBP_ALL = 15
};
}

#endif // DYNRPG_TERRAIN_BATTLE_TYPE_H
