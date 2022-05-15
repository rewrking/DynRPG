#ifndef DYNRPG_WINDOW_MESSAGE_BOX_H
#define DYNRPG_WINDOW_MESSAGE_BOX_H

#include <DynRPG/DStringPtr.h>

#include <string>

namespace RPG
{
/*! \brief Used for message windows.
	\sa RPG::WindowMessage
*/
class DYNRPG_API WindowMessageBox
{
public:
	void** vTable;
	int _unknown_08;
	int _unknown_0C;
	int _unknown_10;
	DStringPtr* txt;
	int count;
	int _unknown_1C; // total lines?? (always seems to be 4)

	std::string getLine(int line);
	void setLine(int line, std::string text);
};
}

#endif // DYNRPG_WINDOW_MESSAGE_BOX_H
