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

	/*static void openOrderMenu() {
		asm volatile("call *%%esi"
			:
			: "S" (0x4A0104)
			: "cc", "memory");

	}*/

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

	void Window::drawString(int x, int y, std::string text, int color, bool initialize)
	{
		RPG::DStringPtr *par1 = new DStringPtr(text); // *cue holy music*
		asm volatile("push %%eax"
			:
			: "a" (par1->str));
		asm volatile("push %%eax"
			:
			: "a" (color));
		asm volatile("push %%eax"
			:
			: "a" (initialize));
		asm volatile("call *%%esi"
			:
			: "S" (0x4C6EA8), "a" (this), "d" (x), "c" (y)
			: "cc", "memory");
		delete par1;
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

	static bool doesSaveExist(int id) {
		int eax = ( *reinterpret_cast<int **> (0x4CDF20) )[0];
		bool out = false;
		asm volatile("call *%%esi"
			: "=a" (out)
			: "S" (0x4A5484), "a" (( *reinterpret_cast<int **> (0x4CDF20) )[0]), "d" (id)
			: "cc", "memory");
		return out;
	}

	void saveFile(int saveId) {
		/*RPG::menu->screen = RPG::MENU_MAIN;
        RPG::system->scene = RPG::SCENE_MAP;
		RPG::menu->repaint = false;*/
		asm volatile("call *%%esi"
			:
			: "S" (0x4A5524), "a" (( *reinterpret_cast<int **> (0x4CDF20) )[0]), "d" (saveId)
			: "cc", "memory");
		//save game into specified save file
	}

	void loadFileAndCrash(int saveId) { // Incompatible with saveload patch
		//RPG::screen->canvas->brightness = 0;
		asm volatile("call *%%esi"
			:
			: "S" (0x4A541C), "a" (( *reinterpret_cast<int **> (0x4CDF20) )[0]), "d" (saveId)
			: "cc", "memory");
		//load game from specified save file
		//bug: music, screen and events not properly updated
		//bug: starts player from FileScene when saving normally
		//please check if SaveXX.lsd exists before loading
	}

	void loadFile(int saveId) {
		//RPG::screen->canvas->brightness = 0;
		( *reinterpret_cast<char ***> (0x4CDC7C) )[0][4] = 5;       //forced SceneChange to FileScene
		( *reinterpret_cast<int ***> (0x4CDFCC) )[0][22] = saveId;  //set SaveSlot to load from
		( *reinterpret_cast<char *>(0x4913C8) ) = 0xE9;             //patch to skip drawing the FileScene
		( *reinterpret_cast<int *>(0x4913C9) ) = 0x000001CD;        //patch to skip [...]
		( *reinterpret_cast<unsigned short *>(0x4915AD) ) = 0x03EB; //patch to skip closing the FileScene
		//patching direct access to FileScene (temporarily) to load SaveFile
		//please check if SaveXX.lsd exists before loading
	}

	void loadFileUnpatch() {
		( *reinterpret_cast<char *>(0x4913C8) ) = 0x80;             //patch to restore drawing the FileScene
		( *reinterpret_cast<int *>(0x4913C9) ) = 0x75000C7B;        //patch to restore [...]
		( *reinterpret_cast<unsigned short *>(0x4915AD) ) = 0xCEE8; //patch to restore closing the FileScene
		//DO use in conjunction with forced SceneChange to FileScene!
		//restores default code
	}

	/*! \brief Open the main menu directly into a sub-menu. Experimental!!
	*/
	void OpenMenu(RPG::MenuSubScreen screen, int heroId = 1, int skillOrItemId = 1) {
		//RPG::menu->repaint = false;
		
		if(RPG::system->scene == RPG::SCENE_MENU && RPG::menu->screen == RPG::MENU_MAIN) {
			*reinterpret_cast<char *>(0x4A3368) = 0xA9; // Default = 0x91
			switch (screen) {
			case MENU_ITEM:
				{   //open MENU_ITEM
					*reinterpret_cast<char *>(0x4A109A) = 0x34;             // Default: 0x10    //speed up transition
					*reinterpret_cast<unsigned short *>(0x4A10D4) = 0xBEEB; // Default: 0x8B53  //re-route closeSubMenu() to closeMenu()
					asm volatile("call *%%esi"
								:
								: "S" (0x4A110C), "a" (RPG::menu)
								: "cc", "memory");
					break;
				}
			case MENU_ITEM_USE:
				{   //open MENU_ITEM_USE
					*reinterpret_cast<char *>(0x4A109A) = 0x34;             // Default: 0x10        //speed up transition
					*reinterpret_cast<char *>(0x4A17FC) = 0xE9;             // Default: 0x53        //re-route closeItemUseMenu() to closeMenu()
					*reinterpret_cast<int *>(0x4A17FD) = 0xFFFFF893;        // Default: 0x0068D88B
					RPG::menu->selectedItem = skillOrItemId;         		//Item_ID (must be in inventory)
					asm volatile("call *%%esi"
								:
								: "S" (0x4A1144), "a" (RPG::menu)
								: "cc", "memory");
					break;
				}
			case MENU_SKILL:
				{   //open MENU_SKILL
					*reinterpret_cast<char *>(0x4A109A) = 0x34;                 // Default: 0x10    //speed up transition
					*reinterpret_cast<unsigned short *>(0x4A10D4) = 0xBEEB;     // Default: 0x8B53  //re-route closeSubMenu() to closeMenu()
					*reinterpret_cast<unsigned short *>(0x4A1874) = 0x0EEB;     // Default: 0x438B  //jump a few bytes
					*reinterpret_cast<char *>(0x4A1884) = 0xBA;                 // Default: 0x00    //allow to set new Hero_ID
					*reinterpret_cast<int *>(0x4A1885) = RPG::variables[3327];  // Default: 0x04508B00
					*reinterpret_cast<unsigned short *>(0x4A2224) = 0x0EEB;     // Default: 0x438B  //jump a few bytes
					*reinterpret_cast<char *>(0x4A2234) = 0xBA;                 // Default: 0x00    //allow to set new Hero_ID (return from SKILL_USE)
					*reinterpret_cast<int *>(0x4A2235) = skillOrItemId;  // Default: 0x04508B00
					asm volatile("call *%%esi"
								:
								: "S" (0x4A1858), "a" (RPG::menu)
								: "cc", "memory");
					break;
				}
			case MENU_SKILL_USE:
				{   //open MENU_SKILL_USE
					//WIP
					break;
				}
			case MENU_TELEPORT:
				{   //open MENU_TELEPORT
					//WIP
					break;
				}
			case MENU_EQUIP:
				{   //open MENU_EQUIP
					*reinterpret_cast<char *>(0x4A109A) = 0x34;                 // Default: 0x10    //speed up transition
					*reinterpret_cast<unsigned short *>(0x4A10D4) = 0xBEEB;     // Default: 0x8B53  //re-route closeSubMenu() to closeMenu()
					*reinterpret_cast<unsigned short *>(0x4A22F8) = 0x0EEB;     // Default: 0x438B  //jump a few bytes
					*reinterpret_cast<char *>(0x4A2308) = 0xBA;                 // Default: 0x00    //allow to set new Hero_ID
					*reinterpret_cast<int *>(0x4A2309) = heroId;  // Default: 0x04508B00
					asm volatile("call *%%esi"
								:
								: "S" (0x4A22DC), "a" (RPG::menu)
								: "cc", "memory");
					break;
				}
			case MENU_QUIT:
				{   //open MENU_QUIT
					*reinterpret_cast<char *>(0x4A109A) = 0x34;             // Default: 0x10    //speed up transition
					*reinterpret_cast<unsigned short *>(0x4A10D4) = 0xBEEB; // Default: 0x8B53  //re-route closeSubMenu() to closeMenu()
					asm volatile("call *%%esi"
								:
								: "S" (0x4A2328), "a" (RPG::menu)
								: "cc", "memory");
					break;
				}
			case MENU_STATUS:
				{   //open MENU_STATUS
					*reinterpret_cast<char *>(0x4A109A) = 0x34;                 // Default: 0x10    //speed up transition
					*reinterpret_cast<unsigned short *>(0x4A10D4) = 0xBEEB;     // Default: 0x8B53  //re-route closeSubMenu() to closeMenu()
					*reinterpret_cast<unsigned short *>(0x4A2378) = 0x0EEB;     // Default: 0x438B  //jump a few bytes
					*reinterpret_cast<char *>(0x4A2388) = 0xBA;                 // Default: 0x00    //allow to set new Hero_ID
					*reinterpret_cast<int *>(0x4A2389) = heroId;  				// Default: 0x04508B00
					asm volatile("call *%%esi"
								:
								: "S" (0x4A235C), "a" (RPG::menu)
								: "cc", "memory");
					break;
				}
			case MENU_ORDER:
				{   //open MENU_ORDER
					*reinterpret_cast<char *>(0x4A109A) = 0x34;                 // Default: 0x10    //speed up transition
					*reinterpret_cast<unsigned short *>(0x4A10D4) = 0xBEEB;     // Default: 0x8B53  //re-route closeSubMenu() to closeMenu()
					asm volatile("call *%%esi"
								:
								: "S" (0x4A23BC), "a" (RPG::menu)
								: "cc", "memory");
					break;
				}
			}
		}
	}

	void unpatchDirectMenuCode() {
		*reinterpret_cast<char *>(0x4A109A) = 0x10;
		*reinterpret_cast<unsigned short *>(0x4A10D4) = 0x8B53;
		*reinterpret_cast<char *>(0x4A17FC) = 0x53;
		*reinterpret_cast<int *>(0x4A17FD) = 0x0068D88B;
		*reinterpret_cast<unsigned short *>(0x4A1874) = 0x438B;
		*reinterpret_cast<char *>(0x4A1884) = 0x00;
		*reinterpret_cast<int *>(0x4A1885) = 0x04508B00;
		*reinterpret_cast<unsigned short *>(0x4A2224) = 0x438B;
		*reinterpret_cast<char *>(0x4A2234) = 0x00;
		*reinterpret_cast<int *>(0x4A2235) = 0x04508B00;
		*reinterpret_cast<unsigned short *>(0x4A22F8) = 0x438B;
		*reinterpret_cast<char *>(0x4A2308) = 0x00;
		*reinterpret_cast<int *>(0x4A2309) = 0x04508B00;
		*reinterpret_cast<unsigned short *>(0x4A2378) = 0x438B;
		*reinterpret_cast<char *>(0x4A2388) = 0x00;
		*reinterpret_cast<int *>(0x4A2389) = 0x04508B00;
	}


}
