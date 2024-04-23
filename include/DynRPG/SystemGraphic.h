#ifndef DYNRPG_SYSTEM_GRAPHIC_H
#define DYNRPG_SYSTEM_GRAPHIC_H

#include <DynRPG/Enum/SystemFont.h>

#include <DynRPG/FontImage.h>
#include <DynRPG/Image.h>

#include <string>

namespace RPG
{
/*! \brief Used to store the system and "system2" graphics
	\sa RPG::System
	\sa RPG::Image::setSystemPalette
*/
class DYNRPG_API SystemGraphic
{
public:
	void** vTable;
	Image* systemImage; //!< \c %System image
	Image* exFont; //!< Image file for glyphs

	FontImage font; //!< Placeholder for font structure

	bool systemTiled; //!< Is the window background tiled? (in-game version of RPG::DBSystem::systemTiled)
	SystemFont systemFont; //!< MS Gothic or MS Mincho? (in-game version of RPG::DBSystem::systemFont)  (See RPG::SystemFont)
	Image* system2Image; //!< \c System2 image

	/*! \brief Loads the font used for text drawing
		\param fontName Name of the font
		\warning This is an experimental function.
	*/
	void loadFont(std::string fontName);

	/*! \brief Changes the system graphic
		\param systemGraphicName Name of the font
		\param isTiled Tile the system graphic?
		\param isMincho Is the font MS Mincho?
		\warning This is an experimental function.
	*/
	void change(std::string systemGraphicName, bool isTiled, bool isMincho);
};
}

#endif // DYNRPG_SYSTEM_GRAPHIC_H
