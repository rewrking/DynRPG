namespace RPG {
	
	//! Possible values for the RPG::BattleEventTrigger::triggerFlags member
	enum TriggerFlag {
		TF_NONE = 0,
		TF_SWITCH_A = 1,
		TF_SWITCH_B = 2,
		TF_VARIABLE = 4,
		TF_TURN_NUM = 8,
		TF_EXHAUSTION = 16,
		TF_MONSTER_HP = 32,
		TF_HERO_HP = 64,
		TF_MONSTER_TURN = 128
	};

	//! One-byte version of RPG::TriggerFlag
	typedef unsigned char TriggerFlag_T;
	
	//! Possible values for the RPG::BattleEventTrigger::triggerFlags2k3 member
	enum TriggerFlag2k3 {
		TF2_HERO_TURN = 1,
		TF2_BATTLE_COMMAND = 2
	};

	//! One-byte version of RPG::TriggerFlag2k3
	typedef unsigned char TriggerFlag2k3_T;
	
	/*! \brief Used to access event command specific to the current battle. (OMG YES)

		\sa RPG::DBMonsterGroup
		\sa RPG::BattleEventPage
		\sa RPG::TriggerFlag
		\sa RPG::TriggerFlag2k3
	*/
	class BattleEventTrigger {
		public:
			void **vTable;
			TriggerFlag_T triggerFlags; //!< The triggers that are checked off (enums can be combined)
			TriggerFlag2k3_T triggerFlags2k3; //!< Additional triggers added in Rm2k3 (enums can be combined)
			int switchId[2]; //!< The IDs of switches A & B
			int variableId; //!< The ID of the variable to trigger
			int variableValue; //!< The variable trigger will be above this value
			int turnsXValue; //!< The "X" value for the general turns elapsed (left field)
			int turnsPlusValue;//!< The plus value for the general turns elapsed (right field)
			int exhaustionStart; //!< Between this value and exhaustionEnd (left field)
			int exhaustionEnd; //!< Between exhaustionStart and this value (right field)
			int monsterHpMonId; //!< Monster party slot (zero-based) for when "HP between" is checked off
			int monsterHpStart; //!< Between this value and monsterHpEnd (left field)
			int monsterHpEnd; //!< Between monsterHpStart and this value (right field)
			int heroHpHeroId; //!< The hero whose HP causes the trigger (database ID) ("HP Between" checkbox)
			int heroHpStart; //!< Between this value and heroHpEnd (left field)
			int heroHpEnd; //!< Between heroHpStart and this value (right field)
			int monsterTurnsMonId; //!< The monster whose turns cause the trigger (zero-based)
			int monsterTurnsXValue; //!< The "X" value for the monster's turns (left field)
			int monsterTurnsPlusValue; //!< The plus value for the monster's turns (right field)
			int heroTurnsHeroId; //!< The hero whose turns cause the trigger (database ID)
			int heroTurnsXValue; //!< The "X" value for the hero's turns (left field)
			int heroTurnsPlusValue; //!< The plus value for the hero's turns (right field)
			int heroCommandHeroId; //!< The hero whose command should cause the trigger (database ID)
			int heroCommandId; //!< The actual command ID (one-based)(See RPG::BattleCommands)

	};

}

