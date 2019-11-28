#ifndef RPG_WINDOW_MESSAGE_BOX_HPP
#define RPG_WINDOW_MESSAGE_BOX_HPP

#include <string>

#include <DynRPG/Delphi/DStringPtr.hpp>

namespace RPG
{
/*! \brief Used for message windows.
	\sa RPG::WindowMessage
*/
struct WindowMessageBox
{
	// clang-format off
	void** vTable;
		int _unknown_08;
		int _unknown_0C;
		int _unknown_10;
	DStringPtr* txt;
	int count;
		int _unknown_1C; // total lines?? (always seems to be 4)
	// clang-format on

	std::string getLine(int line);
	void setLine(int line, std::string text);
};
}

#endif // RPG_WINDOW_MESSAGE_BOX_HPP
