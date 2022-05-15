#ifndef DYNRPG_CATALOG_PTR_H
#define DYNRPG_CATALOG_PTR_H

#include <DynRPG/Catalog.h>

namespace RPG
{
/*! \brief Wrapper class for RPG::Catalog pointers (syntactic sugar)

	Allows you to write <tt>someCatalogPointer[i]</tt> instead of
	<tt>(*someCatalogPointer)[i]</tt>.
	\note The size of this class equals to
	<tt>sizeof(Catalog\<T\> *)</tt>.
	\sa RPG::Catalog
	\sa RPG::NamedCatalogPtr
*/
template <class T = void*>
class CatalogPtr
{
public:
	Catalog<T>* ptr; //!< Pointer to the actual RPG::Catalog

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

	//! Returns the number of items in the list
	int count()
	{
		return ptr ? ptr->count() : 0;
	}
};
}

#endif // DYNRPG_CATALOG_PTR_H
