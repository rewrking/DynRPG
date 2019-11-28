#define DYNRPG_STATIC
#include <DynRPG/Debug.hpp>

#include <iostream>

namespace RPG
{
/******************************************************************************
 *
 *****************************************************************************/
bool Debug::s_consoleAttached = false;

/******************************************************************************
 *
 *****************************************************************************/
void Debug::attachConsole(char*& pluginName)
{
	if (!AttachConsole(ATTACH_PARENT_PROCESS))
	{
		AllocConsole();
		AttachConsole(GetCurrentProcessId());
	}

	freopen("CONOUT$", "w", stdout);

	std::cout << "\n====== " << pluginName << " ======\n"
			  << std::endl;

	s_consoleAttached = true;

	atexit(&freeConsole);
}

/******************************************************************************
 *
 *****************************************************************************/
Debug::~Debug()
{
	freeConsole();
}

/******************************************************************************
 *
 *****************************************************************************/
void Debug::freeConsole()
{
	if (s_consoleAttached)
		FreeConsole();
}
}
