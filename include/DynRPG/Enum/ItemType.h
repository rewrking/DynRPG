#ifndef DYNRPG_ITEM_TYPE_H
#define DYNRPG_ITEM_TYPE_H

namespace RPG
{
/*! \brief Possible values for RPG::Item::type

	The item's type. This determines which parameters will be available to use.
	\note Refer to the database's Item page to determine which params can be used.
	\warning Use of any variables outside of their item type is untested.
*/
enum ItemType
{
	ITEM_COMMON,
	ITEM_WEAPON,
	ITEM_SHIELD,
	ITEM_ARMOR,
	ITEM_HELMET,
	ITEM_OTHER,
	ITEM_MEDICINE,
	ITEM_BOOK, //!< Skill Book
	ITEM_SEED, //!< Stat Up
	ITEM_SCROLL, //!< Skill Scroll
	ITEM_SWITCH
};
}

#endif // DYNRPG_ITEM_TYPE_H
