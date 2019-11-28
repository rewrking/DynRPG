#ifndef RPG_BATTLE_ENCOUNTER_CONDITION_HPP
#define RPG_BATTLE_ENCOUNTER_CONDITION_HPP

namespace RPG
{
//! Possible values for RPG::BattleData::encounterCondition
enum class BattleEncounterCondition
{
	NoSpecialConditions,
	Initiative,
	BackAttack,
	SurroundAttack,
	PincerAttack,
};
}

#endif // RPG_BATTLE_ENCOUNTER_CONDITION_HPP
