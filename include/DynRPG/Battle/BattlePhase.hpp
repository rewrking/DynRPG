#ifndef RPG_BATTLE_PHASE_HPP
#define RPG_BATTLE_PHASE_HPP

namespace RPG
{
//! Possible values for RPG::BattleData::battlePhase
enum class BattlePhase
{
	Battle, //!< From the moment the battle starts until a victory/death condition
	Death, //!< After the party has died
	Victory, //!< After the party has achieved a victory
	End //!< After the battle screen has faded out before going back to the map
};
}

#endif // RPG_BATTLE_PHASE_HPP
