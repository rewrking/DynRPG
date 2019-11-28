#define DYNRPG_STATIC
#include <DynRPG/Map/MapTree.hpp>

namespace RPG
{
/******************************************************************************
 *
 *****************************************************************************/
int MapTree::getTreeIndex(int mapId)
{
	for (int i = 0; i < mapTree->properties.count(); i++)
	{
		if (mapTree->properties[i]->id == mapId)
			return i;
	}
	return -1;
}
}
