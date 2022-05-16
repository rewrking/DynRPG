#ifndef DYNRPG_WINDOW_H
#define DYNRPG_WINDOW_H

#include <DynRPG/DListPtr.h>
#include <DynRPG/Image.h>

namespace RPG
{
/*! \brief Used for Window objects of all kinds.

	\sa RPG::SceneMenu
	\sa RPG::SceneShop
	\sa RPG::SceneTitle
	\sa RPG::SceneDebug
*/
class DYNRPG_API Window
{
public:
	void** vTable;
	/*! \brief The number of choices per row
		\note The Items window has 2.
	*/
	int choicesPerRow;
	Image* image; //!< The actual image of the window after it's been drawn.
	Image* imageFrame; //!< The window's frame & background (if redrawn).
	Image* imageText; //!< The window's text (if redrawn), but can only draw underneath.
	int x; //!< The window's x-position
	int y; //!< The window's y-position
	int width; //!< The window's width
	int height; //!< The window's height
	int jumpX; //!< Change in x-position when moving cursor
	int jumpY; //!< Change in y-position when moving cursor
	int rowsPerPage; //!< Number of text rows on the window (choices or plain text)
	int cursorX; //!< The cursor's starting x-position (upper-left choice)
	int cursorY; //!< The cursor's starting y-position (upper-left choice)
	int cursorWidth; //!< The width of the cursor
	int cursorHeight; //!< The height of the cursor
	int totalChoices; //!< The total number of choices in the window
	int currentChoice; //!< The current choice selected (zero-based)
	int currentScroll; //!< Amount of choices above current choice
	int scrollTimer; //!< The timer between cursor movements (-12 or 12, minus or plus 4 each frame until it's 0)
	bool choiceVisible; //!< Has the choice bar been drawn? (It can still be considered visible if another window is active)
	bool choiceActive; //!< Is the choice bar of the window active?
	int choiceTimer; //!< The number of frames the choice has been selected
	// bugmenot's notes:
	// Can't say what the deal with the Roll-On is. It takes on values from 0..8 and somehow
	// reflects the progress of an inflateRect() process.
	int rollOn1;
	int rollOn2;
	int winTimer; //!< The total number of frames the window has been visible before a RPG::Scene change
	DListPtr<char>* text; //!< The window's text (doesn't work yet)
	int _unknown_68;
	int fontSet; //!< The window's font set?
	int _unknown_70;
	int _unknown_74;

	// Functions
	Window(); //!< Experimental
	~Window(); //!< Experimental

	/*! \brief Experimental
		\param window The window to be created
		\param width The width of the window
		\param height The height of the window
		\param x The X-coordinate of the window, based on the upper-left
		\param y The Y-coordinate of the window, based on the upper-left
		\param startHidden Start the window hidden?
	*/
	void create(int width, int height, int x, int y, bool startHidden);

	void redraw(); //!< Experimental

	void updateCursor(int choice); //!< Experimental

	/*! \brief Clears the specified window of any text, so that it can be drawn on again.
		\param window The window to be cleared
	*/
	void clear(); //!< Experimental

	void refresh(); //!< Experimental

	/*! \brief Removes the specified window object and all of its components
		\param window The window to be cleared
	*/
	void destroy(); //!< Experimental

	/*! \brief Built-in RM2k3 function that draws a string to a Window. (experimental)
	*/
	void drawString(int x, int y, std::string text, int color, bool initialize);

	/*! \brief  Gets the index of a selection within a RPG::Window object (Example: int selected = RPG::battleData->winMonTarget->getSelected())
		\return the zero-based index of the selection, or -1 if the RPG::Window object is not active
	*/
	int getSelected();
};
}

#endif // DYNRPG_WINDOW_H
