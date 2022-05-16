#ifndef DYNRPG_DB_SYSTEM_H
#define DYNRPG_DB_SYSTEM_H

#include <DynRPG/Enum/MenuCommand.h>
#include <DynRPG/Enum/SystemFont.h>
#include <DynRPG/Enum/Transition.h>

#include <DynRPG/DArray.h>
#include <DynRPG/DStringPtr.h>
#include <DynRPG/Music.h>
#include <DynRPG/Sound.h>

namespace RPG
{
//! \cond
typedef void TestPlayer;
//! \endcond

/*! \brief Used for the default system data which is defined in the
	database

	\note The members of this class either mean default values of a
	property or they are used for properties which aren't supposed to be
	changed in-game, thus the members won't be saved and loaded
	automatically (as it is the case with RPG::System), but only loaded
	once at startup.\n\n
	If you want to access data which could be changed in-game, use the
	members and methods of RPG::System instead.\n\n
	\sa RPG::dbSystem
	\sa RPG::System
	\sa RPG::system
*/
class DBSystem
{
public:
	void** vTable;
	DStringPtr boatFilename; //!< Filename of the boat vehicle
	DStringPtr _unknown_8;
	DStringPtr shipFilename; //!< Filename of the ship vehicle
	DStringPtr _unknown_10;
	DStringPtr airshipFilename; //!< Filename of the airship vehicle
	DStringPtr _unknown_18;
	DStringPtr titleFilename; //!< Filename of the title screen
	DStringPtr gameOverFilename; //!< Filename of the game over screen
	DStringPtr systemGraphicFilename; //!< Default filename of the system graphic
	int _unknown_28;
	int _unknown_2C;
	Music* titleBGM; //!< Default title screen music
	Music* battleBGM; //!< Default battle music
	Music* victoryBGM; //!< Default victory music
	Music* innBGM; //!< Default inn music
	Music* skiffBGM; //!< Default skiff music
	Music* shipBGM; //!< Default ship music
	Music* airshipBGM; //!< Default airship music
	Music* gameOverBGM; //!< Default game over music
	Sound* cursorSE; //!< Default cursor moving sound
	Sound* decisionSE; //!< Default decision sound
	Sound* cancelSE; //!< Default cancel sound
	Sound* buzzerSE; //!< Default buzzer sound
	Sound* battleStartSE; //!< Default sound played at battle start
	Sound* fleeSE; //!< Default sound played when a battler escapes
	Sound* enemyAttackSE; //!< Default sound played when a monster attacks
	Sound* enemyDamageSE; //!< Default sound played when a monster is damaged
	Sound* heroDamageSE; //!< Default sound played when an actor is damaged
	Sound* evasionSE; //!< Default sound played when an attack is evaded
	Sound* enemyDeathSE; //!< Default sound played when a monster is killed
	Sound* itemSE; //!< Default sound played when an item is used
	Transition_T teleportEraseTrans; //!< Default screen erasing transition on teleport (see RPG::Transition)
	Transition_T teleportShowTrans; //!< Default screen showing transition on teleport (see RPG::Transition)
	Transition_T battleStartEraseTrans; //!< Default screen erasing transition on battle start (see RPG::Transition)
	Transition_T battleStartShowTrans; //!< Default screen showing transition on battle start (see RPG::Transition)
	Transition_T battleEndEraseTrans; //!< Default screen erasing transition on battle end (see RPG::Transition)
	Transition_T battleEndShowTrans; //!< Default screen showing transition on battle end (see RPG::Translation)
	bool systemTiled; //!< Is the window background tiled? (Default value)
	SystemFont systemFont; //!< Default system font
	int _unknown_90;
	int _unknown_94;
	DStringPtr _unknown_98;
	//! \cond
	TestPlayer* testPlayer;
	//! \endcond
	int _unknown_A0;
	int _unknown_A4;
	int _unknown_A8;
	// System 2 Tab
	DArray<MenuCommand_T> menuCommand; //!< Array of Menu Commands, set to the index of the menu item (see RPG::MenuCommand)
		//int _unknown_B0;
		//int _unknown_B4;
	DStringPtr system2GraphicFilename; //!< Default filename of the system2 graphic
	DStringPtr frameGraphicFilename; //!< Default filename of the frame graphic
	bool useFrame; //!< Use a frame?
	bool _unknown_B9;
	bool _unknown_BA;
	bool _unknown_BB;
	bool reverseBattleAnims; //!< Reverse Battle Animations when attacked from Behind
	bool _unknown_BD;
	bool _unknown_BE;
	bool _unknown_BF;
	bool itemUsableByClass; //!< Makes items usable by class instead of usable by hero. Not so sure though... untested...
};

/*! \ingroup game_objects
	\brief Object of "system" data, used for default values and properties
	which are not supposed to be changed in-game.
	\sa RPG::system
*/
extern DYNRPG_API RPG::DBSystem*& dbSystem;
}

#endif // DYNRPG_DB_SYSTEM_H
