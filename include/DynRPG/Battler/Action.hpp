#ifndef RPG_ACTION_HPP
#define RPG_ACTION_HPP

#include <DynRPG/Battler/ActionKind.hpp>
#include <DynRPG/Battler/BasicAction.hpp>
#include <DynRPG/Battler/Target.hpp>

namespace RPG
{
/*! \brief %Action of a battler (normal attack, skill, escape, etc.), including target

	This class is used to describe the action an actor or monster does in battle.
	\note The action of a battler is always tied to the battler itself.
	\sa RPG::Battler
	\sa RPG::ActionKind
	\sa RPG::BasicAction
	\sa RPG::Target
*/
// TLcfgUnitActItem
struct Action
{
	// clang-format off
	void** vTable;
	ActionKind kind; //!< Kind of the action (see RPG::ActionKind)
	BasicAction basicActionId; //!< If \c kind is RPG::ActionKind::Basic: Kind of the basic action (see RPG::BasicAction)
		char _unknown_6; // Was "userData1" earlier
	bool retrying; //!< \c true if the last try to execute the action failed
	int skillId; //!< If \c kind is RPG::ActionKind::Skill: Database ID of the skill
	int monsterId; //!< If \c kind is RPG::ActionKind::Transform: Database ID of the monster to transform into
	int itemId; //!< If \c kind is RPG::ActionKind::Item: Database ID of the item
		int _unknown_14;
		// int _unknown_18;
	int switchIdOn; //!< If the action turns on a switch: The ID of the switch
	int switchIdOff; // !< If the action turns off a switch: The ID of the switch
	Target target; //!< %Target of the action (see RPG::Target)
	int targetId; //!< If \c target is RPG::TARGET_ACTOR or RPG::TARGET_MONSTER: Zero-based party member index of the target
	// clang-format on
};
}

#endif // RPG_ACTION_HPP
