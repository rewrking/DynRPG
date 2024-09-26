#include <DynRPG/CharacterGraphics.h>

namespace RPG
{
void CharacterGraphics::clearAll()
{
	asm volatile(
		"call *%%esi"
		: "=a"(_eax), "=d"(_edx), "=c"(_ecx)
		: "S"(0x483A64), "a"(this)
		: "cc", "memory");
}

void CharacterGraphics::markAllUnused()
{
	asm volatile(
		"call *%%esi"
		: "=a"(_eax), "=d"(_edx), "=c"(_ecx)
		: "S"(0x483AB4), "a"(this)
		: "cc", "memory");
}

void CharacterGraphics::cleanUp()
{
	asm volatile(
		"call *%%esi"
		: "=a"(_eax), "=d"(_edx), "=c"(_ecx)
		: "S"(0x483ADC), "a"(this)
		: "cc", "memory");
}

int CharacterGraphics::addFile(std::string filename, bool isCharSet2)
{
	DStringPtr s(filename);
	int out;
	asm volatile(
		"call *%%esi"
		: "=a"(out), "=d"(_edx), "=c"(_ecx)
		: "S"(0x483B40), "a"(this), "d"(s.str), "c"(isCharSet2)
		: "cc", "memory");
	return out;
}

int CharacterGraphics::findIndex(std::string filename)
{
	DStringPtr s(filename);
	int out;
	asm volatile(
		"call *%%esi"
		: "=a"(out), "=d"(_edx), "=c"(_ecx)
		: "S"(0x483CB8), "a"(this), "d"(s.str)
		: "cc", "memory");
	return out;
}

void CharacterGraphics::draw(
	Canvas* canvas, int x, int y, int fileIndex, int spriteIndex,
	Direction direction, AnimationFrameCharset step, TerrainSpriteDisplay spriteDisplay,
	bool isCharSet2)
{
	asm volatile(
		"pushl %7;"
		"pushl %8;"
		"pushl %9;"
		"pushl %10;"
		"pushl %11;"
		"pushl %12;"
		"pushl %13;"
		"call *%%esi"
		: "=a"(_eax), "=d"(_edx), "=c"(_ecx)
		: "S"(0x483CC4), "a"(this), "d"(canvas), "c"(x), "m"(y), "m"(fileIndex), "m"(spriteIndex), "m"(direction), "m"(step), "m"(spriteDisplay), "m"(isCharSet2)
		: "cc", "memory");
}

}
