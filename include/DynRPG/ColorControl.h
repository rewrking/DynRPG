#ifndef DYNRPG_COLOR_CONTROL_H
#define DYNRPG_COLOR_CONTROL_H

namespace RPG
{
//! \cond
class Image;
//! \endcond

/*! \brief Color effect settings for RPG::Image objects
	\sa RPG::Image
*/
class ColorControl
{
public:
	void** vTable;
	Image* parentImage; //!< Pointer to the image to which the color effect belongs
	int red; //!< Red value (\c 0 to \c 255)
	int green; //!< Green value (\c 0 to \c 255)
	int blue; //!< Blue value (\c 0 to \c 255)
	int chroma; //!< Chroma value (\c 0 to \c 255)
};
}

#endif // DYNRPG_COLOR_CONTROL_H
