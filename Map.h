namespace RPG {
	//! Not implemented yet
	typedef void Chipset;

	/*! \brief Used for accessing and manipulating the current map environment
		\sa RPG::map
	*/
	class Map {
		public:
			void **vTable;
			int cameraSubX; //!< X position of the camera <b>in units of 1/16th of a pixel</b>
			int cameraSubY; //!< Y position of the camera <b>in units of 1/16th of a pixel</b>
			int encounterRateNew; //!< If the encounter rate is changed by event command, it's stored here
			int chipsetIdNew; //!< If the chipset id is changed by event command, it's stored here
			Chipset *chipset; //!< Pointer to the map's chipset (not yet implemented)
			NamedCatalogPtr<Event *> events; //!< Array of events (use event ID as index)
			unsigned char lowerTileIdNew[144]; //!< Lower tile ID? if changed via tile substitution event command (zero-based. index = old tile id, value = new tile id)
			unsigned char upperTileIdNew[144]; //!< Upper tile ID? if changed via tile substitution event command (zero-based. index = old tile id, value = new tile id)
			DStringPtr panoramaFilenameNew; //!< The filename of the panorama's image (if set by event command)
			bool horScrollNew; //!< Is horizontal scrolling enabled? (if set by event command)
			bool verScrollNew;//!< Is vertical scrolling enabled? (if set by event command)
			bool horAutoscrollNew; //!< Is horizontal auto-scrolling enabled? (if set by event command)
			int horScrollSpeedNew; //!< If horizontal scrolling enabled, this is the defined speed (if set by event command)
			bool verAutoscrollNew;//!< Is vertical auto-scrolling enabled? (if set by event command)
			int verScrollSpeedNew; //!< If horizontal scrolling enabled, this is the defined speed (if set by event command)

			//! Returns the current X position of the camera in pixels (this value means the position of the upper-left screen pixel of the screen on the map)
			int getCameraX();

			//! Returns the current Y position of the camera in pixels (this value means the position of the upper-left screen pixel of the screen on the map)
			int getCameraY();

			/*! \brief Sets a new camera position
				\param x New X position (pixels)
				\param y New Y position (pixels)
				\note This method also updates the camera "memory", so that the
				"Return to origin" function works
			*/
			void setCamera(int x, int y);

			/*! \brief Moves the camera (pixel-exact)

				This function can move the camera the specified amount of
				pixels in the specified speed.
				\param offsetX Amount of pixels to move horizontally (may also be negative)
				\param offsetY Amount of pixels to move vertically (may also be negative)
				\param speed Exact speed, in units of 3.75 pixels per second (1/16 tile per frame)
				\sa RPG::Character::customExactSpeed
			*/
			void moveCamera(int offsetX, int offsetY, int speed);

			//! Returns the width of the current map
			int getWidth();

			//! Returns the height of the current map
			int getHeight();

			/*! \brief Updates the start conditions of events after a change

				This function can be used to re-check the start conditions of
				all events. This is necessary if you modify a switch from
				DynRPG which is start condition of an event, for example.
			*/
			void updateEvents();
			
			/*! \brief Gets the tile ID for the lower layer tile at the specified coordinate
				\param map The map being checked. For now, just RPG::map is supported as it's not (yet?) possible to check maps the player isn't on
				\param x The Y coordinate of the tile
				\param y The Y coordinate of the tile
				\sa RPG::Tileset::lowerTilePassability
			*/
			int getLowerLayerTileId(int x, int y);
			
			/*! \brief Gets the tile ID for the upper layer tile at the specified coordinate
				\param map The map being checked. For now, just RPG::map is supported as it's not (yet?) possible to check maps the player isn't on
				\param x The Y coordinate of the tile
				\param y The Y coordinate of the tile
				\sa RPG::Tileset::upperTilePassability
			*/
			int getUpperLayerTileId(int x, int y);
			
			/*! \brief Gets the terrain ID for the tile ID specified
				\param map The map being checked. For now, just RPG::map is supported as it's not (yet?) possible to check maps the player isn't on
				\param x The Y coordinate of the tile
				\param y The Y coordinate of the tile
				\sa RPG::Tileset::lowerTileTerrainId
			*/
			int getTerrainId(int tileId);

			/*! \brief Returns the map properties information for the map that is
				currently loaded
				\return Pointer to the current map's properties
				\sa RPG::MapProperties
				\sa RPG::MapTreeProperties
			*/
			static MapProperties *&properties;

	};

	RPG::MapProperties *&RPG::Map::properties  = (**reinterpret_cast<RPG::MapProperties ***>(0x4CDD14));


	/*! \ingroup game_objects
		\brief The current map environment (camera, events, etc.)

		For accessing events, use <tt>RPG::map->events[<i>event ID</i>]</tt>.
		\sa RPG::mapTree
	*/
	static RPG::Map *&map = (**reinterpret_cast<RPG::Map ***>(0x4CDD74));
	
	
	int RPG::Map::getLowerLayerTileId(int x, int y) {
		int out;
		asm volatile("call *%%esi"
			: "=a" (out), "=c" (RPG::_ecx), "=d" (RPG::_edx)
			: "S" (0x4A80CC), "a" (this), "c" (y), "d" (x)
			: "cc", "memory");
		return out;
	}

	int RPG::Map::getUpperLayerTileId(int x, int y) {
		int out;
		asm volatile("call *%%esi"
			: "=a" (out), "=c" (RPG::_ecx), "=d" (RPG::_edx)
			: "S" (0x4A80F4), "a" (this), "c" (y), "d" (x)
			: "cc", "memory");
		return out;
	}
	
	int RPG::Map::getTerrainId(int tileId) {
		int out;
		asm volatile("movl 20(%%eax), %%eax; call *%%esi"
			: "=a" (out), "=d" (RPG::_edx)
			: "S" (0x47D038), "a" (this), "d" (tileId)
			: "ecx", "cc", "memory");
		return out;
	}

	/*! \brief Easily returns an event line.

		Allows you to write <tt>RPG::getBattleEventLine(6,2,0)->command</tt> instead of <tt>RPG::mapCurrent->events[6]->pages[3]->scriptLines->list->items[0]->command</tt> which gets the first line on the 3rd page of the event 6.

		\param eventId The monster group ID (one-based)
		\param pageId The monster group's battle event page ID (zero-based)
		\param lineId The line ID (zero-based)

		\sa RPG::MapEventPage
	*/
	RPG::EventScriptLine *getEventLine(int eventId, int pageId, int lineId) {
		return map->events[eventId]->data->pages[pageId]->scriptLines->list->items[lineId];
	}
}
