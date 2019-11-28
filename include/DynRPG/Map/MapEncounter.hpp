#ifndef RPG_MAP_ENCOUNTER_HPP
#define RPG_MAP_ENCOUNTER_HPP

namespace RPG
{
/*! \brief A single monster group encounter on a map (the map itself has the full array).

	\sa RPG::MapTreeProperties
	\sa RPG::MapTree
*/
struct MapEncounter
{
	// clang-format off
	void** vTable;
	int id; //!< The ID of this encounter (one-based)
		int _unknown_08;
	int monsterGroupId; //!< The database ID of the monster group
	// clang-format on
};

}

#endif // RPG_MAP_ENCOUNTER_HPP