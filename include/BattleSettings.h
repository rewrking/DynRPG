namespace RPG {

	//! Possible values for RPG::BattleSettings::layout
	enum BattleLayout {
		BL_TRADITIONAL, //!< "Traditional" layout
		BL_ALTERNATIVE, //!< "Alternative" layout
		BL_GAUGE //!< "Gauge" layout
	};
	
	//! One-byte version of RPG::BattleLayout
	typedef unsigned char BattleLayout_T;
	
	//! Possible values for RPG::BattleSettings::randomEncounterDeath
	enum RandomEncounterDeath {
		RE_DEATH_GAME_OVER,
		RE_DEATH_CALL_COMMON_EVENT
	};
	
	/*! \brief Used for battle settings (layout, etc.)
		\sa RPG::battleSettings
		\sa RPG::BattleLayout
		\sa RPG::BattleCommands
		\sa RPG::RandomEncounterDeath
		\sa RPG::System
	*/
	class BattleSettings {
		public:
			void **vTable;
			int characterPlacement; //!< Manual (0) or Automatic (1)?
			BattleLayout_T layout; //!< Battle layout
				int _unknown_C;
			// Documented as WindowSize	(0|1 = large|small) (dword), which suggests the opposite...
			bool largeWindows; //!< Are the "large windows" active?
				bool _unknown_11;
				bool _unknown_12;
				bool _unknown_13;
			bool transparentWindows; //!< Are transparent windows active? (This affects the whole game even though the %RPG Maker guys have put it into the battle settings.)
			CatalogPtr<BattleCommand *> battleCommands; //!< Pointer to the RPG::BattleCommands array
				int _unknown_1C;
			Row rowShown;  //!< The current row shown?
			RandomEncounterDeath randomEncounterDeath; //!< Does a random encounter death cause a game over, or call a common event? (see RPG::RandomEncounterDeath)
			int commonEventId; //!< The ID of the common event to call
			bool deathTeleportFlag; //!< Teleport before executing the common event?
			int deathTeleportMapId; //!< The Map ID to teleport to upon death
			int deathTeleportX; //!< The Map's X coordinate to teleport to upon death
			int deathTeleportY; //!< The Map's Y coordinate to teleport to upon death
			TeleportDirection deathTeleportFacingDirection; //!< The direction to face in upon teleporting after death (see RPG::TeleportDirection)
	};
	
	/*! \ingroup game_objects
		\brief Battle settings
		
		Please mind that this object is not saved and loaded automatically, but only initialized once at startup.
	*/
	static RPG::BattleSettings *&battleSettings = (**reinterpret_cast<RPG::BattleSettings ***>(0x4CDD60));
}
