namespace RPG {
	//! Stub
	typedef void Stub;

	/*! \brief Possible values for RPG::AnimationInBattle::currentAnimTarget

		The current target of the battle animation
	*/
	enum AnimationTargetMonster {
		ATM_NONE = -2,
		ATM_ALL_ENEMIES = -1,
		ATM_ENEMY_1 = 0,
		ATM_ENEMY_2 = 1,
		ATM_ENEMY_3 = 2,
		ATM_ENEMY_4 = 3,
		ATM_ENEMY_5 = 4,
		ATM_ENEMY_6 = 5,
		ATM_ENEMY_7 = 6,
		ATM_ENEMY_8 = 7,
	};

	/*! \brief Used to access battle animation data while an animation is on screen 

		\sa RPG::AnimationTargetMonster
		\sa RPG::Animation
	*/

	class AnimationInBattle {
		public:
			void **vTable;
				int _unknown_04;
				Stub *_unknown_08; // battlers that are already pointed to in RPG::monsters and RPG::actors
				int monsterGroupId; //!< The ID of the monster group
				//int _unknown_0C;
			bool isAnimationPlaying; //!< Is a battle animation playing?
			AnimationCurrent *currentAnim; //!< The battle animation's data
			int currentAnimationId; //!< The ID of the battle animation currently playing
			int currentAnimTarget; //!< The target of the battle animation currently playing (See RPG::AnimationTargetMonster)
			int currentAnimationFrame; //!< Current animation frame playing
	};
}
