namespace RPG {
	//! Not implemented yet
	typedef void AuroraBoard;

	/*! \brief Possible values for RPG::Teleport::facingDirection

		The teleport direction
	*/
	enum TeleportDirection {
		TP_DIR_RETAIN_FACING,
		TP_DIR_UP,
		TP_DIR_RIGHT,
		TP_DIR_DOWN,
		TP_DIR_LEFT
	};
	
	/*! \brief Class used for teleporting.
		\sa RPG::teleport
		\sa RPG::teleportManagement
		\sa RPG::teleportHero()
	*/
	class Teleport {
		public:
			void **vTable;
				AuroraBoard *AuroraBoard1; //!< Not even a little bit implemented...
				AuroraBoard *AuroraBoard2; //!< Not even a little bit implemented...
			bool initialized; //!< Possibly checks if the screen initialized? Not sure about this one...
			bool teleportTrigger; //!< Set teleport parameters, and then set this to true to actually teleport;
				//bool _unknown_0E;
				//bool _unknown_0F;
			int mapId; //!< Map ID to teleport to
			int mapX; //!< Map X-coordinate to teleport to
			int mapY; //!< Map Y-coordinate to teleport to
				int _unknown_1C;
			TeleportDirection facingDirection; //!< The direction to face after teleporting
			//void teleportHero(int mapId, int x, int y, TeleportDirection dir); 
	};

	/*! \ingroup game_objects
		\brief Teleport parameters.
	*/
	static RPG::Teleport *&teleport = (**reinterpret_cast<RPG::Teleport ***>(0x4CDC1C));
	
	//! Simple function for teleporting
	void teleportHero(int mapId = 1, int x = 0, int y = 0, TeleportDirection dir = RPG::TP_DIR_RETAIN_FACING) {
		teleport->mapId = mapId;
        teleport->mapX = x;
        teleport->mapY = y;
        teleport->facingDirection = dir;
        teleport->teleportTrigger = true;
	}


}
