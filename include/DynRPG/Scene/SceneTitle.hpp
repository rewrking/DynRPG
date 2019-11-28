#ifndef RPG_SCENE_TITLE_HPP
#define RPG_SCENE_TITLE_HPP

#include <DynRPG/Graphics/Image.hpp>
#include <DynRPG/Utility/Types.hpp>
#include <DynRPG/Window/Window.hpp>

namespace RPG
{
/*! \brief Access to the title screen parameters.
	\sa RPG::title
*/
class SceneTitle
{
	// clang-format off
	void** vTable;
	AuroraBoard* auroraBoard1; //!< Not even a little bit implemented...
	AuroraBoard* auroraBoard2; //!< Not even a little bit implemented...
	bool initialized; //!< Has the title screen initialized?
	bool isLoadNotDefault; //!< Set to false to make Load the default option;
	bool saveFilesPresent; //!< Are save files present (controls whether load can be selected). Determined DURING drawing of the title screen.
		bool _unknown_0F;
	Image* backgroundImage; //!< The title screen's background image. Can only be called after it's been drawn.
	Window* winStartLoadEnd; //!< The window object for Save/Load/End. Can only be called after it's been drawn.
	// clang-format on
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
static SceneTitle*& title = (**reinterpret_cast<SceneTitle***>(0x4CDB94));
}

#endif // RPG_SCENE_TITLE_HPP