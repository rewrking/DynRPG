#ifndef RPG_DAMAGE_MULTIPLIER_HPP
#define RPG_DAMAGE_MULTIPLIER_HPP

#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
/*! \brief Possible values for RPG::DBActor::conditions, RPG::DBActor::attributes, RPG::DBMonster::conditions, RPG::DBMonster::attributes
	The damage multipliers.
*/
enum class DamageMultiplier : uchar
{
	DmgA,
	DmgB,
	DmgC,
	DmgD,
	DmgE
};

//! One-byte version or RPG::DamageMultiplier
//typedef uchar DamageMultiplier_T;
}

#endif // RPG_DAMAGE_MULTIPLIER_HPP
