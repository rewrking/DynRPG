#ifndef RPG_TILESET_HPP
#define RPG_TILESET_HPP

#include <DynRPG/Catalog/NamedCatalogPtr.hpp>
#include <DynRPG/Delphi/DStringPtr.hpp>
#include <DynRPG/Tileset/TilePassability.hpp>
#include <DynRPG/Tileset/WaterAnimation.hpp>
#include <DynRPG/Tileset/WaterSpeed.hpp>
#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
/*! \brief Used for the data of tilesets which can be accessed or changed in-game.

	\sa RPG::tilesets
	\sa RPG::TilePassability
	\sa RPG::WaterAnimation
	\sa RPG::WaterSpeed
*/
struct Tileset
{
	void** vTable;
	int id; //!< ID of the tileset
	DStringPtr name; //!< The name of the tileset in the database
	DStringPtr filename; //!< The filename of the tileset
	ushort lowerTileTerrainId[162]; //!< The lower tile layer's terrain ID (See RPG::Terrain)
	TilePassability_T lowerTilePassability[162]; //!< The lower tile layer's passability (See RPG::TilePassability)
	TilePassability_T upperTilePassability[144]; //!< The upper tile layer's passability (See RPG::TilePassability)
	WaterAnimation waterAnim; //!< The tileset's water animation sequence (See RPG::WaterAnimation)
	WaterSpeed waterSpeed; //!< The tileset's water speed value (See RPG::WaterSpeed)
};

/*! \ingroup game_objects
	\brief Array of tilesets from the database, used for default values and
	properties which are not supposed to be changed in-game.

	Use the database ID as index for accessing a tileset.

	Example:
	\code
if (RPG::tilesets[2]->lowerTilePassability[36] == (RPG::CP_STAR + RPG::CP_O)) do some stuff...
	\endcode
*/
static NamedCatalogPtr<Tileset*>& tilesets = (**reinterpret_cast<NamedCatalogPtr<Tileset*>**>(0x4CDD0C));
}

#endif // RPG_TILESET_HPP