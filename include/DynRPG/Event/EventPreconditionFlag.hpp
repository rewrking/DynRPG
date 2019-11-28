#ifndef RPG_EVENT_PRECONDITION_FLAG_HPP
#define RPG_EVENT_PRECONDITION_FLAG_HPP

#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
//! Possible values for the RPG::EventPrecondition::flag member
enum class EventPreconditionFlag : uchar
{
	None = 0,
	SwitchA = 1,
	SwitchB = 2,
	Variable = 4,
	Item = 8,
	Hero = 16,
	Timer1 = 32,
	Timer2 = 64
};

//! One-byte version of RPG::EventPreconditionFlag
//typedef uchar EventPreconditionFlag_T;
}

#endif // RPG_EVENT_PRECONDITION_FLAG_HPP
