#include <DynRPG/Actor.h>
#include <DynRPG/Animation.h>
#include <DynRPG/Animation2.h>
#include <DynRPG/Attribute.h>
#include <DynRPG/BattleData.h>
#include <DynRPG/BattleEvent.h>
#include <DynRPG/BattleSettings.h>
#include <DynRPG/CommonEvent.h>
#include <DynRPG/Condition.h>
#include <DynRPG/DBActor.h>
#include <DynRPG/DBClass.h>
#include <DynRPG/DBMonster.h>
#include <DynRPG/DBMonsterGroup.h>
#include <DynRPG/DBSystem.h>
#include <DynRPG/DynRPGGlobals.h>
#include <DynRPG/Hero.h>
#include <DynRPG/Input.h>
#include <DynRPG/Inventory.h>
#include <DynRPG/Item.h>
#include <DynRPG/Map.h>
#include <DynRPG/MapTree.h>
#include <DynRPG/Monster.h>
#include <DynRPG/Panorama.h>
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
#include <DynRPG/Switches.h>
#include <DynRPG/System.h>
#include <DynRPG/Teleport.h>
#include <DynRPG/TeleportManagement.h>
#include <DynRPG/Terrain.h>
#include <DynRPG/Tileset.h>
#include <DynRPG/Variables.h>
#include <DynRPG/Vehicle.h>
#include <DynRPG/WindowMessage.h>

namespace RPG
{
void*** sceneObjects[] = {
	(void***)0x4CDC1C, (void***)0x4CDC60, (void***)0x4CDD38, (void***)0x4CDE4C, (void***)0x4CDBF4, (void***)0x4CDFCC, (void***)0x4CDB94, (void***)0x4CE008, (void***)0x4CDD4C
};

bool& isTestPlay = (**reinterpret_cast<bool**>(0x4CDD50));

bool& isBattleTest = (**reinterpret_cast<bool**>(0x4CDCB8));

bool& showTitle = (**reinterpret_cast<bool**>(0x4CDF90));

bool& showingLogo = (**reinterpret_cast<bool**>(0x4CDADC));

int& battleSpeed = (*reinterpret_cast<int*>(0x442600));

bool& transparentWindowsEverywhere = (*reinterpret_cast<bool*>(0x442604));

RPG::Switches switches __attribute__((unused));
RPG::Variables variables __attribute__((unused));

//

NamedCatalogPtr<Actor*>& actors = (**reinterpret_cast<NamedCatalogPtr<Actor*>**>(0x4CDDC8));

NamedCatalogPtr<Animation*>& battleAnimations = (**reinterpret_cast<NamedCatalogPtr<Animation*>**>(0x4CDDC4));

NamedCatalogPtr<Animation2*>& battlerAnimations = (**reinterpret_cast<NamedCatalogPtr<Animation2*>**>(0x4CDC90));

NamedCatalogPtr<Attribute*>& attributes = (**reinterpret_cast<NamedCatalogPtr<Attribute*>**>(0x4CDE44));

BattleData*& battleData = (**reinterpret_cast<BattleData***>(0x4CDD38));

BattleEvent*& battleEvents = (**reinterpret_cast<BattleEvent***>(0x4CDB10));

BattleSettings*& battleSettings = (**reinterpret_cast<BattleSettings***>(0x4CDD60));

Hero*& hero = (**reinterpret_cast<Hero***>(0x4CDE54));

Vehicle*& vehicleSkiff = (**reinterpret_cast<Vehicle***>(0x4CE00C));

Vehicle*& vehicleShip = (**reinterpret_cast<Vehicle***>(0x4CE034));

Vehicle*& vehicleAirship = (**reinterpret_cast<Vehicle***>(0x4CDE68));

NamedCatalogPtr<CommonEvent*>& commonEvents = (**reinterpret_cast<NamedCatalogPtr<CommonEvent*>**>(0x4CDF40));

NamedCatalogPtr<Condition*>& conditions = (**reinterpret_cast<NamedCatalogPtr<Condition*>**>(0x4CDE84));

NamedCatalogPtr<DBActor*>& dbActors = (**reinterpret_cast<NamedCatalogPtr<DBActor*>**>(0x4CDD54));

NamedCatalogPtr<DBClass*>& dbClasses = (**reinterpret_cast<NamedCatalogPtr<DBClass*>**>(0x4CDD7C));

NamedCatalogPtr<DBMonster*>& dbMonsters = (**reinterpret_cast<NamedCatalogPtr<DBMonster*>**>(0x4CDE0C));

NamedCatalogPtr<DBMonsterGroup*>& dbMonsterGroups = (**reinterpret_cast<NamedCatalogPtr<DBMonsterGroup*>**>(0x4CDDC0));

DBSystem*& dbSystem = (**reinterpret_cast<DBSystem***>(0x4CDC0C));

Input*& input = (**reinterpret_cast<Input***>(0x4CDAEC));

Inventory*& inventory = (**reinterpret_cast<Inventory***>(0x4CDB74));

ScreenEffect*& effect = (**reinterpret_cast<ScreenEffect***>(0x4CDDA8));

Screen*& screen = (**reinterpret_cast<Screen***>(0x4CDB24));

NamedCatalogPtr<Item*>& items = (**reinterpret_cast<NamedCatalogPtr<Item*>**>(0x4CDB14));

Map*& map = (**reinterpret_cast<Map***>(0x4CDD74));

MapTree*& mapTree = (**reinterpret_cast<MapTree***>(0x4CDCF4));

CatalogPtr<Monster*>& monsters = (**reinterpret_cast<CatalogPtr<Monster*>**>(0x4CDE64));

Panorama*& panorama = (**reinterpret_cast<Panorama***>(0x4CDBBC));

NamedCatalogPtr<Picture*>& pictures = (**reinterpret_cast<NamedCatalogPtr<Picture*>**>(0x4CDF3C));

SceneDebug*& debug = (**reinterpret_cast<SceneDebug***>(0x4CDD4C));
SceneEnterName*& enterName = (**reinterpret_cast<SceneEnterName***>(0x4CDBF4));
SceneFile*& fileSaveLoad = (**reinterpret_cast<SceneFile***>(0x4CDFCC));
SceneGameOver*& gameOver = (**reinterpret_cast<SceneGameOver***>(0x4CE008));
SceneMenu*& menu = (**reinterpret_cast<SceneMenu***>(0x4CDC60));
SceneShop*& shop = (**reinterpret_cast<SceneShop***>(0x4CDE4C));
SceneTitle*& title = (**reinterpret_cast<SceneTitle***>(0x4CDB94));

WindowMessage*& winMessage = (**reinterpret_cast<WindowMessage***>(0x4CDEF4));

System*& system = (**reinterpret_cast<System***>(0x4CDC7C));

NamedCatalogPtr<Skill*>& skills = (**reinterpret_cast<NamedCatalogPtr<Skill*>**>(0x4CDBC4));

Teleport*& teleport = (**reinterpret_cast<Teleport***>(0x4CDC1C));

TeleportManagement*& teleportManagement = (**reinterpret_cast<TeleportManagement***>(0x4CDB50));

NamedCatalogPtr<Terrain*>& terrains = (**reinterpret_cast<NamedCatalogPtr<Terrain*>**>(0x4CDD80));

DStringPtr*& vocabulary = (**reinterpret_cast<DStringPtr***>(0x4CDCB4));

NamedCatalogPtr<Tileset*>& tilesets = (**reinterpret_cast<NamedCatalogPtr<Tileset*>**>(0x4CDD0C));
}
