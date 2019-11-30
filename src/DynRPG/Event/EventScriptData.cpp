#define DYNRPG_STATIC
#include <DynRPG/Event/EventScriptData.hpp>

namespace RPG
{
/******************************************************************************
 *
 *****************************************************************************/
EventScriptLine* EventScriptData::line(int index)
{
	if (lines && lines->list)
		return lines->list->get(index);

	return nullptr;
}
}
