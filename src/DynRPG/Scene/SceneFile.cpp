#define DYNRPG_STATIC
#include <DynRPG/Scene/SceneFile.hpp>

namespace RPG
{
/******************************************************************************
 *
 *****************************************************************************/
bool SceneFile::doesSaveExist(int saveId)
{
	bool out = false;
	asm volatile("call *%%esi"
				 : "=a"(out), "=d"(_edx)
				 : "S"(0x4A5484), "a"((*reinterpret_cast<int**>(0x4CDF20))[0]), "d"(saveId)
				 : "ecx", "cc", "memory");
	// Don't replace *reinterpret_cast..." with "this" in this function - If it's called in a plugin,
	// it will seemingly work... until you hit the close button, when a mystery error sound occurs.
	return out;
}

/******************************************************************************
 *
 *****************************************************************************/
void SceneFile::saveFile(int saveId)
{
	asm volatile("call *%%esi"
				 : "=a"(_eax), "=d"(_edx)
				 : "S"(0x45D2ED), "a"(this), "d"(saveId)
				 : "ecx", "cc", "memory");
}

/******************************************************************************
 *
 *****************************************************************************/
void SceneFile::loadFile(int saveId)
{
	screen->canvas->brightness = 0;
	(*reinterpret_cast<char***>(0x4CDC7C))[0][4] = 5; // Force SceneChange to FileScene
	(*reinterpret_cast<int***>(0x4CDFCC))[0][22] = saveId; // Set SaveSlot to load from
	(*reinterpret_cast<char*>(0x4913C8)) = 0xE9; // Patch to skip drawing the FileScene
	(*reinterpret_cast<int*>(0x4913C9)) = 0x000001CD; // Patch to skip [...]
	(*reinterpret_cast<ushort*>(0x4915AD)) = 0x03EB; // Patch to skip closing the FileScene
		// Patches direct access to FileScene (temporarily) to load SaveFile
}

/******************************************************************************
 *
 *****************************************************************************/
void SceneFile::loadFileUnpatch()
{
	(*reinterpret_cast<char*>(0x4913C8)) = 0x80; // Patch to restore drawing the FileScene
	(*reinterpret_cast<int*>(0x4913C9)) = 0x75000C7B; // Patch to restore [...]
	(*reinterpret_cast<ushort*>(0x4915AD)) = 0xCEE8; // Patch to restore closing the FileScene
		// Restores default code
}

/******************************************************************************
 * Incompatible with saveload patch. experimental!
 *****************************************************************************/
void SceneFile::loadFileSimple(int saveId)
{
	screen->canvas->brightness = 0;
	asm volatile("call *%%esi"
				 : "=a"(_eax), "=d"(_edx)
				 : "S"(0x45D2E0), "a"(this), "d"(saveId)
				 : "ecx", "cc", "memory");
}
}
