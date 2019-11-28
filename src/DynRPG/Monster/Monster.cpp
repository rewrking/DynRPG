#define DYNRPG_STATIC
#include <DynRPG/Monster/Monster.hpp>

#include <DynRPG/Utility/AsmRegisters.hpp>

namespace RPG
{
/******************************************************************************
 *
 *****************************************************************************/
AnimationInBattle*& Monster::animData = (**reinterpret_cast<AnimationInBattle***>(0x4CDE64));

/******************************************************************************
 *
 *****************************************************************************/
void Monster::transform(int monsterId)
{
	asm volatile("call *%%esi"
				 : "=a"(_eax), "=d"(_edx)
				 : "S"(0x4BDDD8), "a"(this), "d"(monsterId)
				 : "ecx", "cc", "memory");
}

/******************************************************************************
 *
 *****************************************************************************/
void Monster::loadMonsterGroup(int id)
{
	asm volatile("call *%%esi"
				 : "=a"(_eax), "=d"(_edx)
				 : "S"(0x4BE8E0), "a"(monsters.ptr), "d"(id)
				 : "ecx", "cc", "memory");
}
}
