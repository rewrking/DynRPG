namespace RPG {	
	/*! \brief Possible values for RPG::Terrain::spriteDisplay
		
		Sprite display controls how the hero sprite will appear when walking over the terrain.
	*/
	enum TerrainSpriteDisplay {
		TSD_DISP_NORMAL,
		TSD_DISP_OBSCURE_THIRD, //!< One-third of the sprite is semi-transparent
		TSD_DISP_OBSCURE_HALF, //!< Half of the sprite is semi-transparent
		TSD_DISP_SEMI_TRANSPARENT, //!< ALl of the sprite is semi-transparent
	};
	
	//! One-byte version or RPG::TilePassability
	typedef unsigned char TerrainSpriteDisplay_T;
	
	/*! \brief Possible values for RPG::Terrain::battleTypes
		
		\note Values can be combined up to 15 (meaning all 4 special battle types are checked off). 
		The TBP_ALL enum has been added for convenience.
	*/
	enum TerrainBattleType {
		TBP_NONE = 0,
		TBP_INITIATIVE = 1, 
		TBP_BACK_ATK = 2,
		TBP_SURROUND_ATK = 4,
		TBP_PINCERS_ATK = 8,
		TBP_ALL = 15
	};
	
	/*! \brief Possible values for RPG::Terrain::gridDepth
	
		These are basically presets for the grid shape. TGD_NONE encompasses any custom grid shapes
		set via gridTopY,  gridElongation & gridInclination, equivalent to clicking on the grid graphic 
		and adjusting the lines.
	*/
	enum TerrainGridDepth {
		TGD_NONE,
		TGD_SHALLOW,
		TGD_DEEP
	};
	
	/*! \brief Used for the data of terrains which can be accessed or changed in-game.

		\sa RPG::terrains
		\sa RPG::SpriteDisplay
		\sa RPG::TerrainBattleType
		\sa RPG::TerrainGridDepth
	*/
	class Terrain {
		public:
			void **vTable;
			int id; //!< ID of the terrain
			DStringPtr name; //!< The name of the terrain in the database
			int damage; //!< The amount of damage the terrain does
			int encounterMultiplier; //!< Percentage to multiply the encounter rate by on the type of terrain
			DStringPtr backdropFilename; //!< The name of the terrain's backdrop
			bool boatCanPass; //!< Boat/Skiff can pass
			bool shipCanPass; //!< Ship can pass
			bool airshipCanPass; //!< Airship can pass
			bool airshipCanLand; //!< Airship can land
			TerrainSpriteDisplay_T spriteDisplay; //!< The sprite's opacity settings
			Sound *soundEffect; //!< Plays a sound effect while walking on this type of terrain
			bool playSoundOnlyIfDamaged; //!< Plays the defined sound effect only if damaged
				char _unknown_25;
				char _unknown_26;
				char _unknown_27;
			bool bgIsFrame; //!< Does the background use frames?
			TerrainBattleType battleTypes; //!< The special battle types allowed on this terrain
			int initiativePercent; //!< "Initiative" battle type percentage
			int backAtkPercent; //!< "Back Attack" battle type percentage
			int surroundAtkPercent; //!< "Surround Attack" battle type percentage
			int pincersAtkPercent; //!< "Pincers Attack" battle type percentage
			TerrainGridDepth gridDepth; //!< The terrain's grid depth of field
			int gridTopY; //!< Y-position of the top of the grid
			int gridElongation; // test this
			int gridInclination; // test this
			
			DStringPtr frameBgFilename; //!< The name of the terrain's background frame
			bool frameBgHorScroll; //!< Does the frame bg horizontally scroll?
			bool frameBgVerScroll;//!< Does the frame bg vertically scroll?
			int frameBgHorScrollSpeed; //!< Frame bg's horizontal scroll speed
			int frameBgVerScrollSpeed; //!< Frame bg's vertical scroll speed
			
			bool frameFgFlag; //!< Does the frame have a foreground?
			
			DStringPtr frameFgFilename; //!< The name of the terrain's foreground frame
			bool frameFgHorScroll; //!< Does the frame fg horizontally scroll?
			bool frameFgVerScroll;//!< Does the frame fg vertically scroll?
			int frameFgHorScrollSpeed; //!< Frame fg's horizontal scroll speed
			int frameFgVerScrollSpeed; //!< Frame fg's vertical scroll speed
	};
	
	/*! \ingroup game_objects
		\brief Array of terrains from the database, used for default values and
		properties which are not supposed to be changed in-game.

		Use the database ID as index for accessing a terrain.

		Example:
		\code
int temp = RPG::terrains[36]->frameBgHorScrollSpeed;
		\endcode
	*/
	static RPG::NamedCatalogPtr<RPG::Terrain *> &terrains = (**reinterpret_cast<RPG::NamedCatalogPtr<RPG::Terrain *> **>(0x4CDD80));
}
