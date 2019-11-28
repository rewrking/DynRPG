#define DYNRPG_STATIC
#include <DynRPG/Teleport/Teleport.hpp>

namespace RPG
{
/******************************************************************************
 *
 *****************************************************************************/
void teleportHero(int mapId = 1, int x = 0, int y = 0, TeleportDirection dir = TeleportDirection::RetainFacing)
{
	teleport->mapId = mapId;
	teleport->mapX = x;
	teleport->mapY = y;
	teleport->facingDirection = dir;
	teleport->teleportTrigger = true;
}
}
