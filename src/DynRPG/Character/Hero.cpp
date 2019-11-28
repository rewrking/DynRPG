#define DYNRPG_STATIC
#include <DynRPG/Character/Hero.hpp>

#include <DynRPG/Utility/AsmRegisters.hpp>

namespace RPG
{

/******************************************************************************
 *
 *****************************************************************************/
HeroControlMode Hero::getControlMode()
{
	uchar& a1 = *(uchar*)0x4A9B87;
	uchar& a2 = *(uchar*)0x4A9A04;
	if (a2 == 0xC3)
		return HeroControlMode::ControlNothing;
	if (a1 == 0x7F)
		return HeroControlMode::ControlEverythingExceptMovement;
	return HeroControlMode::ControlEverything;
}

/******************************************************************************
 *
 *****************************************************************************/
void Hero::setControlMode(HeroControlMode controlMode)
{
	uchar& a1 = *(uchar*)0x4A9B87;
	uchar& a2 = *(uchar*)0x4A9A04;
	switch (controlMode)
	{
		case HeroControlMode::ControlEverything:
			a1 = 0x02;
			a2 = 0x53;
			break;
		case HeroControlMode::ControlEverythingExceptMovement:
			a1 = 0x7F;
			a2 = 0x53;
			break;
		case HeroControlMode::ControlNothing:
			a1 = 0x7F;
			a2 = 0xC3;
			break;
	}
}

/******************************************************************************
 *
 *****************************************************************************/
void Hero::act()
{
	asm volatile("call *%%esi"
				 : "=a"(_eax)
				 : "S"(0x4A9A04), "a"(this)
				 : "edx", "ecx", "cc", "memory");
	// 0x4A9A04, vTable[15]
}

/******************************************************************************
 *
 *****************************************************************************/
void Hero::checkEventOverlapTrigger(EventTrigger triggerType, bool startedByActionButton)
{
	asm volatile("call *%%esi"
				 : "=a"(_eax), "=d"(_edx), "=c"(_ecx)
				 : "S"(0x4AA8CC), "a"(this), "d"(triggerType), "c"(startedByActionButton)
				 : "cc", "memory");
}

/******************************************************************************
 *
 *****************************************************************************/
void Hero::checkEventInFrontTrigger(EventTrigger triggerType, bool startedByActionButton)
{
	asm volatile("call *%%esi"
				 : "=a"(_eax), "=d"(_edx), "=c"(_ecx)
				 : "S"(0x4AA978), "a"(this), "d"(triggerType), "c"(startedByActionButton)
				 : "cc", "memory");
}
}
