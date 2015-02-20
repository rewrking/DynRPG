namespace RPG {	
	/*! \brief Possible values for RPG::Item::type
		
		The item's type. This determines which parameters will be available to use. 
		\note Refer to the database's Item page to determine which params can be used.
		\warning Use of any variables outside of their item type is untested.
	*/
	enum ItemType {
		ITEM_COMMON,
		ITEM_WEAPON,
		ITEM_SHIELD,
		ITEM_ARMOR,
		ITEM_HELMET,
		ITEM_OTHER,
		ITEM_MEDICINE,
		ITEM_BOOK, //!< Skill Book
		ITEM_SEED, //!< Stat Up
		ITEM_SCROLL, //!< Skill Scroll
		ITEM_SWITCH
	};
	
	/*! \brief Possible values for RPG::Item::target
		
		If ITEM_MEDICINE, this determines if one hero or all heroes are affected. 
	*/
	enum ItemTarget {
		ITEM_TARGET_SINGLE,
		ITEM_TARGET_ALL
	};
	
	/*! \brief Possible values for RPG::Item::messageShown
		
		If ITEM_SCROLL, this determines if the item's name or the skill's name 
		will be used in the battle window. 
	*/
	enum ItemScrollMsgShown {
		ITEM_SCROLL_MSG_ITEM, //!< Item Name
		ITEM_SCROLL_MSG_SKILL //!< Name of Associated Skill
	};
	
	/*! \brief Possible values for RPG::Item::conditionFlag
		
		Determines if the item will inflict or remove. 
	*/
	enum ItemConditionFlag {
		ITEM_CONDITION_INFLICT,
		ITEM_CONDITION_REMOVE,
	};
	
		/*! \brief Possible values for RPG::Item::weaponTrajectory
	
		If ranged weapon, this is the movement of the ammunition.
	*/
	enum WeaponRangedTrajectory {
		WEAPON_RANGED_TRAJ_FLY_TO_TARGET, //!< Fly Straight to Target (crossbows, bullets, etc.)
		WEAPON_RANGED_TRAJ_RETURN_TO_HERO //!< Return to User after Striking (steel ball & chain, etc.)
	};
	
	/*! \brief Possible values for RPG::Item::weaponTargetting
	
		If ranged weapon, this is the type of targetting that the weapon uses.
	*/
	enum WeaponRangedTargetting {
		WEAPON_RANGED_TARGET_SINGLE, //!< Single Target
		WEAPON_RANGED_TARGET_SCREEN_CENTER, //!< Fly Down Center of Screen
		WEAPON_RANGED_TARGET_ALL_SIMUL, //!< Strike Each Enemy Simultaneously
		WEAPON_RANGED_TARGET_ALL_INTURN //!< STrike Each Enemy in Turn
	};
	
	/*! \brief Used for the data of items which can be accessed or changed in-game.

		\sa RPG::items
		\sa RPG::ItemType
		\sa RPG::ItemTarget
		\sa RPG::ItemScrollMsgShown
		\sa RPG::ItemConditionFlag
		\sa RPG::WeaponRangedTrajectory
		\sa RPG::WeaponRangedTargetting
		\sa RPG::AnimationWeapon
	*/
	class Item {
		public:
			void **vTable;
			int id; //!< ID of the item
			DStringPtr name; //!< The name of the item
			DStringPtr description; //!< The description of the item
			ItemType type; //!< The item's type as defined in the database (see RPG::ItemType)
			int price; //!< Price
			int numUses; //!< Number of uses (0 = unlimited)

			// ITEM_WEAPON
			int str; //!< Attack \sa RPG::ITEM_WEAPON
			int def; //!< Defense \sa RPG::ITEM_WEAPON
			int intl; //!< Intelligence \sa RPG::ITEM_WEAPON
			int agl; //!< Agility \sa RPG::ITEM_WEAPON
			bool twoHanded; //!< Is it two-handed? (Hands Required) \sa RPG::ITEM_WEAPON
			int mpCost; //!< Agility \sa RPG::ITEM_WEAPON
			int hitProb; //!< Hit Probability \sa RPG::ITEM_WEAPON
			int critBonus; //!< Critical Bonus \sa RPG::ITEM_WEAPON
			int battleAnimId; //!< Battle Animation ID \sa RPG::ITEM_WEAPON
			bool alwaysAttackFirst; //!< Always attack first? \sa RPG::ITEM_WEAPON
			bool attackTwice; //!< Attack twice? \sa RPG::ITEM_WEAPON
			bool attackAll;  //!< Attack all enemies? \sa RPG::ITEM_WEAPON
			bool ignoreEvasion;  //!< Ignore evasion? \sa RPG::ITEM_WEAPON

			// ITEM_SHIELD
			bool preventCrit;  //!< Prevent critical hits? \sa RPG::ITEM_SHIELD
			bool increaseEvasion;  //!< Increased evasion? \sa RPG::ITEM_SHIELD
			bool halfMpCost;  //!< Half MP Consumption? \sa RPG::ITEM_SHIELD
			bool noTerrainDmg;  //!< No Terrain Damage? \sa RPG::ITEM_SHIELD

			// ITEM_MEDICINE
			ItemTarget target; //!< Does the item target a single hero or all? (see RPG::ItemTarget) \sa RPG::ITEM_MEDICINE
			int hpRestorePercent; //!< % of Max HP to restore \sa RPG::ITEM_MEDICINE
			int hpRestoreUnits; //!< Amount of HP to restore \sa RPG::ITEM_MEDICINE
			int mpRestorePercent; //!< % of Max MP to restore \sa RPG::ITEM_MEDICINE
			int mpRestoreUnits; //!< Amount of MP to restore \sa RPG::ITEM_MEDICINE
			bool onlyInField;  //!< Only usable on the field map? \sa RPG::ITEM_MEDICINE
			bool onlyOnDead;  //!< Only usable on dead characters? \sa RPG::ITEM_MEDICINE

			// ITEM_SEED
			int addMaxHp; //!< Max HP to add \sa RPG::ITEM_SEED
			int addMaxMp; //!< Max MP to add \sa RPG::ITEM_SEED
			int addStr; //!< STR to add \sa RPG::ITEM_SEED
			int addDef; //!< DEF to add \sa RPG::ITEM_SEED
			int addInt; //!< INT to add \sa RPG::ITEM_SEED
			int addAgl; //!< AGL to add \sa RPG::ITEM_SEED

			// ITEM_SCROLL
			ItemScrollMsgShown messageShown; //!< Message Shown When Used (see RPG::ItemScrollMsgShown) \sa RPG::ITEM_SCROLL
			int skillId;  //!< Skill Id \sa RPG::ITEM_SCROLL

			// ITEM_SWITCH
			int switchId;  //!< Switch Id \sa RPG::ITEM_SWITCH
			bool useInField;  //!< Activation in field? \sa RPG::ITEM_SWITCH
			bool useInBattle;  //!< Activation in battle? \sa RPG::ITEM_SWITCH

			// All/Misc
			DArray<bool> usableByHero; //!< Usable By Hero Array
			DArray<bool> conditions; //!< Array of Conditions. size = highest condition that is checked off
			DArray<bool> attributes; //!< Array of Attributes. size = highest attribute that is checked off
			int conditionPercentage; //!< Inflict/Resist Condition %
				int _unknown_01;
			NamedCatalogPtr<AnimationWeapon *> weaponAnims; //!< Pointer to the RPG::AnimationWeapon array
			bool invokeSkill; //!< Does the item invoke a skill (set skill with skillId)
			DArray<bool> usableByClass; //!< Usable By Class Array
			bool isCursed; //!< Is the item cursed?
			
			// Note: conditionFlag is a DWORD, so this can't be defined as bool
			ItemConditionFlag conditionFlag; //!< Does the item remove the condition instead of inflict? (see RPG::ItemConditionFlag)
			WeaponRangedTrajectory weaponTrajectory; //!< If a ranged weapon, the weapons' trajectory (see RPG::WeaponRangedTrajectory)
			WeaponRangedTargetting weaponTargetting; //!< If a ranged weapon, the weapons' target(s) (see RPG::WeaponRangedTargetting)
			
	};
	
	/*! \ingroup game_objects
		\brief Array of items from the database, used for default values and
		properties which are not supposed to be changed in-game.

		Use the database ID as index for accessing an item.

		Example:
		\code
int swordHitProb = RPG::items[36]->hitProb;
		\endcode
		\sa RPG::inventory
	*/
	static RPG::NamedCatalogPtr<RPG::Item *> &items = (**reinterpret_cast<RPG::NamedCatalogPtr<RPG::Item *> **>(0x4CDB14));
}
