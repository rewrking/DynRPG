#ifndef DYNRPG_ITEM_SCROLL_MSG_SHOWN_H
#define DYNRPG_ITEM_SCROLL_MSG_SHOWN_H

namespace RPG
{
/*! \brief Possible values for RPG::Item::messageShown

	If ITEM_SCROLL, this determines if the item's name or the skill's name
	will be used in the battle window.
*/
enum ItemScrollMsgShown
{
	ITEM_SCROLL_MSG_ITEM, //!< Item Name
	ITEM_SCROLL_MSG_SKILL //!< Name of Associated Skill
};
}

#endif // DYNRPG_ITEM_SCROLL_MSG_SHOWN_H
