namespace RPG {
	/*! \brief Possible values for RPG::WeaponAnimation::battlerPose and RPG::SkillAnimation::battlerPose
	
		The animation pose ID of the battler.
		\note Each of these is numerical based starting from 0, but correspond to their value+1 in the database
		\note Use numerical values for poses 13-32. These are 0 based, so they will be defined as 12-31 here.
	*/
	enum AnimationBattlerPose { // zero-based
		ANIM_POSE_STAND, //!< Pose 1 in the database
		ANIM_POSE_PUNCH_RIGHT, //!< Pose 2 in the database
		ANIM_POSE_PUNCH_LEFT, //!< Pose 3 in the database
		ANIM_POSE_SKILL, //!< Pose 4 in the database
		ANIM_POSE_DEAD, //!< Pose 5 in the database
		ANIM_POSE_DAMAGE, //!< Pose 6 in the database
		ANIM_POSE_DAZED, //!< Pose 7 in the database
		ANIM_POSE_BLOCK, //!< Pose 8 in the database
		ANIM_POSE_RUN_LEFT, //!< Pose 9 in the database
		ANIM_POSE_RUN_RIGHT, //!< Pose 10 in the database
		ANIM_POSE_VICTORY, //!< Pose 11 in the database
		ANIM_POSE_ITEM //!< Pose 12 in the database
	};

	/*! \brief Possible values for RPG::WeaponAnimation::movement and RPG::SkillAnimation::movement
		
		These values describe the hero's movement before attacking
	*/
	enum AnimationMoveBeforeAttack {
		ANIM_MOVE_BEFORE_ACTION_NONE, //!< No movement animation before attacking
		ANIM_MOVE_BEFORE_ACTION_STEP_FORWARD, //!< Step forward a little bit before attacking
		ANIM_MOVE_BEFORE_ACTION_JUMP_FORWARD, //!< Jump forward before attacking
		ANIM_MOVE_BEFORE_ACTION_MOVE_TO_TARGET //!< Quickly move to target before attacking
	};
	
	/*! \brief Possible values for RPG::Animation::scope
		
		Does the battle animation target a single opponent or all?
	*/
	enum AnimationScope {
		ANIM_SCOPE_LOCAL,
		ANIM_SCOPE_GLOBAL
	};

	//! One-byte version of RPG::AnimationScope
	typedef unsigned char AnimationScope_T;
	
	/*! \brief Possible values for RPG::Animation::yLine
		
		Where does the vertical center of the animation lie?
	*/
	enum AnimationYAxisLine {
		ANIM_YAXIS_HIGH,
		ANIM_YAXIS_CENTER,
		ANIM_YAXIS_LOW
	};

	//! One-byte version of RPG::AnimationYAxisLine
	typedef unsigned char AnimationYAxisLine_T;
	
	/*! \brief Used to define a battle animation, its frames, and effects.
		\sa RPG::battleAnimations
		\sa RPG::AnimationEffect
		\sa RPG::AnimationScope
		\sa RPG::AnimationYAxisLine
		\sa RPG::AnimationFrame
	*/
	
	class Animation {
		public:
			void **vTable;
			int id; //!< ID of the animation
			DStringPtr name; //!< The name of the animation
			DStringPtr filename; //!< The filename of the animation's graphic
			bool isLargeAnimation; //!< Does the animation use a large animation file?
				bool _unknown_11;
				bool _unknown_12;
				bool _unknown_13;
			CatalogPtr<AnimationEffect *> effects; //!< Pointer to the RPG::AnimationEffect array
			AnimationScope_T scope; //!< The scope of the animation (See RPG::AnimationScope)
			AnimationYAxisLine_T yLine; //!< The location of the y-axis (See RPG::AnimationYAxisLine)
				bool _unknown_1A;
				bool _unknown_1B;
			CatalogPtr<AnimationFrame *> frames; //!< Pointer to the RPG::AnimationFrame array

	};
	/*! \ingroup game_objects
		\brief Array of battle animations from the database, used for default values and
		properties which are not supposed to be changed in-game.

		Use the database ID as index for accessing an animation.

		Example:
		\code
std::string animationName = RPG::battleAnimations[4]->filename.s_str());
		\endcode
	*/
	static RPG::NamedCatalogPtr<RPG::Animation *> &battleAnimations = (**reinterpret_cast<RPG::NamedCatalogPtr<RPG::Animation *> **>(0x4CDDC4));
}
