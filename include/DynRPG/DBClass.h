#ifndef DYNRPG_DB_CLASS_H
#define DYNRPG_DB_CLASS_H

#include <DynRPG/Enum/DamageMultiplier.h>

#include <DynRPG/ArrayBaseOne.h>
#include <DynRPG/CatalogPtr.h>
#include <DynRPG/DArray.h>
#include <DynRPG/DStringPtr.h>
#include <DynRPG/NamedCatalogPtr.h>
#include <DynRPG/SkillProgression.h>

namespace RPG
{
/*! \brief Used for the default data of classes which is defined in the
	database

	\note The members of this class either mean default values of a
	property or they are used for properties which aren't supposed to be
	changed in-game, thus the members won't be saved and loaded
	automatically (as it is the case with RPG::Actor), but only loaded once
	at startup.\n\n
	\sa RPG::dbClasses
	\sa RPG::Actor
	\sa RPG::actors
*/

class DBClass
{
public:
	void** vTable;
	int id; //!< ID of the class
	DStringPtr name; //!< Default class name
	int _unknown_0C;
	bool twoWeapons; //!< Does the class use a second weapon instead of the shield?
	bool lockEquipment; //!< Is the equipment locked?
	bool aiControl; //!< Is the class controlled by the computer in battle?
	bool mightyGuard; //!< Does defending reduce the damage more than usual?
	ArrayBaseOne<short, 99> maxHp; //!< Array of maximum HP values for each level
	ArrayBaseOne<short, 99> maxMp; //!< Array of maximum MP values for each level
	ArrayBaseOne<short, 99> attack; //!< Array of attack values for each level
	ArrayBaseOne<short, 99> defense; //!< Array of defense values for each level
	ArrayBaseOne<short, 99> intelligence; //!< Array of intelligence values for each level
	ArrayBaseOne<short, 99> agility; //!< Array of agility values for each level
	int expPrimary; //!< Primary experience curve parameter
	int expSecondary; //!< Secondary experience curve parameter
	int expTertiary; //!< Tertiary experience curve parameter
	CatalogPtr<SkillProgression*> skillLearning; //!< Skill learning data

	/*! \brief Condition Resistance Array (See RPG::DamageMultiplier)

		If at a certain point, the resistance of a condition and all conditions higher than it are C, the conditions.size will equal the number of the highest non-C condition.

		\b Example:

			Cond1: A
			Cond2: B
			Cond3: C
			Cond4: C
			Cond5: C

		Because Cond3 is C, and those above it are C, conditions.size will be 2, because Cond2 is the last non-C condition.

		\warning This can be confusing, because if you need to use conditions[15], but check for conditions.size to be 15 first, it could be 10 if 11-15 are all C, so the check would be false. The solution would be to use RPG::conditions.count() for the check instead. This would resize the array once a condition higher than conditions.size is called, but because of the resizeValue in the template for RPG::DArray, conditions 11-15 would be correctly assigned to C
	*/
	DArray<DamageMultiplier_T, 1, 2> conditions;

	/*! \brief Attribute Resistance Array (See RPG::DamageMultiplier)

		If at a certain point, the resistance of an attribute and all attributes higher than it are C, the attributes.size will equal the number of the highest non-C attribute.

		\b Example:

			Attr1: A
			Attr2: B
			Attr3: C
			Attr4: C
			Attr5: C

		Because Attr3 is C, and those above it are C, attributes.size will be 2, because Attr2 is the last non-C attribute.

		\warning This can be confusing, because if you need to use attributes[15], but check for attributes.size to be 15 first, it could be 10 if 11-15 are all C, so the check would be false. The solution would be to use RPG::attributes.count() for the check instead. This would resize the array once an attribute higher than attributes.size is called, but because of the resizeValue in the template for RPG::DArray, attributes 11-15 would be correctly assigned to C
	*/
	DArray<DamageMultiplier_T, 1, 2> attributes;
	int battleGraphicId; //!< Battle graphic ID
	int battleCommands[7]; //!< Default battle commands (\c 0 and \c -1 both mean "no command at this position")
};

/*! \ingroup game_objects
	\brief Array of actors from the database, used for default values and
	properties which are not supposed to be changed in-game.

	Use the database ID as index for accessing a battler's class.

	Example:
	\code
	int experience1 = RPG::dbClasses[1]->expPrimary;
	\endcode
	\sa RPG::actors
*/
extern DYNRPG_API RPG::NamedCatalogPtr<RPG::DBClass*>& dbClasses;
}

#endif // DYNRPG_DB_CLASS_H
