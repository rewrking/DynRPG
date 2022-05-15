#ifndef DYNRPG_WINDOW_MENU_ORDER_H
#define DYNRPG_WINDOW_MENU_ORDER_H

#include <DynRPG/Window.h>

namespace RPG
{
/*! \brief Used for quit menu from the main menu.

	\sa RPG::SceneMenu
*/
class DYNRPG_API WindowMenuOrder : public Window
{
public:
	Window* winNewConfig; //!< The sub-window for the new configuration
	Window* winConfirm; //!< The sub-window for the new config confirmation
};
}

#endif // DYNRPG_WINDOW_MENU_ORDER_H
