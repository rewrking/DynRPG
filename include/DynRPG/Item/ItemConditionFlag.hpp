#ifndef RPG_ITEM_CONDITION_FLAG_HPP
#define RPG_ITEM_CONDITION_FLAG_HPP

namespace RPG
{
/*! \brief Possible values for RPG::Item::conditionFlag

	Determines if the item will inflict or remove.
*/
enum class ItemConditionFlag
{
	Inflict,
	Remove,
};
}

#endif // RPG_ITEM_CONDITION_FLAG_HPP
