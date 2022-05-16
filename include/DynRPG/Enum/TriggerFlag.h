#ifndef DYNRPG_TRIGGER_FLAG_H
#define DYNRPG_TRIGGER_FLAG_H

namespace RPG
{
//! Possible values for the RPG::BattleEventTrigger::triggerFlags member
enum TriggerFlag
{
	TF_NONE = 0,
	TF_SWITCH_A = 1,
	TF_SWITCH_B = 2,
	TF_VARIABLE = 4,
	TF_TURN_NUM = 8,
	TF_EXHAUSTION = 16,
	TF_MONSTER_HP = 32,
	TF_HERO_HP = 64,
	TF_MONSTER_TURN = 128
};

//! One-byte version of RPG::TriggerFlag
typedef unsigned char TriggerFlag_T;

//! Possible values for the RPG::BattleEventTrigger::triggerFlags2k3 member
enum TriggerFlag2k3
{
	TF2_HERO_TURN = 1,
	TF2_BATTLE_COMMAND = 2
};

//! One-byte version of RPG::TriggerFlag2k3
typedef unsigned char TriggerFlag2k3_T;
}

#endif // DYNRPG_TRIGGER_FLAG_H
