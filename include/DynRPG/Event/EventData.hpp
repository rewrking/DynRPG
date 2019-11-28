#ifndef RPG_EVENT_DATA_HPP
#define RPG_EVENT_DATA_HPP

#include <DynRPG/Catalog/CatalogPtr.hpp>
#include <DynRPG/Delphi/DStringPtr.hpp>
#include <DynRPG/Event/EventPage.hpp>

namespace RPG
{
/*! \brief Class used for storing event names, ids, the event pages, and script data

	\sa RPG::Map
	\sa RPG::Event
	\sa RPG::EventPage
*/
struct EventData
{
	void** vTable;
	int id; //!< The ID of the event
	DStringPtr name; //!< The name of the event
	int x; //!< The event's x coordinate
	int y; //!< The event's y coordinate
	CatalogPtr<EventPage*> pages; //!< The array of pages on the event, as well as their properties and event commands (zero-based)
};
}

#endif // RPG_EVENT_DATA_HPP