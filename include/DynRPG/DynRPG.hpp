/*
	DynRPG v0.30

	RM2k3 Plugin SDK
	by David "Cherry" Trapp
	http://cherrytree.at

	Updates by Andrew King (PepsiOtaku)

	Include this file in your C++ project to work with the DynRPG SDK!
*/

#ifndef DYNRPG_HPP
#define DYNRPG_HPP

#ifndef __GNUC__
	#error Sorry, DynRPG does only work with the GNU C++ compiler! See gcc.gnu.org
#endif // __GNUC__

#ifndef __cplusplus
	#error Sorry, DynRPG is a C++ SDK! Mind the plus plus :-)
#endif // __cplusplus

#if __GNUC__ < 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ < 7 || (__GNUC_MINOR__ == 7 && __GNUC_PATCHLEVEL__ < 1)))
	#error Sorry, this DynRPG version needs at least GNU C++ version 4.7.1! See gcc.gnu.org
#endif

// Note: Do not change the include order unless you know what you're doing!

// Some friendly helper types (uchar, uint, etc)
#include <DynRPG/Utility/Types.hpp>

#ifndef DYNRPG_MIN
	#include <DynRPG/Actor/Actor.hpp>
	#include <DynRPG/Actor/DamageMultiplier.hpp>
	#include <DynRPG/Actor/DBActor.hpp>
	#include <DynRPG/Actor/DBClass.hpp>
	#include <DynRPG/Actor/SkillProgression.hpp>
	//
	#include <DynRPG/Animation/Animation.hpp>
	#include <DynRPG/Animation/AnimationBattlerPose.hpp>
	#include <DynRPG/Animation/AnimationCurrent.hpp>
	#include <DynRPG/Animation/AnimationEffect.hpp>
	#include <DynRPG/Animation/AnimationEffectScope.hpp>
	#include <DynRPG/Animation/AnimationFrame.hpp>
	#include <DynRPG/Animation/AnimationFrameCel.hpp>
	#include <DynRPG/Animation/AnimationInBattle.hpp>
	#include <DynRPG/Animation/AnimationMoveBeforeAttack.hpp>
	#include <DynRPG/Animation/AnimationScope.hpp>
	#include <DynRPG/Animation/AnimationSkill.hpp>
	#include <DynRPG/Animation/AnimationTargetMonster.hpp>
	#include <DynRPG/Animation/AnimationWeapon.hpp>
	#include <DynRPG/Animation/AnimationYAxisLine.hpp>
	#include <DynRPG/Animation/WeaponNumberOfAttacks.hpp>
	#include <DynRPG/Animation/WeaponRangedAnimSpeed.hpp>
	//
	#include <DynRPG/Animation2/Anim2DisplaySpeed.hpp>
	#include <DynRPG/Animation2/Animation2.hpp>
	#include <DynRPG/Animation2/Animation2Pose.hpp>
	#include <DynRPG/Animation2/Animation2PoseType.hpp>
	#include <DynRPG/Animation2/Animation2Weapon.hpp>
	//
	#include <DynRPG/Attribute/Attribute.hpp>
	#include <DynRPG/Attribute/AttributeType.hpp>
	//
	#include <DynRPG/Audio/Music.hpp>
	#include <DynRPG/Audio/Sound.hpp>
	//
	#include <DynRPG/Battle/BattleCommand.hpp>
	#include <DynRPG/Battle/BattleCommandArchetype.hpp>
	#include <DynRPG/Battle/BattleData.hpp>
	#include <DynRPG/Battle/BattleEncounterCondition.hpp>
	#include <DynRPG/Battle/BattleEvent.hpp>
	#include <DynRPG/Battle/BattleEventPage.hpp>
	#include <DynRPG/Battle/BattleEventTrigger.hpp>
	#include <DynRPG/Battle/BattleEventUpdateMode.hpp>
	#include <DynRPG/Battle/BattleLayout.hpp>
	#include <DynRPG/Battle/BattleNavigationLevel.hpp>
	#include <DynRPG/Battle/BattlePartyFormation.hpp>
	#include <DynRPG/Battle/BattlePhase.hpp>
	#include <DynRPG/Battle/BattleSettings.hpp>
	#include <DynRPG/Battle/BattleType.hpp>
	#include <DynRPG/Battle/RandomEncounterDeath.hpp>
	#include <DynRPG/Battle/TriggerFlag.hpp>
	#include <DynRPG/Battle/TriggerFlag2k3.hpp>
	//
	#include <DynRPG/Battler/Action.hpp>
	#include <DynRPG/Battler/ActionKind.hpp>
	#include <DynRPG/Battler/ActionStatus.hpp>
	#include <DynRPG/Battler/ActionType.hpp>
	#include <DynRPG/Battler/BasicAction.hpp>
	#include <DynRPG/Battler/Battler.hpp>
	#include <DynRPG/Battler/BattleRow.hpp>
	#include <DynRPG/Battler/Target.hpp>
	#include <DynRPG/Battler/WeaponSlotInUse.hpp>
	//
	#include <DynRPG/Catalog/Catalog.hpp>
	#include <DynRPG/Catalog/CatalogPtr.hpp>
	#include <DynRPG/Catalog/NamedCatalog.hpp>
	#include <DynRPG/Catalog/NamedCatalogPtr.hpp>
	//
	#include <DynRPG/Character/AnimationFrameCharset.hpp>
	#include <DynRPG/Character/AnimationType.hpp>
	#include <DynRPG/Character/Character.hpp>
	#include <DynRPG/Character/Direction.hpp>
	#include <DynRPG/Character/Facing.hpp>
	#include <DynRPG/Character/Hero.hpp>
	#include <DynRPG/Character/HeroControlMode.hpp>
	#include <DynRPG/Character/HeroPanTransitionSpeed.hpp>
	#include <DynRPG/Character/HeroVehicle.hpp>
	#include <DynRPG/Character/Layer.hpp>
	#include <DynRPG/Character/Vehicle.hpp>
	//
	#include <DynRPG/Comment/ParameterType.hpp>
	#include <DynRPG/Comment/ParsedCommentData.hpp>
	#include <DynRPG/Comment/ParsedCommentParameter.hpp>
	//
	#include <DynRPG/CommonEvent/CommonEvent.hpp>
	#include <DynRPG/CommonEvent/CommonEventTrigger.hpp>
	//
	#include <DynRPG/Condition/ActionRestriction.hpp>
	#include <DynRPG/Condition/AlterationType.hpp>
	#include <DynRPG/Condition/BaseStatAlteration.hpp>
	#include <DynRPG/Condition/Condition.hpp>
	//
	#include <DynRPG/Delphi/DArray.hpp>
	#include <DynRPG/Delphi/DList.hpp>
	#include <DynRPG/Delphi/DListPtr.hpp>
	#include <DynRPG/Delphi/DString.hpp>
	#include <DynRPG/Delphi/DStringPtr.hpp>
	//
	#include <DynRPG/Event/Event.hpp>
	#include <DynRPG/Event/EventCommand.hpp>
	#include <DynRPG/Event/EventData.hpp>
	#include <DynRPG/Event/EventFrame.hpp>
	#include <DynRPG/Event/EventMoveFrequency.hpp>
	#include <DynRPG/Event/EventPage.hpp>
	#include <DynRPG/Event/EventPrecondition.hpp>
	#include <DynRPG/Event/EventPreconditionFlag.hpp>
	#include <DynRPG/Event/EventPreconditionVarLogic.hpp>
	#include <DynRPG/Event/EventScriptData.hpp>
	#include <DynRPG/Event/EventScriptLine.hpp>
	#include <DynRPG/Event/EventScriptList.hpp>
	#include <DynRPG/Event/EventTrigger.hpp>
	#include <DynRPG/Event/MoveRoute.hpp>
	#include <DynRPG/Event/MoveType.hpp>
	//
	#include <DynRPG/Graphics/Canvas.hpp>
	#include <DynRPG/Graphics/ColorControl.hpp>
	#include <DynRPG/Graphics/Image.hpp>
	#include <DynRPG/Graphics/Picture.hpp>
	#include <DynRPG/Graphics/PictureEffect.hpp>
	#include <DynRPG/Graphics/Screen.hpp>
	#include <DynRPG/Graphics/ScreenEffect.hpp>
	#include <DynRPG/Graphics/Transition.hpp>
	//
	#include <DynRPG/Input/Input.hpp>
	#include <DynRPG/Input/Key.hpp>
	#include <DynRPG/Input/KeyDown.hpp>
	#include <DynRPG/Input/KeyModifierDown.hpp>
	//
	#include <DynRPG/Item/Inventory.hpp>
	#include <DynRPG/Item/Item.hpp>
	#include <DynRPG/Item/ItemConditionFlag.hpp>
	#include <DynRPG/Item/ItemScrollMsgShown.hpp>
	#include <DynRPG/Item/ItemTarget.hpp>
	#include <DynRPG/Item/WeaponRangedTargetting.hpp>
	#include <DynRPG/Item/WeaponRangedTrajectory.hpp>
	//
	#include <DynRPG/Map/DungeonGenPassWidth.hpp>
	#include <DynRPG/Map/DungeonGenType.hpp>
	#include <DynRPG/Map/Map.hpp>
	#include <DynRPG/Map/MapAllowType.hpp>
	#include <DynRPG/Map/MapBackgroundType.hpp>
	#include <DynRPG/Map/MapEncounter.hpp>
	#include <DynRPG/Map/MapGraphics.hpp>
	#include <DynRPG/Map/MapLmuFile.hpp>
	#include <DynRPG/Map/MapMusicType.hpp>
	#include <DynRPG/Map/MapProperties.hpp>
	#include <DynRPG/Map/MapStartPositions.hpp>
	#include <DynRPG/Map/MapTree.hpp>
	#include <DynRPG/Map/MapTreeProperties.hpp>
	#include <DynRPG/Map/MapTreeType.hpp>
	#include <DynRPG/Map/MapWrapping.hpp>
	#include <DynRPG/Map/Panorama.hpp>
	//
	#include <DynRPG/Monster/DBMonster.hpp>
	#include <DynRPG/Monster/DBMonsterGroup.hpp>
	#include <DynRPG/Monster/Monster.hpp>
	#include <DynRPG/Monster/MonsterAlignment.hpp>
	#include <DynRPG/Monster/MonsterBehavior.hpp>
	#include <DynRPG/Monster/MonsterGroupPosition.hpp>
	#include <DynRPG/Monster/MonsterPrecondition.hpp>
	//
	#include <DynRPG/Scene/FileSceneMode.hpp>
	#include <DynRPG/Scene/MenuCommand.hpp>
	#include <DynRPG/Scene/MenuSubScreen.hpp>
	#include <DynRPG/Scene/Scene.hpp>
	#include <DynRPG/Scene/SceneDebug.hpp>
	#include <DynRPG/Scene/SceneEnterName.hpp>
	#include <DynRPG/Scene/SceneFile.hpp>
	#include <DynRPG/Scene/SceneGameOver.hpp>
	#include <DynRPG/Scene/SceneMenu.hpp>
	#include <DynRPG/Scene/SceneShop.hpp>
	#include <DynRPG/Scene/SceneTitle.hpp>
	#include <DynRPG/Scene/ShopSubScene.hpp>
	#include <DynRPG/Scene/ShopTransaction.hpp>
	#include <DynRPG/Scene/ShopVocabulary.hpp>
	//
	#include <DynRPG/Skill/Skill.hpp>
	#include <DynRPG/Skill/SkillTarget.hpp>
	#include <DynRPG/Skill/SkillType.hpp>
	//
	#include <DynRPG/Switch/Switch.hpp>
	#include <DynRPG/Switch/Switches.hpp>
	//
	#include <DynRPG/System/ATBMode.hpp>
	#include <DynRPG/System/DBSystem.hpp>
	#include <DynRPG/System/FontImage.hpp>
	#include <DynRPG/System/System.hpp>
	#include <DynRPG/System/SystemFont.hpp>
	#include <DynRPG/System/SystemGraphic.hpp>
	#include <DynRPG/System/Vocabulary.hpp>
	//
	#include <DynRPG/Teleport/Teleport.hpp>
	#include <DynRPG/Teleport/TeleportDirection.hpp>
	#include <DynRPG/Teleport/TeleportManagement.hpp>
	//
	#include <DynRPG/Terrain/Terrain.hpp>
	#include <DynRPG/Terrain/TerrainBattleType.hpp>
	#include <DynRPG/Terrain/TerrainGridDepth.hpp>
	#include <DynRPG/Terrain/TerrainSpriteDisplay.hpp>
	//
	#include <DynRPG/Tileset/TilePassability.hpp>
	#include <DynRPG/Tileset/Tileset.hpp>
	#include <DynRPG/Tileset/WaterAnimation.hpp>
	#include <DynRPG/Tileset/WaterSpeed.hpp>
	//
	#include <DynRPG/Utility/ArrayBaseOne.hpp>
	#include <DynRPG/Utility/AsmRegisters.hpp>
	#include <DynRPG/Utility/DBitmap.hpp>
	#include <DynRPG/Utility/Defines.hpp>
	#include <DynRPG/Utility/Win32.hpp>
	//
	#include <DynRPG/Variable/Variable.hpp>
	#include <DynRPG/Variable/Variables.hpp>
	//
	#include <DynRPG/Window/FacePosition.hpp>
	#include <DynRPG/Window/MessagePosition.hpp>
	#include <DynRPG/Window/Window.hpp>
	#include <DynRPG/Window/WindowMenuEnd.hpp>
	#include <DynRPG/Window/WindowMenuEquip.hpp>
	#include <DynRPG/Window/WindowMenuItem.hpp>
	#include <DynRPG/Window/WindowMenuOrder.hpp>
	#include <DynRPG/Window/WindowMenuSkill.hpp>
	#include <DynRPG/Window/WindowMenuStatus.hpp>
	#include <DynRPG/Window/WindowMenuTarget.hpp>
	#include <DynRPG/Window/WindowMessage.hpp>
	#include <DynRPG/Window/WindowMessageBox.hpp>
	#include <DynRPG/Window/WindowSaveFile.hpp>
#endif // DYNRPG_MIN

#include <DynRPG/Globals.hpp>

#include <DynRPG/DynCore/PluginCallbacks.hpp>

#ifdef AUTO_DLLMAIN
	#warning AUTO_DLLMAIN is deprecated as automatically adding a DllMain function is the default behaviour now. Use #define CUSTOM_DLLMAIN to achieve the reverse.
#endif

#endif // DYNRPG_HPP
