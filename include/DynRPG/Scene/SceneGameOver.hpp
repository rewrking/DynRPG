#ifndef RPG_SCENE_GAME_OVER_HPP
#define RPG_SCENE_GAME_OVER_HPP

#include <DynRPG/Graphics/Image.hpp>
#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
/*! \brief The Game Over scene.
	\sa RPG::gameOver
*/
struct SceneGameOver
{
	void** vTable;
	AuroraBoard* auroraBoard1; //!< Not even a little bit implemented...
	AuroraBoard* auroraBoard2; //!< Not even a little bit implemented...
	bool initialized; //!< Has the game over scene initialized?
	Image* image; //!< The game over image itself. Only accessible if a game over has been triggered. (See RPG::Image)
};

/*! \ingroup game_objects
	\brief Access to the game over scene
*/
static SceneGameOver*& gameOver = (**reinterpret_cast<SceneGameOver***>(0x4CE008));

}

#endif // RPG_SCENE_GAME_OVER_HPP