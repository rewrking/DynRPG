#ifndef DYNRPG_INPUT_H
#define DYNRPG_INPUT_H

#include <DynRPG/Enum/Key.h>
#include <DynRPG/Enum/KeyDown.h>
#include <DynRPG/Enum/KeyDownAlt.h>

namespace RPG
{
/*! \brief Used for key input
	\sa RPG::input
*/
class DYNRPG_API Input
{
public:
	void** vTable;
	int joystickId; //!< The ID of the first joystick
	char _unknown_08;
	char _unknown_09;
	char _unknown_0A;
	char _unknown_0B;
	/*! \brief Array of key codes assigned to the different RPG::Key
		values (part 1)

		This array contains the key assignments for those key functions
		which exist both in %RPG Maker 2000 and %RPG Maker 2003. Use
		the \ref key method for easy access.

		Indexes:

				0-7: Down
				8-15: Left
			16-23: Right
			24-31: Up
			32-39: Decision
			40-47: Cancel

		\sa keys2k3
		\sa RPG::Key
		\sa key
	*/
	int keys[48];
	int _unknown_CC[32];
	/*! \brief Array of key codes assigned to the different RPG::Key
		values (part 2)

		This array contains the key assignments for those key functions
		which exist only in %RPG Maker 2003. Use the \ref key method
		for easy access. Specifically these are the key assignments for
		numpad keys or otherwise that are detected via the
		"Key Input Processing" event command

		Indexes:
				0-7: 0 (Detected via Key Input Processing normally)
				8-15: 1 "
				16-23: 2 "
				24-31: 3 "
				32-39: 4 "
				40-47: 5 "
				48-55: 6 "
				56-63: 7 "
				64-71: 8 "
				72-79: 9 "
				80-87: + "
				88-95: - "
				96-103: * "
			104-111: / "
			112-119: . "

		\sa keys
		\sa RPG::Key
		\sa key
	*/
	int keys2k3[120];
	int resolutionTime; //!< In milliseconds
	int _unknown_330;
	int uTimerId; //!< 0 if timerEvent for input not existing
	KeyDown_T isPressed; //!< Are a combination of keys pressed & released (See RPG::KeyDown)
	KeyDownAlt_T isShiftCtrlPressed; //!< Are the Shift or Ctrl keys & released (See RPG::KeyDownAlt)
	char _unknown_33A;
	char _unknown_33B;
	int _unknown_33C;
	KeyDown_T isHeld; //!< Are a combination of keys held (See RPG::KeyDown)
	KeyDownAlt_T isShiftCtrlHeld; //!< Are the Shift or Ctrl keys held (See RPG::KeyDownAlt)
	char _unknown_342;
	char _unknown_343;
	KeyDown_T isTapped; //!< Are a combination of keys tapped (See RPG::KeyDown)
	KeyDownAlt_T isShiftCtrlTapped; //!< Are the Shift or Ctrl keys tapped (See RPG::KeyDownAlt)
	char _unknown_34A;
	char _unknown_34B;
	int joyInfo[4]; //!< JOYINFO button state?
	int _unknown_35C;
	int keyHoldTimer; //!< Amount of time a key is held?
	char leftRight;
	char _unknown_365;
	char _unknown_366;
	char _unknown_367;
	int directionNumpad; //!< down (2), left (4), right (6), up (8)
	bool joyRepsonseFlag; //!< If 1, response for button status of joy device took too long & don't process JoyInput

	/*! \brief Provides easy access to the key assignments

		This function returns a pointer to the "block" of 8 key codes
		in the \c keys or \c keys2k3 array which corresponds to the
		given RPG::Key value. The result should be used with the
		<tt>[]</tt> syntax with an index from \c 0 to \c 7.

		Example:
		\code
RPG::input->key(RPG::KEY_DECISION)[3] = VK_TAB;
		\endcode
		This example would assign the \c TAB key as a new decision key
		(the default decision keys are \c Enter, \c Space and \c Z,
		indexes \c 3 to \c 7 are not assigned by default).

		The values used for key assignments are
		<a href="http://msdn.microsoft.com/en-us/library/windows/desktop/dd375731(v=vs.85).aspx">virtual key codes</a>,
		zero meaning "not assigned".
		\param keyId RPG::Key for which the key codes should be read or
		changed
		\return Pointer to the first key code used for this RPG::Key
		\sa RPG::Key
	*/
	int* key(RPG::Key keyId);

	/*! \brief Checks whether a RPG::Key is pressed

		This function checks if one of the physical keys asiigned to a
		RPG::Key is currently held down. This function does not use the
		%RPG Maker's internal key cache.
		\param keyId RPG::Key to check
		\return \c true if the key is pressed, \c false otherwise
	*/
	bool pressed(RPG::Key keyId);

	/*! \brief Updates the %RPG Maker's internal key cache

		The %RPG Maker uses an internal key cache which is normally
		updated every frame. This function updates the key cache.
	*/
	void update();
};

/*! \ingroup game_objects
	\brief Object used for key assignments and key input checking.
*/
extern DYNRPG_API RPG::Input*& input;
}

#endif // DYNRPG_INPUT_H
