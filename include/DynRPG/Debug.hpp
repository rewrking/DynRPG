#ifndef RPG_DEBUG_HPP
#define RPG_DEBUG_HPP

#define _WIN32_WINNT 0x0502
#include <DynRPG/Utility/Win32.hpp>

#include <iostream>

namespace RPG
{
/*! \brief Attach a console window to RPG_RT.exe for debugging

	1. Include this file before including DynRPG.hpp
	2. call attachConsole(pluginName) in the onStartup() callback

	\note This class is NOT included by default

	Example:
	\code
#include <DynRPG/Debug.hpp> // Place before DynRPG.hpp -- Important!
#include <DynRPG/DynRPG.hpp>

...

bool onStartup(char *pluginName)
{
RPG::Debug::attachConsole(pluginName);
return true;
}
	\endcode
*/

struct Debug
{
	inline static void attachConsole(char*& pluginName)
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
	~Debug()
	{
		freeConsole();
	};

private:
	inline static void freeConsole()
	{
		if (s_consoleAttached)
			FreeConsole();
	}

	inline static bool s_consoleAttached = false;
};
}

#endif // RPG_DEBUG_HPP
