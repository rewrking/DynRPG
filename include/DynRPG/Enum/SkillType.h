#ifndef DYNRPG_SKILL_TYPE_H
#define DYNRPG_SKILL_TYPE_H

namespace RPG
{
/*! \brief Possible values for RPG::Skill::type

	The skill's type. This determines which parameters will be available to use.
	\note Skill subsets are accessible through values 4+, with 4 being the first subset,
	5 being the second, 6 being the third, etc.
	\warning Max number of subsets: 252 (in extreme cases), but beyond that is untested.
*/
enum SkillType
{
	SKILL_NORMAL,
	SKILL_TELEPORT,
	SKILL_ESCAPE,
	SKILL_SWITCH
	// Skill subsets valued 4-252
};
}

#endif // DYNRPG_SKILL_TYPE_H
