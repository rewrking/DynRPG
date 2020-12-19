namespace RPG {

	/*! \brief The paramaters for the LMU (map) files.

		\sa RPG::MapProperties
	*/
	class MapLmuFile {
		public:
			void **vTable;
			int mapWidth; //!< The width of the map
			int mapHeight; //!< The height of the map
			bool horWrapping; //!< Is horizontal wrapping enabled?
			bool verWrapping; //!< Is vertical wrapping enabled?
				char _unknown_0E;
				char _unknown_0F;
				UnknownPointer *_unknown_10;
				int _unknown_14;
				UnknownPointer *_unknown_18; // MapProperties? (0 if not used)
	};
}
