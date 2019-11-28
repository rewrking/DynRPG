#ifndef RPG_BATTLE_NAVIGATION_LEVEL_HPP
#define RPG_BATTLE_NAVIGATION_LEVEL_HPP

#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
//! Possible values for RPG::BattleData::navLevel
enum class BattleNavigationLevel : uchar
{
	InFightEscapeWindow,
	InPartyWindow,
	InCommandWindow,
	Blank, //!< Not used?
	Escaping
};

//! One-byte version of RPG::BattleNavigationLevel
//typedef uchar BattleNavigationLevel_T;
}

#endif // RPG_BATTLE_NAVIGATION_LEVEL_HPP
