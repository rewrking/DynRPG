#ifndef DYNRPG_COMMON_EVENT_H
#define DYNRPG_COMMON_EVENT_H

#include <DynRPG/Enum/CommonEventTrigger.h>

#include <DynRPG/DStringPtr.h>
#include <DynRPG/EventScriptData.h>
#include <DynRPG/NamedCatalogPtr.h>

namespace RPG
{
/*! \brief Access to the common events.
	\sa RPG::commonEvents
	\sa RPG::CommonEventTrigger
*/
class DYNRPG_API CommonEvent
{
public:
	void** vTable;
	int id; //!< The ID of the common event
	DStringPtr name; //!< The name of the common event
	int _unknown_0C;
	int _unknown_10;
	EventScriptList* scriptLines; //!< The event script lines
	CommonEventTrigger_T trigger; //!< The trigger condition for the common event
	bool switchActivated; //!< Is the common event activated via switch?
	int switchId; //!< The switch ID if activated via switch

	/*! \brief Easily returns a common event line.

		Allows you to write <tt>RPG::getCommonEventLine(12,1)->command</tt> instead of <tt>RPG::commonEvents[12]->scriptLines->list->items[1]->command</tt> which gets the 2nd line of common event 12.

		\param lineId The line ID (zero-based)

		\sa RPG::CommonEvent
	*/
	RPG::EventScriptLine* getLine(int lineId);
};

/*! \ingroup game_objects
	\brief Access to the common events.
*/
extern DYNRPG_API RPG::NamedCatalogPtr<RPG::CommonEvent*>& commonEvents;

}

#endif // DYNRPG_COMMON_EVENT_H
