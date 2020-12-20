namespace RPG {
	/*! \brief Possible values for RPG::SceneMenu::screen

		The sub-screen the user is currently on.
	*/
	enum MenuSubScreen {
		// Starts at 256 if MenuSubScreen_T is not used
		MENU_MAIN, //!< Main menu screen
		MENU_ITEM, //!< Item screen
		MENU_ITEM_USE, //!< Item sub-screen for when an item is used on a hero
		MENU_SKILL, //!< Skill screen
		MENU_SKILL_USE, //!< Skill sub-screen for when a skill is used on a hero
		MENU_TELEPORT, //!< ???
		MENU_EQUIP, //!< Equip screen
		MENU_QUIT, //!< Quit confirm/cancel screen
		MENU_STATUS, //!< Status screen
		MENU_ORDER, //!< Order screen
		MENU_ULT_SAVELOAD = 20, //!< PepsiOtaku's Ultimate Save/Load Menu Plugin (forthcoming)
		MENU_ULT_SYSTEM = 21, //!< PepsiOtaku's Ultimate System Menu Plugin (forthcoming)
	};

	//! One-byte version of RPG::MenuSubScreen
	typedef unsigned char MenuSubScreen_T;


	/*! \brief Used to access the menu windows and its variables.

		\sa RPG::menu
		\sa RPG::Window
	*/
	class SceneMenu {
		public:
			void **vTable;
				int _unknown_04;
				int _unknown_08;
			MenuSubScreen_T screen; //!< The RPG::MenuSubScreen currently being displayed (replaces getMenuScreen() function from the days of yore)
			bool repaint; //!< The flag to repaint the screen
				bool _unknown_0E;
				bool _unknown_0F;
			Window *winOptions; //!< Pointer to the Options window's objects (Items, Skills, etc.).
			Window *winGold; //!< Pointer to the Gold window's objects.
			Window *winParty; //!< Pointer to the Party window's objects.
			WindowMenuTarget *winItemSkillUse; //!< Pointer to the Item/Skill Use window's objects.
			WindowMenuItem *winItems; //!< Pointer to the Item window's objects. (See RPG::WindowMenuItem)
			WindowMenuSkill *winSkills; //!< Pointer to the Skills window's objects. (See RPG::WindowMenuSkill)
			Window *winTeleport; //!< Pointer to the Teleport pseudo-window's objects.
			WindowMenuEquip *winEquip; //!< Pointer to the Equip window's objects. (See RPG::WindowMenuEquip)
			WindowMenuEnd *winQuit; //!< Pointer to the Quit window's objects. (See RPG::WindowMenuEnd)
			int ScrollUpCountItem; //!< The number of rows off-screen after a scroll (for items)
			/*! \brief The item selection index (relative to the screen).
				\note indexes are zero-based starting from the top-left, and zig-zag to the right position, followed by the down-left position.
			*/
			int inventoryPositionItem;
			int scrollUpCountSkill; //!< The number of rows off-screen after a scroll (for skills)
			/*! \brief The skill selection index (relative to the screen).
				\note indexes are zero-based starting from the top-left, and zig-zag to the right position, followed by the down-left position.
			*/
			int inventoryPositionSkill;
			int selectedItem; //!< The database ID of the item selected for the MENU_ITEM_USE RPG::MenuSubScreen
			int selectedSkill; //!< The database ID of the skill selected for the MENU_SKILL_USE RPG::MenuSubScreen
			WindowMenuStatus *winStatus; //!< Pointer to the Status window's objects.
			WindowMenuOrder *winOrder; //!< Pointer to the Order window's objects.

	};

	/*! \ingroup game_objects
		\brief Access to the menu scene
	*/
	static RPG::SceneMenu *&menu = (**reinterpret_cast<RPG::SceneMenu ***>(0x4CDC60));

}

// Old function
/*RPG::MenuScreen RPG::Menu::getScreen() {
	return (RPG::MenuScreen)(**reinterpret_cast<char ***>(0x4CDC60))[12];
}*/

