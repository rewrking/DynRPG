namespace RPG {

// Functions added in the 0.30 update
// ==================================

	/*! \brief Built-in RM2k3 function that gets a random number between 1 and the specified number
		\param maxValue the maximum number to return
		\return A random number between 1 and the specified number
	*/
	static int getDiceRoll(int maxValue) { // 2k3 function that gets a random number from 0 to maxValue
		int out;
		asm volatile("call *%%esi" : "=a" (out) : "S" (0x403054), "a" (maxValue) :"cc", "memory");
		// If maxValue is 20, by default, 19 is the actual max that will be returned by the function, so out+1 is returned below
		// This also ensures 1 is returned instead of 0, to simulate actual dice rolls
		return out+1;
	}

	/*! \brief Goes directly to the title screen.
	*/
	static void goToTitle() {
		asm volatile("call *%%esi"
			:
			: "S" (0x46BC00)
			: "cc", "memory");
	}

	/*! \brief Built-in RM2k3 function that gets the party's average agility in battle
		\return The agility average of the party
	*/
	static int getAvgPartyAgl() {
		int out;
		asm volatile("call *%%esi"
			: "=a" (out)
			: "S" (0x4A690C), "a" (RPG::inventory) // It doesn't make sense to put this function in inventory, even though it references it
			: "cc", "memory");
		return out;
	}

	/*! \brief Built-in RM2k3 function that gets the monster party's average agility in battle
		\return The agility average of the monster party
	*/
	static int getAvgMonsterPartyAgl() {
		int out;
		asm volatile("call *%%esi"
			: "=a" (out)
			: "S" (0x4BEDF4), "a" (RPG::inventory) // It doesn't make sense to put this function in inventory, even though it references it
			: "cc", "memory");
		return out;
	}

	void Image::drawString(int x, int y, std::string text, int color)
	{
		RPG::DStringPtr *par2 = new DStringPtr(text); // *cue holy music*
		asm volatile("push %%eax" 
			: 
			: "a" (y));
		asm volatile("push %%eax" 
			: 
			: "a" (par2->str));
		asm volatile("push %%eax" 
			: 
			: "a" (color));
		asm volatile("call *%%esi" 
			: 
			: "S" (0x4892AC), "a" (RPG::system->systemGraphic), "d" (this), "c" (x) 
			: "cc", "memory");
	}


	/*void drawText(RPG::Window *window, int x, int y, std::string text, int color) { // doesn't work correctly yet
		asm volatile("push %%eax"
			:
			: "a" (y));
		asm volatile("push %%eax"
			:
			: "a" (text.c_str()));
		asm volatile("push %%eax"
			:
			: "a" (color));
		asm volatile("call *%%esi"
			:
			: "S" (0x4892AC), "a" (RPG::system->systemGraphic), "d" (window), "c" (x)
			: "cc", "memory");
	}*/

}
