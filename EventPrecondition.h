namespace RPG {
	//! Possible values for the RPG::EventPrecondition::flag member
	enum EventPreconditionFlag {
		EPF_NONE = 0,
		EPF_SWITCH_A = 1,
		EPF_SWITCH_B = 2,
		EPF_VARIABLE = 4,
		EPF_ITEM = 8,
		EPF_HERO = 16,
		EPF_TIMER1 = 32,
		EPF_TIMER2 = 64
	};
	
	//! One-byte version of RPG::EventPreconditionFlag
	typedef unsigned char EventPreconditionFlag_T;
	
	//! Possible values for the RPG::EventPrecondition::varLogic member
	enum EventPreconditionVarLogic {
		EPVL_EQUAL,
		EPVL_GREATER_EQUAL,
		EPVL_LESS_EQUAL,
		EPVL_GREATER,
		EPVL_LESS,
		EPVL_NOT_EQUAL
	};
	
	/*! \brief The preconditions for a particular event page

		\sa RPG::EventPage
		\sa RPG::EventData
		\sa RPG::EventPreconditionFlag
		\sa RPG::EventPreconditionVarLogic
	*/
	class EventPrecondition {
		public:
			void **vTable;
			EventPreconditionFlag_T flag; //!< Precondition flags (can be combined)
			int switchId[2]; //!< The IDs of switches A & B
			int variableId; //!< The ID of the variable to trigger
			int variableValue; //!< The variable trigger will be above this value
			int itemId; //!< Database ID of item
			int HeroId; //!< Database ID of hero
			int TimerValue[2]; //!< The values of timers 1 & 2 (in seconds)
			EventPreconditionVarLogic varLogic; //!< The variable's logic (equal/greater/less etc.)

	};
}
