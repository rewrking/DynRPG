#ifndef DYNRPG_SHOP_TRANSACTION_H
#define DYNRPG_SHOP_TRANSACTION_H

namespace RPG
{
/*! \brief Possible values for RPG::SceneShop::transaction

	The type of transaction that is allowed.
*/
enum ShopTransaction
{
	SHOP_TRANS_BUY_SELL,
	SHOP_TRANS_BUY_ONLY,
	SHOP_TRANS_SELL_ONLY
};
}

#endif // DYNRPG_SHOP_TRANSACTION_H
