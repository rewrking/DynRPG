#ifndef DYNRPG_SKILL_TARGET_H
#define DYNRPG_SKILL_TARGET_H

namespace RPG
{
/*! \brief Possible values for RPG::Skill::target

	The target type for the skill as defined in the database.
	\warning Not to be confused with Action::target!
*/
enum SkillTarget
{
	SKILL_TARGET_ENEMY,
	SKILL_TARGET_ALL_ENEMIES,
	SKILL_TARGET_SELF,
	SKILL_TARGET_ALLY,
	SKILL_TARGET_ALL_ALLIES
};
}

#endif // DYNRPG_SKILL_TARGET_H
