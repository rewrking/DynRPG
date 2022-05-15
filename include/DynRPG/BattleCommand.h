#ifndef DYNRPG_BATTLE_COMMAND_H
#define DYNRPG_BATTLE_COMMAND_H

#include <DynRPG/Enum/BattleCommandArchetype.h>

#include <DynRPG/DStringPtr.h>

namespace RPG
{
/*! \brief Used to define the actual battle commands (Attack, Defend, etc)
	\sa RPG::BattleCommandArchetype
	\sa RPG::BattleSettings
	\sa RPG::battleSettings
*/
class BattleCommand //!< Skill Animation sub-screen
{
public:
	void** vTable;
	int id; //!< ID of the battle command
	DStringPtr name; //!< The name of the battle command
	BattleCommandArchetype archetype; //!< The command's archetype (see RPG::BattleCommandArchetype)
};
}

#endif // DYNRPG_BATTLE_COMMAND_H
