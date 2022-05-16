#ifndef DYNRPG_SCENE_SHOP_H
#define DYNRPG_SCENE_SHOP_H

#include <DynRPG/Enum/ShopSubScene.h>
#include <DynRPG/Enum/ShopTransaction.h>
#include <DynRPG/Enum/ShopVocabulary.h>

#include <DynRPG/DList.h>
#include <DynRPG/Window.h>

namespace RPG
{
/*! \brief Used to access the menu windows and its variables.

	\sa RPG::shop
	\sa RPG::Window
*/
class SceneShop
{
public:
	void** vTable;
	//Image *winTest1; //!< Experimental
	//Image *winTest2; //!< Experimental
	void* AuroraBoard1; //!< Not even a little bit implemented...
	void* AuroraBoard2; //!< Not even a little bit implemented...
	ShopSubScene_T screen; //!< The RPG::ShopSubScene currently being displayed
	bool initialized; //!< The flag to repaint the screen
	bool _unknown_0E;
	bool _unknown_0F;
	Window* winShopCover; //!< Pointer to the cover window's objects. This appears over the shop when selecting buy/sell/leave.
	Window* winShopMessage; //!< Pointer to the message box window's objects.
	Window* winShopInfo; //!< Pointer to the info window's objects.
	Window* winShopBuy; //!< Pointer to the buy window's objects. Same dimensions as Sell/Vending.
	Window* winShopSell; //!< Pointer to the sell window's objects. Same dimensions as Buy/Vending.
	Window* winShopVending; //!< Pointer to the vending window's objects. Same dimensions as Buy/Sell.
	Window* winShopParty; //!< Pointer to the party window's objects.
	Window* winShopOwnedEquipped; //!< Pointer to the owned/equipped window's objects.
	Window* winShopGold; //!< Pointer to the gold window's objects.
	ShopTransaction transaction; //!< What type of transactions are allowed?
	ShopVocabulary vocabulary; //!< Shop vocabulary type A, B, or C?
	void* successScriptData; //!< Pointer to scriptData for success handler. Not yet implemented.
	DList<int>* shopItems; //!< Zero-based Array of item ids
	int transactionDelay; //!< The number of frames to delay either of the "_COMPLETE" sub-scenes. (See RPG::ShopSubScene)
	int itemSellId; //!< The ID of the item being sold
	int menuOptionsX; //!< X-position of Buy/Sell/Leave choices.
	int menuOptionsStringLength; //!< The string length of the message window. Must be changed before the screen draws.
};

/*! \ingroup game_objects
	\brief Access to the shop scene
*/
extern DYNRPG_API SceneShop*& shop;
}

#endif // DYNRPG_SCENE_SHOP_H
