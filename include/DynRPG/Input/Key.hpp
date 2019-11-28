#ifndef RPG_KEY_HPP
#define RPG_KEY_HPP

namespace RPG
{
/*! \brief %RPG Maker key names
	\note The \c Shift key is handled differently by the %RPG Maker, thus
	it can't be used the way other keys can be used by DynRPG.
	\sa RPG::Input
	\sa RPG::Input::pressed
	\note <b>Not all enumeration values are documented here</b>, scroll to the top
	to see all possible values (in the general enum overview)!
*/
enum class Key
{
	Down, //!< Keys which are used for moving down
	Left, //!< Keys which are used for moving left
	Right, //!< Keys which are used for moving right
	Up, //!< Keys which are used for moving up
	Decision, //!< Keys which are used to confirm an action
	Cancel, //!< Keys which are used to cancel an action or open the menu
	Key0,
	Key1,
	Key2,
	Key3,
	Key4,
	Key5,
	Key6,
	Key7,
	Key8,
	Key9,
	Add,
	Subtract,
	Multiply,
	Divide,
	Decimal
};
}

#endif // RPG_KEY_HPP
