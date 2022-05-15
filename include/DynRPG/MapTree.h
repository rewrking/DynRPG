#ifndef DYNRPG_MAP_TREE_H
#define DYNRPG_MAP_TREE_H

#include <DynRPG/Catalog.h>
#include <DynRPG/MapStartPositions.h>
#include <DynRPG/MapTreeProperties.h>

namespace RPG
{
/*! \brief Used for the default data of monster groups which are defined in the
	database

	\sa RPG::mapTree
	\sa RPG::MapTreeProperites
	\sa RPG::MapEncounter
	\sa RPG::MapStartPositions
*/

class DYNRPG_API MapTree
{
public:
	void** vTable;
	int _unknown_04;
	/*! \brief The map properties for a certain map in this array

		\note The array index does not always equal the map's id, so map 134 might be properties[125]. Use getTreeIndex(##) or mapTree->properties[##]->id to check if the map in the array is the one you're looking for.
	*/
	Catalog<MapTreeProperties*> properties;
	int _unknown_0C;
	int lastMapId; //!< ID of the most recently created/changed map.
	MapStartPositions* startPositions; //!< The start positions for the hero and vehicles

	/*! \brief Gets the map tree index of a map
		\return The index of the requested map ID
	*/
	int getTreeIndex(int mapId);
};

/*! \ingroup game_objects
	\brief The map tree, used for default values and properties which are not supposed to be changed in-game.

	Example:
	\code
bool isThisAnArea = RPG::mapTree->properties[id]->isArea;
int parent = RPG::mapTree->properties[RPG::mapTree->getMapTreeIndex(id)]->parentMapId;
	\endcode
	\sa RPG::map
*/
extern DYNRPG_API MapTree*& mapTree;
}

#endif // DYNRPG_MAP_TREE_H
