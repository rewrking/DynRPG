#ifndef RPG_ITEM_TYPE_HPP
#define RPG_ITEM_TYPE_HPP

namespace RPG
{
/*! \brief Possible values for RPG::Item::type

	The item's type. This determines which parameters will be available to use.
	\note Refer to the database's Item page to determine which params can be used.
	\warning Use of any variables outside of their item type is untested.
*/
enum class ItemType
{
	Common,
	Weapon,
	Shield,
	Armor,
	Helmet,
	Other,
	Medicine,
	Book, //!< Skill Book
	Seed, //!< Stat Up
	Scroll, //!< Skill Scroll
	Switch
};
}

#endif // RPG_ITEM_TYPE_HPP
