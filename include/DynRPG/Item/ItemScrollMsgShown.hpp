#ifndef RPG_ITEM_SCROLL_MSG_SHOWN_HPP
#define RPG_ITEM_SCROLL_MSG_SHOWN_HPP

namespace RPG
{
/*! \brief Possible values for RPG::Item::messageShown

	If ITEM_SCROLL, this determines if the item's name or the skill's name
	will be used in the battle window.
*/
enum class ItemScrollMsgShown
{
	Item, //!< Item Name
	Skill //!< Name of Associated Skill
};
}

#endif // RPG_ITEM_SCROLL_MSG_SHOWN_HPP
