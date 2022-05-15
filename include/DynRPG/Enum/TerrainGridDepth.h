#ifndef DYNRPG_TERRAIN_GRID_DEPTH_H
#define DYNRPG_TERRAIN_GRID_DEPTH_H

namespace RPG
{
/*! \brief Possible values for RPG::Terrain::gridDepth

	These are basically presets for the grid shape. TGD_NONE encompasses any custom grid shapes
	set via gridTopY,  gridElongation & gridInclination, equivalent to clicking on the grid graphic
	and adjusting the lines.
*/
enum TerrainGridDepth
{
	TGD_NONE,
	TGD_SHALLOW,
	TGD_DEEP
};
}

#endif // DYNRPG_TERRAIN_GRID_DEPTH_H
