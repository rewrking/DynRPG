#ifndef DYNRPG_COMMON_EVENT_TRIGGER_H
#define DYNRPG_COMMON_EVENT_TRIGGER_H

namespace RPG
{
//! Possible values for the RPG::CommonEvent::trigger member
enum CommonEventTrigger
{
	CET_AUTO_START = 3,
	CET_PARALLEL_PROCESS,
	CET_CALL
};

//! One-byte version of RPG::CommonEventTrigger
typedef unsigned char CommonEventTrigger_T;
}

#endif // DYNRPG_COMMON_EVENT_TRIGGER_H
