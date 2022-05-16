#ifndef DYNRPG_MAP_ENCOUNTER_H
#define DYNRPG_MAP_ENCOUNTER_H

namespace RPG
{
/*! \brief A single monster group encounter on a map (the map itself has the full array).

	\sa RPG::MapTreeProperties
	\sa RPG::MapTree
*/
class MapEncounter
{
public:
	void **vTable;
	int id; //!< The ID of this encounter (one-based)
		int _unknown_08;
	int monsterGroupId; //!< The database ID of the monster group
};
}

#endif // DYNRPG_MAP_ENCOUNTER_H
