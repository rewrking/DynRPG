#ifndef DYNRPG_MAP_H
#define DYNRPG_MAP_H

#include <DynRPG/DStringPtr.h>
#include <DynRPG/Event.h>
#include <DynRPG/MapProperties.h>
#include <DynRPG/NamedCatalogPtr.h>

namespace RPG
{
//! Not implemented yet
typedef void Chipset;

/*! \brief Used for accessing and manipulating the current map environment
	\sa RPG::map
*/
class DYNRPG_API Map
{
public:
	void** vTable;
	int cameraSubX; //!< X position of the camera <b>in units of 1/16th of a pixel</b>
	int cameraSubY; //!< Y position of the camera <b>in units of 1/16th of a pixel</b>
	int encounterRateNew; //!< If the encounter rate is changed by event command, it's stored here
	int chipsetIdNew; //!< If the chipset id is changed by event command, it's stored here
	Chipset* chipset; //!< Pointer to the map's chipset (not yet implemented)
	NamedCatalogPtr<Event*> events; //!< Array of events (use event ID as index)
	unsigned char lowerTileIdNew[144]; //!< Lower tile ID? if changed via tile substitution event command (zero-based. index = old tile id, value = new tile id)
	unsigned char upperTileIdNew[144]; //!< Upper tile ID? if changed via tile substitution event command (zero-based. index = old tile id, value = new tile id)
	DStringPtr panoramaFilenameNew; //!< The filename of the panorama's image (if set by event command)
	bool horScrollNew; //!< Is horizontal scrolling enabled? (if set by event command)
	bool verScrollNew; //!< Is vertical scrolling enabled? (if set by event command)
	bool horAutoscrollNew; //!< Is horizontal auto-scrolling enabled? (if set by event command)
	int horScrollSpeedNew; //!< If horizontal scrolling enabled, this is the defined speed (if set by event command)
	bool verAutoscrollNew; //!< Is vertical auto-scrolling enabled? (if set by event command)
	int verScrollSpeedNew; //!< If horizontal scrolling enabled, this is the defined speed (if set by event command)

	//! Returns the current X position of the camera in pixels (this value means the position of the upper-left screen pixel of the screen on the map)
	int getCameraX();

	//! Returns the current Y position of the camera in pixels (this value means the position of the upper-left screen pixel of the screen on the map)
	int getCameraY();

	/*! \brief Sets a new camera position
		\param x New X position (pixels)
		\param y New Y position (pixels)
		\note This method also updates the camera "memory", so that the
		"Return to origin" function works
	*/
	void setCamera(int x, int y);

	/*! \brief Moves the camera (pixel-exact)

		This function can move the camera the specified amount of
		pixels in the specified speed.
		\param offsetX Amount of pixels to move horizontally (may also be negative)
		\param offsetY Amount of pixels to move vertically (may also be negative)
		\param speed Exact speed, in units of 3.75 pixels per second (1/16 tile per frame)
		\sa RPG::Character::customExactSpeed
	*/
	void moveCamera(int offsetX, int offsetY, int speed);

	//! Returns the width of the current map
	int getWidth();

	//! Returns the height of the current map
	int getHeight();

	/*! \brief Updates the start conditions of events after a change

		This function can be used to re-check the start conditions of
		all events. This is necessary if you modify a switch from
		DynRPG which is start condition of an event, for example.
	*/
	void updateEvents();

	/*! \brief Gets the tile ID for the lower layer tile at the specified coordinate
		\param x The Y coordinate of the tile
		\param y The Y coordinate of the tile
		\sa RPG::Tileset::lowerTilePassability
	*/
	int getLowerLayerTileId(int x, int y);

	/*! \brief Gets the tile ID for the upper layer tile at the specified coordinate
		\param x The Y coordinate of the tile
		\param y The Y coordinate of the tile
		\sa RPG::Tileset::upperTilePassability
	*/
	int getUpperLayerTileId(int x, int y);

	/*! \brief Gets the terrain ID for the tile ID specified
		\param tileId The tile's id
		\sa RPG::Tileset::lowerTileTerrainId
	*/
	int getTerrainId(int tileId);

	/*! \brief Gets the event ID at the position specified, or
		\param x The Y coordinate of the event
		\param y The Y coordinate of the event
		\return The event ID, or 0 if no event was found
	*/
	int getEventAt(int x, int y);

	/*! \brief Returns the map properties information for the map that is
		currently loaded
		\return Pointer to the current map's properties
		\sa RPG::MapProperties
		\sa RPG::MapTreeProperties
	*/
	static MapProperties*& properties;
};

/*! \ingroup game_objects
	\brief The current map environment (camera, events, etc.)

	For accessing events, use <tt>RPG::map->events[<i>event ID</i>]</tt>.
	\sa RPG::mapTree
*/
extern DYNRPG_API Map*& map;
}

#endif // DYNRPG_MAP_H
