#ifndef RPG_MONSTER_PRECONDITION_HPP
#define RPG_MONSTER_PRECONDITION_HPP

#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
/*! \brief Possible values for RPG::MonsterBehavior::precondition

	The precondition of the action, as defined in the Behavior entry.
*/
enum class MonsterPrecondition : uchar
{
	None,
	Switch,
	Turns,
	MonsterPresent,
	MonsterHp,
	MonsterMp,
	AverageLevel,
	AverageExhaustion
};

//! One-byte version or RPG::MonsterPrecondition
//typedef uchar MonsterPrecondition_T;
}

#endif // RPG_MONSTER_PRECONDITION_HPP
