namespace RPG {
	struct WeatherParticle {
		int t; //!< Particle time left
		int x; //!< Particle x positon
		int y; //!< Particle y position

		int alpha; //!< Particle alpha factor 0: fully transparent, 255: fully opaque (sandstorm only)
		double vx; //!< Particle x velocity (sandstorm only)
		double vy; //!< Particle y velocity (sandstorm only)
		double ax; //!< Particle x acceleration (sandstorm only)
		double ay; //!< Particle y accelration (sandstorm only)
	};

	/*! \brief Screen effects
		\sa RPG::Screen
	*/
	class ScreenEffect {
		public:
			void **vTable;
			/*! \brief Screen tint's final red value
				
				Supported values are from \c 0 (completely black) to \c 200
				(completely red). \c 100 is the normal value. This value is
				changed during "Tint Screen" event commands.
			*/
			int tintFinalR;

			/*! \brief Screen tint's final green value
				
				Supported values are from \c 0 (completely black) to \c 200
				(completely green). \c 100 is the normal value. This value is
				changed during "Tint Screen" event commands.
			*/
			int tintFinalG;

			/*! \brief Screen tint's final blue value
				
				Supported values are from \c 0 (completely black) to \c 200
				(completely blue). \c 100 is the normal value. This value is
				changed during "Tint Screen" event commands.
			*/
			int tintFinalB;

			/*! \brief Screen tint's final saturation value
				
				Supported values are from \c 0 (completely desaturated) to \c 200
				(completely saturated). \c 100 is the normal value. This value is
				changed during "Tint Screen" event commands.
			*/
			int tintSaturation;

			double tintCurrentR; //!< current red value in tint screen animation.
			double tintCurrentG; //!< current green value in tint screen animation.
			double tintCurrentB; //!< current blue value in tint screen animation.
			double tintCurrentSaturation; //<! current saturation valye in tint screen animation.

			/*! \brief Screen tint's transition timer (in frames)
				
				Start with the # of frames to transition from, and each frame will 
				count backwards. Keep in mind 1.0 Secs = 60 frames. This value is
				changed during "Tint Screen" event commands.
			*/
			int transitionTimer;
			int flashR; //!< Red value during "Flash Screen"
			int flashG; //!< Green value during "Flash Screen"
			int flashB; //!< Blue value during "Flash Screen"
			double flashIntensity; //<!Strength fo current flash
			
			/*! \brief "Flash Screen" timer (in frames)
				
				Start with the # of frames to transition from, and each frame will 
				count backwards. Keep in mind 1.0 Secs = 60 frames. This value is
				changed during "Flash Screen" event commands.
			*/
			int flashTimer;
			
			/*! \brief Shake strength
				
				Strength value used in "Shake Screen" command (0-9).
			*/
			int shakeStr; //!< Shake strength value used in "Shake Screen" command (0-9). Can be set higher than the default
			int shakeSpd; //!< Shake speed value used in "Shake Screen" command (0-9). Can be set higher than the default
			int shakeOffsetX; //!< The screen offset value during a "Shake Screen" command.
			int shakeOffsetY; //!< An unused Y offset for a vertical Shake Screen. Affects the screen, but gets reset to 0 every frame.
			
			/*! \brief "Shake Screen" timer (in frames)
				
				Start with the # of frames to transition from, and each frame will 
				count backwards. Keep in mind 1.0 Secs = 60 frames. This value is
				changed during "Shake Screen" event commands.
			*/
			int shakeTimer;
			
			
			/*! \brief Built-in RM2k3 function to flash the screen (similar to the event command)
			    \param r Red value (0 to 31)
				\param g Green value (0 to 31)
				\param b Blue value (0 to 31)
				\param intensity Intensity of the flash (0 to 33.5)
				\param duration	Duration in frames
			*/
			void flash(int r, int g, int b, int intensity, int duration);

			int _unknown_68; // Always some big number?
			int _unknown_6C; // Always 0?
			int _unknown_70; // Always 0?
			int _unknown_74; // Always 0?
			int animationId; //<! Currently active battle animation id
			int _unknown_7C; // Always 0?
			int animationCurrentFrame; //<! Current animation id frame
			int animationActive; //<! Whether or not animation is active
			int _unknown_88; //Always 38073260?

			/*! \brief Which weather effect is active
			    0 - None
				1 - Rain
				2 - Snow
				3 - Fog
				4 - Sandstorm
			*/
			int weather_type;
			/*! \brief the strength level of the current weather effect

				Valid values are 0,1, and 2. Values >= 3 work but produce glitchy effects.
			*/
			int weather_strength;

			int _unknown_94; // Always 0?


			/*! \brief Particles used for weather effects

				Rain and Snow use 100 particles and only t, x, and y.
				Fog uses the first 2 particles for the 2 fog layer movement and uses only x.
				Sandstorm uses the first 2 particles the same as fog and the remaining 253 particles and all the fields for the move sand particles.
			*/
			WeatherParticle weather_particles[255];

			int fog_back_opacity; //<! Opacity for the back fog layer. Values are based on strength:  0->32, 1->64, 2->96
			int fog_front_opacity; //<! Opacity for the front fog layer. Values are based on strength: 0->64, 1->80, 2->160

			/*! \brief the image used for the fog effect

				This 16x18 texture is randomly generated each time RPG_RT starts.
				It is used for both font and back fog layers.
			*/
			Image* fog_image;

			double continuousFlashIntensity; //!< Value to reset flash intensity when continuous flash repeats
			int continuousFlashTimer; //!< Value to reset flashTimer when continuous flash repeats
			int continuousFlashEnabled; //!< True if continuous flash is enabled.
			int continuousShakeEnabled; //!< True if continuous shake is enabled.
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

