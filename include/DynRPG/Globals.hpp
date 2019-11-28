#ifndef RPG_DYN_GLOBALS_HPP
#define RPG_DYN_GLOBALS_HPP

#include <string>

#include <DynRPG/Battle/BattleEventUpdateMode.hpp>
#include <DynRPG/Battler/Battler.hpp>
#include <DynRPG/Scene/MenuSubScreen.hpp>

namespace RPG
{
//! \cond
static void*** sceneObjects[] __attribute__((unused)) = {
	(void***)0x4CDC1C, (void***)0x4CDC60, (void***)0x4CDD38, (void***)0x4CDE4C, (void***)0x4CDBF4, (void***)0x4CDFCC, (void***)0x4CDB94, (void***)0x4CE008, (void***)0x4CDD4C
};
//! \endcond

//! The test play flag
/*! This flag may also be changed at runtime. */
static bool& isTestPlay = (**reinterpret_cast<bool**>(0x4CDD50));

//! The test play flag
/*! This flag may also be changed at runtime, but it probably wouldn't make sense. */
static bool& isBattleTest = (**reinterpret_cast<bool**>(0x4CDCB8));
//static bool &isBattleTest = (**reinterpret_cast<bool **>(0x4CDCB4)); // 0x4CDCB4 is what's documented by bugmenot... check both

//! Should the title screen be shown (according to the "Show Title" button in the %RPG Maker)?
/*! This flag may also be changed at runtime, but it probably wouldn't make sense. */
static bool& showTitle = (**reinterpret_cast<bool**>(0x4CDF90));

//! Speed of the ATB system in percent
/*! This value can be set to zero to pause the battle.
	\note This is a special feature of the DynRPG patch.
*/
static int& battleSpeed = (*reinterpret_cast<int*>(0x442600));

//! Allows transparent windows in outside of the map too
/*! Set this flag to \c true to allow transparent windows in the menu, on
	the title screen, etc.
	\note This is a special feature of the DynRPG patch.
*/
static bool& transparentWindowsEverywhere = (*reinterpret_cast<bool*>(0x442604));

/*! \brief Shows an error message and asks whether the game should be continued or not.

	This function can be used to show an error message of any kind.
	\param message Message to show
	\param eventId %Event ID
	\param pageId %Event page ID
	\param lineId Zero-based line number (will be incremented before being shown to the user)
*/
void showError(std::string message, int eventId, int pageId, int lineId);

/*! \brief Updates the battle, including actions, ATB, animations, etc.

	This function can be used if you want to do something which takes
	longer than one frame, for example displaying some kind of animation
	or taking and processing user input.

	\pre You must be in battle, otherwise the behavior is undefined.
	\warning This function is experimental.
*/
void updateBattle();

/*! \brief Processes battle events

	This function can be used to update battle events and maybe call them
	at a time where normally no battle event is processed.
	\param mode Mode of the update (see RPG::BattleEventUpdateMode)
	\param battler %Battler whose action is executed
	\note \c battler can be \c 0 if \c mode is RPG::BEUM_BATTLE_START.
	\pre You must be in battle, otherwise the behavior is undefined.
	\warning This function is <b>highly experimental</b>!
	\sa RPG::updateBattleEvents
*/
void updateBattleEvents(BattleEventUpdateMode mode, Battler* battler);

/*! \brief Returns the index of the currently selected monster

	This function can be used to found out which monster is selected when
	the player is selecting a target for an attack or skill.
	\return Zero-based party member index of the selected monster
	\pre You must be in battle, otherwise the behavior is undefined.
*/
int getSelectedMonsterIndex();

/*! \brief Returns the name of an item
	\param id Database ID of the item
	\return Name of the item
	\sa RPG::getItemDescription
*/
std::string getItemName(int id);

/*! \brief Returns the description of an item
	\param id Database ID of the item
	\return Description of the item
	\sa RPG::getItemName
*/
std::string getItemDescription(int id);

/*! \brief Returns the name of a skill
	\param id Database ID of the skill
	\return Name of the skill
	\sa RPG::getSkillDescription
*/
std::string getSkillName(int id);

/*! \brief Returns the description of a skill
	\param id Database ID of the skill
	\return Description of the skill
	\sa RPG::getSkillName
*/
std::string getSkillDescription(int id);

/*! \brief Returns the name of a condition
	\param id Database ID of the condition
	\return Name of the condition
*/
std::string getConditionName(int id);

/*! \brief Encodes a numerical value for use with RPG::Character::move
	\param value Value to encode
	\return Encoded value as string (may be 1 to 5 characters long)
*/
std::string encode(int value);

/*! \brief Encodes a string for use with RPG::Character::move
	\param value String to encode
	\return Encoded string (including length information)
*/
std::string encode(std::string value);

/*! \brief Built-in RM2k3 function that gets a random number between 1 and the specified number
	\param maxValue the maximum number to return
	\return A random number between 1 and the specified number
*/
// 2k3 function that gets a random number from 1 to maxValue
int getDiceRoll(int maxValue);

/*! \brief Goes directly to the title screen.
*/
void goToTitle();

/*! \brief Quits the game, and runs through the proper quit procedure code.
*/
void quitGame();

/*static void openOrderMenu() {
	asm volatile("call *%%esi"
		:
		: "S" (0x4A0104)
		: "edx", "ecx", "eax", "cc", "memory");

}*/

/*! \brief Built-in RM2k3 function that gets the party's average agility in battle
	\return The agility average of the party
*/
int getAvgPartyAgl();

/*! \brief Built-in RM2k3 function that gets the monster party's average agility in battle
	\return The agility average of the monster party
*/
int getAvgMonsterPartyAgl();

/*! \brief Open the main menu directly into a sub-menu. Experimental!!
*/
void openMenu(MenuSubScreen screen, int heroId = 1, int skillOrItemId = 1);

/*! \brief The unpatch code for using RPG::openMenu. Experimental!!
*/
void OpenMenuUnpatch();
}

#endif // RPG_DYN_GLOBALS_HPP
