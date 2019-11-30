#ifndef RPG_DLIST_HPP
#define RPG_DLIST_HPP

#include <DynRPG/Utility/Defines.hpp>

namespace RPG
{
/*! \brief Class representing Delphi's \c TList (without resizing for the moment)
	\sa RPG::DListPtr
	\sa RPG::Catalog
*/
template <class T = void*>
struct DList
{
	void** vTable;
	T* items; //!< Pointer to the actual array
	int count; //!< Number of elements in the list

	//! Array access operator which will throw an error on invalid indexes
	T& operator[](int index)
	{
		if (index < 0 || index >= count)
			throw "DList index out of bounds (resizing not implemented)";
		return items[index];
	}

	//! Array access method which will return \c 0 on invalid indexes
	T get(int index)
	{
		if (index < 0 || index >= count)
			return nullptr;

		return items[index];
	}
};
}

#endif // RPG_DLIST_HPP
