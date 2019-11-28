#ifndef RPG_ITEM_TARGET_HPP
#define RPG_ITEM_TARGET_HPP

namespace RPG
{
/*! \brief Possible values for RPG::Item::target

	If ITEM_MEDICINE, this determines if one hero or all heroes are affected.
*/
enum class ItemTarget
{
	Single,
	All
};
}

#endif // RPG_ITEM_TARGET_HPP
