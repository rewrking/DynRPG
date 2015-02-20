namespace RPG {

	// would be nice if this ItemTable class worked, so that one could use RPG::inventory->items[#]->id, RPG::inventory->items[#]->amount and RPG::inventory->items[#]->uses instead of RPG::inventory->items[#] RPG::inventory->itemitemAmount[#] and RPG::inventory->itemUses[#]
	// Need to research this more...
	/*class ItemTable {
		public:
			short id;
			char *amount;
			char *uses;
	};*/


	/*! \brief Used for the inventory data and statistics of the current game being played.

		\sa RPG::inventory
		\sa RPG::Item
		\sa RPG::items
	*/
	class Inventory {
		public:
			void **vTable;

			/*! \brief Similarly to RPG::Actor::partyMember(index), this returns the database value of the hero,
				however, you can also use this DArray to retrieve the party's size (RPG::inventory->party.size)

			*/
			DArray<short > party;
			//int partySize; // alternative to DArray
			//unsigned short *party; // alternative to DArray

			DArray<short > items; //!< Items in the inventory. Index is zero-based.
			//int partySize; // alternative to DArray
			//unsigned short *id; // alternative to DArray
			/*! \brief Amount of each item in the inventory.

				\note This points to the item's amount array, which shares the same size as RPG::Inventory::items.
				Therefore, you could do "for (int i=0; i<RPG::inventory->items[i]; i++)" to loop through all of the items,
				followed by RPG::inventory->itemAmount[i] to access the amounts.
				RPG::inventory->itemAmount[3] will get the amount of the fourth item.
			*/
			unsigned char *itemAmount;

			/*! \brief Uses count of each item in the inventory.

				\note This points to the item's uses array in memory, which shares the same size as RPG::Inventory::items, in the
				same manner as RPG::Inventory::itemAmount.
				The item's use value is set via "Number of Uses" in the database or RPG::Item::numUses.

				Assuming a Potion has 5 uses, and itemAmount is 3:

					itemUses = 0 -- The potion hasn't been used yet
					itemUses = 1 -- It's been used once, itemAmount hasn't decreased yet
					itemUses = 2 -- It's been used twice, itemAmount hasn't decreased yet
					itemUses = 3 -- It's been used three times, itemAmount hasn't decreased yet
					itemUses = 4 -- It's been used four times, itemAmount hasn't decreased yet

				On the fifth use, itemUses is reset to 0, and itemAmount decreases to 2.
			*/
			unsigned char *itemUses;

			/*! \brief Amount of gold the party holds.

				\note Max value: 999999. Any value higher will be automatically set to 999999.
			*/
			int goldAmount;
			Image *partyFaceImage[4]; //!< Array for the facesets of the 4 party members
			int timerOneTicks; //!< Number of ticks in the first timer
			bool timerOneRunning; //!< Is the first timer running?
			bool timerOneVisible; //!< Is the first timer visible?
			bool timerOneBattle; //!< Can the first timer be displayed in battle?
			int numBattles; //!< Total number of battles
			int numVictories; //!< Total number of victories
			int numDefeats; //!< Total number of defeats
			int numEscapes; //!< Total number of escapes
			int numTurns; //!< Total number of battle turns?
			int numSteps; //!< Total umber of steps taken
			int timerTwoTicks; //!< Number of ticks in the second timer
			bool timerTwoRunning; //!< Is the second timer running?
			bool timerTwoVisible; //!< Is the second timer visible?
			bool timerTwoBattle; //!< Can the second timer be displayed in battle?

			/*! \brief Checks if a particular RPG::Actor is in the party.

				\param databaseId The database ID of the actor.
				\return If the actor is in the party, their party index is returned (0-3), otherwise -1 is returned.
			*/
			int getPartyIndex(int databaseId);

			/*! \brief Built-in RM2k3 function that adds an item to the inventory
				\param id The database ID of the item
				\param amount Amount of the item to add
			*/
			void addItem(int id, int amount);
			
			/*! \brief Built-in RM2k3 function that removes an item to the inventory
				\param id The database ID of the item
				\param amount Amount of the item to add
			*/
			void removeItem(int id, int amount);
			/*! \brief Built-in RM2k3 function that increments an items use count by one if it's set to more than one use
				\param id The database ID of the item
			*/
			void incrementItemUses(int id);
	};

	/*! \ingroup game_objects
		\brief The player's inventory (items, # of items, uses), and party statistics

		Example:
		\code
int goldAmount = RPG::inventory->goldAmount;
		\endcode
		\sa RPG::items
	*/
	static RPG::Inventory *&inventory = (**reinterpret_cast<RPG::Inventory ***>(0x4CDB74));


	void RPG::Inventory::addItem(int id, int amount) { 
		asm volatile("call *%%esi"
			:
			: "S" (0x4A620C), "a" (this), "d" (id), "c" (amount)
			: "cc", "memory");
	}
	
	void RPG::Inventory::removeItem(int id, int amount) { 
		asm volatile("call *%%esi"
			:
			: "S" (0x4A6308), "a" (this), "d" (id), "c" (amount)
			: "cc", "memory");
	}
	
	void RPG::Inventory::incrementItemUses(int id) { 
		asm volatile("call *%%esi"
			:
			: "S" (0x4A63BC), "a" (this), "d" (id)
			: "cc", "memory");
	}

	int getPartyIndex(int databaseId) {
		// Do not loop more times than the size of the party
		for (int i=0; i<RPG::inventory->party.size; i++){
			// if the party's id matches the database ID of the hero being checked for
			if (RPG::inventory->party[i] == databaseId){
				return i;
			}
		}
		return -1;
	}

}


