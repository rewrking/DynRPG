#ifndef DYNRPG_TERRAIN_SPRITE_DISPLAY_H
#define DYNRPG_TERRAIN_SPRITE_DISPLAY_H

namespace RPG
{
/*! \brief Possible values for RPG::Terrain::spriteDisplay

	Sprite display controls how the hero sprite will appear when walking over the terrain.
*/
enum TerrainSpriteDisplay
{
	TSD_DISP_NORMAL,
	TSD_DISP_OBSCURE_THIRD, //!< One-third of the sprite is semi-transparent
	TSD_DISP_OBSCURE_HALF, //!< Half of the sprite is semi-transparent
	TSD_DISP_SEMI_TRANSPARENT, //!< ALl of the sprite is semi-transparent
};

//! One-byte version or RPG::TilePassability
typedef unsigned char TerrainSpriteDisplay_T;
}

#endif // DYNRPG_TERRAIN_SPRITE_DISPLAY_H
