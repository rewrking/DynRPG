#include <DynRPG/SystemGraphic.h>

#include <DynRPG/DStringPtr.h>

namespace RPG
{
void SystemGraphic::change(std::string systemGraphicName, bool isTiled = false, bool isMincho = false)
{
	DStringPtr graphicDString(systemGraphicName);
	asm volatile("push %%eax"
				 :
				 : "a"(isTiled));
	asm volatile("call *%%esi"
				 : "=a"(_eax), "=c"(_ecx), "=d"(_edx)
				 : "S"(0x4AE280), "a"(this), "d"(isMincho), "c"(graphicDString.str)
				 : "cc", "memory");
}
}
