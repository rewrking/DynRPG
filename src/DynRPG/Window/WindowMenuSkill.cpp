#define DYNRPG_STATIC
#include <DynRPG/Window/WindowMenuSkill.hpp>

namespace RPG
{
/******************************************************************************
 *
 *****************************************************************************/
void WindowMenuSkill::refreshSkills()
{
	asm volatile("call *%%esi"
				 :
				 : "S"(0x4C9274), "a"(this)
				 : "edx", "ecx", "cc", "memory");
}
}
