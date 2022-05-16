#ifndef DYNRPG_KEY_H
#define DYNRPG_KEY_H

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
enum Key
{
	KEY_DOWN, //!< Keys which are used for moving down
	KEY_LEFT, //!< Keys which are used for moving left
	KEY_RIGHT, //!< Keys which are used for moving right
	KEY_UP, //!< Keys which are used for moving up
	KEY_DECISION, //!< Keys which are used to confirm an action
	KEY_CANCEL, //!< Keys which are used to cancel an action or open the menu
	KEY_0,
	KEY_1,
	KEY_2,
	KEY_3,
	KEY_4,
	KEY_5,
	KEY_6,
	KEY_7,
	KEY_8,
	KEY_9,
	KEY_ADD,
	KEY_SUBTRACT,
	KEY_MULTIPLY,
	KEY_DIVIDE,
	KEY_DECIMAL
};
}

#endif // DYNRPG_KEY_H
