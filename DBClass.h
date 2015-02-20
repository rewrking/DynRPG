namespace RPG {
	/*! \brief Used for the default data of classes which is defined in the
		database

		\note The members of this class either mean default values of a
		property or they are used for properties which aren't supposed to be
		changed in-game, thus the members won't be saved and loaded
		automatically (as it is the case with RPG::Actor), but only loaded once
		at startup.\n\n
		\sa RPG::dbClasses
		\sa RPG::Actor
		\sa RPG::actors
	*/
	
	class DBClass {
		public:
			void **vTable;
			int id; //!< ID of the class
			DStringPtr name; //!< Default class name
				int _unknown_0C;
			bool twoWeapons; //!< Does the class use a second weapon instead of the shield?
			bool lockEquipment; //!< Is the equipment locked?
			bool aiControl; //!< Is the class controlled by the computer in battle?
			bool mightyGuard; //!< Does defending reduce the damage more than usual?
			ArrayBaseOne<short, 99> maxHp; //!< Array of maximum HP values for each level
			ArrayBaseOne<short, 99> maxMp; //!< Array of maximum MP values for each level
			ArrayBaseOne<short, 99> attack; //!< Array of attack values for each level
			ArrayBaseOne<short, 99> defense; //!< Array of defense values for each level
			ArrayBaseOne<short, 99> intelligence; //!< Array of intelligence values for each level
			ArrayBaseOne<short, 99> agility; //!< Array of agility values for each level
			int expPrimary; //!< Primary experience curve parameter
			int expSecondary; //!< Secondary experience curve parameter
			int expTertiary; //!< Tertiary experience curve parameter
			CatalogPtr<SkillProgression *> skillLearning; //!< Skill learning data
			DArray<DamageMultiplier_T> conditions; //!< Conditions Array (See RPG::DamageMultiplier)
			DArray<DamageMultiplier_T> attributes; //!< Attributes Array (See RPG::DamageMultiplier)
			int battleGraphicId; //!< Battle graphic ID
			int battleCommands[7]; //!< Default battle commands (\c 0 and \c -1 both mean "no command at this position")
			
	};
	
	/*! \ingroup game_objects
		\brief Array of actors from the database, used for default values and
		properties which are not supposed to be changed in-game.

		Use the database ID as index for accessing a battler's class.

		Example:
		\code
int experience1 = RPG::dbClasses[1]->expPrimary;
		\endcode
		\sa RPG::actors
	*/
	static RPG::NamedCatalogPtr<RPG::DBClass *> &dbClasses = (**reinterpret_cast<RPG::NamedCatalogPtr<RPG::DBClass *> **>(0x4CDD7C));
}
