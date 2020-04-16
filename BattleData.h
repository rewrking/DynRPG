namespace RPG {
	//! Possible values for RPG::BattleData::navLevel
	enum BattleNavigationLevel {
		BNAV_IN_FIGHT_ESCAPE_WINDOW,
		BNAV_IN_PARTY_WINDOW,
		BNAV_IN_COMMAND_WINDOW,
		BNAV_BLANK, //!< Not used?
		BNAV_ESCAPING
	};

	//! One-byte version of RPG::BattleNavigationLevel
	typedef unsigned char BattleNavigationLevel_T;

	//! Possible values for RPG::BattleData::battlePhase
	enum BattlePhase {
		BPHASE_BATTLE, //!< From the moment the battle starts until a victory/death condition
		BPHASE_DEATH, //!< After the party has died
		BPHASE_VICTORY, //!< After the party has achieved a victory
		BPHASE_END //!< After the battle screen has faded out before going back to the map
	};

	//! Possible values for RPG::BattleData::partyFormation
	enum BattlePartyFormation {
		BPFORM_TERRAIN,
		BPFORM_LOOSE,
		BPFORM_TIGHT
	};

	//! Possible values for RPG::BattleData::encounterCondition
	enum BattleEncounterCondition {
		BENC_TYPE_NO_SPECIAL_CONDITIONS,
		BENC_TYPE_INITIATIVE,
		BENC_TYPE_BACK_ATTACK,
		BENC_TYPE_SURROUND_ATTACK,
		BENC_TYPE_PINCER_ATTACK,
	};

	//! Possible values for RPG::BattleData::battleType
	enum BattleType {
		BTYPE_RANDOM_ENCOUNTER,
		BTYPE_ENCOUNTER_BY_EVENT_COMMAND
	};

	//! Possible results for a battle
	enum BattleResult {
		BRES_VICTORY,
		BRES_ESCAPE,
		BRES_DEFEAT,
		BRES_ABORT
	};

	/*! \brief Used for the data and settings for the current battle. (OMG YES)

		\sa RPG::battleData
		\sa RPG::BattleNavigationLevel
		\sa RPG::BattlePhase
		\sa RPG::BattlePartyFormation
		\sa RPG::BattleEncounterCondition
		\sa RPG::BattleType
	*/
	class BattleData {
		public:
			void **vTable;
				int _unknown_04;
				int _unknown_08;
			int monsterGroupId; //!< ID of the monster group
			DStringPtr backdropFilename; //!< The filename of the backdrop
			bool escapeAllowed; //!< Is escaping allowed?
			bool defeatAllowed; //!< Is defeat allowed? (This would cause a game over)
			bool firstStrike; // More research
				bool _unknown_17;
				int _unknown_18;
			Image *backdropImage; //!< The RPG::Image object of the backdrop
			BattleNavigationLevel_T navLevel; //!< Which window or action has the focus?
			bool isInitialized; //!< Has the battle been initialized?
				bool _unknown_22;
				bool _unknown_23;
			Window *winParty; //!< The RPG::Window object of the party
			Window *winFightEscape; //!< The RPG::Window object for fight/escape/autobattle
			Window *winCommand; //!< The RPG::Window object for commands
			Window *winSkill; //!< The RPG::Window object for skills
			Window *winItem; //!< The RPG::Window object for items
			Window *winPartyTarget; //!< The RPG::Window object for targetting party members
			Window *winMonTarget; //!< The RPG::Window object for targetting enemies
			Window *winAction; //!< The RPG::Window object for the action window!
			int actionMessageLineAmount; // More research
			int currentHeroId; //!< Party slot
			Battler *currentHero; //!< The RPG::Battler data for the currently commanded hero
				int _unknown_50;
				int _unknown_54;
			int fleeChance; //!< Percentage for escape (Formula: 50 + (100 - 100 * Avg Enemy AGI / Avg Hero AGI))
			DListPtr<char> battleProgress; // More research
			bool canvasRedrawn; //!< Was the canvas redrawn?

			/*! \brief If a hero is ready to act, their party index will be added to this array
				\note This array lists the heroes in the order that they become ready, so if hero 2 is the first to act, and hero 3 is next to act, readyPartySlot[0] = 1 (hero 2), readyPartySlot[1] = 2 (hero 3), readyPartySlot[2] = -1 (empty) and readyPartySlot[3] = -1 (empty)
			*/
			int readyPartySlot[4];
				int _unknown_74;
			bool isSys2CursorShown; //!< Is the system2 cursor currently on the screen?
			BattlePhase battlePhase; //!< The phase of the battle (you can use this for special conditions)
			/*! \brief Timer between the frame the last monster is defeated, and the end of battle message windows.
			
				Starts at 60 the moment the last enemy is defeated and counts back to 0 each frame (60 = 1 second)
			
			*/
			int battlEndTimer;
			bool isDefeat; //!< Was the party defeated? (you can use this for special actions upon losing the battle)
			bool isVictory; //!< Was the party victorious (you can use this for special actions upon winning the battle)
			int sys2CursorX; //!< The x-position of the System2 cursor
			int sys2CursorY; //!< The y-position of the System2 cursor
			BattlePartyFormation partyFormation; //!< The party's formation
			BattleEncounterCondition encounterCondition; //!< The condition of the battle encounter
			Panorama *backgroundFrame; //!< The background frame panorama object (defined by the terrain)
			Panorama *foregroundFrame; //!< The foreground frame panorama object (defined by the terrain)
			int terrainId; //!< The ID of the terrain
			Battler *reflectTarget; //!< If the current action is being reflected, the target of the reflecting spell.
			char reflectTargetRange; // More research
			bool isBattleAnimPlaying; // More research
			bool autoBattle; //!< is autoBattle enabled?
				bool _unknown_AB; // Used by RPS Patch
			BattleType battleType; //!< Is this a random encounter or did it start via event?
			char currentTargetRange; // More research
				bool _unknown_B1; // Used by RPS Patch
				bool _unknown_B2; // Used by RPS Patch
			int currentActingBattlerId; //!< Currently acting battler
			int currentActingHeroDbId; //!< Database ID of the currently acting hero, -1 = enemy
				int _unknown_BC;
			bool continueBattle; // More research
			bool eventReady; //!< Is an event command ready to be executed?
			bool delay; //!< Delay the battle (might be able to use this for long actions & animations)
				bool _unknown_C3;
			
	};
	
	/*! \ingroup game_objects
		\brief Data and settings for the current battle.

		Example:
		\code
std::string backdropName = RPG::battleData->backdropFilename.s_str());
		\endcode
	*/
	static RPG::BattleData *&battleData = (**reinterpret_cast<RPG::BattleData ***>(0x4CDD38));

}

