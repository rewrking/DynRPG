#ifndef RPG_MONSTER_GROUP_POSITION_HPP
#define RPG_MONSTER_GROUP_POSITION_HPP

namespace RPG
{
/*! \brief Used to define an individual monster's position in the group.

	\sa RPG::DBMonsterGroup
	\sa RPG::dbMonsterGroups
*/
struct MonsterGroupPosition
{
	// clang-format off
	void** vTable;
	int id; //!< The one-based ID of the entry
		int _unknown_08;
	int monsterId; //!< monster's id
	int xPos; //!< X-position of the monster
	int yPos; //!< Y-position of the monster
	bool isHidden; //!< Is the monster hidden (aka "Invisible" in the editor)?
	// clang-format on
};
}

#endif // RPG_MONSTER_GROUP_POSITION_HPP
