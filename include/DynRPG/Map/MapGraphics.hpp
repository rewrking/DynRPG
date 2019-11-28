#ifndef RPG_MAP_GRAPHICS_HPP
#define RPG_MAP_GRAPHICS_HPP

#include <DynRPG/Delphi/DStringPtr.hpp>
#include <DynRPG/Graphics/Image.hpp>
#include <DynRPG/Tileset/Tileset.hpp>

namespace RPG
{
/*! \brief Serves as the pointer to the tileset, the filename of the Chipset
	and the data for the actual tiles??

	\sa RPG::MapProperties
	\sa RPG::Map
*/
struct MapGraphics
{
	// clang-format off
	void** vTable;
	Tileset* tileset; //!< The referenced tileset
	DStringPtr filename; //!< The filename of the tileset (again...)
	Image* chipsetImage; //!< The chipset's image
	// clang-format on
};
}

#endif // RPG_MAP_GRAPHICS_HPP