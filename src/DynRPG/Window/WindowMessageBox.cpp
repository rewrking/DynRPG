#define DYNRPG_STATIC
#include <DynRPG/Window/WindowMessageBox.hpp>

namespace RPG
{
/******************************************************************************
 *
 *****************************************************************************/
std::string WindowMessageBox::getLine(int line)
{
	return txt[line * 2].s_str();
}

/******************************************************************************
 *
 *****************************************************************************/
void WindowMessageBox::setLine(int line, std::string text)
{
	txt[line * 2] = text;
}
}
