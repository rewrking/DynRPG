#ifndef RPG_WINDOW_MENU_SKILL_HPP
#define RPG_WINDOW_MENU_SKILL_HPP

#include <DynRPG/Delphi/DList.hpp>
#include <DynRPG/Window/Window.hpp>

namespace RPG
{
/*! \brief Used for skill menu from the main menu.

	\sa RPG::SceneMenu
*/
struct WindowMenuSkill : Window
{
	// clang-format off
	int heroId; //!< Database ID of the hero selected
	Window* winInfo; //!< The sub-window for the skill description
	Window* winHeroInfo; //!< The sub-window for the selected hero information
		int _unknown_84;
	DList<int>* skillSubsets; //!< Zero-based Array of skill subsets. Unsure about this though...
	bool isSkillSubset; //!< Is the selected skill a subset?
	//Window *winHeroMp; // ????
	// clang-format on

	void refreshSkills();
};
}

#endif // RPG_WINDOW_MENU_SKILL_HPP
