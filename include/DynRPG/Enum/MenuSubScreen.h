#ifndef DYNRPG_MENU_SUB_SCREEN_H
#define DYNRPG_MENU_SUB_SCREEN_H

namespace RPG
{
/*! \brief Possible values for RPG::SceneMenu::screen

	The sub-screen the user is currently on.
*/
enum MenuSubScreen
{
	// Starts at 256 if MenuSubScreen_T is not used
	MENU_MAIN, //!< Main menu screen
	MENU_ITEM, //!< Item screen
	MENU_ITEM_USE, //!< Item sub-screen for when an item is used on a hero
	MENU_SKILL, //!< Skill screen
	MENU_SKILL_USE, //!< Skill sub-screen for when a skill is used on a hero
	MENU_TELEPORT, //!< ???
	MENU_EQUIP, //!< Equip screen
	MENU_QUIT, //!< Quit confirm/cancel screen
	MENU_STATUS, //!< Status screen
	MENU_ORDER, //!< Order screen
	MENU_ULT_SAVELOAD = 20, //!< PepsiOtaku's Ultimate Save/Load Menu Plugin (forthcoming)
	MENU_ULT_SYSTEM = 21, //!< PepsiOtaku's Ultimate System Menu Plugin (forthcoming)
};

//! One-byte version of RPG::MenuSubScreen
typedef unsigned char MenuSubScreen_T;
}

#endif // DYNRPG_MENU_SUB_SCREEN_H
