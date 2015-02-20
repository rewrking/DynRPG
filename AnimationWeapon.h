namespace RPG {
	
	/*! \brief Possible values for RPG::Item::WeaponAnimation::numAttacks
	
		This is the number of times a weapon will attack. 
		\note If the weapon has the attackTwice flag set, the number of attacks will double. 
	*/
	enum WeaponNumberOfAttacks {
		WEAPON_NUM_ATTACKS_ONCE,
		WEAPON_NUM_ATTACKS_TWICE,
		WEAPON_NUM_ATTACKS_THREE_TIMES 
		// Note: Are more values possible? (3+)
	};
	
	/*! \brief Possible values for RPG::Item::WeaponAnimation::rangedAnimSpeed
		
		The speed of the ranged weapon's ammunition battle animation. 
	*/
	enum WeaponRangedAnimSpeed {
		WEAPON_RANGED_ANIM_FAST, 
		WEAPON_RANGED_ANIM_MEDIUM, 
		WEAPON_RANGED_ANIM_SLOW
	};
	
	/*! \brief Used to define a weapon animation for a particular battler.
		\sa RPG::AnimationBattlerPose
		\sa RPG::AnimationMoveBeforeAttack
		\sa RPG::AnimationAfterImage
		\sa RPG::WeaponNumberOfAttacks
		\sa RPG::WeaponRangedAnimSpeed
		\sa RPG::Item
		\sa RPG::items
	*/
	class AnimationWeapon { //!< Weapon Animation sub-screen
		public:
			void **vTable;
			int id; //!< ID of the hero to have the weapon animation
				int _unknown_08;
				int _unknown_0C;
			AnimationBattlerPose battlerPose; //!< pose # of the hero. Default is 3. (See RPG::AnimationBattlerPose)
			bool isBattleAnim; //!< Weapon animation or Battle animation?
			int battleAnimId; //!< Battle animation ID
				int _unknown_1C;
			AnimationMoveBeforeAttack movement; //!< Movement before attack (See RPG::AnimationMoveBeforeAttack)
			bool addAfterImage; //!< "Add" the after image?
			WeaponNumberOfAttacks numAttacks; //!< Number of attacks (See RPG::WeaponNumberOfAttacks)
			bool isRangedWeapon; //!< Is ranged weapon?
			int rangedAnimId; //!< ID of ranged animation
			WeaponRangedAnimSpeed rangedAnimSpeed; //!< Ranged animation speed? (See RPG::WeaponRangedAnimSpeed)
	};
}