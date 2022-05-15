#ifndef DYNRPG_TELEPORT_H
#define DYNRPG_TELEPORT_H

#include <DynRPG/Enum/TeleportDirection.h>

namespace RPG
{
/*! \brief Class used for teleporting.
	\sa RPG::teleport
	\sa RPG::teleportManagement
	\sa RPG::teleportHero()
*/
class Teleport
{
public:
	void** vTable;
	void* AuroraBoard1; //!< Not even a little bit implemented...
	void* AuroraBoard2; //!< Not even a little bit implemented...
	bool initialized; //!< Possibly checks if the screen initialized? Not sure about this one...
	bool teleportTrigger; //!< Set teleport parameters, and then set this to true to actually teleport;
		//bool _unknown_0E;
		//bool _unknown_0F;
	int mapId; //!< Map ID to teleport to
	int mapX; //!< Map X-coordinate to teleport to
	int mapY; //!< Map Y-coordinate to teleport to
	int _unknown_1C;
	TeleportDirection facingDirection; //!< The direction to face after teleporting
	//void teleportHero(int mapId, int x, int y, TeleportDirection dir);
};

/*! \ingroup game_objects
	\brief Teleport parameters.
*/
extern DYNRPG_API RPG::Teleport*& teleport;
}

#endif // DYNRPG_TELEPORT_H
