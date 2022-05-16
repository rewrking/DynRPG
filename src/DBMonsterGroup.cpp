#include <DynRPG/DBMonsterGroup.h>

namespace RPG
{
RPG::EventScriptLine* DBMonsterGroup::getEventPageLine(int battleEventPage, int lineId)
{
	return battleEventPages[battleEventPage]->scriptLines->list->items[lineId];
}
}
