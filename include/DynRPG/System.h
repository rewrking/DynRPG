#ifndef DYNRPG_SYSTEM_H
#define DYNRPG_SYSTEM_H

#include <DynRPG/Enum/ATBMode.h>
#include <DynRPG/Enum/FacePosition.h>
#include <DynRPG/Enum/MessagePosition.h>
#include <DynRPG/Enum/Scene.h>
#include <DynRPG/Enum/SystemFont.h>
#include <DynRPG/Enum/Transition.h>

#include <DynRPG/DArray.h>
#include <DynRPG/DStringPtr.h>
#include <DynRPG/Music.h>
#include <DynRPG/Sound.h>
#include <DynRPG/SystemGraphic.h>

namespace RPG
{
/*! \brief Used for system data which can change in-game

	\note Many things are only stored in this class if they were changed
	and are now different from the default in the database, thus you
	should use the getter methods to access these things.
	\sa RPG::system
	\sa RPG::DBSystem
	\sa RPG::dbSystem
*/
class DYNRPG_API System
{
public:
	void** vTable;
	Scene_T scene; //!< Current game scene (see RPG::Scene)
	/*! \brief Internal frame counter (see details!)

		This frame counter will count every update of the game scene.
		Please <b>read the \ref onFrame documentation</b> too!
		\sa onFrame
	*/
	int frameCounter;
	DStringPtr systemGraphicFilename; //!< Filename of the system graphic (empty for default)
	bool systemTiled; //!< Is the window background tiled?
	SystemFont systemFont; //!< Current system font
	SystemGraphic* systemGraphic; //!< Current system and system2 graphic
	DArray<bool, 1> switches; //!< %Switches (see also RPG::Switch!)
	DArray<int, 1> variables; //!< %Variables (see also RPG::Variable!)
	bool messageTransparent; //!< Is the message background invisible? (see also RPG::BattleSettings::transparentWindows)
	MessagePosition messagePosition; //!< Position of the message
	bool messageAutoPos; //!< Prevent hero from being overlapped by a message?
	bool messageModal; //!< Should messages pause other event activites?
	DStringPtr faceFilename; //!< Filename of the current face
	int faceID; //!< ID of the sprite in the faceset
	FacePosition facePosition; //!< Position of the face
	bool faceMirrored; //!< Is the face mirrored?
	Image* faceImage; //!< RPG::Image of the face
	bool messageActive; //!< Is a message active?
	bool musicFade; //!< Is the music fading?
	Music* currentBGM; //!< Current background music
	Music* pedestrianBGM; //!< Background music which should be restored after the vehicle has been exited
	Music* mapBGM; //!< Background music on the map (used to restore music after battle)
	Music* memorizedBGM; //!< Memorized music
	Music* titleBGM; //!< Current title screen music (empty for default)
	Music* battleBGM; //!< Current battle music (empty for default)
	Music* victoryBGM; //!< Current victory music (empty for default)
	Music* innBGM; //!< Current inn music (empty for default)
	Music* skiffBGM; //!< Current skiff music (empty for default)
	Music* shipBGM; //!< Current ship music (empty for default)
	Music* airshipBGM; //!< Current airship music (empty for default)
	Music* gameOverBGM; //!< Current game over music (empty for default)
	Sound* cursorSE; //!< Current cursor sound (empty for default)
	Sound* decisionSE; //!< Current decision sound (empty for default)
	Sound* cancelSE; //!< Current cancel sound (empty for default)
	Sound* buzzerSE; //!< Current buzzer sound (empty for default)
	Sound* battleStartSE; //!< Current sound played at battle start (empty for default)
	Sound* fleeSE; //!< Current sound played when a battler escapes (empty for default)
	Sound* enemyAttackSE; //!< Current sound played when a monster attacks (empty for default)
	Sound* enemyDamageSE; //!< Current sound played when a monster is damaged (empty for default)
	Sound* heroDamageSE; //!< Current sound played when an actor is damaged (empty for default)
	Sound* evasionSE; //!< Current sound played when an attack is evaded (empty for default)
	Sound* enemyDeathSE; //!< Current sound played when a monster is killed (empty for default)
	Sound* itemSE; //!< Current sound played when an item is used (empty for default)
	Transition_T teleportEraseTrans; //!< Current screen erasing transition on teleport (see RPG::Transition)
	Transition_T teleportShowTrans; //!< Current screen showing transition on teleport (see RPG::Transition)
	Transition_T battleStartEraseTrans; //!< Current screen erasing transition on battle start (see RPG::Transition)
	Transition_T battleStartShowTrans; //!< Current screen showing transition on battle start (see RPG::Transition)
	Transition_T battleEndEraseTrans; //!< Current screen erasing transition on battle end (see RPG::Transition)
	Transition_T battleEndShowTrans; //!< Current screen showing transition on battle end (see RPG::Translation)
	bool teleportAllowed; //!< Are teleport skills allowed?
	bool escapeAllowed; //!< Are escaped skills allowed?
	bool saveAllowed; //!< Is saving allows?
	bool menuAllowed; //!< Is the game menu allowed?
	DStringPtr defaultBackdrop; //!< Filename of default backdrop
	int saveCount; //!< Number of times saved
	int lastSavedSlot; //!< The last save slot called
	ATBMode_T atbMode; //!< ATB mode

