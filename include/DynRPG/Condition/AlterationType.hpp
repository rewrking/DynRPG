#ifndef RPG_ALTERATION_TYPE_HPP
#define RPG_ALTERATION_TYPE_HPP

namespace RPG
{
/*! \brief Possible values for RPG::Condition::hpAlterationType and RPG::Condition::mpAlterationType

	The alteration type for hp & mp as defined for the condition
*/
enum class AlterationType
{
	Damage,
	Recover,
	None,
};
}

#endif // RPG_ALTERATION_TYPE_HPP
