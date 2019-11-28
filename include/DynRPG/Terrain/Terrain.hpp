#ifndef RPG_TERRAIN_HPP
#define RPG_TERRAIN_HPP

#include <DynRPG/Audio/Sound.hpp>
#include <DynRPG/Catalog/NamedCatalogPtr.hpp>
#include <DynRPG/Delphi/DStringPtr.hpp>
#include <DynRPG/Terrain/TerrainBattleType.hpp>
#include <DynRPG/Terrain/TerrainGridDepth.hpp>
#include <DynRPG/Terrain/TerrainSpriteDisplay.hpp>
#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
/*! \brief Used for the data of terrains which can be accessed or changed in-game.

	\sa RPG::terrains
	\sa RPG::SpriteDisplay
	\sa RPG::TerrainBattleType
	\sa RPG::TerrainGridDepth
*/
class Terrain
{
public:
	void** vTable;
	int id; //!< ID of the terrain
	DStringPtr name; //!< The name of the terrain in the database
	int damage; //!< The amount of damage the terrain does
	int encounterMultiplier; //!< Percentage to multiply the encounter rate by on the type of terrain
	DStringPtr backdropFilename; //!< The name of the terrain's backdrop
	bool boatCanPass; //!< Boat/Skiff can pass
	bool shipCanPass; //!< Ship can pass
	bool airshipCanPass; //!< Airship can pass
	bool airshipCanLand; //!< Airship can land
	TerrainSpriteDisplay spriteDisplay; //!< The sprite's opacity settings
	Sound* soundEffect; //!< Plays a sound effect while walking on this type of terrain
	bool playSoundOnlyIfDamaged; //!< Plays the defined sound effect only if damaged
	char _unknown_25;
	char _unknown_26;
	char _unknown_27;
	bool bgIsFrame; //!< Does the background use frames?
	TerrainBattleType battleTypes; //!< The special battle types allowed on this terrain
	int initiativePercent; //!< "Initiative" battle type percentage
	int backAtkPercent; //!< "Back Attack" battle type percentage
	int surroundAtkPercent; //!< "Surround Attack" battle type percentage
	int pincersAtkPercent; //!< "Pincers Attack" battle type percentage
	TerrainGridDepth gridDepth; //!< The terrain's grid depth of field
	int gridTopY; //!< Y-position of the top of the grid
	int gridElongation; //!< The top/bottom stretch value of the grid
	int gridInclination; //!< The value of the grid's inward stretch towards the top

	DStringPtr frameBgFilename; //!< The name of the terrain's background frame
	bool frameBgHorScroll; //!< Does the frame bg horizontally scroll?
	bool frameBgVerScroll; //!< Does the frame bg vertically scroll?
	int frameBgHorScrollSpeed; //!< Frame bg's horizontal scroll speed
	int frameBgVerScrollSpeed; //!< Frame bg's vertical scroll speed

	bool frameFgFlag; //!< Does the frame have a foreground?

	DStringPtr frameFgFilename; //!< The name of the terrain's foreground frame
	bool frameFgHorScroll; //!< Does the frame fg horizontally scroll?
	bool frameFgVerScroll; //!< Does the frame fg vertically scroll?
	int frameFgHorScrollSpeed; //!< Frame fg's horizontal scroll speed
	int frameFgVerScrollSpeed; //!< Frame fg's vertical scroll speed
};

/*! \ingroup game_objects
	\brief Array of terrains from the database, used for default values and
	properties which are not supposed to be changed in-game.

	Use the database ID as index for accessing a terrain.

	Example:
	\code
int temp = RPG::terrains[36]->frameBgHorScrollSpeed;
	\endcode
*/
static NamedCatalogPtr<Terrain*>& terrains = (**reinterpret_cast<NamedCatalogPtr<Terrain*>**>(0x4CDD80));
}

#endif // RPG_TERRAIN_HPP