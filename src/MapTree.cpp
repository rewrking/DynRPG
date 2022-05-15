#include <DynRPG/MapTree.h>

namespace RPG
{
int MapTree::getTreeIndex(int mapId)
{
	for (int i = 0; i < RPG::mapTree->properties.count(); i++)
	{
		if (mapTree->properties[i]->id == mapId)
			return i;
	}
	return -1;
}
}
