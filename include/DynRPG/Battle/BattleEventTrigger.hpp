#ifndef RPG_BATTLE_EVENT_TRIGGER_HPP
#define RPG_BATTLE_EVENT_TRIGGER_HPP

#include <DynRPG/Battle/TriggerFlag.hpp>
#include <DynRPG/Battle/TriggerFlag2k3.hpp>

namespace RPG
{
/*! \brief Used to access event command specific to the current battle. (OMG YES)

	\sa RPG::DBMonsterGroup
	\sa RPG::BattleEventPage
	\sa RPG::TriggerFlag
	\sa RPG::TriggerFlag2k3
*/
struct BattleEventTrigger
{
	void** vTable;
	TriggerFlag triggerFlags; //!< The triggers that are checked off (enums can be combined)
	TriggerFlag2k3 triggerFlags2k3; //!< Additional triggers added in Rm2k3 (enums can be combined)
	int switchId[2]; //!< The IDs of switches A & B
	int variableId; //!< The ID of the variable to trigger
	int variableValue; //!< The variable trigger will be above this value
	int turnsXValue; //!< The "X" value for the general turns elapsed (left field)
	int turnsPlusValue; //!< The plus value for the general turns elapsed (right field)
	int exhaustionStart; //!< Between this value and exhaustionEnd (left field)
	int exhaustionEnd; //!< Between exhaustionStart and this value (right field)
	int monsterHpMonId; //!< Monster party slot (zero-based) for when "HP between" is checked off
	int monsterHpStart; //!< Between this value and monsterHpEnd (left field)
	int monsterHpEnd; //!< Between monsterHpStart and this value (right field)
	int heroHpHeroId; //!< The hero whose HP causes the trigger (database ID) ("HP Between" checkbox)
	int heroHpStart; //!< Between this value and heroHpEnd (left field)
	int heroHpEnd; //!< Between heroHpStart and this value (right field)
	int monsterTurnsMonId; //!< The monster whose turns cause the trigger (zero-based)
	int monsterTurnsXValue; //!< The "X" value for the monster's turns (left field)
	int monsterTurnsPlusValue; //!< The plus value for the monster's turns (right field)
	int heroTurnsHeroId; //!< The hero whose turns cause the trigger (database ID)
	int heroTurnsXValue; //!< The "X" value for the hero's turns (left field)
	int heroTurnsPlusValue; //!< The plus value for the hero's turns (right field)
	int heroCommandHeroId; //!< The hero whose command should cause the trigger (database ID)
	int heroCommandId; //!< The actual command ID (one-based)(See RPG::BattleCommands)
};

}

#endif // RPG_BATTLE_EVENT_TRIGGER_HPP
