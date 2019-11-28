#define DYNRPG_STATIC
#include <DynRPG/Window/WindowMessage.hpp>

namespace RPG
{
/******************************************************************************
 *
 *****************************************************************************/
WindowMessage::WindowMessage()
{
	int n = 1;
	asm volatile("call *%%esi"
				 :
				 : "S"(0x4C712C), "a"(0x4C605C), "d"(n)
				 : "cc", "memory"); // welp
}

/******************************************************************************
 *
 *****************************************************************************/
WindowMessage::~WindowMessage()
{
	int n = 1;
	asm volatile("call *%%esi"
				 :
				 : "S"(0x40376), "a"(this)
				 : "cc", "memory");
}
}
