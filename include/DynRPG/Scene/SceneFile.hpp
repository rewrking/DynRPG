#ifndef RPG_SCENE_FILE_HPP
#define RPG_SCENE_FILE_HPP

#include <DynRPG/Graphics/Screen.hpp>
#include <DynRPG/Scene/FileSceneMode.hpp>
#include <DynRPG/Utility/Types.hpp>
#include <DynRPG/Window/Window.hpp>
#include <DynRPG/Window/WindowSaveFile.hpp>

namespace RPG
{

/*! \brief The Save/Load scene.
	\sa RPG::saveLoad
*/
struct SceneFile
{
	void** vTable;
	AuroraBoard* auroraBoard1; //!< Not even a little bit implemented...
	AuroraBoard* auroraBoard2; //!< Not even a little bit implemented...
	bool initialized; //!< Has the enter hero name scene initialized?
	Window* winInfo; //!< The info window (very top)
	WindowSaveFile* winFile[15]; //!< The actual file windows
	FileSceneMode mode; //!< The mode of the scene (save or load)
	bool fromMenu; //!< Set to true to return to the main menu
	int timesScrolled; //!< Times scrolled down?
	int cursorPosition; //!< The position of the cursor
	int timer; //!< Some kind of timer?
	int scrollCounter; //!< For scrolling the windows?

	/*! \brief Built-in RM2k3 function to check whether a save file exists or not
		\param saveId The save ID to check for (can be greater than 15)
		\return true of the save exists, false otherwise
	*/
	// Defined as static so it can be called via RPG::SceneFile::doesSaveExist() or RPG::fileSaveLoad->doesSaveExist()
	static bool doesSaveExist(int saveId);

	/*! \brief Built-in RM2k3 function to save the current game's data to a file.
		\param saveId The save ID to check for (can be greater than 15)
		\note Can be called outside of the actual File scene.
			Menus, fades, transitions must be handled separately by the plugin!
	*/
	void saveFile(int saveId);

	/*! \brief DynRPG function to load a particular save file, and properly draw the resulting scene.
		\param saveId The save ID to check for (can be greater than 15)
		\note loadFileUnpatch() must be called onLoadGame after this is called in the same plugin
			Can be called outside of the actual File scene.

	*/
	void loadFile(int saveId);

	/*! \brief DynRPG function to finish loading a particular save file.
		\pre loadFile(int) must have been called prior to this being called
		\note this function must be called onLoadGame in the plugin that calls loadFile(int)
		\warning It's not recommended to use this for anything else!
			Please check if SaveXX.lsd exists before loading.

	*/
	void loadFileUnpatch();

	/*! \brief Built-in RM2k3 function to load a particular save file, but does NOT redraw the scene afterwards
		\param saveId The save ID to check for (can be greater than 15)
		\note Can be called outside of the actual File scene.
			Music, screen and events do not get updated to the newly loaded file.
			Starts player from FileScene instead of the Map.
		\warning Incompatible with Cherry's SaveLoad patch.
			Experimental!
	*/
	void loadFileSimple(int saveId);
};

/*! \ingroup game_objects
	\brief Access to the Save/Load scene
*/
static SceneFile*& fileSaveLoad = (**reinterpret_cast<SceneFile***>(0x4CDFCC));

}

#endif // RPG_SCENE_FILE_HPP