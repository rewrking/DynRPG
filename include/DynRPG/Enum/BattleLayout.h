#ifndef DYNRPG_BATTLE_LAYOUT_H
#define DYNRPG_BATTLE_LAYOUT_H

namespace RPG
{
//! Possible values for RPG::BattleSettings::layout
enum BattleLayout
{
	BL_TRADITIONAL, //!< "Traditional" layout
	BL_ALTERNATIVE, //!< "Alternative" layout
	BL_GAUGE //!< "Gauge" layout
};

//! One-byte version of RPG::BattleLayout
typedef unsigned char BattleLayout_T;
}

#endif // DYNRPG_BATTLE_LAYOUT_H
