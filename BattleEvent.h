namespace RPG {
	//! Stub
	typedef void BattleEventScriptData;

	/*! \brief Used to access battle event parameters (NOT the scriptlines).

		\sa RPG::battleEvents
	*/
	class BattleEvent {
		public:
			void **vTable;
			BattleEventScriptData *eventData; //!< Stub. Use RPG::getBattleEventLine(monsterGroup,battleEventPage,lineId) to access battle event data
			char _unknown_08;
			char _unknown_09;
			char _unknown_0A;
			bool key_input_wait;
			int key_input_variable;
			bool key_input_all_direction;
			bool key_input_decision;
			bool key_input_cancel;
#if RPG_RT_ENGINE == 2000
			bool key_input_shift_2k;
			bool key_input_down_2k; // In 2k3, this is wait frame for wait command
			bool key_input_left_2k;
			bool key_input_right_2k;
			bool key_input_up_2k;
			int wait_command_wait;
			int _unknown_1C;
#elif RPG_RT_ENGINE == 2003
			bool _unknown_13;
			int wait_command_wait;
			bool command_wait_wait_for_key;
			bool key_input_timed;
			int key_input_time_variable;
			int key_input_timed_frames;
			bool key_input_numbers;
			bool key_input_operators;
			bool key_input_shift_2k3;
			bool key_input_down_2k3;
			bool key_input_left_2k3;
			bool key_input_right_2k3;
			bool key_input_up_2k3;
			char _unknown_2B; // unused?
#endif // RPG_RT_ENGINE == 2003
			bool eventPageDone[100]; //!< Determines whether a particular battle event page has finished executing
	};

	/*! \ingroup game_objects
		\brief Battle event data.

		Example:
		\code
std::string temp = RPG::battleEvents->eventPageDone[0]);
		\endcode
	*/
	static RPG::BattleEvent *&battleEvents = (**reinterpret_cast<RPG::BattleEvent ***>(0x4CDB10));
}

