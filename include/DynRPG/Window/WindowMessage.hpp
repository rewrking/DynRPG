#ifndef RPG_WINDOW_MESSAGE_HPP
#define RPG_WINDOW_MESSAGE_HPP

#include <DynRPG/Window/MessagePosition.hpp>
#include <DynRPG/Window/Window.hpp>
#include <DynRPG/Window/WindowMessageBox.hpp>

namespace RPG
{
/*! \brief Used for message windows.
	\sa RPG::SceneMenu
*/
struct WindowMessage : Window
{
	// clang-format off
	Window* winGold; //!< Pointer to gold window
					 //int _unknown_7C; // Message box text... not yet implemented // Doesn't crash: DList<DStringPtr > *text
	WindowMessageBox* text;
	int currentTextRow; //!< The current row of the text being drawn (1-4)
	int currentTextColumn; //!< The current column of the text being drawn (1-??)
	int currentTextX; //!< The x-coordinate of the text being drawn, relative to where the text started drawing
	MessagePosition messageBoxPosition; //!< The position of the message box
	int currentTextColor; //!< The color of the text currently being drawn
	int currentTextSpeed; //!< The speed of the text currently being drawn
	int textTimer; //!< Internally used to time the drawing of a single text character
	bool isWaiting; //!< Is the text box waiting? (Slash dot command maybe?)
	bool autoEnter; //!< Was the slash carrot command used?
	int cancelChoice; //!< The cancel choice option (1-4, or 5 if execute handler)
		int _unknown_90; // Pointer on choice case event code?
	int inputNumValue; //!< Current input total
	int inputNumDigits; //!< Number of input digits
	int inputNumVariableId; //!< The destination variable for the input
	bool innIsActive; //!< Is the inn active?
	int innCost; //!< The inn's cost
	bool messageOpen; //!< Is a message box currently drawn?
	// clang-format on

	WindowMessage(); //!< Experimental
	~WindowMessage(); //!< Experimental
};

/*! \ingroup game_objects
	\brief Properties of the message window
*/
static WindowMessage*& winMessage = (**reinterpret_cast<WindowMessage***>(0x4CDEF4));
}

#endif // RPG_WINDOW_MESSAGE_HPP
