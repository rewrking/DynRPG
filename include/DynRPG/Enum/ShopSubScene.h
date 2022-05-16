#ifndef DYNRPG_SHOP_SUB_SCENE_H
#define DYNRPG_SHOP_SUB_SCENE_H

namespace RPG
{
/*! \brief Possible values for RPG::SceneShop::screen

	The sub-screen the user is currently on.
*/
enum ShopSubScene
{
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
}

#endif // DYNRPG_SHOP_SUB_SCENE_H
