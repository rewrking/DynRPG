namespace RPG {
    //! Possible values for RPG::EventPage::charsetDir and RPG::Character::facing
	enum Facing { // Moved from Character.h
		FACE_UP, //!< %Character looks up
		FACE_RIGHT, //!< %Character looks to the right
		FACE_DOWN, //!< %Character looks down
		FACE_LEFT //!< %Character looks to the left
	};

	//! One-byte version of RPG::Facing
	typedef unsigned char Facing_T;

	//! Possible values for the RPG::EventPage::charsetFrame member
	enum EventFrame {
		EF_LEFT,
		EF_MIDDLE,
		EF_RIGHT
	};

	//! Possible values for the RPG::EventPage::moveSpeed member
	enum EventMoveFrequency {
		EMS_ONE_EIGHTH_NORMAL = 1,
		EMS_ONE_FOURTH_NORMAL,
		EMS_ONE_HALF_NORMAL,
		EMS_NORMAL,
		EMS_TWICE_NORMAL,
		EMS_FOUR_TIMES_NORMAL
	};

	/*! \brief Used for pages within a map event, along with their conditions, script list, commands, etc.

		\sa RPG::EventData
		\sa RPG::EventPrecondition
		\sa RPG::Facing
		\sa RPG::EventFrame
		\sa RPG::MoveRoute
	*/
	class EventPage {
		public:
			void **vTable;
			int id;
				int _unknown_08;
				int _unknown_0C;
				UnknownPointer *_unknown_10;
			EventScriptList *scriptLines; //!< The event script lines! (See RPG::EventScriptList)
			EventPrecondition *preconditions; //!< The event's preconditions (See RPG::MapEventPrecondition)
			DStringPtr charsetFilename; //!< The filename of the charset used for the event graphic
			int charsetId; //!< The ID of the character within the charset (0-7)
			Facing charsetDir; //!< The direction the charset is facing in
			EventFrame charsetFrame; //!< The starting frame of animation for the charset (See RPG::EventFrame)
			bool isTransparent;
			int moveSpeed; //!< The event's movement speed (1-8)
				UnknownPointer *_unknown_34;
			EventMoveFrequency moveFrequency; //!< The event's movement frequency (See RPG::EventMoveFrequency)
			MoveRoute *moveRoute; //!< The move route of the event

			// WHERE'S MOVEMENT TYPE, FORBID EVENT OVERLAP, TRIGGER CONDITION, EVENT LAYER
			// AAAAH WHY AM I YELLING
	};
}
