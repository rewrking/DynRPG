#ifndef DYNRPG_BATTLE_PHASE_H
#define DYNRPG_BATTLE_PHASE_H

namespace RPG
{
//! Possible values for RPG::BattleData::battlePhase
enum BattlePhase
{
	BPHASE_BATTLE, //!< From the moment the battle starts until a victory/death condition
	BPHASE_DEATH, //!< After the party has died
	BPHASE_VICTORY, //!< After the party has achieved a victory
	BPHASE_END //!< After the battle screen has faded out before going back to the map
};
}

#endif // DYNRPG_BATTLE_PHASE_H
