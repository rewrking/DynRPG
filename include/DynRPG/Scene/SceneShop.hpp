#ifndef RPG_SCENE_SHOP_HPP
#define RPG_SCENE_SHOP_HPP

#include <DynRPG/Delphi/DList.hpp>
#include <DynRPG/Scene/ShopSubScene.hpp>
#include <DynRPG/Scene/ShopTransaction.hpp>
#include <DynRPG/Scene/ShopVocabulary.hpp>
#include <DynRPG/Utility/Types.hpp>
#include <DynRPG/Window/Window.hpp>

namespace RPG
{
//! Not implemented yet
using ShopScript = void;

/*! \brief Used to access the menu windows and its variables.

	\sa RPG::shop
	\sa RPG::Window
*/
struct SceneShop
{
	// clang-format off
	void** vTable;
	//Image *winTest1; //!< Experimental
	//Image *winTest2; //!< Experimental
	AuroraBoard* auroraBoard1; //!< Not even a little bit implemented...
	AuroraBoard* auroraBoard2; //!< Not even a little bit implemented...
	ShopSubScene screen; //!< The RPG::ShopSubScene currently being displayed
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
	ShopScript* successScriptData; //!< Pointer to scriptData for success handler. Not yet implemented.
	DList<int>* shopItems; //!< Zero-based Array of item ids
	int transactionDelay; //!< The number of frames to delay either of the "_COMPLETE" sub-scenes. (See RPG::ShopSubScene)
	int itemSellId; //!< The ID of the item being sold
	int menuOptionsX; //!< X-position of Buy/Sell/Leave choices.
	int menuOptionsStringLength; //!< The string length of the message window. Must be changed before the screen draws.
	// clang-format on
};

/*! \ingroup game_objects
	\brief Access to the shop scene
*/
static SceneShop*& shop = (**reinterpret_cast<SceneShop***>(0x4CDE4C));
}

#endif // RPG_SCENE_SHOP_HPP