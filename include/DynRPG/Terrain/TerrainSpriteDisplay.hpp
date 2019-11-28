#ifndef RPG_TERRAIN_SPRITE_DISPLAY_HPP
#define RPG_TERRAIN_SPRITE_DISPLAY_HPP

#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
/*! \brief Possible values for RPG::Terrain::spriteDisplay

	Sprite display controls how the hero sprite will appear when walking over the terrain.
*/
enum class TerrainSpriteDisplay : uchar
{
	Normal,
	ObscureThird, //!< One-third of the sprite is semi-transparent
	ObscureHalf, //!< Half of the sprite is semi-transparent
	SemiTransparent, //!< ALl of the sprite is semi-transparent
};

//! One-byte version or RPG::TilePassability
//typedef uchar TerrainSpriteDisplay_T;
}

#endif // RPG_TERRAIN_SPRITE_DISPLAY_HPP
