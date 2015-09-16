namespace RPG {

	/*! \brief Used for the default data of monsters which is defined in the
		database

		\note The members of this class either mean default values of a
		property or they are used for properties which aren't supposed to be
		changed in-game, thus the members won't be saved and loaded
		automatically (as it is the case with RPG::Actor and RPG::DBActor), 
		but only loaded once at startup.\n\n
		If you want to access a monster's data IN BATTLE, use the members and methods of RPG::Monster or RPG::Battler instead.
		\sa RPG::dbMonsters
		\sa RPG::DamageMultiplier
		\sa RPG::MonsterBehavior
		\sa RPG::monsters
	*/

	class DBMonster {
		public:
			void **vTable;
			int id; //!< ID of the monster
			DStringPtr name; //!< Monster's name
			DStringPtr filename; //!< Monster's filename
			unsigned int colorAlteration; //!< The color hue of the monster graphic. 0 represents the center of the slider. 0-180 is the right side, while 180-350 is the left side
			int maxHp; //!< The monster's Maximum HP
			int maxMp; //!< The monster's Maximum MP
			int attack; //!< The monster's attack value
			int defense; //!< The monster's defense value
			int intelligence; //!< The monster's intelligence value
			int agility; //!< The monster's agility value
			bool isTransparent; //!< Is the monster partially transparent?
			int exp; //!< The amount of experience rewarded
			int gold; //!< The amount of gold rewarded
			int itemId; //!< The ID of the item rewarded (0 = no item)
			int itemProbability; //!< The probability of getting the item (percentage) (0-100)
			bool critFlag; //!< Can the monster perform a critical hit?
			int critPercentage; //!< The probablity of getting the critical hit (percentage) (0-100)
			bool oftenMiss; //!< Does the monster often miss?
			bool isFlying; //!< Is the monster flying?
			DArray<DamageMultiplier_T, 1> conditions; //!< Conditions Array (See RPG::DamageMultiplier). Ensure conditions.size is greater than 0 before reading from individual conditions!! Otherwise, the array will resize to fit the condition that was referenced, and set it to "0" (A), which will affect damage and confuse your brain. Explained in RPG::DArray::operator[]()
			DArray<DamageMultiplier_T, 1> attributes; //!< Attributes Array (See RPG::DamageMultiplier). Ensure attributes.size is greater than 0 before reading from individual attributes!! Otherwise, the array will resize to fit the condition that was referenced, and set it to "0" (A), which will affect damage and confuse your brain. Explained in RPG::DArray::operator[]()
			CatalogPtr<MonsterBehavior *> behavior; //!< Behavior Array (See RPG::MonsterBehavior)
	};

	/*! \ingroup game_objects
		\brief Array of monsters from the database, used for default values and
		properties which are not supposed to be changed in-game.

		Use the database ID as index for accessing a monster.

		Example:
		\code
int monCrit = RPG::dbMonsters[1]->critPercentage;
		\endcode
		\sa RPG::monsters
	*/
	static RPG::NamedCatalogPtr<RPG::DBMonster *> &dbMonsters = (**reinterpret_cast<RPG::NamedCatalogPtr<RPG::DBMonster *> **>(0x4CDE0C));
}
