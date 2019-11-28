#ifndef RPG_BATTLE_COMMAND_HPP
#define RPG_BATTLE_COMMAND_HPP

#include <DynRPG/Battle/BattleCommandArchetype.hpp>
#include <DynRPG/Delphi/DStringPtr.hpp>

namespace RPG
{
/*! \brief Used to define the actual battle commands (Attack, Defend, etc)
	\sa RPG::BattleCommandArchetype
	\sa RPG::BattleSettings
	\sa RPG::battleSettings
*/
struct BattleCommand
{
	//!< Skill Animation sub-screen
	void** vTable;
	int id; //!< ID of the battle command
	DStringPtr name; //!< The name of the battle command
	BattleCommandArchetype archetype; //!< The command's archetype (see RPG::BattleCommandArchetype)
};
}

#endif // RPG_BATTLE_COMMAND_HPP