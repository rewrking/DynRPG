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
			int critPercentage; //!< The probability of getting the critical hit (percentage) (0-100)
			bool oftenMiss; //!< Does the monster often miss?
			bool isFlying; //!< Is the monster flying?
				
			/*! \brief Condition Resistance Array (See RPG::DamageMultiplier)
				
				If at a certain point, the resistance of a condition and all conditions higher than it are C, the conditions.size will equal the number of the highest non-C condition. 
				
				\b Example: 
				
					Cond1: A
					Cond2: B
					Cond3: C
					Cond4: C
					Cond5: C
					
				Because Cond3 is C, and those above it are C, conditions.size will be 2, because Cond2 is the last non-C condition.
					
				\warning This can be confusing, because if you need to use conditions[15], but check for conditions.size to be 15 first, it could be 10 if 11-15 are all C, so the check would be false. The solution would be to use RPG::conditions.count() for the check instead. This would resize the array once a condition higher than conditions.size is called, but because of the resizeValue in the template for RPG::DArray, conditions 11-15 would be correctly assigned to C
			*/
			DArray<DamageMultiplier_T, 1, 2> conditions;
			
			/*! \brief Attribute Resistance Array (See RPG::DamageMultiplier)
				
				If at a certain point, the resistance of an attribute and all attributes higher than it are C, the attributes.size will equal the number of the highest non-C attribute. 
				
				\b Example: 
				
					Attr1: A
					Attr2: B
					Attr3: C
					Attr4: C
					Attr5: C
					
				Because Attr3 is C, and those above it are C, attributes.size will be 2, because Attr2 is the last non-C attribute.
					
				\warning This can be confusing, because if you need to use attributes[15], but check for attributes.size to be 15 first, it could be 10 if 11-15 are all C, so the check would be false. The solution would be to use RPG::attributes.count() for the check instead. This would resize the array once an attribute higher than attributes.size is called, but because of the resizeValue in the template for RPG::DArray, attributes 11-15 would be correctly assigned to C
			*/
			DArray<DamageMultiplier_T, 1, 2> attributes;
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
