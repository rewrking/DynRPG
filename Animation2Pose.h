namespace RPG {
	/*! \brief Possible values for RPG::Animation2Pose::animType

		The type of the battler animation pose
	*/
	enum PoseAnimationType {
		PT_CHARACTER_POSE,
		PT_BATTLE_ANIMATION
	};
	
	//! One-byte version of RPG::PoseAnimationType
	typedef unsigned char PoseAnimationType_T;

	/*! \brief Used to define a battler's character animation pose and pose parameters.
		\sa RPG::battlerAnimations
		\sa RPG::PoseAnimationType
		\sa RPG::Animation2
		\sa RPG::Animation2Weapon
	*/
	class Animation2Pose {
		public:
			void **vTable;
			int id; //!< ID of the pose
			DStringPtr name; //!< The name of the pose
			DStringPtr battleCharsetFilename; //!< The name of BattleCharSet file used for the poses
			int battleCharsetId; //!< The pose's index in the BattleCharSet file (0-7)
				int _unknown_14;
				int _unknown_18;
			PoseAnimationType_T animType; //!< The pose's animation type
			int battleAnimId; //!< the battle animation ID if animTYpe is set to RPG::PT_BATTLE_ANIMATION (See RPG::PoseAnimationType)
	};
	
}