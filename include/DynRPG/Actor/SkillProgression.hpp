#ifndef RPG_SKILL_PROGRESSION_HPP
#define RPG_SKILL_PROGRESSION_HPP

namespace RPG
{
/*! \brief Used to define the skill progression table for a particular hero.
	\sa RPG::DBActor
	\sa RPG::dbActors
*/
struct SkillProgression
{
	// clang-format off
	void** vTable;
	int id; //!< The one-based ID of the entry
		int _unknown_08;
	int levelReq; //!< Level requirement
	int skillId; //!< ID of the skill
	// clang-format on
};
}

#endif // RPG_SKILL_PROGRESSION_HPP