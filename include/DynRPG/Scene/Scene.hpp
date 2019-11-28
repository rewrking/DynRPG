#ifndef RPG_SCENE_HPP
#define RPG_SCENE_HPP

#include <DynRPG/Utility/Types.hpp>

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
enum class Scene : uchar
{
	Map, //!< %Map
	Menu, //!< Game menu
	Battle, //!< Battle
	Shop, //!< Shop
	Name, //!< %Hero naming screen
	File, //!< Save <b>or</b> load menu
	Title, //!< Title screen
	GameOver, //!< Game over screen
	Debug, //!< Debug screen (\c F9 menu)
	// Custom scenes below
	CustomScene9, // Did this have a purpose??
	CustomShop = 17, //!< Scene #17 - Alternate Shop for special items, exchanges, etc.
	CustomGameJolt = 18, //!< Scene #18 - PepsiOtaku's Game Jolt plugin
	CustomUltimateSaveLoad = 19, //!< Scene #19 - PepsiOtaku's Ultimate Save/Load Menu Plugin (forthcoming)
	CustomUltimateName = 20, //!< Scene #22 - PepsiOtaku's Ultimate Hero Rename Plugin (forthcoming)
	//CustomUltimateParty = 21, //!< Scene #21 - PepsiOtaku's Ultimate Party Menu Plugin (forthcoming)
	CustomUniDebugTool = 42, //!< Scene #42 - Cherry's UniDebug Tool,
	CustomOpenGlOptions = 77
};

//! One-byte version of RPG::Scene
//typedef uchar Scene_T;
}

#endif // RPG_SCENE_HPP
