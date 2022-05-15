#ifndef DYNRPG_WINDOW_MENU_SKILL_H
#define DYNRPG_WINDOW_MENU_SKILL_H

#include <DynRPG/DList.h>
#include <DynRPG/Window.h>

namespace RPG
{
/*! \brief Used for skill menu from the main menu.

	\sa RPG::SceneMenu
*/
class DYNRPG_API WindowMenuSkill : public Window
{
public:
	int heroId; //!< Database ID of the hero selected
	Window* winInfo; //!< The sub-window for the skill description
	Window* winHeroInfo; //!< The sub-window for the selected hero information
	int _unknown_84;
	DList<int>* skillSubsets; //!< Zero-based Array of skill subsets. Unsure about this though...
	bool isSkillSubset; //!< Is the selected skill a subset?
	//Window *winHeroMp; // ????

	void refreshSkills();
};
}

#endif // DYNRPG_WINDOW_MENU_SKILL_H
