#ifndef RPG_BATTLE_COMMAND_ARCHETYPE_HPP
#define RPG_BATTLE_COMMAND_ARCHETYPE_HPP

namespace RPG
{
//! Possible values for RPG::BattleCommands::archetype
enum class BattleCommandArchetype
{
	Attack,
	Skill,
	SkillSubset,
	Defend,
	Item,
	Escape,
	LinkToEvent
};
}

#endif // RPG_BATTLE_COMMAND_ARCHETYPE_HPP
