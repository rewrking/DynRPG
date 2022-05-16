#include <DynRPG/Screen.h>

#include <DynRPG/DynRPGGlobals.h>

namespace RPG
{
HWND Screen::getCanvasHWND()
{
	try
	{
		return (**reinterpret_cast<HWND****>(0x4CE048))[25][96];
	}
	catch (...)
	{
		return NULL;
	}
}

void Screen::setFPS(int fps)
{
	millisecondsPerFrame = 1000.0 / (double)fps;
	maxFPS = fps;
}

void Screen::update(Scene scene)
{
	asm volatile("call *%%esi"
				 : "=a"(_eax)
				 : "S"(0x48CD40), "a"(**sceneObjects[scene])
				 : "edx", "ecx", "cc", "memory");
}

void Screen::toggleFullScreen(bool fullScreen)
{
	asm volatile("call *%%esi"
				 : "=a"(_eax), "=d"(_edx)
				 : "S"(0x46B29C), "a"(this), "d"(fullScreen)
				 : "ecx", "cc", "memory");
}

void Screen::toggleLargeWindow(bool largeWindow)
{
	asm volatile("call *%%esi"
				 : "=a"(_eax), "=d"(_edx)
				 : "S"(0x46B400), "a"(this), "d"(largeWindow)
				 : "ecx", "cc", "memory");
}
}
