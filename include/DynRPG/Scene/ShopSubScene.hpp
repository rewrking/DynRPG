#ifndef RPG_SHOP_SUB_SCENE_HPP
#define RPG_SHOP_SUB_SCENE_HPP

#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
/*! \brief Possible values for RPG::SceneShop::screen

	The sub-screen the user is currently on.
*/
enum class ShopSubScene : uchar
{
	Menu,
	Buy, //!< Main buy scene
	BuyVending, //!< Scene for selecting sell amount
	BuyComplete, //!< Scene that appears for a second or two after making a buy transaction
	Sell, //!< Main sell scene
	SellVending, //!< Scene for selecting sell amount
	SellComplete, //!< Scene that appears for a second or two after making a sell transaction
};

//! One-byte version of RPG::ShopSubScene
//typedef uchar ShopSubScene_T;
}

#endif // RPG_SHOP_SUB_SCENE_HPP
