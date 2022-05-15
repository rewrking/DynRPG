#ifndef DYNRPG_SCENE_H
#define DYNRPG_SCENE_H

namespace RPG
{
/*! \brief In-game scenes

	Each scene has its own drawing method and its own data.
	You may also "invent" a new scene and draw its contents using the
	\ref onFrame callback.
	If you are creating a new scene for wide-spread use, please contact me (PepsiOtaku)
	to reserve a scene ID and I will add it below. This will prevent any conflicts if two+
	people use the same scene ID.
	\sa onFrame
	\sa RPG::Screen::update
*/
enum Scene
{
	SCENE_MAP, //!< %Map
	SCENE_MENU, //!< Game menu
	SCENE_BATTLE, //!< Battle
	SCENE_SHOP, //!< Shop
	SCENE_NAME, //!< %Hero naming screen
	SCENE_FILE, //!< Save <b>or</b> load menu
	SCENE_TITLE, //!< Title screen
	SCENE_GAME_OVER, //!< Game over screen
	SCENE_DEBUG, //!< Debug screen (\c F9 menu)
	// Custom scenes below
	SCENE_9,
	SCENE_SHOP_2 = 17, //!< Scene #17 - Alternate Shop for special items, exchanges, etc.
	SCENE_GAMEJOLT = 18, //!< Scene #18 - PepsiOtaku's Game Jolt plugin
	SCENE_ULT_SAVELOAD = 19, //!< Scene #19 - PepsiOtaku's Ultimate Save/Load Menu Plugin (forthcoming)
	SCENE_ULT_NAME = 20, //!< Scene #22 - PepsiOtaku's Ultimate Hero Rename Plugin (forthcoming)
	//SCENE_ULT_PARTY = 21, //!< Scene #21 - PepsiOtaku's Ultimate Party Menu Plugin (forthcoming)
	SCENE_UNI_DEBUG = 42, //!< Scene #42 - Cherry's UniDebug Tool,
	SCENE_OGL_OPTIONS = 77
};

//! One-byte version of RPG::Scene
typedef unsigned char Scene_T;
}

#endif // DYNRPG_SCENE_H
