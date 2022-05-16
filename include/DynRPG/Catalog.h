#ifndef DYNRPG_CATALOG_H
#define DYNRPG_CATALOG_H

#include <DynRPG/DListPtr.h>

namespace RPG
{
/*! \brief Wrapper class for RPG::DList which doesn't crash if the index
	is out of bounds
	\note Please do not ask me why this class is there. I didn't invent it.
	\warning This class has more members than the one which is documented
	(the others are used internally), so <tt>sizeof(RPG::Catalog\<T\>)</tt>
	is not equal to <tt>sizeof(RPG::DList\<T\> *)</tt>!
	\sa RPG::CatalogPtr
	\sa RPG::NamedCatalog
	\sa RPG::NamedCatalogPtr
	\sa RPG::DList
*/
template <class T = void*>
class Catalog
{
public:
	void** vTable;
	//! \cond
	void** itemVTable;
	//! \endcond
	DListPtr<T> list; //!< Pointer to the actual RPG::DList

	//! Array access operator
	T operator[](int index)
	{
		return get(index);
	}

	//! Array access method
	T get(int index)
	{
		return list.get(index);
	}

	//! Returns the number of items in the list
	int count()
	{
		return list.list->count;
	}
};
}

#endif // DYNRPG_CATALOG_H
