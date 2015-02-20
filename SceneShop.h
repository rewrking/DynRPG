namespace RPG {
	//! Not implemented yet
	typedef void ShopScript;
	/*! \brief Possible values for RPG::SceneShop::screen

		The sub-screen the user is currently on.
	*/
	enum ShopSubScene {
		SHOP_MENU,
		SHOP_BUY, //!< Main buy scene
		SHOP_BUY_VENDING, //!< Scene for selecting sell amount
		SHOP_BUY_COMPLETE, //!< Scene that appears for a second or two after making a buy transaction
		SHOP_SELL, //!< Main sell scene
		SHOP_SELL_VENDING, //!< Scene for selecting sell amount
		SHOP_SELL_COMPLETE, //!< Scene that appears for a second or two after making a sell transaction
	};

	//! One-byte version of RPG::ShopSubScene
	typedef unsigned char ShopSubScene_T;

	/*! \brief Possible values for RPG::SceneShop::transaction

		The type of transaction that is allowed.
	*/
	enum ShopTransaction {
		SHOP_TRANS_BUY_SELL,
		SHOP_TRANS_BUY_ONLY,
		SHOP_TRANS_SELL_ONLY
	};

	/*! \brief Possible values for RPG::SceneShop::vocabulary

		The vocabulary used for the shop
	*/
	enum ShopVocabulary {
		SHOP_VOCAB_TYPE_A,
		SHOP_VOCAB_TYPE_B,
		SHOP_VOCAB_TYPE_C
	};

	/*! \brief Used to access the menu windows and its variables.

		\sa RPG::shop
		\sa RPG::Window
	*/
	class SceneShop {
		public:
			void **vTable;
				AuroraBoard *AuroraBoard1; //!< Not even a little bit implemented...
				AuroraBoard *AuroraBoard2; //!< Not even a little bit implemented...
			ShopSubScene_T screen; //!< The RPG::ShopSubScene currently being displayed
			bool initialized; //!< The flag to repaint the screen
				bool _unknown_0E;
				bool _unknown_0F;
			Window *winShopCover; //!< Pointer to the cover window's objects. This appears over the shop when selecting buy/sell/leave.
			Window *winShopMessage; //!< Pointer to the message box window's objects.
			Window *winShopInfo; //!< Pointer to the info window's objects.
			Window *winShopBuy; //!< Pointer to the buy window's objects. Same dimensions as Sell/Vending.
			Window *winShopSell; //!< Pointer to the sell window's objects. Same dimensions as Buy/Vending.
			Window *winShopVending; //!< Pointer to the vending window's objects. Same dimensions as Buy/Sell.
			Window *winShopParty; //!< Pointer to the party window's objects.
			Window *winShopOwnedEquipped; //!< Pointer to the owned/equipped window's objects.
			Window *winShopGold; //!< Pointer to the gold window's objects.
			ShopTransaction transaction; //!< What type of transactions are allowed?
			ShopVocabulary vocabulary; //!< Shop vocabulary type A, B, or C?
				ShopScript *successScriptData; //!< Pointer to scriptData for success handler. Not yet implemented.
			DList<int> *shopItems; //!< Zero-based Array of item ids
			int transactionDelay; //!< The number of frames to delay either of the "_COMPLETE" sub-scenes. (See RPG::ShopSubScene)
			int itemSellId; //!< The ID of the item being sold
			int menuOptionsX; //!< X-position of Buy/Sell/Leave choices.
			int menuOptionsStringLength; //!< The string length of the message window. Must be changed before the screen draws.

	};
	
	/*! \ingroup game_objects
		\brief Access to the shop scene
	*/
	static RPG::SceneShop *&shop = (**reinterpret_cast<RPG::SceneShop ***>(0x4CDE4C));
}
