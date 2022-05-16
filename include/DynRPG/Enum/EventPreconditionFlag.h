#ifndef DYNRPG_EVENT_PRECONDITION_FLAG_H
#define DYNRPG_EVENT_PRECONDITION_FLAG_H

namespace RPG
{
//! Possible values for the RPG::EventPrecondition::flag member
enum EventPreconditionFlag
{
	EPF_NONE = 0,
	EPF_SWITCH_A = 1,
	EPF_SWITCH_B = 2,
	EPF_VARIABLE = 4,
	EPF_ITEM = 8,
	EPF_HERO = 16,
	EPF_TIMER1 = 32,
	EPF_TIMER2 = 64
};

//! One-byte version of RPG::EventPreconditionFlag
typedef unsigned char EventPreconditionFlag_T;
}

#endif // DYNRPG_EVENT_PRECONDITION_FLAG_H
