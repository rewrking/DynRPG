namespace RPG {
	
	//! Possible values for RPG::AnimationEffect::flashScope and RPG::AnimationEffect::shakeScope
	enum AnimationEffectScope {
		ANIM_EFFECT_SCOPE_NONE,
		ANIM_EFFECT_SCOPE_TARGET,
		ANIM_EFFECT_SCOPE_SCREEN
	};

	//! One-byte version of RPG::AnimationScope
	typedef unsigned char AnimationEffectScope_T;
	
	/*! \brief Used to define an animation's effect from its effect array.
		\sa RPG::AnimationEffectScope
		\sa RPG::Animation
		\sa RPG::battleAnimations

	*/
	class AnimationEffect {
		public:
			void **vTable;
			int id; //!< ID of the animation effect
				int _unknown_08;
			int startFrame; //!< The frame the animation effect starts on
			Sound *soundEffect; //!< The sound effect 
			AnimationEffectScope_T flashScope; //!< The flash scope of the animation effect (See RPG::AnimationEffectScope)
				bool _unknown_15;
				bool _unknown_16;
				bool _unknown_17;
			int red; //!< The red value
			int green; //!< The green value
			int blue; //!< The blue value
			int magnitude; //!< The strength of the color effect
			AnimationEffectScope_T shakeScope; //!< The shake scope of the animation effect (See RPG::AnimationEffectScope)

	};
}