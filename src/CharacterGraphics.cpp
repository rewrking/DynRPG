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

// Note: isCharSet2 in addFile/draw should be always false! It was intended for large charsets, a feature that was never finished. Setting it to true in addFile would attempt to load a hardcoded file "CharSet2\主人公1", in draw it has no effect.
//
int CharacterGraphics::addFile(const std::string& filename)
{
	DStringPtr s(filename);
	bool isCharSet2 = false;
	int out;
	asm volatile(
		"call *%%esi"
		: "=a"(out), "=d"(_edx), "=c"(_ecx)
		: "S"(0x483B40), "a"(this), "d"(s.str), "c"(isCharSet2)
		: "cc", "memory");
	return out;
}

int CharacterGraphics::findIndex(const std::string& filename)
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

int CharacterGraphics::require(const std::string& filename)
{
	int index = findIndex(filename);
	if (index == -1)
	{
		index = addFile(filename);
	}

	return index;
}

void CharacterGraphics::draw(
	Canvas* canvas, int x, int y, int fileIndex, int spriteIndex,
	Direction direction, AnimationFrameCharset step, TerrainSpriteDisplay spriteDisplay)
{
	bool isCharSet2 = false;
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
