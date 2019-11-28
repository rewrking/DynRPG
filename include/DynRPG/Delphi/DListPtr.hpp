#ifndef RPG_DLIST_PTR_HPP
#define RPG_DLIST_PTR_HPP

#include <DynRPG/Delphi/DList.hpp>

namespace RPG
{
/*! \brief Wrapper class for RPG::DList pointers (syntactic sugar)

	\note The size of this class equals to
	<tt>sizeof(DList\<T\> *)</tt>.
	\sa RPG::DList
*/
template <class T = void*>
struct DListPtr
{
	DList<T>* list; //!< Actual RPG::DList pointer

	//! Array access operator which will throw an error on invalid indexes
	T& operator[](int index)
	{
		return (*list)[index];
	}

	//! Array access method which will return \c 0 on invalid indexes
	T get(int index)
	{
		return list->get(index);
	}
};
}

#endif // RPG_DLIST_PTR_HPP
