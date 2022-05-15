#ifndef DYNRPG_ACTOR_H
#define DYNRPG_ACTOR_H

#include <DynRPG/Enum/AnimationMoveBeforeAttack.h>
#include <DynRPG/Enum/WeaponRangedTargeting.h>
#include <DynRPG/Enum/WeaponRangedTrajectory.h>
#include <DynRPG/Enum/WeaponSlotInUse.h>

#include <DynRPG/Animation.h>
#include <DynRPG/AnimationCurrent.h>
#include <DynRPG/AnimationInBattle.h>
#include <DynRPG/AnimationWeapon.h>
#include <DynRPG/Battler.h>
#include <DynRPG/DArray.h>
#include <DynRPG/DStringPtr.h>
#include <DynRPG/Image.h>
#include <DynRPG/NamedCatalogPtr.h>

#include <string>

namespace RPG
{
/*! \brief Used for the data of actors which can be changed in-game.

	\note Many things are only stored in this class if they were changed
	and are now different from the default in the database, thus you
	should use the getter methods to access these things.\n\n
	The members ending with \c Diff are "offsets" which are added to the
	default value (which is calculated from the current level, class and
	equipment).
	\sa RPG::actors
	\sa RPG::DBActor
	\sa RPG::dbActors
	\sa RPG::Battler
*/
class DYNRPG_API Actor : public Battler // TLcfgPlayerItem
{
public:
	// sizeof(Battler) == 0xD8
	DStringPtr name; //!< Name ("\x01" means database default)
	DStringPtr degree; //!< Degree ("\x01" means database default)
	DStringPtr charsetFilename; //!< Filename of the charset (empty means database default)
	int charsetId; //!< ID of the sprite in the charset file (only valid if \c charsetFilename isn't empty)
	int charsetTransparency; //!< Transparency of the charset (\c 0 to \c 8, only valid if \c charsetFilename isn't empty)
	DStringPtr facesetFilename; //!< Filename of the faceset (empty means database default)
	int facesetId; //!< ID of the sprite in the faceset file (only valid if \c facesetFilename isn't empty)
	int level; //!< Current level
	int exp; //!< Current experience points
	int maxHpDiff; //!< Difference from the default maximal HP
	int maxMpDiff; //!< Difference from the default maximal MP
	int attackDiff; //!< Difference from the default attack value
	int defenseDiff; //!< Difference from the default defense value
	int intelligenceDiff; //!< Difference from the default intelligence value
	int agilityDiff; //!< Difference from the default agility value
		//int skillAmount;
	DArray<short> learnedSkills;
	short weaponId; //!< Database ID of the current weapon (zero for none)
	short shieldId; //!< Database ID of the current shield (or second-hand weapon, zero for none)
	short armorId; //!< Database ID of the current armor (zero for none)
	short helmetId; //!< Database ID of the current helmet (zero for none)
	short accessoryId; //!< Database ID of the current accessory (zero for none)
	bool twoWeapons; //!< Can the actor hold two weapons?
	bool lockEquipment; //!< Is the actor's equipment unchangable by the player?
	//bool autoBattle; //!< Is the battle AI activated for this actor?
	bool aiControl; //!< Is the battle AI activated for this actor?
	bool mightyGuard; //!< Is the "mighty guard" mode activated for this actor?
	int battleGraphicId; //!< Database ID of the battle graphic (zero for database default)
	bool customBattleCommands; //!< \c true if the \c battleCommands member is valid, otherwise the database default should be used
	int battleCommands[7]; //!< The current battle commands for this actor (\c 0 and \c -1 both mean "no command at this position")

