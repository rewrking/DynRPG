#ifndef RPG_TELEPORT_HPP
#define RPG_TELEPORT_HPP

#include <DynRPG/Teleport/TeleportDirection.hpp>
#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
/*! \brief Class used for teleporting.
	\sa RPG::teleport
	\sa RPG::teleportManagement
	\sa RPG::Map::teleportHero()
*/
struct Teleport
{
	// clang-format off
	void** vTable;
	AuroraBoard* AuroraBoard1; //!< Not even a little bit implemented...
	AuroraBoard* AuroraBoard2; //!< Not even a little bit implemented...
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
	// clang-format on

	//! Simple function for teleporting
	static void teleportHero(int mapId = 1, int x = 0, int y = 0, TeleportDirection dir = TeleportDirection::RetainFacing);
};

/*! \ingroup game_objects
	\brief Teleport parameters.
*/
static Teleport*& teleport = (**reinterpret_cast<Teleport***>(0x4CDC1C));

}

#endif // RPG_TELEPORT_HPP