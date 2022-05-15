#include <DynRPG/Actor.h>

#include <DynRPG/DBActor.h>

namespace RPG
{
RPG::AnimationInBattle*& RPG::Actor::animData = (**reinterpret_cast<RPG::AnimationInBattle***>(0x4CDDC8));

std::string Actor::getDegree()
{
	if (degree.s_str() == "\x01")
		return dbActors[id]->degree;

	return degree;
}

std::string Actor::getCharsetFilename()
{
	if (charsetFilename.s_str().empty())
		return dbActors[id]->charsetFilename;

	return charsetFilename;
}

int Actor::getCharsetId()
{
	if (charsetFilename.s_str().empty())
		return dbActors[id]->charsetId;

	return charsetId;
}

int Actor::getCharsetTransparency()
{
	if (charsetFilename.s_str().empty())
		return dbActors[id]->charsetTransparent ? 3 : 0;

	return charsetTransparency;
}

std::string Actor::getFacesetFilename()
{
	if (facesetFilename.s_str().empty())
		return dbActors[id]->facesetFilename;
	return facesetFilename;
}

int Actor::getFacesetId()
{
	if (facesetFilename.s_str().empty())
		return dbActors[id]->facesetId;

	return facesetId;
}

int Actor::getBattleGraphicId()
{
	if (battleGraphicId == 0)
		return dbActors[id]->battleGraphicId;

	return battleGraphicId;
}

int Actor::getBattleCommand(int index)
{
	if (!customBattleCommands)
		return dbActors[id]->battleCommands[index];

	return battleCommands[index];
}

Actor* Actor::partyMember(int index)
{
	Actor* ret = NULL;
	asm volatile("call *%%esi"
				 : "=a"(ret), "=d"(_edx)
				 : "S"(0x4A6014), "a"(**(void***)0x4CDB74), "d"(index)
				 : "ecx", "cc", "memory"); // GetPartyMember
	return ret;
}

void RPG::Actor::addSkill(int skillId)
{
	asm volatile("call *%%esi"
				 :
				 : "S"(0x4B7884), "a"(this), "d"(skillId)
				 : "ecx", "cc", "memory");
}

void RPG::Actor::removeSkill(int skillId)
{
	asm volatile("call *%%esi"
				 :
				 : "S"(0x4B7928), "a"(this), "d"(skillId)
				 : "ecx", "cc", "memory");
}

bool RPG::Actor::isSkillKnown(int skillId)
{
	bool out;
	asm volatile("call *%%esi"
				 : "=a"(out)
				 : "S"(0x4B798C), "a"(this), "d"(skillId)
				 : "ecx", "cc", "memory");
	return out;
}

int RPG::Actor::getTwoWeaponAttack()
{
	int out;
	asm volatile("call *%%esi"
				 : "=a"(out)
				 : "S"(0x4B7250), "a"(this)
				 : "ecx", "edx", "cc", "memory");
	return out;
}

int RPG::Actor::getTwoWeaponAgility()
{
	int out;
	asm volatile("call *%%esi"
				 : "=a"(out)
				 : "S"(0x4B760C), "a"(this)
				 : "ecx", "edx", "cc", "memory");
	return out;
}

// Doesn't work yet
/*void RPG::Actor::changeClass(RPG::DBClass *toClass)
{
	bool int1 = 1;
	bool int2 = 1;
	bool int3 = 1;
	bool int4 = 1;
	bool int5 = 1;
	int toClass2 = 5;
	asm volatile("push %%eax" : : "a" (int3));
	asm volatile("push %%eax" : : "a" (int2));
	asm volatile("push %%eax" : : "a" (int1));
	asm volatile("call *%%esi"
		: "=a" (_eax), "=d" (_edx), "=c" (_ecx)
		: "S" (0x4B11B8), "a" (this), "d" (toClass2), "c" (int4)
		: "cc", "memory");
}*/
}
