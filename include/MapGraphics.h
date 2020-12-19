namespace RPG {

	/*! \brief Serves as the pointer to the tileset, the filename of the Chipset
		and the data for the actual tiles??

		\sa RPG::MapProperties
		\sa RPG::Map
	*/
	class MapGraphics {
		public:
			void **vTable;
			Tileset *tileset; //!< The referenced tileset 
			DStringPtr filename; //!< The filename of the tileset (again...)
			Image *chipsetImage; //!< The chipset's image
	};
}
