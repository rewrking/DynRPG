#ifndef RPG_DB_MONSTER_GROUP_HPP
#define RPG_DB_MONSTER_GROUP_HPP

#include <DynRPG/Battle/BattleEventPage.hpp>
#include <DynRPG/Catalog/CatalogPtr.hpp>
#include <DynRPG/Catalog/NamedCatalogPtr.hpp>
#include <DynRPG/Delphi/DArray.hpp>
#include <DynRPG/Delphi/DStringPtr.hpp>
#include <DynRPG/Monster/MonsterAlignment.hpp>
#include <DynRPG/Monster/MonsterGroupPosition.hpp>

namespace RPG
{
/*! \brief Used for the default data of monster groups which are defined in the
	database

	\sa RPG::dbMonsterGroups
	\sa RPG::MonsterAlignment
	\sa RPG::BattleEventPage
	\sa RPG::MonsterGroupPosition
	\sa RPG::getBattleEventLine(int monsterGroup, int battleEventPage, int lineId)
*/

struct DBMonsterGroup
{
	void** vTable;
	int id; //!< ID of the monster group
	DStringPtr name; //!< Name of the monster group
	CatalogPtr<MonsterGroupPosition*> monsterList; //!< The current monsters in the grouping, along with their position
	DArray<bool, 1> habitatTerrain; //!< The array of "Habitats" for this monster group
	CatalogPtr<BattleEventPage*> battleEventPages; //!< The battle event pages associated to this monster group
	bool randomizeHidden; //!< 50% chance for hidden flag
	MonsterAlignment alignment;
};

/*! \ingroup game_objects
	\brief Array of monsters from the database, used for default values and
	properties which are not supposed to be changed in-game.

	Use the database ID as index for accessing a monster.

	Example:
	\code
int monCrit = RPG::dbMonsterGroups[1]->critPercentage;
	\endcode
*/
static NamedCatalogPtr<DBMonsterGroup*>& dbMonsterGroups = (**reinterpret_cast<NamedCatalogPtr<DBMonsterGroup*>**>(0x4CDDC0));

/*! \brief Easily returns a battle event line.

	Allows you to write <tt>RPG::getBattleEventLine(23,1,1)->command</tt> instead of <tt>RPG::dbMonsterGroups[23]->battleEventPages[1]->scriptLines->list->items[1]->command</tt> which gets the 2nd line on the 2nd page of monster group 23.

	\param monsterGroup The monster group ID (one-based)
	\param battleEventPage The monster group's battle event page ID (zero-based)
	\param lineId The line ID (zero-based)

	\sa RPG::BattleEventPage
*/
EventScriptLine* getBattleEventLine(int monsterGroup, int battleEventPage, int lineId);
}

#endif // RPG_DB_MONSTER_GROUP_HPP