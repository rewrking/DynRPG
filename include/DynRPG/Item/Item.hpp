#ifndef RPG_ITEM_HPP
#define RPG_ITEM_HPP

#include <DynRPG/Animation/AnimationWeapon.hpp>
#include <DynRPG/Catalog/NamedCatalogPtr.hpp>
#include <DynRPG/Delphi/DArray.hpp>
#include <DynRPG/Delphi/DStringPtr.hpp>
#include <DynRPG/Item/ItemConditionFlag.hpp>
#include <DynRPG/Item/ItemScrollMsgShown.hpp>
#include <DynRPG/Item/ItemTarget.hpp>
#include <DynRPG/Item/ItemType.hpp>
#include <DynRPG/Item/WeaponRangedTargetting.hpp>
#include <DynRPG/Item/WeaponRangedTrajectory.hpp>

namespace RPG
{
/*! \brief Used for the data of items which can be accessed or changed in-game.

	\sa RPG::items
	\sa RPG::ItemType
	\sa RPG::ItemTarget
	\sa RPG::ItemScrollMsgShown
	\sa RPG::ItemConditionFlag
	\sa RPG::WeaponRangedTrajectory
	\sa RPG::WeaponRangedTargetting
	\sa RPG::AnimationWeapon
*/
class Item
{
	// clang-format off
	void** vTable;
	int id; //!< ID of the item
	DStringPtr name; //!< The name of the item
	DStringPtr description; //!< The description of the item
	ItemType type; //!< The item's type as defined in the database (see RPG::ItemType)
	int price; //!< Price
	int numUses; //!< Number of uses (0 = unlimited)

	// ITEM_WEAPON
	int str; //!< Attack \sa RPG::ITEM_WEAPON
	int def; //!< Defense \sa RPG::ITEM_WEAPON
	int intl; //!< Intelligence \sa RPG::ITEM_WEAPON
	int agl; //!< Agility \sa RPG::ITEM_WEAPON
	bool twoHanded; //!< Is it two-handed? (Hands Required) \sa RPG::ITEM_WEAPON
	int mpCost; //!< Agility \sa RPG::ITEM_WEAPON
	int hitProb; //!< Hit Probability \sa RPG::ITEM_WEAPON
	int critBonus; //!< Critical Bonus \sa RPG::ITEM_WEAPON
	int battleAnimId; //!< Battle Animation ID \sa RPG::ITEM_WEAPON
	bool alwaysAttackFirst; //!< Always attack first? \sa RPG::ITEM_WEAPON
	bool attackTwice; //!< Attack twice? \sa RPG::ITEM_WEAPON
	bool attackAll; //!< Attack all enemies? \sa RPG::ITEM_WEAPON
	bool ignoreEvasion; //!< Ignore evasion? \sa RPG::ITEM_WEAPON

	// ITEM_SHIELD
	bool preventCrit; //!< Prevent critical hits? \sa RPG::ITEM_SHIELD
	bool increaseEvasion; //!< Increased evasion? \sa RPG::ITEM_SHIELD
	bool halfMpCost; //!< Half MP Consumption? \sa RPG::ITEM_SHIELD
	bool noTerrainDmg; //!< No Terrain Damage? \sa RPG::ITEM_SHIELD

	// ITEM_MEDICINE
	ItemTarget target; //!< Does the item target a single hero or all? (see RPG::ItemTarget) \sa RPG::ITEM_MEDICINE
	int hpRestorePercent; //!< % of Max HP to restore \sa RPG::ITEM_MEDICINE
	int hpRestoreUnits; //!< Amount of HP to restore \sa RPG::ITEM_MEDICINE
	int mpRestorePercent; //!< % of Max MP to restore \sa RPG::ITEM_MEDICINE
	int mpRestoreUnits; //!< Amount of MP to restore \sa RPG::ITEM_MEDICINE
	bool onlyInField; //!< Only usable on the field map? \sa RPG::ITEM_MEDICINE
	bool onlyOnDead; //!< Only usable on dead characters? \sa RPG::ITEM_MEDICINE

	// ITEM_SEED
	int addMaxHp; //!< Max HP to add \sa RPG::ITEM_SEED
	int addMaxMp; //!< Max MP to add \sa RPG::ITEM_SEED
	int addStr; //!< STR to add \sa RPG::ITEM_SEED
	int addDef; //!< DEF to add \sa RPG::ITEM_SEED
	int addInt; //!< INT to add \sa RPG::ITEM_SEED
	int addAgl; //!< AGL to add \sa RPG::ITEM_SEED

	// ITEM_SCROLL
	ItemScrollMsgShown messageShown; //!< Message Shown When Used (see RPG::ItemScrollMsgShown) \sa RPG::ITEM_SCROLL
	int skillId; //!< Skill Id \sa RPG::ITEM_SCROLL

	// ITEM_SWITCH
	int switchId; //!< Switch Id \sa RPG::ITEM_SWITCH
	bool useInField; //!< Activation in field? \sa RPG::ITEM_SWITCH
	bool useInBattle; //!< Activation in battle? \sa RPG::ITEM_SWITCH

	// All/Misc
	DArray<bool> usableByHero; //!< Usable By Hero Array
	DArray<bool> conditions; //!< Array of Conditions. size = highest condition that is checked off
	DArray<bool> attributes; //!< Array of Attributes. size = highest attribute that is checked off
	int conditionPercentage; //!< Inflict/Resist Condition %
		int _unknown_01;
	NamedCatalogPtr<AnimationWeapon*> weaponAnims; //!< Pointer to the RPG::AnimationWeapon array
	bool invokeSkill; //!< Does the item invoke a skill (set skill with skillId)
	DArray<bool> usableByClass; //!< Usable By Class Array
	bool isCursed; //!< Is the item cursed?

	// Note: conditionFlag is a DWORD, so this can't be defined as bool
	ItemConditionFlag conditionFlag; //!< Does the item remove the condition instead of inflict? (see RPG::ItemConditionFlag)
	WeaponRangedTrajectory weaponTrajectory; //!< If a ranged weapon, the weapons' trajectory (see RPG::WeaponRangedTrajectory)
	WeaponRangedTargetting weaponTargetting; //!< If a ranged weapon, the weapons' target(s) (see RPG::WeaponRangedTargetting)
	// clang-format on
};

/*! \ingroup game_objects
	\brief Array of items from the database, used for default values and
	properties which are not supposed to be changed in-game.

	Use the database ID as index for accessing an item.

	Example:
	\code
int swordHitProb = RPG::items[36]->hitProb;
	\endcode
	\sa RPG::inventory
*/
static NamedCatalogPtr<Item*>& items = (**reinterpret_cast<NamedCatalogPtr<Item*>**>(0x4CDB14));
}

#endif // RPG_ITEM_HPP
