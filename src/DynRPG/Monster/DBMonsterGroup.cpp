#define DYNRPG_STATIC
#include <DynRPG/Monster/DBMonsterGroup.hpp>

namespace RPG
{
/******************************************************************************
 *
 *****************************************************************************/
EventScriptLine* getBattleEventLine(int monsterGroup, int battleEventPage, int lineId)
{
	return dbMonsterGroups[monsterGroup]->battleEventPages[battleEventPage]->scriptLines->list->items[lineId];
}
}
