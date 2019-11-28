#ifndef RPG_TRIGGER_FLAG_2K3_HPP
#define RPG_TRIGGER_FLAG_2K3_HPP

#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
//! Possible values for the RPG::BattleEventTrigger::triggerFlags2k3 member
enum TriggerFlag2k3 : uchar
{
	HeroTurn = 1,
	BattleCommand = 2
};

//! One-byte version of RPG::TriggerFlag2k3
//typedef uchar TriggerFlag2k3_T;
}

#endif // RPG_TRIGGER_FLAG_2K3_HPP
