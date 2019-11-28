#ifndef RPG_EVENT_PAGE_HPP
#define RPG_EVENT_PAGE_HPP

#include <DynRPG/Character/Facing.hpp>
#include <DynRPG/Event/EventFrame.hpp>
#include <DynRPG/Event/EventMoveFrequency.hpp>
#include <DynRPG/Event/EventPrecondition.hpp>
#include <DynRPG/Event/EventScriptList.hpp>
#include <DynRPG/Event/MoveRoute.hpp>
#include <DynRPG/Utility/Types.hpp>

namespace RPG
{

/*! \brief Used for pages within a map event, along with their conditions, script list, commands, etc.

	\sa RPG::EventData
	\sa RPG::EventPrecondition
	\sa RPG::Facing
	\sa RPG::EventFrame
	\sa RPG::MoveRoute
*/
struct EventPage
{
	// clang-format off
	void** vTable;
	int id; //!< ID of the event page (1-100)
		int _unknown_08;
		int _unknown_0C;
		StubPtr _unknown_10;
	EventScriptList* scriptLines; //!< The event script lines! (See RPG::EventScriptList)
	EventPrecondition* preconditions; //!< The event's preconditions (See RPG::MapEventPrecondition)
	DStringPtr charsetFilename; //!< The filename of the charset used for the event graphic
	int charsetId; //!< The ID of the character within the charset (0-7)
	Facing charsetDir; //!< The direction the charset is facing in
	EventFrame charsetFrame; //!< The starting frame of animation for the charset (See RPG::EventFrame)
	bool isTransparent; //!< Is the event graphic transparent?
	int moveSpeed; //!< The event's movement speed (1-8)
		StubPtr _unknown_34;
	EventMoveFrequency moveFrequency; //!< The event's movement frequency (See RPG::EventMoveFrequency)
	MoveRoute* moveRoute; //!< The move route of the event
	// clang-format on

	// WHERE'S MOVEMENT TYPE, FORBID EVENT OVERLAP, TRIGGER CONDITION, EVENT LAYER
	// AAAAH WHY AM I YELLING
};
}

#endif // RPG_EVENT_PAGE_HPP