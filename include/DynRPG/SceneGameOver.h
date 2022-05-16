#ifndef DYNRPG_SCENE_GAME_OVER_H
#define DYNRPG_SCENE_GAME_OVER_H

#include <DynRPG/Image.h>

namespace RPG
{
/*! \brief The Game Over scene.
	\sa RPG::gameOver
*/
class SceneGameOver
{
public:
	void** vTable;
	void* AuroraBoard1; //!< Not even a little bit implemented...
	void* AuroraBoard2; //!< Not even a little bit implemented...
	bool initialized; //!< Has the game over scene initialized?
	Image* image; //!< The game over image itself. Only accessible if a game over has been triggered. (See RPG::Image)
};

/*! \ingroup game_objects
	\brief Access to the game over scene
*/
extern DYNRPG_API SceneGameOver*& gameOver;
}

#endif // DYNRPG_SCENE_GAME_OVER_H
