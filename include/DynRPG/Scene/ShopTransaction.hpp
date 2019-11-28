#ifndef RPG_SHOP_TRANSACTION_HPP
#define RPG_SHOP_TRANSACTION_HPP

namespace RPG
{
/*! \brief Possible values for RPG::SceneShop::transaction

	The type of transaction that is allowed.
*/
enum ShopTransaction
{
	BuyAndSell,
	BuyOnly,
	SellOnly
};
}

#endif // RPG_SHOP_TRANSACTION_HPP
