#ifndef DYNRPG_ACTION_STATUS_H
#define DYNRPG_ACTION_STATUS_H

namespace RPG
{
//! \brief Possible values for RPG::Battler::actionStatus
enum ActionStatus
{
	AS_IDLE, //!< No action is active
	AS_WAITING, //!< Info window is displayed or action is otherwise waiting
	AS_FINAL_PHASE //!< Final phase, damage is displayed, etc.
};
}

#endif // DYNRPG_ACTION_STATUS_H
