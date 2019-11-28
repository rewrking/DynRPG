#ifndef RPG_SKILL_TARGET_HPP
#define RPG_SKILL_TARGET_HPP

namespace RPG
{
/*! \brief Possible values for RPG::Skill::target

	The target type for the skill as defined in the database.
	\warning Not to be confused with Action::target!
*/
enum class SkillTarget
{
	Enemy,
	AllEnemies,
	Self,
	Ally,
	AllAllies
};
}

#endif // RPG_SKILL_TARGET_HPP
