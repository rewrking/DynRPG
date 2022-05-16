#ifndef DYNRPG_RANDOM_ENCOUNTER_DEATH_H
#define DYNRPG_RANDOM_ENCOUNTER_DEATH_H

namespace RPG
{
//! Possible values for RPG::BattleSettings::randomEncounterDeath
enum RandomEncounterDeath
{
	RE_DEATH_GAME_OVER,
	RE_DEATH_CALL_COMMON_EVENT
};
}

#endif // DYNRPG_RANDOM_ENCOUNTER_DEATH_H
