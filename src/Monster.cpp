#include <DynRPG/Monster.h>

namespace RPG
{
AnimationInBattle*& Monster::animData = (**reinterpret_cast<AnimationInBattle***>(0x4CDE64));

void Monster::transform(int monsterId)
{
	asm volatile("call *%%esi"
				 : "=a"(_eax), "=d"(_edx)
				 : "S"(0x4BDDD8), "a"(this), "d"(monsterId)
				 : "ecx", "cc", "memory");
}

void Monster::loadMonsterGroup(int id)
{
	asm volatile("call *%%esi"
				 : "=a"(_eax), "=d"(_edx)
				 : "S"(0x4BE8E0), "a"(this), "d"(id)
				 : "ecx", "cc", "memory");
}
}