	//! Returns the current title screen music
	RPG::Music* getTitleBGM();
	//! Returns the current battle music
	RPG::Music* getBattleBGM();
	//! Returns the current victory music
	RPG::Music* getVictoryBGM();
	//! Returns the current inn music
	RPG::Music* getInnBGM();
	//! Returns the current skiff music
	RPG::Music* getSkiffBGM();
	//! Returns the current ship music
	RPG::Music* getShipBGM();
	//! Returns the current airship music
	RPG::Music* getAirshipBGM();
	//! Returns the current game over music
	RPG::Music* getGameOverBGM();

	//! Returns the current cursor sound
	RPG::Sound* getCursorSE();
	//! Returns the current decision sound
	RPG::Sound* getDecisionSE();
	//! Returns the current cancel sound
	RPG::Sound* getCancelSE();
	//! Returns the current buzzer sound
	RPG::Sound* getBuzzerSE();
	//! Returns the current battle start sound
	RPG::Sound* getBattleStartSE();
	//! Returns the current escape sound
	RPG::Sound* getFleeSE();
	//! Returns the current monster attack sound
	RPG::Sound* getEnemyAttackSE();
	//! Returns the current monster damage sound
	RPG::Sound* getEnemyDamageSE();
	//! Returns the current actor damage sound
	RPG::Sound* getHeroDamageSE();
	//! Returns the current evasion sound
	RPG::Sound* getEvasionSE();
	//! Returns the current monster death sound
	RPG::Sound* getEnemyDeathSE();
	//! Returns the current item sound
	RPG::Sound* getItemSE();

	//! Returns the current teleport screen erasing transition
	RPG::Transition getTeleportEraseTrans();
	//! Returns the current teleport screen showing transition
	RPG::Transition getTeleportShowTrans();
	//! Returns the current battle start screen erasing transition
	RPG::Transition getBattleStartEraseTrans();
	//! Returns the current battle start screen showing transition
	RPG::Transition getBattleStartShowTrans();
	//! Returns the current battle end screen erasing transition
	RPG::Transition getBattleEndEraseTrans();
	//! Returns the current battle end screen showing transition
	RPG::Transition getBattleEndShowTrans();
};

/*! \ingroup game_objects
	\brief Object of "system" data, used for values which can be changed
	in-game
	\sa RPG::dbSystem
*/

extern DYNRPG_API System*& system;
}

#endif // DYNRPG_SYSTEM_H
