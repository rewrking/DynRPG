#ifndef DYNRPG_EVENT_PRECONDITION_VAR_LOGIC_H
#define DYNRPG_EVENT_PRECONDITION_VAR_LOGIC_H

namespace RPG
{
//! Possible values for the RPG::EventPrecondition::varLogic member
enum EventPreconditionVarLogic
{
	EPVL_EQUAL,
	EPVL_GREATER_EQUAL,
	EPVL_LESS_EQUAL,
	EPVL_GREATER,
	EPVL_LESS,
	EPVL_NOT_EQUAL
};
}

#endif // DYNRPG_EVENT_PRECONDITION_VAR_LOGIC_H
