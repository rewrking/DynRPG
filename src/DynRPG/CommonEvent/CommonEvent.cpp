#define DYNRPG_STATIC
#include <DynRPG/CommonEvent/CommonEvent.hpp>

namespace RPG
{
/******************************************************************************
 *
 *****************************************************************************/
EventScriptLine* getCommonEventLine(int eventId, int lineId)
{
	return commonEvents[eventId]->scriptLines->list->items[lineId];
}
}
