#ifndef RPG_NAMED_CATALOG_HPP
#define RPG_NAMED_CATALOG_HPP

#include <DynRPG/Catalog/Catalog.hpp>
#include <DynRPG/Utility/AsmRegisters.hpp>

namespace RPG
{
/*! \brief Class inherited from RPG::Catalog in which elements with
	non-consecutive IDs are stored without waste of memory (i.e.
	events on a map)

	If you need to enumerate all items in an RPG::NamedCatalog, use
	\code
for(int i = 0; i < myCatalog.count(); i++) {
SomeObjectType *item = myCatalog.list[i];
// Processing here...
}
	\endcode
	If you have an RPG::NamedCatalogPtr, it works the same way.
	\sa RPG::Catalog
	\sa RPG::NamedCatalogPtr
*/
template <class T = void*>
struct NamedCatalog : Catalog<T>
{
	//! Array access operator
	T operator[](int index)
	{
		return get(index);
	}

	//! Array access method
	T get(int index)
	{
		T ret = nullptr;
		asm volatile("call *%%esi"
					 : "=a"(ret), "=d"(_edx)
					 : "S"(0x475740), "a"(this), "d"(index)
					 : "ecx", "cc", "memory"); // GetFromList
		return ret;
	}
};
}

#endif // RPG_NAMED_CATALOG_HPP
