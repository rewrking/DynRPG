#ifndef DYNRPG_SCENE_TITLE_H
#define DYNRPG_SCENE_TITLE_H

#include <DynRPG/Image.h>
#include <DynRPG/Window.h>

namespace RPG
{
/*! \brief Access to the title screen parameters.
	\sa RPG::title
*/
class SceneTitle
{
public:
	void** vTable;
	void* AuroraBoard1; //!< Not even a little bit implemented...
	void* AuroraBoard2; //!< Not even a little bit implemented...
	bool initialized; //!< Has the title screen initialized?
	bool notComingFromLoadMenu; //!< true if not coming from the Load menu. Set to false to make Load the default option;
	bool saveFilesPresent; //!< Are save files present (controls whether load can be selected). Determined DURING drawing of the title screen.
	bool _unknown_0F;
	Image* backgroundImage; //!< The title screen's background image. Can only be called after it's been drawn.
	Window* winStartLoadEnd; //!< The window object for Save/Load/End. Can only be called after it's been drawn.
};

/*! \ingroup game_objects
	\brief Access to the title screen parameters.

	\warning Most of the parameters can't be used in onInitTitleScreen, because they haven't
		been created yet. Use onFrame instead to catch them when they have.

	Example:
	\code
if (RPG::title->winStartLoadEnd) { // Moves the title screen window to position 0,32.
RPG::title->winStartLoadEnd->x = 0;
RPG::title->winStartLoadEnd->y = 32;
}
	\endcode
*/
extern DYNRPG_API SceneTitle*& title;
}

#endif // DYNRPG_SCENE_TITLE_H
