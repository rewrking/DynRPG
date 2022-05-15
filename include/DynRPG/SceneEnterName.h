#ifndef DYNRPG_SCENE_ENTER_NAME_H
#define DYNRPG_SCENE_ENTER_NAME_H

#include <DynRPG/Image.h>
#include <DynRPG/Window.h>

namespace RPG
{
/*! \brief The Enter Hero Name scene.
	\sa RPG::enterName
*/
class SceneEnterName
{
public:
	void** vTable;
	void* AuroraBoard1; //!< Not even a little bit implemented...
	void* AuroraBoard2; //!< Not even a little bit implemented...
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
extern DYNRPG_API SceneEnterName*& enterName;
}

#endif // DYNRPG_SCENE_ENTER_NAME_H
