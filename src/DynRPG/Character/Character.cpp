#define DYNRPG_STATIC
#include <DynRPG/Character/Character.hpp>

#include <string>

#include <DynRPG/Actor/Actor.hpp>
#include <DynRPG/Character/Hero.hpp>
#include <DynRPG/Event/Event.hpp>
#include <DynRPG/Utility/AsmRegisters.hpp>
#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
/******************************************************************************
 *
 *****************************************************************************/
int Character::getScreenX()
{
	int ret;
	asm volatile("call *%%esi"
				 : "=a"(ret)
				 : "S"(0x4C46E8), "a"(this)
				 : "edx", "ecx", "cc", "memory");
	return ret;
}

/******************************************************************************
 *
 *****************************************************************************/
int Character::getScreenY()
{
	int ret;
	asm volatile("call *%%esi"
				 : "=a"(ret)
				 : "S"(0x4C47C4), "a"(this)
				 : "edx", "ecx", "cc", "memory");
	return ret;
}

/******************************************************************************
 *
 *****************************************************************************/
void Character::setFixedStep(int newStep)
{
	stepFrameCounter = -1;
	step = newStep;
}

/******************************************************************************
 *
 *****************************************************************************/
void Character::setNormalStep()
{
	stepFrameCounter = 0;
	step = 3;
}

/******************************************************************************
 *
 *****************************************************************************/
void Character::setAnimationType(AnimationType type)
{
	animationType = type;
	fixedDirection = type == AnimationType::FixedDirNormal || type == AnimationType::FixedDirStepping || type == AnimationType::FixedGraphic;
}

/******************************************************************************
 *
 *****************************************************************************/
bool Character::isMovePossible(int fromX, int fromY, int toX, int toY)
{
	bool ret;
	asm volatile(
		"pushl %7;"
		"pushl %8;"
		"call *%%esi"
		: "=a"(ret), "=d"(_edx), "=c"(_ecx)
		: "S"(vTable[11]), "a"(this), "d"(fromX), "c"(fromY), "m"(toX), "m"(toY)
		: "cc", "memory");
	return ret;
}

/******************************************************************************
 *
 *****************************************************************************/
std::string Character::getName()
{
	if (vTable == reinterpret_cast<void**>(0x4AAC8C))
	{
		return reinterpret_cast<Event*>(this)->data->name;
	}
	else if (this == hero)
	{
		Actor* firstHero = Actor::partyMember(0);
		if (firstHero)
			return firstHero->getName();
		else
			return "";
	}
	else
	{
		return "";
	}
}

/******************************************************************************
 *
 *****************************************************************************/
void Character::move(const char* data, int length, bool repeatPattern, bool ignoreImpossible, int frequency)
{
	asm volatile(
		"pushl %7;"
		"pushl %8;"
		"pushl %9;"
		"call *%%esi"
		: "=a"(_eax), "=d"(_edx), "=c"(_ecx)
		: "S"(0x4C43EC), "a"(this), "d"(data), "c"(length), "m"(frequency), "m"(repeatPattern), "m"(ignoreImpossible)
		: "cc", "memory");
	// Constraints for repeatPattern and ignoreImpossible are "m" and not "g" because they are bool and trying to push an 8-bit register won't work
	// Also, frequency is now "m" too because of possible "g" bugs
}

/******************************************************************************
 *
 *****************************************************************************/
void Character::stop()
{
	asm volatile("call *%%esi"
				 : "=a"(_eax)
				 : "S"(0x4C445C), "a"(this)
				 : "edx", "ecx", "cc", "memory");
}

/******************************************************************************
 *
 *****************************************************************************/
void Character::doStep(Direction direction)
{
	asm volatile("call *%%esi"
				 : "=a"(_eax), "=d"(_edx)
				 : "S"(vTable[12]), "a"(this), "d"(direction)
				 : "ecx", "cc", "memory");
}
}
