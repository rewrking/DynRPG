#ifndef RPG_COMMON_EVENT_TRIGGER_HPP
#define RPG_COMMON_EVENT_TRIGGER_HPP

#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
//! Possible values for the RPG::CommonEvent::trigger member
enum class CommonEventTrigger : uchar
{
	AutoStart = 3,
	ParallelProcess,
	Call
};

//! One-byte version of RPG::CommonEventTrigger
//typedef uchar CommonEventTrigger_T;
}

#endif // RPG_COMMON_EVENT_TRIGGER_HPP
