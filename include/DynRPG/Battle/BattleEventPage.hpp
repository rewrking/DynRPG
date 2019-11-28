#ifndef RPG_BATTLE_EVENT_PAGE_HPP
#define RPG_BATTLE_EVENT_PAGE_HPP

#include <DynRPG/Battle/BattleEventTrigger.hpp>
#include <DynRPG/Event/EventScriptList.hpp>

namespace RPG
{
/*! \brief Used to access battle event pages specific to the monster group being referenced.

	\sa RPG::DBMonsterGroup
	\sa RPG::dbMonsterGroups
*/
struct BattleEventPage
{
	// clang-format off
	void** vTable;
	int id; //!< The one-based ID of the event page
		int _unknown_08;
		int _unknown_0C;
		int _unknown_10;
	EventScriptList* scriptLines; //!< The event script lines
	BattleEventTrigger* triggers; //!< The trigger conditions for the battle event page
	// clang-format on
};
}

#endif // RPG_BATTLE_EVENT_PAGE_HPP
