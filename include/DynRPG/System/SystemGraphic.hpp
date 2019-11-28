#ifndef RPG_SYSTEM_GRAPHIC_HPP
#define RPG_SYSTEM_GRAPHIC_HPP

#include <string>

#include <DynRPG/Graphics/Image.hpp>
#include <DynRPG/System/FontImage.hpp>
#include <DynRPG/System/SystemFont.hpp>

namespace RPG
{

/*! \brief Used to store the system and "system2" graphics
	\sa RPG::System
	\sa RPG::Image::setSystemPalette
*/
struct SystemGraphic
{
	void** vTable;
	Image* systemImage; //!< \c %System image
	Image* exFont; //!< Image file for glyphs

	FontImage font;

	bool systemTiled; //!< Is the window background tiled? (in-game version of RPG::DBSystem::systemTiled)
	SystemFont systemFont; //!< MS Gothic or MS Mincho? (in-game version of RPG::DBSystem::systemFont)  (See RPG::SystemFont)
	Image* system2Image; //!< \c System2 image

	/*! \brief Loads the font used for text drawing
		\param fontName Name of the font
		\warning This is an experimental function.
	*/
	void loadFont(std::string fontName);

	/*! \brief Changes the system graphic
		\param fontName Name of the font
		\warning This is an experimental function.
	*/
	void change(std::string systemGraphicName, bool isTiled, bool isMincho);
};
}

#endif // RPG_SYSTEM_GRAPHIC_HPP
