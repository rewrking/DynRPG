#include <DynRPG/Inventory.h>

namespace RPG
{
int Inventory::getPartyIndex(int databaseId)
{
	// Do not loop more times than the size of the party
	for (int i = 0; i < party.size; ++i)
	{
		// if the party's id matches the database ID of the hero being checked for
		if (party[i] == databaseId)
			return i;
	}
	return -1;
}

bool Inventory::isItemOwned(int id)
{
	int out;
	asm volatile("call *%%esi"
				 : "=a"(out), "=d"(_edx)
				 : "S"(0x4A6440), "a"(this), "d"(id)
				 : "ecx", "cc", "memory");
	return out;
}

void Inventory::addItem(int id, int amount)
{
	asm volatile("call *%%esi"
				 : "=a"(_eax), "=c"(_ecx), "=d"(_edx)
				 : "S"(0x4A620C), "a"(this), "c"(amount), "d"(id)
				 : "cc", "memory");
}

void Inventory::removeItem(int id, int amount)
{
	asm volatile("call *%%esi"
				 : "=a"(_eax), "=c"(_ecx), "=d"(_edx)
				 : "S"(0x4A6308), "a"(this), "d"(id), "c"(amount)
				 : "cc", "memory");
}

void Inventory::incrementItemUses(int id)
{
	asm volatile("call *%%esi"
				 : "=a"(_eax), "=d"(_edx)
				 : "S"(0x4A63BC), "a"(this), "d"(id)
				 : "ecx", "cc", "memory");
}
}
