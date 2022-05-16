#include <DynRPG/Hero.h>

namespace RPG
{
HeroControlMode Hero::getControlMode()
{
	unsigned char& a1 = *(unsigned char*)0x4A9B87;
	unsigned char& a2 = *(unsigned char*)0x4A9A04;
	if (a2 == 0xC3)
		return CONTROL_NOTHING;
	if (a1 == 0x7F)
		return CONTROL_EVERYTHING_EXCEPT_MOVEMENT;
	return CONTROL_EVERYTHING;
}

void Hero::setControlMode(HeroControlMode controlMode)
{
	unsigned char& a1 = *(unsigned char*)0x4A9B87;
	unsigned char& a2 = *(unsigned char*)0x4A9A04;
	switch (controlMode)
	{
		case CONTROL_EVERYTHING:
			a1 = 0x02;
			a2 = 0x53;
			break;
		case CONTROL_EVERYTHING_EXCEPT_MOVEMENT:
			a1 = 0x7F;
			a2 = 0x53;
			break;
		case CONTROL_NOTHING:
			a1 = 0x7F;
			a2 = 0xC3;
			break;
	}
}

void RPG::Hero::act()
{
	asm volatile("call *%%esi"
				 : "=a"(_eax)
				 : "S"(0x4A9A04), "a"(this)
				 : "edx", "ecx", "cc", "memory");
	// 0x4A9A04, vTable[15]
}

void RPG::Hero::checkEventOverlapTrigger(EventTrigger triggerType, bool startedByActionButton)
{
	asm volatile("call *%%esi"
				 : "=a"(_eax), "=d"(_edx), "=c"(_ecx)
				 : "S"(0x4AA8CC), "a"(this), "d"(triggerType), "c"(startedByActionButton)
				 : "cc", "memory");
}

void RPG::Hero::checkEventInFrontTrigger(EventTrigger triggerType, bool startedByActionButton)
{
	asm volatile("call *%%esi"
				 : "=a"(_eax), "=d"(_edx), "=c"(_ecx)
				 : "S"(0x4AA978), "a"(this), "d"(triggerType), "c"(startedByActionButton)
				 : "cc", "memory");
}
}
