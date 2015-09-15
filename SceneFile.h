namespace RPG {
	//! Not implemented yet
	typedef void AuroraBoard;

	/*! \brief Possible values for RPG::SceneFile::mode
	*/
	enum FileSceneMode {
		FILE_LOAD,
		FILE_SAVE
	};

	//! One-byte version of RPG::FileSceneMode
	typedef unsigned char FileSceneMode_T;

	/*! \brief The Save/Load scene.
		\sa RPG::saveLoad
	*/
	class SceneFile {
		public:
			void **vTable;
				AuroraBoard *AuroraBoard1; //!< Not even a little bit implemented...
				AuroraBoard *AuroraBoard2; //!< Not even a little bit implemented...
			bool initialized; //!< Has the enter hero name scene initialized?
			Window *winInfo; //!< The info window (very top)
			WindowSaveFile *winFile[15]; //!< The actual file windows
			FileSceneMode_T mode; //!< The mode of the scene (save or load)
			bool fromMenu; //!< Set to true to return to the main menu
			int timesScrolled; //!< Times scrolled down?
			int cursorPosition; //!< The position of the cursor
			int timer; //!< Some kind of timer?
			int scrollCounter; //!< For scrolling the windows?

			/*! \brief Built-in RM2k3 function to check whether a save file exists or not
			    \param saveId The save ID to check for (can be greater than 15)
				\return true of the save exists, false otherwise
			*/
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

	bool SceneFile::doesSaveExist(int saveId) {
		/*bool out = false;
		asm volatile("call *%%esi"
				: "=a" (out), "=d" (RPG::_edx)
				: "S" (0x4A5484), "a" (this), "d" (saveId)
				: "ecx", "cc", "memory");
		return out;*/
		//int eax = ( *reinterpret_cast<int **> (0x4CDF20) )[0];
 		bool out = false;
 		asm volatile("call *%%esi"
 			: "=a" (out), "=d" (RPG::_edx)
 			: "S" (0x4A5484), "a" (( *reinterpret_cast<int **> (0x4CDF20) )[0]), "d" (saveId)
 			: "ecx", "cc", "memory");
 		return out;
	}

	void SceneFile::saveFile(int saveId) {
		asm volatile("call *%%esi"
			: "=a" (RPG::_eax), "=d" (RPG::_edx)
			: "S" (0x45D2ED), "a" (this), "d" (saveId)
			: "ecx", "cc", "memory");
	}

	void SceneFile::loadFile(int saveId) {
		RPG::screen->canvas->brightness = 0;
		( *reinterpret_cast<char ***> (0x4CDC7C) )[0][4] = 5;       // Force SceneChange to FileScene
		( *reinterpret_cast<int ***> (0x4CDFCC) )[0][22] = saveId;  // Set SaveSlot to load from
		( *reinterpret_cast<char *>(0x4913C8) ) = 0xE9;             // Patch to skip drawing the FileScene
		( *reinterpret_cast<int *>(0x4913C9) ) = 0x000001CD;        // Patch to skip [...]
		( *reinterpret_cast<unsigned short *>(0x4915AD) ) = 0x03EB; // Patch to skip closing the FileScene
		// Patches direct access to FileScene (temporarily) to load SaveFile
	}

	void SceneFile::loadFileUnpatch() {
		( *reinterpret_cast<char *>(0x4913C8) ) = 0x80;             // Patch to restore drawing the FileScene
		( *reinterpret_cast<int *>(0x4913C9) ) = 0x75000C7B;        // Patch to restore [...]
		( *reinterpret_cast<unsigned short *>(0x4915AD) ) = 0xCEE8; // Patch to restore closing the FileScene
		// Restores default code
	}

	void SceneFile::loadFileSimple(int saveId) { // Incompatible with saveload patch. experimental!
		RPG::screen->canvas->brightness = 0;
		asm volatile("call *%%esi"
			: "=a" (RPG::_eax), "=d" (RPG::_edx)
			: "S" (0x45D2E0), "a" (this), "d" (saveId)
			: "ecx", "cc", "memory");
	}

	/*! \ingroup game_objects
		\brief Access to the Save/Load scene
	*/
	static RPG::SceneFile *&fileSaveLoad = (**reinterpret_cast<RPG::SceneFile ***>(0x4CDFCC));

}
