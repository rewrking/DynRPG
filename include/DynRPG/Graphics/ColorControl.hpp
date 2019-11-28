#ifndef RPG_COLOR_CONTROL_HPP
#define RPG_COLOR_CONTROL_HPP

namespace RPG
{
//! \cond
struct Image;
//! \endcond

/*! \brief Color effect settings for RPG::Image objects
	\sa RPG::Image
*/
struct ColorControl
{
	void** vTable;
	Image* parentImage; //!< Pointer to the image to which the color effect belongs
	int red; //!< Red value (\c 0 to \c 255)
	int green; //!< Green value (\c 0 to \c 255)
	int blue; //!< Blue value (\c 0 to \c 255)
	int chroma; //!< Chroma value (\c 0 to \c 255)
};
}

#endif // RPG_COLOR_CONTROL_HPP
