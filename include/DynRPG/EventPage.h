#ifndef DYNRPG_EVENT_PAGE_H
#define DYNRPG_EVENT_PAGE_H

#include <DynRPG/Enum/EventFrame.h>
#include <DynRPG/Enum/EventMoveFrequency.h>
#include <DynRPG/Enum/Facing.h>

#include <DynRPG/DStringPtr.h>
#include <DynRPG/EventPrecondition.h>
#include <DynRPG/EventScriptData.h>
#include <DynRPG/MoveRoute.h>

namespace RPG
{
/*! \brief Used for pages within a map event, along with their conditions, script list, commands, etc.

	\sa RPG::EventData
	\sa RPG::EventPrecondition
	\sa RPG::Facing
	\sa RPG::EventFrame
	\sa RPG::MoveRoute
*/
class EventPage
{
public:
	void** vTable;
	int id; //!< ID of the event page (1-100)
	int _unknown_08;
	int _unknown_0C;
	void* _unknown_10;
	EventScriptList* scriptLines; //!< The event script lines! (See RPG::EventScriptList)
	EventPrecondition* preconditions; //!< The event's preconditions (See RPG::MapEventPrecondition)
	DStringPtr charsetFilename; //!< The filename of the charset used for the event graphic
	int charsetId; //!< The ID of the character within the charset (0-7)
	Facing charsetDir; //!< The direction the charset is facing in
	EventFrame charsetFrame; //!< The starting frame of animation for the charset (See RPG::EventFrame)
	bool isTransparent; //!< Is the event graphic transparent?
	int moveSpeed; //!< The event's movement speed (1-8)
	void* _unknown_34;
	EventMoveFrequency moveFrequency; //!< The event's movement frequency (See RPG::EventMoveFrequency)
	MoveRoute* moveRoute; //!< The move route of the event

	// WHERE'S MOVEMENT TYPE, FORBID EVENT OVERLAP, TRIGGER CONDITION, EVENT LAYER
	// AAAAH WHY AM I YELLING
};
}

#endif // DYNRPG_EVENT_PAGE_H
