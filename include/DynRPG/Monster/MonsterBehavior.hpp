#ifndef RPG_MONSTER_BEHAVIOR_HPP
#define RPG_MONSTER_BEHAVIOR_HPP

#include <DynRPG/Battler/ActionKind.hpp>
#include <DynRPG/Battler/BasicAction.hpp>
#include <DynRPG/Monster/MonsterPrecondition.hpp>
#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
/*! \brief An entry of the monster's behavior (normal attack, skill, transform, etc.)

	This class is used to describe a monster's behavior as defined in the database, and represents a single entry.
	\sa RPG::DBMonster
	\sa RPG::dbMonsters
	\sa RPG::ActionKind
	\sa RPG::BasicAction
	\sa RPG::MonsterPrecondition
*/
struct MonsterBehavior
{
	// clang-format off
	void** vTable;
	int id; //!< index of the monster's behavior (one-based)
		int _unknown_08;
	ActionKind kind; //!< The monster's action (Only AK_BASIC, AK_SKILL, & AK_TRANSFORM)
	BasicAction basicActionId; //!< If \c kind is RPG::AK_BASIC: Kind of the basic action (see RPG::BasicAction)
	int skillId; //!< If \c kind is RPG::AK_SKILL: Database ID of the skill (See RPG::ActionKind)
	int monsterId; //!< If \c kind is RPG::AK_TRANSFORM: Database ID of the monster to transform into (See RPG::ActionKind)
	MonsterPrecondition precondition; //!< The monster's precondition
	int preconditionParam[2]; //!< Precondition parameters (amount vary depending on precondition)
	bool preconditionSwitchId; //!< If precondition is set to MON_PRE_SWITCH (See RPG::MonsterPrecondition)
		char _unknown_25;
		char _unknown_26;
		char _unknown_27;
	bool switchOn; //!< Does the action turn on a switch?
	int switchOnId; //!< The ID of the switch to turn ON
	bool switchOff; //!< Does the action turn off a switch?
	int switchOffId; //!< The ID of the switch to turn OFF
	int priority; //!< the priority of the action
	// clang-format on
};
}

#endif // RPG_MONSTER_BEHAVIOR_HPP