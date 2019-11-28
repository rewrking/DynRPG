#ifndef RPG_EVENT_HPP
#define RPG_EVENT_HPP

#include <DynRPG/Character/Character.hpp>
#include <DynRPG/Event/EventData.hpp>
#include <DynRPG/Event/EventPage.hpp>

namespace RPG
{
/*! \brief Used for events as subtype of characters
	\sa RPG::Map::events
*/
struct Event : Character
{
	// clang-format off
	// sizeof(Character) == 0x94
		int _unknown_94;
	EventData* data; //!< Pointer to the RPG::EventData of this event
	EventPage* currentPage; //!< The currently loaded event page
	bool isWaiting; //!< Is the event waiting? Set to true to run the event's code, but has some dependency with facing/direction event to hero relationships that affect whether it runs or not.
		int _unknown_A4;
		int _unknown_A8;
		int _unknown_AC; // Pointer to More scriptData? See
	// clang-format on

	/*! \brief Checks whether a certain event page exists

		This function may be used to check for a certain event page
		prior to calling it.
		\param id Event page to check
		\return \c true if the event page exists, \c false otherwise
	*/
	bool doesEventPageExist(int id);

	/*! \brief Built-in function to run various checks after a step has been made (NOT map collision!)... event-related checks (not all known)
	*/
	void act();
};
}

#endif // RPG_EVENT_HPP
