#ifndef RPG_TERRAIN_BATTLE_TYPE_HPP
#define RPG_TERRAIN_BATTLE_TYPE_HPP

namespace RPG
{
/*! \brief Possible values for RPG::Terrain::battleTypes

	\note Values can be combined up to 15 (meaning all 4 special battle types are checked off).
	The TBP_ALL enum has been added for convenience.
*/
enum class TerrainBattleType
{
	None = 0,
	Initiative = 1,
	BackAttack = 2,
	SurroundAttack = 4,
	PincersAttack = 8,
	All = 15
};
}

#endif // RPG_TERRAIN_BATTLE_TYPE_HPP
