#ifndef RPG_TERRAIN_GRID_DEPTH_HPP
#define RPG_TERRAIN_GRID_DEPTH_HPP

namespace RPG
{
/*! \brief Possible values for RPG::Terrain::gridDepth

	These are basically presets for the grid shape. TGD_NONE encompasses any custom grid shapes
	set via gridTopY,  gridElongation & gridInclination, equivalent to clicking on the grid graphic
	and adjusting the lines.
*/
enum class TerrainGridDepth
{
	None,
	Shallow,
	Deep
};
}

#endif // RPG_TERRAIN_GRID_DEPTH_HPP
