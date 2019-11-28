#ifndef RPG_PANORAMA_HPP
#define RPG_PANORAMA_HPP

#include <DynRPG/Delphi/DStringPtr.hpp>
#include <DynRPG/Graphics/Image.hpp>

namespace RPG
{
/*! \brief Used to define a panorama object (ie. battle frames), or the panorama/frame on a particular map
	\sa RPG::Map
*/
struct Panorama
{
	void** vTable;
	int panoramaOffsetX; //!< PanOffset(x-Axis) (32 for each pixel)
	int panoramaOffsetY; //!< PanOffset(y-Axis) (32 for each pixel) - 2048 during testing... ?
	Image* image; //!< The panorama's image (see RPG::Image)
	int imageWidth; //!< The width of the panorama (in pixels)
	int imageHeight; //!< The height of the panorama (in pixels)
	DStringPtr filename; //!< The filename of the panorama's image
	bool enabled; //!< Is the panorama enabled?
	bool horScroll; //!< Is horizontal scrolling enabled?
	bool verScroll; //!< Is vertical scrolling enabled?
	bool horAutoscroll; //!< Is horizontal auto-scrolling enabled?
	bool verAutoscroll; //!< Is vertical auto-scrolling enabled?
	bool verWrapping; //!< Is vertical wrapping enabled? If the map is set to "Both" than RPG::Panorama::horWrapping will also be set to true
	bool horWrapping; //!< Is horizontal wrapping enabled? If the map is set to "Both" than RPG::Panorama::verWrapping will also be set to true
	bool isPanorama; //!< 1 if Panorama, 0 if Frame
	int horScrollSpeed; //!< If horizontal scrolling enabled, this is the defined speed
	int verScrollSpeed; //!< If horizontal scrolling enabled, this is the defined speed
	int mapWidth; //!< Map width (in tiles)
	int mapHeight; //!< Map height (in tiles)
};

/*! \ingroup game_objects
	\brief Settings for the panorama on the current map.

	Example:
	\code
std::string panoramaName = RPG::panorama->filename.s_str());
	\endcode
*/
static Panorama*& panorama = (**reinterpret_cast<Panorama***>(0x4CDBBC));
}

#endif // RPG_PANORAMA_HPP