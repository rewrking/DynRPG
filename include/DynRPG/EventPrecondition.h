#ifndef DYNRPG_EVENT_PRECONDITION_H
#define DYNRPG_EVENT_PRECONDITION_H

#include <DynRPG/Enum/EventPreconditionFlag.h>
#include <DynRPG/Enum/EventPreconditionVarLogic.h>

namespace RPG
{
/*! \brief The preconditions for a particular event page

	\sa RPG::EventPage
	\sa RPG::EventData
	\sa RPG::EventPreconditionFlag
	\sa RPG::EventPreconditionVarLogic
*/
class EventPrecondition
{
public:
	void** vTable;
	EventPreconditionFlag_T flag; //!< Precondition flags (can be combined)
	int switchId[2]; //!< The IDs of switches A & B
	int variableId; //!< The ID of the variable to trigger
	int variableValue; //!< The variable trigger will be above this value
	int itemId; //!< Database ID of item
	int heroId; //!< Database ID of hero
	int TimerValue[2]; //!< The values of timers 1 & 2 (in seconds)
	EventPreconditionVarLogic varLogic; //!< The variable's logic (equal/greater/less etc.)
};
}

#endif // DYNRPG_EVENT_PRECONDITION_H
