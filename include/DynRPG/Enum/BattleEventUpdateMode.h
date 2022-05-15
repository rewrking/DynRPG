#ifndef DYNRPG_BATTLE_EVENT_UPDATE_MODE_H
#define DYNRPG_BATTLE_EVENT_UPDATE_MODE_H

namespace RPG
{
//! Possible values of the \c mode parameter of RPG::updateBattleEvents
/*! \warning I am not completely sure about the effects these modes have.
*/

enum BattleEventUpdateMode
{
	BEUM_BEFORE_ACTION, //!< Used before a battler executes its action
	BEUM_AFTER_ACTION, //!< Used after a battler executes its action
	BEUM_SWITCH_ACTIVATED, //!< Used when a skill or an item activates a switch
	BEUM_BATTLE_START //!< Used to call events with start condition "Turns elapsed [0x+0]"
};
}

#endif // DYNRPG_BATTLE_EVENT_UPDATE_MODE_H
