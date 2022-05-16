#ifndef DYNRPG_WINDOW_MENU_END_H
#define DYNRPG_WINDOW_MENU_END_H

#include <DynRPG/Window.h>

namespace RPG
{
/*! \brief Used for quit menu from the main menu.

	\sa RPG::SceneMenu
*/
class DYNRPG_API WindowMenuEnd : public Window
{
public:
	Window* winQuitMsg; //!< The sub-window for the "Are you sure" message
};
}

#endif // DYNRPG_WINDOW_MENU_END_H
