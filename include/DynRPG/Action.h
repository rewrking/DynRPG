#ifndef DYNRPG_ACTION_H
#define DYNRPG_ACTION_H

#include <DynRPG/Enum/ActionKind.h>
#include <DynRPG/Enum/BasicAction.h>
#include <DynRPG/Enum/Target.h>

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
class Action // TLcfgUnitActItem
{
public:
	void** vTable;
	ActionKind_T kind; //!< Kind of the action (see RPG::ActionKind)
	BasicAction_T basicActionId; //!< If \c kind is RPG::AK_BASIC: Kind of the basic action (see RPG::BasicAction)
	char _unknown_6; // Was "userData1" earlier
	bool retrying; //!< \c true if the last try to execute the action failed
	int skillId; //!< If \c kind is RPG::AK_SKILL: Database ID of the skill
	int monsterId; //!< If \c kind is RPG::AK_TRANSFORM: Database ID of the monster to transform into
	int itemId; //!< If \c kind is RPG::AK_ITEM: Database ID of the item
	int _unknown_14;
	//int _unknown_18;
	int switchIdOn; //!< If the action turns on a switch: The ID of the switch
	int switchIdOff; // !< If the action turns off a switch: The ID of the switch
	Target_T target; //!< %Target of the action (see RPG::Target)
	int targetId; //!< If \c target is RPG::TARGET_ACTOR or RPG::TARGET_MONSTER: Zero-based party member index of the target
};
}

#endif // DYNRPG_ACTION_H
