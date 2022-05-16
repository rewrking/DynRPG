#ifndef DYNRPG_MAP_TREE_PROPERTIES_H
#define DYNRPG_MAP_TREE_PROPERTIES_H

#include <DynRPG/Enum/MapAllowType.h>
#include <DynRPG/Enum/MapBgType.h>
#include <DynRPG/Enum/MapMusicType.h>
#include <DynRPG/Enum/MapTreeType.h>

#include <DynRPG/CatalogPtr.h>
#include <DynRPG/DStringPtr.h>
#include <DynRPG/MapEncounter.h>
#include <DynRPG/Music.h>

namespace RPG
{
/*! \brief The properties of a map (including some map tree data).

	\sa RPG::MapTree
	\sa RPG::MapTreeType
	\sa RPG::MapMusicType
	\sa RPG::MapBgType
	\sa RPG::MapAllowType

*/
class MapTreeProperties
{
public:
	void** vTable;
	int id; //!< ID of the map in the map tree. This INCLUDES areas. The id = 0 if it's the top level (Name of your game)
	DStringPtr name; //!< The name of the map in the map tree
	int _unknown_0C;
	int parentMapId; //!< ID of the parent map in the map tree
	int treeDepth; //!< The number value representing how deep the map is in the tree. A map within a map within a map within the main folder would be considered "2"
	MapTreeType_T treeEntryType; //!< The type of entry in the map tree.
	int _unknown_1C; // 86 on AREAs
	int _unknown_20; // -75 on AREAs
	bool isNotArea; //!< true if the map is not an area
	MapMusicType_T bgmType; //!< The type of music defined on the map
	Music* bgmSpecify; //!< The music pointer for the BGM file (See RPG::Music)
	MapBgType_T battleBgType; //!< The type of battle background defined on the map
	DStringPtr battleBgFilename; //!< The filename of the battle background
	MapAllowType_T teleportType; //!< Is teleporting using a skill allowed?
	MapAllowType_T escapeType; //!< Is escaping using a skill allowed?
	MapAllowType_T saveType; //!< Is saving allowed?
	CatalogPtr<MapEncounter*> encounterList; //!< The list of enemy encounters on the map
	int encounterRate; //!< The encounter rate on the map
	int areaStartX; //!< If the map is an area, the X value of the top-left.
	int areaStartY; //!< If the map is an area, the Y value of the top-left.
	int areaEndX; //!< If the map is an area, the X value of the bottom-right PLUS 1. Internally, 2k3 includes the top-left of a tile through the bottom-right of a tile for the area's rectangle, while the editor just considers the top-left.
	int areaEndY; //!< If the map is an area, the Y value of the bottom-right PLUS 1. Internally, 2k3 includes the top-left of a tile through the bottom-right of a tile for the area's rectangle, while the editor just considers the top-left.
	int _unknown_50;
};
}

#endif // DYNRPG_MAP_TREE_PROPERTIES_H
