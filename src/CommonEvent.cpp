#include <DynRPG/CommonEvent.h>

namespace RPG
{
RPG::EventScriptLine* CommonEvent::getLine(int lineId)
{
	return scriptLines->list->items[lineId];
}
}
