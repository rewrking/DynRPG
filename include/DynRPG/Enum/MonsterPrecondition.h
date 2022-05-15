#ifndef DYNRPG_MONSTER_PRECONDITION_H
#define DYNRPG_MONSTER_PRECONDITION_H

namespace RPG
{
/*! \brief Possible values for RPG::MonsterBehavior::precondition

	The precondition of the action, as defined in the Behavior entry.
*/
enum MonsterPrecondition
{
	MON_PRE_NONE,
	MON_PRE_SWITCH,
	MON_PRE_TURNS,
	MON_PRE_MONSTER_PRESENT,
	MON_PRE_MONSTER_HP,
	MON_PRE_MONSTER_MP,
	MON_PRE_AVG_LEVEL,
	MON_PRE_AVG_EXHAUSTION
};

//! One-byte version or RPG::MonsterPrecondition
typedef unsigned char MonsterPrecondition_T;
}

#endif // DYNRPG_MONSTER_PRECONDITION_H
