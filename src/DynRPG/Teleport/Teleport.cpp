#define DYNRPG_STATIC
#include <DynRPG/Teleport/Teleport.hpp>

namespace RPG
{
/******************************************************************************
 *
 *****************************************************************************/
void Teleport::teleportHero(int mapId, int x, int y, TeleportDirection dir)
{
	teleport->mapId = mapId;
	teleport->mapX = x;
	teleport->mapY = y;
	teleport->facingDirection = dir;
	teleport->teleportTrigger = true;
}
}
