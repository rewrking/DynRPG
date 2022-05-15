#ifndef DYNRPG_DAMAGE_MULTIPLIER_H
#define DYNRPG_DAMAGE_MULTIPLIER_H

namespace RPG
{
/*! \brief Possible values for RPG::DBActor::conditions, RPG::DBActor::attributes, RPG::DBMonster::conditions, RPG::DBMonster::attributes
	The damage multipliers.
*/
enum DamageMultiplier
{
	DMG_A,
	DMG_B,
	DMG_C,
	DMG_D,
	DMG_E
};

//! One-byte version or RPG::DamageMultiplier
typedef unsigned char DamageMultiplier_T;
}

#endif // DYNRPG_DAMAGE_MULTIPLIER_H
