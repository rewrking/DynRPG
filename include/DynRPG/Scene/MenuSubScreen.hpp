#ifndef RPG_MENU_SUBSCREEN_HPP
#define RPG_MENU_SUBSCREEN_HPP

#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
/*! \brief Possible values for RPG::SceneMenu::screen

	The sub-screen the user is currently on.
*/
enum class MenuSubScreen : uchar
{
	// Starts at 256 if MenuSubScreen_T is not used
	Main, //!< Main menu screen
	Item, //!< Item screen
	ItemUse, //!< Item sub-screen for when an item is used on a hero
	Skill, //!< Skill screen
	SkillUse, //!< Skill sub-screen for when a skill is used on a hero
	Teleport, //!< ???
	Equip, //!< Equip screen
	Quit, //!< Quit confirm/cancel screen
	Status, //!< Status screen
	Order, //!< Order screen
	CustomUltimateSaveLoad = 20, //!< PepsiOtaku's Ultimate Save/Load Menu Plugin (forthcoming)
	CustomUltimateSystem = 21, //!< PepsiOtaku's Ultimate System Menu Plugin (forthcoming)
};

//! One-byte version of RPG::MenuSubScreen
//typedef uchar MenuSubScreen_T;
}

#endif // RPG_MENU_SUBSCREEN_HPP
