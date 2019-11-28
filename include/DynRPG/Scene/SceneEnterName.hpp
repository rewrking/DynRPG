#ifndef RPG_SCENE_ENTER_NAME_HPP
#define RPG_SCENE_ENTER_NAME_HPP

#include <DynRPG/Graphics/Image.hpp>
#include <DynRPG/Utility/Types.hpp>
#include <DynRPG/Window/Window.hpp>

namespace RPG
{
/*! \brief The Enter Hero Name scene.
	\sa RPG::enterName
*/
struct SceneEnterName
{
	void** vTable;
	AuroraBoard* auroraBoard1; //!< Not even a little bit implemented...
	AuroraBoard* auroraBoard2; //!< Not even a little bit implemented...
	bool initialized; //!< Has the enter hero name scene initialized?
	Window* winFace; //!< The window that contains the faceset
	Window* winName; //!< use winName->string to get the name string itself
	Window* winInput; //!< use winInput->fontSet to get the fontset used
	Image* faceImage; //!< The face image itself
	int heroId; //!< The ID of the hero
	int initialFontSet; //!< The initial font set
	bool keepDefaultName; //!< Keep the default name? (??)
};

/*! \ingroup game_objects
	\brief Access to the Enter Hero Name scene
*/
static SceneEnterName*& enterName = (**reinterpret_cast<SceneEnterName***>(0x4CDBF4));
}

#endif // RPG_SCENE_ENTER_NAME_HPP