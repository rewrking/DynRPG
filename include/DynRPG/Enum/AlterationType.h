#ifndef DYNRPG_ALTERATION_TYPE_H
#define DYNRPG_ALTERATION_TYPE_H

namespace RPG
{
/*! \brief Possible values for RPG::Condition::hpAlterationType and RPG::Condition::mpAlterationType

	The alteration type for hp & mp as defined for the condition
*/
enum AlterationType
{
	AT_ALTER_DAMAGE,
	AT_ALTER_RECOVER,
	AT_ALTER_NONE,
};
}

#endif // DYNRPG_ALTERATION_TYPE_H
