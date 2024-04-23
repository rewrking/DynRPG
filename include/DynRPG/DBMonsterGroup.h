#ifndef DYNRPG_DB_MONSTER_GROUP_H
#define DYNRPG_DB_MONSTER_GROUP_H

#include <DynRPG/Enum/MonsterAlignment.h>

#include <DynRPG/BattleEventPage.h>
#include <DynRPG/CatalogPtr.h>
#include <DynRPG/DArray.h>
#include <DynRPG/DStringPtr.h>
#include <DynRPG/MonsterGroupPosition.h>
#include <DynRPG/NamedCatalogPtr.h>

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
class DYNRPG_API DBMonsterGroup
{
public:
	void** vTable;
	int id; //!< ID of the monster group
	DStringPtr name; //!< Name of the monster group
	CatalogPtr<MonsterGroupPosition*> monsterList; //!< The current monsters in the grouping, along with their position
	DArray<bool, 1> habitatTerrain; //!< The array of "Habitats" for this monster group
	CatalogPtr<BattleEventPage*> battleEventPages; //!< The battle event pages associated to this monster group
	bool randomizeHidden; //!< 50% chance for hidden flag
	MonsterAlignment alignment;

	/*! \brief Easily returns a battle event line.

		Allows you to write <tt>RPG::getBattleEventLine(23,1,1)->command</tt> instead of <tt>RPG::dbMonsterGroups[23]->battleEventPages[1]->scriptLines->list->items[1]->command</tt> which gets the 2nd line on the 2nd page of monster group 23.

		\param battleEventPage The monster group's battle event page ID (zero-based)
		\param lineId The line ID (zero-based)

		\sa RPG::BattleEventPage
	*/
	RPG::EventScriptLine* getEventPageLine(int battleEventPage, int lineId);
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
extern DYNRPG_API RPG::NamedCatalogPtr<RPG::DBMonsterGroup*>& dbMonsterGroups;

}

#endif // DYNRPG_DB_MONSTER_GROUP_H
