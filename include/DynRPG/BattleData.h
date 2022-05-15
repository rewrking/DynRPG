#ifndef DYNRPG_BATTLE_DATA_H
#define DYNRPG_BATTLE_DATA_H

#include <DynRPG/Enum/BattleEncounterCondition.h>
#include <DynRPG/Enum/BattleNavigationLevel.h>
#include <DynRPG/Enum/BattlePartyFormation.h>
#include <DynRPG/Enum/BattlePhase.h>
#include <DynRPG/Enum/BattleType.h>

#include <DynRPG/Battler.h>
#include <DynRPG/DList.h>
#include <DynRPG/DString.h>
#include <DynRPG/Image.h>
#include <DynRPG/Panorama.h>
#include <DynRPG/Window.h>

namespace RPG
{
/*! \brief Used for the data and settings for the current battle. (OMG YES)

	\sa RPG::battleData
	\sa RPG::BattleNavigationLevel
	\sa RPG::BattlePhase
	\sa RPG::BattlePartyFormation
	\sa RPG::BattleEncounterCondition
	\sa RPG::BattleType
*/
class BattleData
{
public:
	void** vTable;
	int _unknown_04;
	int _unknown_08;
	int monsterGroupId; //!< ID of the monster group
	DStringPtr backdropFilename; //!< The filename of the backdrop
	bool escapeAllowed; //!< Is escaping allowed?
	bool defeatAllowed; //!< Is defeat allowed? (This would cause a game over)
	bool firstStrike; // More research
	bool _unknown_17;
	int _unknown_18;
	Image* backdropImage; //!< The RPG::Image object of the backdrop
	BattleNavigationLevel_T navLevel; //!< Which window or action has the focus?
	bool isInitialized; //!< Has the battle been initialized?
	bool _unknown_22;
	bool _unknown_23;
	Window* winParty; //!< The RPG::Window object of the party
	Window* winFightEscape; //!< The RPG::Window object for fight/escape/autobattle
	Window* winCommand; //!< The RPG::Window object for commands
	Window* winSkill; //!< The RPG::Window object for skills
	Window* winItem; //!< The RPG::Window object for items
	Window* winPartyTarget; //!< The RPG::Window object for targetting party members
	Window* winMonTarget; //!< The RPG::Window object for targetting enemies
	Window* winAction; //!< The RPG::Window object for the action window!
	int actionMessageLineAmount; // More research
	int currentHeroId; //!< Party slot
	Battler* currentHero; //!< The RPG::Battler data for the currently commanded hero
	int _unknown_50;
	int _unknown_54;
	int fleeChance; //!< Percentage for escape (Formula: 50 + (100 - 100 * Avg Enemy AGI / Avg Hero AGI))
	DListPtr<char> battleProgress; // More research
	bool canvasRedrawn; //!< Was the canvas redrawn?

	/*! \brief If a hero is ready to act, their party index will be added to this array
		\note This array lists the heroes in the order that they become ready, so if hero 2 is the first to act, and hero 3 is next to act, readyPartySlot[0] = 1 (hero 2), readyPartySlot[1] = 2 (hero 3), readyPartySlot[2] = -1 (empty) and readyPartySlot[3] = -1 (empty)
	*/
	int readyPartySlot[4];
	int _unknown_74;
	bool isSys2CursorShown; //!< Is the system2 cursor currently on the screen?
	BattlePhase battlePhase; //!< The phase of the battle (you can use this for special conditions)
	/*! \brief Timer between the frame the last monster is defeated, and the end of battle message windows.

		Starts at 60 the moment the last enemy is defeated and counts back to 0 each frame (60 = 1 second)

	*/
	int battlEndTimer;
	bool isDefeat; //!< Was the party defeated? (you can use this for special actions upon losing the battle)
	bool isVictory; //!< Was the party victorious (you can use this for special actions upon winning the battle)
	int sys2CursorX; //!< The x-position of the System2 cursor
	int sys2CursorY; //!< The y-position of the System2 cursor
	BattlePartyFormation partyFormation; //!< The party's formation
	BattleEncounterCondition encounterCondition; //!< The condition of the battle encounter
	Panorama* backgroundFrame; //!< The background frame panorama object (defined by the terrain)
	Panorama* foregroundFrame; //!< The foreground frame panorama object (defined by the terrain)
	int terrainId; //!< The ID of the terrain
	Battler* reflectTarget; //!< If the current action is being reflected, the target of the reflecting spell.
	char reflectTargetRange; // More research
	bool isBattleAnimPlaying; // More research
	bool autoBattle; //!< is autoBattle enabled?
	bool _unknown_AB; // Used by RPS Patch
	BattleType battleType; //!< Is this a random encounter or did it start via event?
	char currentTargetRange; // More research
	bool _unknown_B1; // Used by RPS Patch
	bool _unknown_B2; // Used by RPS Patch
	int currentActingBattlerId; //!< Currently acting battler
	int currentActingHeroDbId; //!< Database ID of the currently acting hero, -1 = enemy
	int _unknown_BC;
	bool continueBattle; // More research
	bool eventReady; //!< Is an event command ready to be executed?
	bool delay; //!< Delay the battle (might be able to use this for long actions & animations)
	bool _unknown_C3;
};

/*! \ingroup game_objects
	\brief Data and settings for the current battle.

	Example:
	\code
std::string backdropName = RPG::battleData->backdropFilename.s_str());
	\endcode
*/
extern DYNRPG_API RPG::BattleData*& battleData;

}

#endif // DYNRPG_BATTLE_DATA_H
