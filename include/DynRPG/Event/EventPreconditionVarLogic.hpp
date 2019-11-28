#ifndef RPG_EVENT_PRECONDITION_VAR_LOGIC_HPP
#define RPG_EVENT_PRECONDITION_VAR_LOGIC_HPP

namespace RPG
{
//! Possible values for the RPG::EventPrecondition::varLogic member
enum EventPreconditionVarLogic
{
	Equal,
	GreaterThanEqual,
	LessThanEqual,
	GreaterThan,
	LessThan,
	NotEqual
};
}

#endif // RPG_EVENT_PRECONDITION_VAR_LOGIC_HPP
