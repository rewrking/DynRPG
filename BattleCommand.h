namespace RPG {
	
	//! Possible values for RPG::BattleCommands::archetype
	enum BattleCommandArchetype {
		BCOM_ATTACK,
		BCOM_SKILL,
		BCOM_SKILL_SUBSET,
		BCOM_DEFEND,
		BCOM_ITEM,
		BCOM_ESCAPE,
		BCOM_LINK_TO_EVENT
	};
	
	/*! \brief Used to define the actual battle commands (Attack, Defend, etc)
		\sa RPG::BattleCommandArchetype
		\sa RPG::BattleSettings
		\sa RPG::battleSettings
	*/
	class BattleCommand { //!< Skill Animation sub-screen
		public:
			void **vTable;
			int id; //!< ID of the battle command
			DStringPtr name; //!< The name of the battle command
			BattleCommandArchetype archetype; //!< The command's archetype (see RPG::BattleCommandArchetype)
	};
	
}