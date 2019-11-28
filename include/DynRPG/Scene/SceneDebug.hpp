#ifndef RPG_SCENE_DEBUG_HPP
#define RPG_SCENE_DEBUG_HPP

#include <DynRPG/Utility/Types.hpp>
#include <DynRPG/Window/Window.hpp>

namespace RPG
{
/*! \brief The Debug scene upon pressing F9 in test play mode.
	\sa RPG::debug
*/
struct SceneDebug
{
	void** vTable;
	AuroraBoard* auroraBoard1; //!< Not even a little bit implemented...
	AuroraBoard* auroraBoard2; //!< Not even a little bit implemented...
	Window* winLeftDebug; //!< The window object for Left side of the window. Can only be called after it's been drawn.
	Window* winRightDebug; //!< The window object for Right side of the window. Can only be called after it's been drawn.
	Window* winSetValue; //!< The window object for when a value has been set? Not so sure about this one...
	bool initialized;
};

/*! \ingroup game_objects
	\brief Access to the debug scene (because why not?!)
*/
static SceneDebug*& debug = (**reinterpret_cast<SceneDebug***>(0x4CDD4C));
}

#endif // RPG_SCENE_DEBUG_HPP