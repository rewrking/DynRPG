#define DYNRPG_STATIC
#include <DynRPG/Window/Window.hpp>

#include <DynRPG/Delphi/DStringPtr.hpp>
#include <DynRPG/Utility/AsmRegisters.hpp>

namespace RPG
{
/******************************************************************************
 *
 *****************************************************************************/
Window::Window()
{
	int n = 1;
	asm volatile("call *%%esi"
				 :
				 : "S"(0x4C6330), "a"(0x4C5F30), "d"(n)
				 : "ecx", "cc", "memory");
}

/******************************************************************************
 *
 *****************************************************************************/
void Window::create(int width, int height, int x, int y, bool startHidden)
{
	asm volatile("push %%eax"
				 :
				 : "a"(width));
	asm volatile("push %%eax"
				 :
				 : "a"(height));
	asm volatile("push %%eax"
				 :
				 : "a"(startHidden));
	asm volatile("call *%%esi"
				 :
				 : "S"(0x4C63DC), "a"(this), "d"(x), "c"(y)
				 : "cc", "memory"); // cc = condition codes
}

/******************************************************************************
 *
 *****************************************************************************/
void Window::clear()
{
	asm volatile("call *%%esi"
				 :
				 : "S"(0x4C63A0), "a"(this)
				 : "edx", "ecx", "cc", "memory");
}

/******************************************************************************
 *
 *****************************************************************************/
void Window::redraw()
{
	asm volatile("call *%%esi"
				 :
				 : "S"(0x4C6CF8), "a"(this), "d"(width), "c"(height)
				 : "cc", "memory");
}

/******************************************************************************
 *
 *****************************************************************************/
void Window::updateCursor(int choice)
{
	asm volatile("call *%%esi"
				 :
				 : "S"(0x4C6810), "a"(this), "d"(choice)
				 : "ecx", "cc", "memory");
}

/******************************************************************************
 *
 *****************************************************************************/
void Window::refresh()
{
	asm volatile("call *%%esi"
				 :
				 : "S"(0x4C6640), "a"(this)
				 : "edx", "ecx", "cc", "memory");
}

/******************************************************************************
 * Destroys the window and all of its members
 *****************************************************************************/
void Window::destroy()
{
	asm volatile("call *%%esi"
				 :
				 : "S"(0x4C66E4), "a"(this)
				 : "edx", "ecx", "cc", "memory");
}

/******************************************************************************
 *
 *****************************************************************************/
void Window::drawString(int x, int y, std::string text, int color, bool initialize)
{
	DStringPtr par1(text); // *cue holy music*
	asm volatile("push %%eax"
				 :
				 : "a"(par1.str));
	asm volatile("push %%eax"
				 :
				 : "a"(color));
	asm volatile("push %%eax"
				 :
				 : "a"(initialize));
	asm volatile("call *%%esi"
				 : "=a"(_eax), "=c"(_ecx), "=d"(_edx)
				 : "S"(0x4C6EA8), "a"(this), "c"(y), "d"(x)
				 : "cc", "memory");
}

/******************************************************************************
 *
 *****************************************************************************/
Window::~Window()
{
	int n = 1;
	asm volatile("call *%%esi"
				 :
				 : "S"(0x40376), "a"(this)
				 : "edx", "ecx", "cc", "memory");
}

/******************************************************************************
 *
 *****************************************************************************/
int Window::getSelected()
{
	if (this->choiceActive)
	{
		return this->currentChoice;
	}
	else
	{
		return -1;
	}
}

}
