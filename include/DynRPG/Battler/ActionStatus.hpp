#ifndef RPG_ACTION_STATUS_HPP
#define RPG_ACTION_STATUS_HPP

namespace RPG
{
//! \brief Possible values for RPG::Battler::actionStatus
enum class ActionStatus
{
	Idle, //!< No action is active
	Waiting, //!< Info window is displayed or action is otherwise waiting
	FinalPhase //!< Final phase, damage is displayed, etc.
};
}

#endif // RPG_ACTION_STATUS_HPP
