#ifndef DYNRPG_NAMED_CATALOG_PTR_H
#define DYNRPG_NAMED_CATALOG_PTR_H

#include <DynRPG/NamedCatalog.h>

namespace RPG
{
/*! \brief Wrapper class for RPG::NamedCatalog pointers (syntactic sugar)

	Allows you to write <tt>RPG::actors[1]->hp</tt> instead of
	<tt>(*</tt><tt>RPG::actors)[1]->hp</tt>, for example.
	\note The size of this class equals to
	<tt>sizeof(NamedCatalog\<T\> *)</tt>.
	\sa RPG::NamedCatalog
*/
template <class T = void*>
class NamedCatalogPtr
{
public:
	NamedCatalog<T>* ptr;

	//! Array access operator
	T operator[](int index)
	{
		return ptr->get(index);
	}

	//! Array access method
	T get(int index)
	{
		return ptr->get(index);
	}

	//! Returns the number of items in the list (not the highest ID!)
	int count()
	{
		return ptr ? ptr->count() : 0;
	}

	/*int size()
	{
		return sizeof((*ptr->list.list->items))/sizeof((*ptr->list.list->get(0)));
	}*/
};
}

#endif // DYNRPG_NAMED_CATALOG_PTR_H
