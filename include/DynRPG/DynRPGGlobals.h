#ifndef DYNRPG_GLOBALS_H
#define DYNRPG_GLOBALS_H

#include <DynRPG/Enum/BattleEventUpdateMode.h>
#include <DynRPG/Enum/MenuSubScreen.h>
#include <DynRPG/Enum/TeleportDirection.h>

#include <DynRPG/Battler.h>
#include <DynRPG/EventScriptLine.h>

#include <map>
#include <string>

namespace RPG
{
//! \cond
extern DYNRPG_API void*** sceneObjects[];
//! \endcond

//! The test play flag
/*! This flag may also be changed at runtime. */
extern DYNRPG_API bool& isTestPlay;

//! The test play flag
/*! This flag may also be changed at runtime, but it probably wouldn't make sense. */
extern DYNRPG_API bool& isBattleTest;
//static bool &isBattleTest = (**reinterpret_cast<bool **>(0x4CDCB4)); // 0x4CDCB4 is what's documented by bugmenot... check both

//! Should the title screen be shown (according to the "Show Title" button in the %RPG Maker)?
/*! This flag may also be changed at runtime, but it probably wouldn't make sense. */
extern DYNRPG_API bool& showTitle;

extern DYNRPG_API bool& showingLogo;

//! Speed of the ATB system in percent
/*! This value can be set to zero to pause the battle.
	\note This is a special feature of the DynRPG patch.
*/
extern DYNRPG_API int& battleSpeed;

//! Allows transparent windows in outside of the map too
/*! Set this flag to \c true to allow transparent windows in the menu, on
	the title screen, etc.
	\note This is a special feature of the DynRPG patch.
*/
extern DYNRPG_API bool& transparentWindowsEverywhere;

/*! \brief Shows an error message and asks whether the game should be continued or not.

	This function can be used to show an error message of any kind.
	\param message Message to show
	\param eventId %Event ID
	\param pageId %Event page ID
	\param lineId Zero-based line number (will be incremented before being shown to the user)
*/
DYNRPG_API void showError(std::string message, int eventId, int pageId, int lineId);

/*! \brief Updates the battle, including actions, ATB, animations, etc.

	This function can be used if you want to do something which takes
	longer than one frame, for example displaying some kind of animation
	or taking and processing user input.

	\pre You must be in battle, otherwise the behavior is undefined.
	\warning This function is experimental.
*/
DYNRPG_API void updateBattle();

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
DYNRPG_API void updateBattleEvents(BattleEventUpdateMode mode, Battler* battler);

/*! \brief Returns the index of the currently selected monster

	This function can be used to found out which monster is selected when
	the player is selecting a target for an attack or skill.
	\return Zero-based party member index of the selected monster
	\pre You must be in battle, otherwise the behavior is undefined.
*/
DYNRPG_API int getSelectedMonsterIndex();

/*! \brief Returns the name of an item
	\param id Database ID of the item
	\return Name of the item
	\sa RPG::getItemDescription
*/
DYNRPG_API std::string getItemName(int id);

/*! \brief Returns the description of an item
	\param id Database ID of the item
	\return Description of the item
	\sa RPG::getItemName
*/
DYNRPG_API std::string getItemDescription(int id);

/*! \brief Returns the name of a skill
	\param id Database ID of the skill
	\return Name of the skill
	\sa RPG::getSkillDescription
*/
DYNRPG_API std::string getSkillName(int id);

/*! \brief Returns the description of a skill
	\param id Database ID of the skill
	\return Description of the skill
	\sa RPG::getSkillName
*/
DYNRPG_API std::string getSkillDescription(int id);

/*! \brief Returns the name of a condition
	\param id Database ID of the condition
	\return Name of the condition
*/
DYNRPG_API std::string getConditionName(int id);

/*! \brief Gets the name of a switch
	\param id Database ID of the switch
	\return The name of the switch
*/
DYNRPG_API std::string getSwitchName(int index);

/*! \brief Gets the name of a variable
	\param id Database ID of the variable
	\return The name of the variable
*/
DYNRPG_API std::string getVariableName(int index);

/*! \brief Simple function for teleporting
*/
DYNRPG_API void teleportHero(int mapId = 1, int x = 0, int y = 0, TeleportDirection dir = TP_DIR_RETAIN_FACING);

/*! \brief Easily returns an event line.

	Allows you to write <tt>RPG::getBattleEventLine(6,2,0)->command</tt> instead of <tt>RPG::mapCurrent->events[6]->pages[3]->scriptLines->list->items[0]->command</tt> which gets the first line on the 3rd page of the event 6.

	\param eventId The monster group ID (one-based)
	\param pageId The monster group's battle event page ID (zero-based)
	\param lineId The line ID (zero-based)

	\sa RPG::MapEventPage
*/
DYNRPG_API RPG::EventScriptLine* getEventLine(int eventId, int pageId, int lineId);

/*! \brief Returns a std::map containing configuration from an INI file

	This function should be used to load configuration for a plugin. See
	the \ref configuration guidelines for more information.
	\param sectionName Name of the section to load from the INI file
	\param filename Name of the INI file (defaults to \c DynRPG.ini)
	\return All keys and values of the specified section from the INI file
*/
DYNRPG_API std::map<std::string, std::string> loadConfiguration(char* sectionName, char* filename = NULL);

/*! \brief Encodes a numerical value for use with RPG::Character::move
	\param value Value to encode
	\return Encoded value as string (may be 1 to 5 characters long)
*/
DYNRPG_API std::string encode(int value);

/*! \brief Encodes a string for use with RPG::Character::move
	\param value String to encode
	\return Encoded string (including length information)
*/
DYNRPG_API std::string encode(std::string value);

// Functions added in the 0.30 update
// ==================================

/*! \brief Built-in RM2k3 function that gets a random number between 1 and the specified number
	\param maxValue the maximum number to return
	\return A random number between 1 and the specified number
*/
DYNRPG_API int getDiceRoll(int maxValue);

/*! \brief Goes directly to the title screen.
*/
DYNRPG_API void goToTitle();

/*! \brief Quits the game, and runs through the proper quit procedure code.
*/
DYNRPG_API void quitGame();

/*! \brief Built-in RM2k3 function that gets the party's average agility in battle
	\return The agility average of the party
*/
DYNRPG_API int getAvgPartyAgl();

/*! \brief Built-in RM2k3 function that gets the monster party's average agility in battle
	\return The agility average of the monster party
*/
DYNRPG_API int getAvgMonsterPartyAgl();

/*! \brief Open the main menu directly into a sub-menu. Experimental!!
*/
DYNRPG_API void openMenu(MenuSubScreen screen, int heroId = 1, int skillOrItemId = 1);

/*! \brief The unpatch code for using RPG::openMenu. Experimental!!
*/
DYNRPG_API void openMenuUnpatch();
}

#endif // DYNRPG_GLOBALS_H
