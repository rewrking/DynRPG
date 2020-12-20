namespace RPG {
	//! Possible values for the RPG::CommonEvent::trigger member
	enum CommonEventTrigger {
		CET_AUTO_START = 3,
		CET_PARALLEL_PROCESS,
		CET_CALL
	};
	
	//! One-byte version of RPG::CommonEventTrigger
	typedef unsigned char CommonEventTrigger_T;

	/*! \brief Access to the common events. 
		\sa RPG::commonEvents
		\sa RPG::CommonEventTrigger
	*/
	class CommonEvent {
		public:
			void **vTable;
			int id; //!< The ID of the common event
			DStringPtr name; //!< The name of the common event
				int _unknown_0C;
				int _unknown_10;
			EventScriptList *scriptLines; //!< The event script lines
			CommonEventTrigger_T trigger; //!< The trigger condition for the common event
			bool switchActivated; //!< Is the common event activated via switch?
			int switchId; //!< The switch ID if activated via switch
			
	};

	/*! \ingroup game_objects
		\brief Access to the common events. 
	*/
	static RPG::NamedCatalogPtr<RPG::CommonEvent *> &commonEvents = (**reinterpret_cast<RPG::NamedCatalogPtr<RPG::CommonEvent *> **>(0x4CDF40));
	
	/*! \brief Easily returns a common event line.

		Allows you to write <tt>RPG::getCommonEventLine(12,1)->command</tt> instead of <tt>RPG::commonEvents[12]->scriptLines->list->items[1]->command</tt> which gets the 2nd line of common event 12.
		
		\param id The common event ID (one-based)
		\param lineId The line ID (zero-based)

		\sa RPG::CommonEvent
	*/
	RPG::EventScriptLine *getCommonEventLine(int id, int lineId) {
		return commonEvents[id]->scriptLines->list->items[lineId];
	}
}
