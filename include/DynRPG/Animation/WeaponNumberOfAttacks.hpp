#ifndef RPG_WEAPON_NUMBER_OF_ATTACKS_HPP
#define RPG_WEAPON_NUMBER_OF_ATTACKS_HPP

namespace RPG
{
/*! \brief Possible values for RPG::Item::WeaponAnimation::numAttacks

	This is the number of times a weapon will attack.
	\note If the weapon has the attackTwice flag set, the number of attacks will double.
*/
enum class WeaponNumberOfAttacks
{
	One,
	Two,
	Three
	// Note: Are more values possible? (3+)
};
}

#endif // RPG_WEAPON_NUMBER_OF_ATTACKS_HPP