	//Fun part
	int _unknown_150; //DArray<short> tempSkills; // Temporary skills array - Unsure about defining it. DArray uses an extra byte
	bool classChanging; //!< Is the actor's class in the process of changing?
	Image* poses[32]; //!< The pose images. These include each of the 3 frames of animation in the pose
	Image* posesMirrored[32]; //!< The mirrored pose images
	Image* firstWeapon; //!< The weapon image for the battler's first equipped weapon
	Image* firstWeaponMirrored; //!< The mirrored weapon image for the battler's first equipped weapon
	Image* firstWeaponRanged; //!< The ranged weapon image for the battler's first equipped weapon
	Image* firstWeaponRangedMirrored; //!< The mirrored ranged weapon image for the battler's first equipped weapon
	Image* secondWeapon; //!< The weapon image for the battler's second equipped weapon (if applicable)
	Image* secondWeaponMirrored; //!< The mirrored weapon image for the battler's second equipped weapon (if applicable)
	Image* secondWeaponRanged; //!< The ranged weapon image for the battler's second equipped weapon (if applicable)
	Image* secondWeaponRangedMirrored; //!< The mirrored ranged weapon image for the battler's second equipped weapon (if applicable)
	int graphicsUpdateValue; //!< allows graphics if remainder after division by 10 is < 5 ??
	int _unknown_27C;
	int _unknown_280;
	int _unknown_284;
	int _unknown_288;
	int battlerAnimFrame; //!< The animation frame of the battler (0-2)
	int currentComboHit; // ??
	int currentComboHitAlt; // ??
	int attackDuration; //!< Affected by ranged speed
	int rangedWeaponX[8]; //!< When a ranged weapon hits multiple enemies, The x value of the image for each enemy
	int rangedWeaponY[8]; //!< When a ranged weapon hits multiple enemies, The y value of the image for each enemy
	int afterImageX; //!< Current X coordinate of the after image
	int afterImageY; //!< Current Y coordinate of the after image
	int afterImageOriginX; //!< Origin X coordinate of the after image
	int afterImageOriginY; //!< Origin Y coordinate of the after image
	int afterImageDestinationX; //!< Destination X coordinate of the after image
	int afterImageDestinationY; //!< Destination Y coordinate of the after image
	AnimationMoveBeforeAttack weaponMovement; //!< The weapon's movement before attacking (See RPG::AnimationMoveBeforeAttack)
	bool weaponAddAfterImage; //!< "Add" the after image of the weapon?
	WeaponNumberOfAttacks weaponNumAttacks; //!< Number of attacks for the weapon (See RPG::WeaponNumberOfAttacks)
	bool isRangedWeapon; //!< Is ranged weapon?
	int _unknown_304;
	WeaponRangedTrajectory weaponTrajectory; //!< If a ranged weapon, the weapons' trajectory (see RPG::WeaponRangedTrajectory)
	WeaponRangedTargeting weaponTargetting; //!< If a ranged weapon, the weapons' target(s) (see RPG::WeaponRangedTargetting)
	WeaponRangedAnimSpeed rangedAnimSpeed; //!< Ranged animation speed? (See RPG::WeaponRangedAnimSpeed)
	WeaponSlotInUse usedWeaponSlot; //!< If actor uses two weapons, the slot of the weapon currently being used (See RPG::WeaponSlotInUse)
	void* _unknown_318; // Another AuroraBoard
	void* _unknown_31C; // Another AuroraBoard
	AnimationCurrent* actorAnim; //!< The actor's battle animation data
	int actorAnimationId; //!< The ID of the actor's current battle animation. Can be battler or weapon anims
	int actorAnimationFrame; //!< The frame of the battle animation
	int _unknown_32C; // hero ID for enable combo?
	int comboUsedBattleCommand; //!< The battle command ID that was used (for use in "Enable Combo")
	int comboBattleCommand; //!< The battle command ID that is expected (set in "Enable Combo")
	int comboRepetitions; //!< Number of times to repeat combo (set in "Enable Combo")
	DArray<short> itemsInBattle; //!< Items in the inventory only updated when accessing Item menu in battle. Index is zero-based. (See RPG::Inventory::items)
	unsigned char* itemAmountInBattle; //!< Item amounts in the inventory only updated when accessing Item menu in battle. Index is zero-based. (See RPG::Inventory::items)
	bool isAutoBattle; //!< Is auto-battle enabled? ( \sa RPG::BattleData::autoBattle )
	int _unknown_34C;
	int maxHitNumber; //!< comboRepetitions * Weapon's hit #?
	bool battlerSpawned; //!< Used internally at start of battler for loading

	/*! \brief Returns the current degree
		\return Current degree
	*/
	std::string getDegree();

	/*! \brief Returns the current charset filename
		\return Current charset filename
		\sa getCharsetId
		\sa getCharsetTransparency
	*/
	std::string getCharsetFilename();

	/*! \brief Returns the current charset ID
		\return ID of sprite in charsets
		\sa getCharsetFilename
		\sa getCharsetTransparency
	*/
	int getCharsetId();

	/*! \brief Returns the current charset transparency
		\return Transparency value (see RPG::Character::transparency
		documentation)
		\sa getCharsetFilename
		\sa getCharsetId
	*/
	int getCharsetTransparency();

	/*! \brief Returns the current faceset filename
		\return Current faceset filename
		\sa getFacesetId
	*/
	std::string getFacesetFilename();

	/*! \brief Returns the current faceset ID
		\return ID of sprite in faceset
		\sa getFacesetFilename
	*/
	int getFacesetId();

	/*! \brief Returns the current battle graphic ID
		\return Database ID of the current battle graphic
	*/
	int getBattleGraphicId();

	/*! \brief Returns the current battle command on a certain position
		\param index Zero-based index of the available commands for
		this actor (\c 0 to \c 6)
		\return Database ID of the battle command on the given position
		or either \c 0 or \c -1 if there is none
	*/
	int getBattleCommand(int index);

	/*! \brief Returns a certain party member
		\param index Zero-based party member index (\c 0 to \c 3)
		\return Pointer to the RPG::Actor object of the particular actor
	*/
	static RPG::Actor* partyMember(int index);

	/*! \brief Returns the battle animation information for when an animation
		is playing over an actor (being attacked or healed)
		\return Pointer to the AnimationInBattle class for the actor party
		\sa RPG::Monster::animData
	*/
	static RPG::AnimationInBattle*& animData;

	/*! \brief Built-in RM2k3 function that adds a skill to a hero
		\param id The database ID of the skill
	*/
	void addSkill(int skillId);

	/*! \brief Built-in RM2k3 function that removes a skill from a hero
		\param id The database ID of the skill
	*/
	void removeSkill(int skillId);

	/*! \brief Built-in RM2k3 function that tests if a hero already knows a certain skill
		\param id The database ID of the skill
	*/
	bool isSkillKnown(int skillId);

	/*! \brief Returns the attack value if actor has two weapons equipped (one weapon is ignored)
		\return Attack value when normally attacking with two weapons (see RPG::Actor::usedWeaponSlot)
	*/
	int getTwoWeaponAttack();

	/*! \brief Returns the agility value if actor has two weapons equipped (one weapon is ignored)
		\return Agility value when normally attacking with two weapons (see RPG::Actor::usedWeaponSlot)
	*/
	int getTwoWeaponAgility();

	/*! \brief
		\param
	*/
	//void changeClass(RPG::DBClass *index);
};

/*! \ingroup game_objects
	\brief Array of actors from the database, used for properties which
	can change in-game.

	Use the database ID as index for accessing an actor.

	Example:
	\code
int zackHp = RPG::actors[1]->hp;
	\endcode
	\sa RPG::dbActors
*/
extern DYNRPG_API RPG::NamedCatalogPtr<RPG::Actor*>& actors;
}

#endif // DYNRPG_ACTOR_H
