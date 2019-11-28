#define DYNRPG_STATIC
#include <DynRPG/Event/Event.hpp>

#include <DynRPG/Catalog/NamedCatalogPtr.hpp>
#include <DynRPG/Utility/AsmRegisters.hpp>

namespace RPG
{
/******************************************************************************
 *
 *****************************************************************************/
bool Event::doesEventPageExist(int id)
{
	void** script;
	asm volatile("call *%%esi"
				 : "=a"(script), "=d"(_edx)
				 : "S"(0x47A0D0), "a"((**reinterpret_cast<void****>(0x4CDD14))[15]), "d"(this->id)
				 : "ecx", "cc", "memory");
	NamedCatalogPtr<void*> pages;
	pages.ptr = reinterpret_cast<NamedCatalog<void*>*>(script[5]);
	return pages[id] != NULL;
}

/******************************************************************************
 *
 *****************************************************************************/
void Event::act()
{
	asm volatile("call *%%esi"
				 : "=a"(_eax)
				 : "S"(vTable[15]), "a"(this)
				 : "edx", "ecx", "cc", "memory");
	// 0x?????, vTable[15]
}
}
