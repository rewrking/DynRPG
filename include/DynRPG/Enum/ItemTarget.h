#ifndef DYNRPG_ITEM_TARGET_H
#define DYNRPG_ITEM_TARGET_H

namespace RPG
{
/*! \brief Possible values for RPG::Item::target

	If ITEM_MEDICINE, this determines if one hero or all heroes are affected.
*/
enum ItemTarget
{
	ITEM_TARGET_SINGLE,
	ITEM_TARGET_ALL
};
}

#endif // DYNRPG_ITEM_TARGET_H
