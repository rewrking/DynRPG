#ifndef RPG_RANDOM_ENCOUNTER_DEATH_HPP
#define RPG_RANDOM_ENCOUNTER_DEATH_HPP

namespace RPG
{
//! Possible values for RPG::BattleSettings::randomEncounterDeath
enum class RandomEncounterDeath
{
	GameOver,
	CallCommonEvent
};
}

#endif // RPG_RANDOM_ENCOUNTER_DEATH_HPP
