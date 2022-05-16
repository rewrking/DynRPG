#include <DynRPG/Battler.h>

#include <DynRPG/DStringPtr.h>
#include <DynRPG/DynRPGGlobals.h>
#include <DynRPG/Enum/Scene.h>

namespace RPG
{
namespace
{
enum
{
	DPT_START = 0x83
};
}

std::string Battler::getName()
{
	DStringPtr s;
	asm volatile("call *%%esi"
				 : "=a"(_eax), "=d"(_edx)
				 : "S"(vTable[9]), "a"(this), "d"(&s)
				 : "ecx", "cc", "memory"); // GetMaxHP
	return s;
}

int Battler::getMaxHp()
{
	int ret;
	asm volatile("call *%%esi"
				 : "=a"(ret)
				 : "S"(vTable[10]), "a"(this)
				 : "edx", "ecx", "cc", "memory"); // GetMaxHP
	return ret;
}

int Battler::getMaxMp()
{
	int ret;
	asm volatile("call *%%esi"
				 : "=a"(ret)
				 : "S"(vTable[11]), "a"(this)
				 : "edx", "ecx", "cc", "memory"); // GetMaxMP
	return ret;
}

int Battler::getAttack()
{
	int ret;
	asm volatile("call *%%esi"
				 : "=a"(ret)
				 : "S"(0x4BFB28), "a"(this)
				 : "edx", "ecx", "cc", "memory"); // GetATK
	return ret;
}

int Battler::getDefense()
{
	int ret;
	asm volatile("call *%%esi"
				 : "=a"(ret)
				 : "S"(0x4BFBF4), "a"(this)
				 : "edx", "ecx", "cc", "memory"); // GetDEF
	return ret;
}

int Battler::getIntelligence()
{
	int ret;
	asm volatile("call *%%esi"
				 : "=a"(ret)
				 : "S"(0x4BFCC0), "a"(this)
				 : "edx", "ecx", "cc", "memory"); // GetINT
	return ret;
}

int Battler::getAgility()
{
	int ret;
	asm volatile("call *%%esi"
				 : "=a"(ret)
				 : "S"(0x4BFD5C), "a"(this)
				 : "edx", "ecx", "cc", "memory"); // GetAGI
	return ret;
}

void Battler::setRow(Row newRow)
{
	rowAlt = newRow;
	row = newRow;
}

void Battler::damagePopup(int number, int color)
{
	damagePopupTimer = DPT_START;
	asm volatile("call *%%esi"
				 : "=a"(_eax), "=d"(_edx), "=c"(_ecx)
				 : "S"(0x4BF5E4), "a"(this), "d"(number), "c"(color)
				 : "cc", "memory"); // ShowDamage
}

void Battler::damagePopup(std::string text)
{
	damagePopupTimer = DPT_START;
	DStringPtr s(text);
	asm volatile("call *%%esi"
				 : "=a"(_eax), "=d"(_edx)
				 : "S"(0x4BF550), "a"(this), "d"(s.str)
				 : "ecx", "cc", "memory");
}

bool Battler::isMonster()
{
	return vTable == reinterpret_cast<void**>(0x4BD35C);
}

void Battler::flash(int r, int g, int b, int intensity, int duration)
{
	flashR = r;
	flashG = g;
	flashB = b;
	flashIntensity = (double)intensity;
	flashTimer = duration;
}

bool Battler::executeAction(bool skipPluginHandlers)
{
	bool ret;
	if (skipPluginHandlers)
	{
		asm volatile("call *%%esi"
					 : "=a"(ret), "=d"(_edx)
					 : "S"(0x49A04C), "a"(**sceneObjects[SCENE_BATTLE]), "d"(this)
					 : "ecx", "cc", "memory"); // ExecuteBattlerAction
	}
	else
	{
		asm volatile("call *%%esi"
					 : "=a"(ret), "=d"(_edx)
					 : "S"(0x45CDF4), "a"(**sceneObjects[SCENE_BATTLE]), "d"(this)
					 : "ecx", "cc", "memory"); // ExecuteBattlerAction (DynRPG)
	}
	return ret;
}

int RPG::Battler::getAttributeResist(int id)
{
	int out;
	int tmp;
	int tmp2;
	asm volatile("call *%%esi"
				 : "=a"(tmp), "=d"(_edx)
				 : "S"(0x47B5D8), "a"((*reinterpret_cast<int**>(0x4CDE44))[0]), "d"(id)
				 : "ecx", "cc", "memory");
	asm volatile("call *%%esi"
				 : "=a"(tmp2), "=d"(_edx)
				 : "S"(0x4BFDF8), "a"(this), "d"((reinterpret_cast<int*>(tmp))[1])
				 : "ecx", "cc", "memory");
	asm volatile("mov %0, %%eax"
				 :
				 : "a"(this));
	asm volatile("push %ebp; mov %eax, %ebp; push %edx; push %eax");
	asm volatile("call *%%esi"
				 : "=a"(out), "=d"(_edx)
				 : "S"(0x47B564), "a"(tmp), "d"(tmp2)
				 : "ecx", "cc", "memory");
	asm volatile("pop %edx; pop %edx; pop %ebp");

	return out;
}

int RPG::Battler::getAttackPower(RPG::Battler* target)
{
	int power;
	asm volatile("call *%%esi"
				 : "=a"(power), "=d"(_edx)
				 : "S"(0x4C0B2C), "a"(this), "d"(target)
				 : "ecx", "cc", "memory");
	return power;
}

int RPG::Battler::getSkillPower(int skillId, RPG::Battler* target)
{
	int power;
	asm volatile("call *%%esi"
				 : "=a"(power), "=d"(_edx), "=c"(_ecx)
				 : "S"(0x4C0DBC), "a"(this), "d"(skillId), "c"(target)
				 : "cc", "memory");
	return power;
}
}
