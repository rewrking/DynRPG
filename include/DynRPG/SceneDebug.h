namespace RPG {
	//! Not implemented yet
	typedef void AuroraBoard;

	/*! \brief The Debug scene upon pressing F9 in test play mode.
		\sa RPG::debug
	*/
	class SceneDebug {
		public:
			void **vTable;
				AuroraBoard *AuroraBoard1; //!< Not even a little bit implemented...
				AuroraBoard *AuroraBoard2; //!< Not even a little bit implemented...
			Window *winLeftDebug; //!< The window object for Left side of the window. Can only be called after it's been drawn.
			Window *winRightDebug; //!< The window object for Right side of the window. Can only be called after it's been drawn.
			Window *winSetValue; //!< The window object for when a value has been set? Not so sure about this one...
			bool initialized;
	};
	
	/*! \ingroup game_objects
		\brief Access to the debug scene (because why not?!)
	*/
	static RPG::SceneDebug *&debug = (**reinterpret_cast<RPG::SceneDebug ***>(0x4CDD4C));

}