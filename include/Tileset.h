namespace RPG {	
	/*! \brief Possible values for RPG::Tileset::LowerTilePassability and RPG::Tileset::UpperTilePassability
		
		A tile's passability value. This determines which properties the tile will have. 
		\note These are named based on their numeric value. Combine enums to get the specific properties of a tile.
		
		A tile that is not passable is considered zero. With each direction that is passable, its value is added (1, 2, 4 & 8). 
		If the tile is completely passable (aka the "O" tile), it adds up to 15. Star tiles, square tiles, and counter flags are added on top of that.
		Think of it like this:
			(CP_X + ) CP_B/CP_L/CP_R/CP_T (Any combo) + CP_STAR/CP_SQUARE + CP_COUNTER
			
		For instance, a tile might have a value of 91, which is a combination of CP_B (1), CP_L (2), CP_T (8) + CP_STAR (16) + CP_COUNTER (64)...
		which means it's above hero (star), passable from the bottom, top, and left, and has the counter flag.
		
		With this in mind, you can give properties to tiles that aren't normally allowed, like adding the counter flag to a lower layer tile.
		
		\warning If you are checking for a specific property, (like if a tile is passable from the top), be sure
		to check each applicable variation as well: 8(CP_T), 24 (CP_T+CP_STAR), 56 (CP_T+CP_SQUARE), 88 (CP_T+CP_STAR+CP_COUNTER), and for the sake of argument, you can also check 120 (CP_T+CP_SQUARE+CP_COUNTER), although it's not possible through normal means. This is an extreme example, so of course you can use less checks if you know the layer or group of tiles.
	*/
	enum TilePassability {
		CP_X = 0, //!< "X" tile (Not passable)
		CP_B = 1, //!< Passable from the bottom
		CP_L = 2, //!< Passable from the left
		CP_R = 4, //!< Passable from the right
		CP_T = 8, //!< Passable from the top
		CP_O = 15, //!< "O" tile (completely passable). Equal to CP_B + CP_L + CP_R+ CP_T.
		CP_STAR = 16, //!< Star tile (above hero), but NOT passable. A typical passable star tile would be considered CP_STAR + CP_O (= 31)
		CP_SQUARE = 48, //!< Square tile. Only allowed in tiles 6-17 (zero-based)
		CP_COUNTER = 64 //!< Counter flag. Only allowed in upper tiles
	};
	
	//! One-byte version or RPG::TilePassability
	typedef unsigned char TilePassability_T;
	
	/*! \brief Possible values for RPG::Tileset::waterAnim
	
		The water animation sequence of the tileset.
	*/
	enum WaterAnimation {
		WATERANIM_1_2_3_2, //!< "1-2-3-2" radio button
		WATERANIM_1_TWO_THREE //!< "1-2-3" radio button
	};
	
	/*! \brief Possible values for RPG::Tileset::waterSpeed
	
		The water animation speed of the tileset.
	*/
	enum WaterSpeed {
		WATERSPD_SLOW,
		WATERSPD_FAST
	};
	
	/*! \brief Used for the data of tilesets which can be accessed or changed in-game.

		\sa RPG::tilesets
		\sa RPG::TilePassability
		\sa RPG::WaterAnimation
		\sa RPG::WaterSpeed
	*/
	class Tileset {
		public:
			void **vTable;
			int id; //!< ID of the tileset
			DStringPtr name; //!< The name of the tileset in the database
			DStringPtr filename; //!< The filename of the tileset
			unsigned short lowerTileTerrainId[162]; //!< The lower tile layer's terrain ID (See RPG::Terrain)
			RPG::TilePassability_T lowerTilePassability[162]; //!< The lower tile layer's passability (See RPG::TilePassability)
			RPG::TilePassability_T upperTilePassability[144]; //!< The upper tile layer's passability (See RPG::TilePassability)
			WaterAnimation waterAnim; //!< The tileset's water animation sequence (See RPG::WaterAnimation)
			WaterSpeed waterSpeed; //!< The tileset's water speed value (See RPG::WaterSpeed)
	};
	
	/*! \ingroup game_objects
		\brief Array of tilesets from the database, used for default values and
		properties which are not supposed to be changed in-game.

		Use the database ID as index for accessing a tileset.

		Example:
		\code
if (RPG::tilesets[2]->lowerTilePassability[36] == (RPG::CP_STAR + RPG::CP_O)) do some stuff...
		\endcode
	*/
	static RPG::NamedCatalogPtr<RPG::Tileset *> &tilesets = (**reinterpret_cast<RPG::NamedCatalogPtr<RPG::Tileset *> **>(0x4CDD0C));
}
