#ifndef DYNRPG_SKILL_H
#define DYNRPG_SKILL_H

#include <DynRPG/Enum/SkillTarget.h>
#include <DynRPG/Enum/SkillType.h>

#include <DynRPG/AnimationSkill.h>
#include <DynRPG/DArray.h>
#include <DynRPG/DStringPtr.h>
#include <DynRPG/NamedCatalogPtr.h>
#include <DynRPG/Sound.h>

namespace RPG
{
/*! \brief Used for the data of skills which can be accessed or changed in-game.

	\sa RPG::skills
	\sa RPG::SkillType
	\sa RPG::SkillTarget
\sa RPG::AnimationSkill
*/
class Skill
{
public:
	void** vTable;
	int id; //!< ID of the skill
	DStringPtr name; //!< The name of the skill
	DStringPtr description; //!< The description of the skill

	DStringPtr useMsg2k; //!< Use message #1. If your project was carried over from RM2000, this was defined there.
	// more research
	DStringPtr useMsg2kAlt; //!< Use message #2.  If your project was carried over from RM2000, this was defined there.
	/*
		On RPG::Skills (and probably RPG::skills, too) right before RPG::SkillType,
		there's the failure/evasion message missing. Since it's only accessible in RM2k
		as well and is set to 0 if a new Skill is created in RM2k3, it sure would be nice
		if it was possible to manipulate it via RPG::skill->evasiontype

		...because if that value isn't == 3 (enumerator = SKILL_AVOIDABLE) it will not take
		the agility of target or user into account when calculating the success chance.
	*/
	// more research - does this require an enum?
	int evasionType; //!< Evasion Type and failure message?

	SkillType type; //!< Skill type (see RPG::SkillType)
	int mpCost; //!< MP cost
	SkillTarget target; //!< Target of skill (see RPG::SkillTarget)
	int switchId; //!< Switch ID \sa RPG::SKILL_SWITCH
	int battleAnimId; //!< Battle animation ID \sa RPG::SKILL_NORMAL
	Sound* soundEffect; //!< Sound effect if type is: \sa RPG::SKILL_TELEPORT \sa RPG::SKILL_ESCAPE \sa RPG::SKILL_SWITCH
	bool useInField; //!< Activation in field? \sa RPG::SKILL_SWITCH
	bool useInBattle; //!< Activation in battle? \sa RPG::SKILL_SWITCH
	int atkInfluence; //!< Attack influence (1-10) \sa RPG::SKILL_NORMAL
	int intInfluence; //!< Intelligence influence (1-10) \sa RPG::SKILL_NORMAL
	int variance; //!< Variance (1-10) \sa RPG::SKILL_NORMAL
	int effectRating; //!< Effect Rating \sa RPG::SKILL_NORMAL
	int successRate; //!< Success Rate (in %) \sa RPG::SKILL_NORMAL
	bool affectHp; //!< Affects HP? \sa RPG::SKILL_NORMAL
	bool affectMp; //!< Affects MP? \sa RPG::SKILL_NORMAL
	bool affectStr; //!< Affects attack? \sa RPG::SKILL_NORMAL
	bool affectDef; //!< Affects defense? \sa RPG::SKILL_NORMAL
	bool affectInt; //!< Affects intelligence? \sa RPG::SKILL_NORMAL
	bool affectAgl; //!< Affects agility? \sa RPG::SKILL_NORMAL
	bool absorb; //!< Absorbs? \sa RPG::SKILL_NORMAL
	bool ignoreDef; //!< Ignores defense? \sa RPG::SKILL_NORMAL
	DArray<bool> conditions; //!< Array of conditions. size = highest condition that is checked off \sa RPG::SKILL_NORMAL
	DArray<bool> attributes; //!< Array of attributes. size = highest attribute that is checked off \sa RPG::SKILL_NORMAL
	bool attributeResist; //!< Attribute increase/decrease resistance flag \sa RPG::SKILL_NORMAL
	bool isMpPercent; //!< Does the skill cost a % of MP? \sa RPG::SKILL_NORMAL
	int mpCostPercent; //!< MP % cost \sa RPG::SKILL_NORMAL
	bool conditionFlag; //!< Inflict/Remove depending on SkillTarget. true = second option \sa RPG::SKILL_NORMAL
	int _unknown_01;
	int _unknown_02;
	int _unknown_03;
	NamedCatalogPtr<AnimationSkill*> skillAnims; //!< Pointer to the RPG::AnimationSkill array \sa RPG::SKILL_NORMAL
};

/*! \ingroup game_objects
	\brief Array of skills from the database, used for default values and
	properties which are not supposed to be changed in-game.

	Use the database ID as index for accessing a skill.

	Example:
	\code
	int animationId = RPG::skills[4]->battleAnimId;
	\endcode
*/
extern DYNRPG_API NamedCatalogPtr<Skill*>& skills;
}

#endif // DYNRPG_SKILL_H
