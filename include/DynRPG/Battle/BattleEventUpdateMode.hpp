#ifndef RPG_BATTLE_EVENT_UPDATE_MODE_HPP
#define RPG_BATTLE_EVENT_UPDATE_MODE_HPP

namespace RPG
{
//! Possible values of the \c mode parameter of RPG::updateBattleEvents
/*! \warning I am not completely sure about the effects these modes have. */
enum class BattleEventUpdateMode
{
	BeforeAction, //!< Used before a battler executes its action
	AfterAction, //!< Used after a battler executes its action
	SwitchActivated, //!< Used when a skill or an item activates a switch
	BattleStart //!< Used to call events with start condition "Turns elapsed [0x+0]"
};
}

#endif // RPG_BATTLE_EVENT_UPDATE_MODE_HPP
