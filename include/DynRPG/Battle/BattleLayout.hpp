#ifndef RPG_BATTLE_LAYOUT_HPP
#define RPG_BATTLE_LAYOUT_HPP

#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
//! Possible values for RPG::BattleSettings::layout
enum class BattleLayout : uchar
{
	Traditional, //!< "Traditional" layout
	Alternative, //!< "Alternative" layout
	Gauge //!< "Gauge" layout
};

//! One-byte version of RPG::BattleLayout
//typedef uchar BattleLayout_T;
}

#endif // RPG_BATTLE_LAYOUT_HPP
