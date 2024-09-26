/*
	DynRPG v0.30
	RM2k3 Plugin SDK
	by David "Cherry" Trapp
	http://cherrytree.at

	Update by Andrew King (PepsiOtaku)

	Include this file in your C++ project to work with the DynRPG SDK!
*/

#ifndef DYNRPG_H
#define DYNRPG_H

#include <DynRPG/DynRPGConfig.h>

#include <DynRPG/DynRPGRegisters.h>

#include <DynRPG/Action.h>
#include <DynRPG/Actor.h>
#include <DynRPG/Animation.h>
#include <DynRPG/Animation2.h>
#include <DynRPG/Animation2Pose.h>
#include <DynRPG/Animation2Weapon.h>
#include <DynRPG/AnimationCurrent.h>
#include <DynRPG/AnimationEffect.h>
#include <DynRPG/AnimationFrame.h>
#include <DynRPG/AnimationFrameCel.h>
#include <DynRPG/AnimationInBattle.h>
#include <DynRPG/AnimationSkill.h>
#include <DynRPG/AnimationWeapon.h>
#include <DynRPG/ArrayBaseOne.h>
#include <DynRPG/Attribute.h>
#include <DynRPG/BattleCommand.h>
#include <DynRPG/BattleData.h>
#include <DynRPG/BattleEvent.h>
#include <DynRPG/BattleEventPage.h>
#include <DynRPG/BattleEventTrigger.h>
#include <DynRPG/BattleSettings.h>
#include <DynRPG/Battler.h>
#include <DynRPG/Canvas.h>
#include <DynRPG/Catalog.h>
#include <DynRPG/CatalogPtr.h>
#include <DynRPG/Character.h>
#include <DynRPG/CharacterGraphics.h>
#include <DynRPG/ColorControl.h>
#include <DynRPG/CommonEvent.h>
#include <DynRPG/Condition.h>
#include <DynRPG/DArray.h>
#include <DynRPG/DBActor.h>
#include <DynRPG/DBClass.h>
#include <DynRPG/DBMonster.h>
#include <DynRPG/DBMonsterGroup.h>
#include <DynRPG/DBSystem.h>
#include <DynRPG/DBitmap.h>
#include <DynRPG/DList.h>
#include <DynRPG/DListPtr.h>
#include <DynRPG/DString.h>
#include <DynRPG/DStringPtr.h>
#include <DynRPG/Event.h>
#include <DynRPG/EventData.h>
#include <DynRPG/EventPage.h>
#include <DynRPG/EventPrecondition.h>
#include <DynRPG/EventScriptData.h>
#include <DynRPG/EventScriptLine.h>
#include <DynRPG/EventScriptList.h>
#include <DynRPG/FontImage.h>
#include <DynRPG/Hero.h>
#include <DynRPG/Image.h>
#include <DynRPG/Input.h>
#include <DynRPG/Inventory.h>
#include <DynRPG/Item.h>
#include <DynRPG/Map.h>
#include <DynRPG/MapEncounter.h>
#include <DynRPG/MapGraphics.h>
#include <DynRPG/MapLmuFile.h>
#include <DynRPG/MapProperties.h>
#include <DynRPG/MapStartPositions.h>
#include <DynRPG/MapTree.h>
#include <DynRPG/MapTreeProperties.h>
#include <DynRPG/Monster.h>
#include <DynRPG/MonsterBehavior.h>
#include <DynRPG/MonsterGroupPosition.h>
#include <DynRPG/MoveRoute.h>
#include <DynRPG/Music.h>
#include <DynRPG/NamedCatalog.h>
#include <DynRPG/NamedCatalogPtr.h>
#include <DynRPG/Panorama.h>
#include <DynRPG/ParsedCommentData.h>
#include <DynRPG/ParsedCommentParameter.h>
#include <DynRPG/Picture.h>
#include <DynRPG/SceneDebug.h>
#include <DynRPG/SceneEnterName.h>
#include <DynRPG/SceneFile.h>
#include <DynRPG/SceneGameOver.h>
#include <DynRPG/SceneMenu.h>
#include <DynRPG/SceneShop.h>
#include <DynRPG/SceneTitle.h>
#include <DynRPG/Screen.h>
#include <DynRPG/ScreenEffect.h>
#include <DynRPG/Skill.h>
#include <DynRPG/SkillProgression.h>
#include <DynRPG/Sound.h>
#include <DynRPG/Switches.h>
#include <DynRPG/System.h>
#include <DynRPG/SystemGraphic.h>
#include <DynRPG/Teleport.h>
#include <DynRPG/TeleportManagement.h>
#include <DynRPG/Terrain.h>
#include <DynRPG/Tileset.h>
#include <DynRPG/Variables.h>
#include <DynRPG/Vehicle.h>
#include <DynRPG/Vocabulary.h>
#include <DynRPG/WinApi.h>
#include <DynRPG/Window.h>
#include <DynRPG/WindowMenuEnd.h>
#include <DynRPG/WindowMenuEquip.h>
#include <DynRPG/WindowMenuItem.h>
#include <DynRPG/WindowMenuOrder.h>
#include <DynRPG/WindowMenuSkill.h>
#include <DynRPG/WindowMenuStatus.h>
#include <DynRPG/WindowMenuTarget.h>
#include <DynRPG/WindowMessage.h>
#include <DynRPG/WindowMessageBox.h>
#include <DynRPG/WindowSaveFile.h>

#include <DynRPG/DynRPGCallbacks.h>
#include <DynRPG/DynRPGGlobals.h>

#endif // DYNRPG_H
