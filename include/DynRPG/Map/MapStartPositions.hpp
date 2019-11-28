#ifndef RPG_MAP_START_POSITIONS_HPP
#define RPG_MAP_START_POSITIONS_HPP

namespace RPG
{
/*! \brief Access to the starting positions of the party and the vehicles.

	\sa RPG::MapTree
*/
struct MapStartPositions
{
	void** vTable;
	int partyStartMapId; //!< The map ID of the party starting position
	int partyStartMapX; //!< The X-coordinate of the party starting position
	int partyStartMapY; //!< The Y-coordinate of the party starting position
	int skiffStartMapId; //!< The map ID of the skiff vehicle's starting position
	int skiffStartMapX; //!< The X-coordinate of the skiff vehicle's starting position
	int skiffStartMapY; //!< The Y-coordinate of the skiff vehicle's starting position
	int shipStartMapId; //!< The map ID of the ship vehicle's starting position
	int shipStartMapX; //!< The X-coordinate of the ship vehicle's starting position
	int shipStartMapY; //!< The Y-coordinate of the ship vehicle's starting position
	int airshipStartMapId; //!< The map ID of the airship vehicle's starting position
	int airshipStartMapX; //!< The X-coordinate of the airship vehicle's starting position
	int airshipStartMapY; //!< The Y-coordinate of the airship vehicle's starting position
};

}

#endif // RPG_MAP_START_POSITIONS_HPP