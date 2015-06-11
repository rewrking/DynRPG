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
			
			bool doesSaveExist(int saveId); //!< Checks whether a save file exists or not
	};
	
	bool SceneFile::doesSaveExist(int saveId) {
		//int eax = ( *reinterpret_cast<int **> (0x4CDF20) )[0];
		int eax = 0;
		bool out = 0;
		asm volatile("call *%%esi"
				: "=a" (out)
				: "S" (0x4A5484), "a" (eax), "d" (saveId)
				: "cc", "memory");
		//out == 0 if file does not exist, 1 if file exists
		return out;
	}
	
	/*! \ingroup game_objects
		\brief Access to the Save/Load scene
	*/
	static RPG::SceneFile *&fileSaveLoad = (**reinterpret_cast<RPG::SceneFile ***>(0x4CDFCC));

}