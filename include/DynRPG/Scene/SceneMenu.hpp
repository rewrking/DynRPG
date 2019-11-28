#ifndef RPG_SCENE_MENU_HPP
#define RPG_SCENE_MENU_HPP

#include <DynRPG/Scene/MenuSubScreen.hpp>
#include <DynRPG/Utility/Types.hpp>
#include <DynRPG/Window/Window.hpp>
#include <DynRPG/Window/WindowMenuEnd.hpp>
#include <DynRPG/Window/WindowMenuEquip.hpp>
#include <DynRPG/Window/WindowMenuItem.hpp>
#include <DynRPG/Window/WindowMenuOrder.hpp>
#include <DynRPG/Window/WindowMenuSkill.hpp>
#include <DynRPG/Window/WindowMenuStatus.hpp>
#include <DynRPG/Window/WindowMenuTarget.hpp>

namespace RPG
{
/*! \brief Used to access the menu windows and its variables.

	\sa RPG::menu
	\sa RPG::Window
*/
struct SceneMenu
{
	// clang-format off
	void** vTable;
	AuroraBoard* auroraBoard1; //!< Not even a little bit implemented...
	AuroraBoard* auroraBoard2; //!< Not even a little bit implemented...
	MenuSubScreen screen; //!< The RPG::MenuSubScreen currently being displayed (replaces getMenuScreen() function from the days of yore)
	bool repaint; //!< The flag to repaint the screen
		bool _unknown_0E;
		bool _unknown_0F;
	Window* winOptions; //!< Pointer to the Options window's objects (Items, Skills, etc.).
	Window* winGold; //!< Pointer to the Gold window's objects.
	Window* winParty; //!< Pointer to the Party window's objects.
	WindowMenuTarget* winItemSkillUse; //!< Pointer to the Item/Skill Use window's objects.
	WindowMenuItem* winItems; //!< Pointer to the Item window's objects. (See RPG::WindowMenuItem)
	WindowMenuSkill* winSkills; //!< Pointer to the Skills window's objects. (See RPG::WindowMenuSkill)
	Window* winTeleport; //!< Pointer to the Teleport pseudo-window's objects.
	WindowMenuEquip* winEquip; //!< Pointer to the Equip window's objects. (See RPG::WindowMenuEquip)
	WindowMenuEnd* winQuit; //!< Pointer to the Quit window's objects. (See RPG::WindowMenuEnd)
	int ScrollUpCountItem; //!< The number of rows off-screen after a scroll (for items)
	/*! \brief The item selection index (relative to the screen).
				\note indexes are zero-based starting from the top-left, and zig-zag to the right position, followed by the down-left position.
			*/
	int inventoryPositionItem;
	int scrollUpCountSkill; //!< The number of rows off-screen after a scroll (for skills)
	/*! \brief The skill selection index (relative to the screen).
				\note indexes are zero-based starting from the top-left, and zig-zag to the right position, followed by the down-left position.
			*/
	int inventoryPositionSkill;
	int selectedItem; //!< The database ID of the item selected for the MENU_ITEM_USE RPG::MenuSubScreen
	int selectedSkill; //!< The database ID of the skill selected for the MENU_SKILL_USE RPG::MenuSubScreen
	WindowMenuStatus* winStatus; //!< Pointer to the Status window's objects.
	WindowMenuOrder* winOrder; //!< Pointer to the Order window's objects.
	// clang-format off
};

/*! \ingroup game_objects
	\brief Access to the menu scene
*/
static SceneMenu*& menu = (**reinterpret_cast<SceneMenu***>(0x4CDC60));

}

// Old function
/*RPG::MenuScreen RPG::Menu::getScreen() {
	return (RPG::MenuScreen)(**reinterpret_cast<char ***>(0x4CDC60))[12];
}*/

#endif // RPG_SCENE_MENU_HPP