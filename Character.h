namespace RPG {

	//! Possible values for RPG::Character::direction
	enum Direction {
		DIR_UP, //!< %Character moves down
		DIR_RIGHT, //!< %Character moves to the right
		DIR_DOWN, //!< %Character moves down
		DIR_LEFT, //!< %Character moves to the left
		DIR_UP_RIGHT, //!< %Character moves diagonally up-right
		DIR_DOWN_RIGHT, //!< %Character moves diagonally down-right
		DIR_DOWN_LEFT, //!< %Character moves diagonally down-left
		DIR_UP_LEFT //!< %Character moves diagonally up-left
	};

	//! One-byte version of RPG::Direction
	typedef unsigned char Direction_T;

	//! Possible values for RPG::Character::animationType
	enum AnimationType {
		ANI_NORMAL, //!< "Non-continuous"
		ANI_STEPPING, //!< "Continuous" (always stepping)
		ANI_FIXED_DIR_NORMAL, //!< "Non-continous", fixed direction
		ANI_FIXED_DIR_STEPPING, //!< "Continuous", fixed direction
		ANI_FIXED_GRAPHIC, //!< Fixed graphic (no stepping, fixed direction)
		ANI_SPIN_AROUND //!< Spinning around
	};

	//! One-byte version of RPG::AnimationType
	typedef unsigned char AnimationType_T;

	//! Possible values for RPG::Character::step
	enum AnimationFrameCharset {
		ANI_FRAME_LEFT,
		ANI_FRAME_MIDDLE_A,
		ANI_FRAME_RIGHT,
		ANI_FRAME_MIDDLE_B
	};

	//! Possible values for RPG::Character::layer
	enum Layer {
		LAYER_BELOW_HERO, //!< Below hero
		LAYER_SAME_LEVEL_AS_HERO, //!< Same level as hero
		LAYER_ABOVE_HERO //!< Above hero
	};

	//! One-byte version of RPG::Layer
	typedef unsigned char Layer_T;

	/*! \brief Used for movable entities on the map, i.e. events, the hero (and vehicles, but they are not supported yet)
		\sa RPG::Event
		\sa RPG::Map::events
		\sa RPG::Hero
		\sa RPG::hero
		\sa RPG::Direction
		\sa RPG::Facing
		\sa RPG::Layer
		\sa RPG::AnimationType
		\sa RPG::MoveRoute
	*/
	class Character {
		public:
			void **vTable;
			int id; //!< ID of the event (zero if not an ordinary event)
				int _unknown_8;
			bool enabled; //!< Is the event visible and enabled?
			int mapId; //!< %Map ID (only relevant for vehicles which are not supported yet)
			int x; //!< X coordinate (tiles)
			int y; //!< Y coordinate (tiles)
			Direction_T direction; //!< Direction for moving (see RPG::Direction)
			Facing_T facing; //!< Direction for facing (see RPG::Facing)
			/*! \brief Current step value (see details)

				Possible values:
					<ul><li>\c 0: Left</li>
					<li>\c 1: Middle</li>
					<li>\c 2: Right</li>
					<li>\c 3: Middle</li></ul>
			*/
			AnimationFrameCharset step; //!< The stepping frame of the charset graphic
			int transparency; //!< Transparency value, between \c 0 (completely visible) to \c 8 (completely invisible)
			/*! \brief Frames left until movement is completed (see details)

				This value is zero if the movement is completed. Otherwise it
				means the frames left until it is completed. This value,
				together with \ref direction, is used to calculate the current
				screen coordinates.
			*/
			int movementFramesLeft;
			int frequency; //!< Current movement frequency (\c 1 to \c 8)
			int originalFrequency; //!< Original movement frequency (use for "Move event" commands with a frequency different from the current one)
			Layer_T layer; //!< %Layer (below/same level as/above hero, see RPG::Layer)
			bool forbidEventOverlap; //!< \c true if the event cannot move onto a tile occupied by another event
			/*! \brief Animation type of the event (see details and RPG::AnimationType)

				This member is used for the animation type as defined in the
				event editor. However, it does not control whether the facing
				is locked or not, i.e. if you set it to RPG::ANI_FIXED_GRAPHIC,
				the event may still not have locked facing. Thus, you should
				use the \ref setAnimationType function which automatically sets
				the \ref fixedDirection member to the correct value.
				\sa setAnimationType
				\sa RPG::AnimationType
			*/
			AnimationType_T animationType;
			bool fixedDirection; //!< Is the facing direction (\ref facing) fixed?
			int speed; //!< Current speed of the character (\c 1 to \c 6, see also \ref customExactSpeed)
			MoveRoute *moveRoute; //!< Current move route (can also be set by "Move Event" commands)
			bool moving; //!< Is the character currently moving?
			/*! \brief Horizontal offset for drawing the event graphic (see details)

				The \ref offsetX and \ref offsetY members can be used to control
				the screen coordinates on which the event is drawn. You specify
				an offset value which will be added to the normal value.

				For example, you might set <tt>offsetX = 8</tt> and
				<tt>offsetY = -16</tt> - and then the event will always be
				drawn 8 pixels to the right and 16 pixels higher than it would
				normally be. This way, you can do a finer movement and even
				do a "fake" pixel movement.

				\note This is a special feature of the DynRPG patch.
			*/
			char offsetX;
			char offsetY; //!< Vertical offset for drawing the event graphic (see \ref offsetX)
			/*! \brief Custom exact speed (see details)

				You can the speed of a character in a finer way than the normal
				six speed values provide. One speed unit means 3.75 pixels per
				second (or 1/16 pixel per frame). For example
				<tt>customExactSpeed = 20</tt> will set the speed to 75 pixels
				per second (1.25 pixels per frame).

				If you set \ref customExactSpeed to \c 0, the speed which is set
				in \ref speed will be used.
				\note This is a special feature of the DynRPG patch.
			*/
			char customExactSpeed;
			int moveRoutePosition; //!< Position in move route
			bool moveRouteDone; //!< Has the move route finished?
				bool isHidden; //!< Only works on hero. Determine if hidden.
				bool slipThrough;
				bool stopAnimation;
			bool phasing; //!< Is the "phasing mode" on?
			int stepFrameCounter; //!< Internally used, for stepping
			int stepTimer; //!< Internally used, for stepping (\c -1 if a fixed step is used, see \ref setFixedStep)
			int frequencyTimer; //!< Internally used, for movement frequency
			bool eventJumping; //!< Is the event jumping?
			int beforeJumpX; //!< Map's X value Before jumping
			int beforeJumpY; //!< Map's Y value Before jumping
			bool isFlying; //!< Flying flag for airship
			DStringPtr charsetFilename; //!< Filename of the current charset
			int charsetId; //!< ID of the current charset
			bool onMap;
			int flashR; //!< The red value for sprite flashing
			int flashG; //!< The green value for sprite flashing
			int flashB; //!< The blue value for sprite flashing
				int _unknown_84; // Strength slider?
			int flashIntensity; //!< This is not the same as strength/power
				int _unknown_8C;
			int flashTimer; //!< The flash timer. Starts at time*6 & decreases each frame
			// Continues to RPG::Hero

			int getScreenX(); //!< Returns the current X screen coordinate
			int getScreenY(); //!< Returns the current Y screen coordinate

			/*! \brief Sets a fixed step

				You can use this function to set a fixed step position and keep
				it until \ref setNormalStep is called.
				\param newStep New step position, for possible values see
				\ref step
				\note This is a special feature of the DynRPG Patch.
				\sa setNormalStep
				\sa step
			*/
			void setFixedStep(int newStep);

			/*! \brief Removes a fixed step position and goes back to normal
				\sa setFixedStep
			*/
			void setNormalStep();

			/*! \brief Sets the animation type

				This function sets the \ref animationType and \ref fixedDirection
				members to the correct values.
				\param type New animation type
				\sa animationType
				\sa RPG::AnimationType
			*/
			void setAnimationType(RPG::AnimationType type);

			/*! \brief Checks whether a certain move is possible

				This function if the character will be able to complete a
				certain move, taking event layer, \ref forbidEventOverlap, other
				blocking events and the tileset attributes into account.
				\param fromX X coordinate (tiles) of the source position
				\param fromY Y coordinate (tiles) of the source position
				\param toX X coordinate (tiles) of the destination position
				\param toY Y coordinate (tiles) of the destination position
				\return \c true if the move is possible, otherwise \c false
				\warning This is an experimental function.
			*/
			bool isMovePossible(int fromX, int fromY, int toX, int toY);

			/*! \brief Returns the name of the character

				This function returns the event name which was set in the event
				editor or the name of the first actor in the party in case the
				character is the hero.
				\return The name of the character (event or hero name)
			*/
			std::string getName();

			/*! \brief Moves a character

				This function will move a character (event or hero) the same
				way the "Move event" command does.

				The \c data parameter is a pointer to a \c char array containing
				the encoded data. You can find a list of possible movement
				commands at the RPG::MoveType documentation. For most
				movement commands, you will just use one byte containing the
				move type.

				Example:
				\code
char moves[] = {RPG::MT_MOVE_UP, RPG::MT_MOVE_RIGHT, RPG::MT_MOVE_RIGHT, RPG::MT_TURN_RANDOMLY, RPG::MT_MOVE_FORWARD};
RPG::hero->move(moves, sizeof(moves));
				\endcode

				There are, however, a few commands which take parameters:
				RPG::MT_SWITCH_ON, RPG::MT_SWITCH_OFF, RPG::MT_CHANGE_GRAPHIC
				and RPG::MT_PLAY_SE. If you want to use these commands, you
				better use a \c std::string. You need to add the parameters to
				the string right after the command byte, using the functions
				\ref RPG::encode(int) for numerical parameters and
				\ref RPG::encode(std::string) for string parameters.

				Example:
				\code
std::string moves = "";
moves += (char)RPG::MT_MOVE_UP;
moves += (char)RPG::MT_FACE_DOWN;
moves += (char)RPG::MT_PLAY_SE;
moves += RPG::encode("chicken"); // filename
moves += RPG::encode(100); // volume
moves += RPG::encode(100); // speed
moves += RPG::encode(50); // pan
moves += (char)RPG::MT_WAIT;
moves += (char)RPG::MT_TURN_AROUND;
RPG::hero->move(moves.c_str(), moves.length());
				\endcode
				\param data Pointer to the movement data
				\param length Length of the movement data
				\param repeatPattern \c true if the pattern should be repeated
				until \ref stop is called
				\param ignoreImpossible Should impossible movements be ignored?
				\param frequency Frequency of the movement
				\note RPG::MT_INCREASE_FREQUENCY and RPG::MT_DECREASE_FREQUENCY
				commands will not take permanent effect after the movement
				ended unless the movement was started with the same frequency
				as in the \ref frequency member of the character.
				\warning This is an experimental function.
				\sa RPG::MoveType
				\sa stop
				\sa doStep
			*/
			void move(const char* data, int length, bool ignoreImpossible = true, bool repeatPattern = false, int frequency = 8);

			/*! \brief Stops the current movement
				\warning This is an experimental function.
				\sa move
			*/
			void stop();

			/*! \brief Does one step (moves the character one tile into a certain direction)
				\param direction Direction to move into
				\warning This is an experimental function.
				\sa move
			*/
			void doStep(RPG::Direction direction);
	};

	//class EventData moved to EventData.h class file

	/*! \brief Used for events as subtype of characters
		\sa RPG::Map::events
	*/
	class Event : public Character {
		public:
			// sizeof(Character) == 0x94
				int _unknown_94;
			EventData *data; //!< Pointer to the RPG::EventData of this event
			EventPage *currentPage; //!< The currently loaded event page
			bool isWaiting; //!< Is the event waiting?
				int _unknown_A4;
				int _unknown_AC; // Pointer to More scriptData? See 
			
			/*! \brief Checks whether a certain event page exists

				This function may be used to check for a certain event page
				prior to calling it.
				\param id Event page to check
				\return \c true if the event page exists, \c false otherwise
			*/
			bool doesEventPageExist(int id);
	};

	//! Possible values for RPG::Hero::vehicle and RPG::Vehicle::type
	enum HeroVehicle {
		HV_NONE, //!< Hero is in no vehicle
		HV_SKIFF, //!< Hero is in the skiff
		HV_SHIP, //!< Hero is in the ship
		HV_AIRSHIP //!< Hero is in the airship
	};

	//! Hero control mode (see RPG::Hero::setControlMode)
	enum HeroControlMode {
		CONTROL_EVERYTHING, //!< Everything works normally
		CONTROL_EVERYTHING_EXCEPT_MOVEMENT, //!< Opening menu and activating events works, but movement is disabled
		CONTROL_NOTHING //!< No control possible (checking key state still works, of course)
	};

	//! Hero pan speed (see RPG::Hero::panTransitionSpeed)
	enum HeroPanTransitionSpeed {
		HPTS_ONE_EIGHTH_NORMAL = 4,
		HPTS_ONE_FOURTH_NORMAL = 8,
		HPTS_ONE_HALF_NORMAL = 16,
		HPTS_NORMAL = 32,
		HPTS_TWICE_NORMAL = 64,
		HPTS_FOUR_TIMES_NORMAL = 128
	};

	/*! \brief Used for the hero as subtype of characters
		\sa RPG::hero
	*/
	class Hero : public Character {
		public:
			// sizeof(Character) == 0x94
				int _unknown_94;
			bool isEnteringVehicle; //!< Only true if the hero is entering a vehicle
			bool isInVehicle; //!< True when the hero has entered a vehicle
			HeroVehicle vehicle; //!< Tells you whether the hero is in a vehicle at the moment
			bool isLeavingVehicle; //!< Only true if the hero is dismounting a vehicle
				int _unknown_A4;
				bool _unknown_A8;
			bool screenPanUnlocked; //!< Can screen panning be used?
			int mapOffsetX; // ??
			int mapOffsetY; // ??
			int mapHeroOffsetX; //!<  (default = 9*256) ??
			int mapHeroOffsetY; //!<  (default = 7*256) ??
			HeroPanTransitionSpeed panTransitionSpeed; //!< Same as Pan Screen Transition Speed^4 (4: Normal would be 16)
				int _unknown_C0;
				int _unknown_C4;
				int _unknown_C8;
				int _unknown_CC;

			/*! \brief Returns the current hero control mode
				\note This is a special feature of the DynRPG patch.
				\return Current control mode
				\sa setControlMode
			*/
			RPG::HeroControlMode getControlMode();

			/*! \brief Sets the hero control mode
				\note This is a special feature of the DynRPG patch.
				\param controlMode The new control mode
				\sa getControlMode
			*/
			void setControlMode(RPG::HeroControlMode controlMode);
	};

	/*! \ingroup game_objects
		\brief The hero (which moves around on the map, similar to an event)
	*/
	static RPG::Hero *&hero = (**reinterpret_cast<RPG::Hero ***>(0x4CDE54));

	/*! \brief Used for the vehicles as subtype of characters
		\sa RPG::hero
	*/
	class Vehicle : public Character {
		public:
			HeroVehicle type; //!< The id of the vehicle
			int takeOffTimer; //!< Timer for when taking off. 256-0 when rising into the air (if HeroVehicle is HV_AIRSHIP)
			int landingTimer; //!< Timer for landing. 256-0 when rising into the air (if HeroVehicle is HV_AIRSHIP)
	};

	/*! \ingroup game_objects
		\brief The skiff vehicle (which moves around on the map, similar to an event)
	*/
	static RPG::Vehicle *&vehicleSkiff = (**reinterpret_cast<RPG::Vehicle ***>(0x4CE00C));
	/*! \ingroup game_objects
		\brief The ship vehicle (which moves around on the map, similar to an event)
	*/
	static RPG::Vehicle *&vehicleShip = (**reinterpret_cast<RPG::Vehicle ***>(0x4CE034));
	/*! \ingroup game_objects
		\brief The airship vehicle (which moves around on the map, similar to an event)
	*/
	static RPG::Vehicle *&vehicleAirship = (**reinterpret_cast<RPG::Vehicle ***>(0x4CDE68));
}
