namespace RPG {
	/*! \brief Used to define an individual monster's position in the group.
	
		\sa RPG::DBMonsterGroup
		\sa RPG::dbMonsterGroups
	*/
	class MonsterGroupPosition {
		public:
			void **vTable;
			int id; //!< The one-based ID of the entry
				int _unknown_08;
			int monsterId; //!< monster's id
			int xPos; //!< X-position of the monster
			int yPos; //!< Y-position of the monster
			bool isHidden; //!< Is the monster hidden (aka "Invisible" in the editor)? 
	};
}