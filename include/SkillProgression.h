namespace RPG {
	/*! \brief Used to define the skill progression table for a particular hero.
		\sa RPG::DBActor
		\sa RPG::dbActors
	*/
	class SkillProgression {
		public:
			void **vTable;
			int id; //!< The one-based ID of the entry
				int _unknown_08;
			int levelReq; //!< Level requirement
			int skillId; //!< ID of the skill
	};
}