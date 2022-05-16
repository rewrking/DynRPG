#ifndef DYNRPG_BATTLE_NAVIGATION_LEVEL_H
#define DYNRPG_BATTLE_NAVIGATION_LEVEL_H

namespace RPG
{
//! Possible values for RPG::BattleData::navLevel
enum BattleNavigationLevel
{
	BNAV_IN_FIGHT_ESCAPE_WINDOW,
	BNAV_IN_PARTY_WINDOW,
	BNAV_IN_COMMAND_WINDOW,
	BNAV_BLANK, //!< Not used?
	BNAV_ESCAPING
};

//! One-byte version of RPG::BattleNavigationLevel
typedef unsigned char BattleNavigationLevel_T;
}

#endif // DYNRPG_BATTLE_NAVIGATION_LEVEL_H
