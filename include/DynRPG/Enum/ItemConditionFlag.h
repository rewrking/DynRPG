#ifndef DYNRPG_ITEM_CONDITION_FLAG_H
#define DYNRPG_ITEM_CONDITION_FLAG_H

namespace RPG
{
/*! \brief Possible values for RPG::Item::conditionFlag

	Determines if the item will inflict or remove.
*/
enum ItemConditionFlag
{
	ITEM_CONDITION_INFLICT,
	ITEM_CONDITION_REMOVE,
};
}

#endif // DYNRPG_ITEM_CONDITION_FLAG_H
