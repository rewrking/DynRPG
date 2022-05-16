#ifndef DYNRPG_DLIST_H
#define DYNRPG_DLIST_H

namespace RPG
{
/*! \brief Class representing Delphi's \c TList (without resizing for the moment)
	\sa RPG::DListPtr
	\sa RPG::Catalog
*/
template <class T = void*>
class DList
{
public:
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
			return NULL;
		return items[index];
	}
};
}

#endif // DYNRPG_DLIST_H
