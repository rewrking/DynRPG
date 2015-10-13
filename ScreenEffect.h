namespace RPG {
	/*! \brief Screen effects
		\sa RPG::Screen
	*/
	class ScreenEffect {
		public:
			void **vTable;
			/*! \brief Screen tint's red value
				
				Supported values are from \c 0 (completely black) to \c 200
				(completely red). \c 100 is the normal value. This value is
				changed during "Tint Screen" event commands.
			*/
			int tintR;
			
			/*! \brief Screen tint's green value
				
				Supported values are from \c 0 (completely black) to \c 200
				(completely green). \c 100 is the normal value. This value is
				changed during "Tint Screen" event commands.
			*/
			int tintG;
			
			/*! \brief Screen tint's blue value
				
				Supported values are from \c 0 (completely black) to \c 200
				(completely blue). \c 100 is the normal value. This value is
				changed during "Tint Screen" event commands.
			*/
			int tintB;
			
			/*! \brief Screen tint's saturation value
				
				Supported values are from \c 0 (completely desaturated) to \c 200
				(completely saturated). \c 100 is the normal value. This value is
				changed during "Tint Screen" event commands.
			*/
			int tintSaturation;
				int _unknown_14;
				int _unknown_18;
				int _unknown_1C;
				int _unknown_20;
				int _unknown_24;
				int _unknown_28;
				int _unknown_2C;
				int _unknown_30;
				int _unknown_34;
				
			/*! \brief Screen tint's transition timer (in frames)
				
				Start with the # of frames to transition from, and each frame will 
				count backwards. Keep in mind 1.0 Secs = 60 frames. This value is
				changed during "Tint Screen" event commands.
			*/
			int transitionTimer;
			int flashR;
			int flashG;
			int flashB;
				int _unknown_48;
				int _unknown_4C;
			int flashTimer;
			
			/*! \brief Shake strength
				
				Strength value used in "Shake Screen" command (0-9).
			*/
			int shakeStr; //!< Shake strength value used in "Shake Screen" command (0-9). Can be set higher than the default
			int shakeSpd; //!< Shake speed value used in "Shake Screen" command (0-9). Can be set higher than the default
			int shakeOffsetX; //!< The screen offset value during a "Shake Screen" command.
				int _unknown_60; // shakeOffsetY somehow?
			int shakeTimer;
			
			
			/*! \brief Built-in RM2k3 function to flash the screen (similar to the event command)
			    \param r Red value (0 to 31)
				\param g Green value (0 to 31)
				\param b Blue value (0 to 31)
				\param intensity Intensity of the flash (0 to 33.5)
				\param duration	Duration in frames
			*/
			void flash(int r, int g, int b, int intensity, int duration);
	};
	
	void RPG::ScreenEffect::flash(int r, int g, int b, int intensity, int duration) {
		asm volatile("push %%eax" : : "a" (b));
		asm volatile("push %%eax" : : "a" (intensity));
	    asm volatile("push %%eax" : : "a" (duration));	//duration in Frames
		asm volatile("push $0");						//? internally always zero
		asm volatile("call *%%esi"
			: "=a" (RPG::_eax), "=c" (RPG::_ecx), "=d" (RPG::_edx)
			: "S" (0x4C2D68), "a" (this), "c" (g), "d" (r)
			: "cc", "memory");
	}
	
}
	