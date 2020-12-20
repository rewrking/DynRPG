namespace RPG {
	/*! \brief Used for an animation frame's cel data.
		\sa RPG::AnimationFrame
		\sa RPG::Animation
		\sa RPG::battleAnimations
	*/
	class AnimationFrameCel {
		public:
			void **vTable;
			int id; //!< ID of the cel (1 to 8)
				int _unknown_08;
			
			/*! \brief Does the cel still exist in the editor? (1 if exists, 0 if deleted)
	
				The cels array holds onto deleted cels (ugh, why?)
			*/
			bool notDeleted; //!< 1 in most cases. Does the animation cel still exist? (wow...)
			int imageSection; //!< The image section of the battle animation graphic
			int xPos; //!< The x-position of the cel
			int yPos; //!< The y-position of the cel
			int magnification; //!< The cel's magnification value This is 20-800 by default, but other values may be possible.
			int red; //!< Red intensity (0-200)
			int green; //!< Green intensity (0-200)
			int blue; //!< Blue intensity (0-200)
			int saturation; //!< Saturation level (0-200)
			int transparency;  //!< Transparency level (0-100)

	};
}