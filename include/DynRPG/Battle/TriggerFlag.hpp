#ifndef RPG_TRIGGER_FLAG_HPP
#define RPG_TRIGGER_FLAG_HPP

#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
//! Possible values for the RPG::BattleEventTrigger::triggerFlags member
enum class TriggerFlag : uchar
{
	None = 0,
	SwitchA = 1,
	SwitchB = 2,
	Variable = 4,
	TurnNum = 8,
	Exhaustion = 16,
	MonsterHp = 32,
	HeroHp = 64,
	MonsterTurn = 128
};

//! One-byte version of RPG::TriggerFlag
//typedef uchar TriggerFlag_T;
}

#endif // RPG_TRIGGER_FLAG_HPP
