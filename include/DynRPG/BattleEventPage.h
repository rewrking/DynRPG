namespace RPG {

	/*! \brief Used to access battle event pages specific to the monster group being referenced.

		\sa RPG::DBMonsterGroup
		\sa RPG::dbMonsterGroups
	*/
	class BattleEventPage {
		public:
			void **vTable;
			int id; //!< The one-based ID of the event page
				int _unknown_08;
				int _unknown_0C;
				int _unknown_10;
			EventScriptList *scriptLines; //!< The event script lines
			BattleEventTrigger *triggers; //!< The trigger conditions for the battle event page

	};

	

}

