#ifndef DYNRPG_ARRAY_BASE_ONE_H
#define DYNRPG_ARRAY_BASE_ONE_H

namespace RPG
{
/*! \brief Helper class for arrays with base one

	This class template is used for arrays in classes with should have one
	as base (unlike normal arrays with base zero).
*/
template <class T, int size>
class ArrayBaseOne
{
private:
	T array[size]; //!< Original array

public:
	/*! \brief Simple indexing operator for accessing array elements
		\param index One-based index
		\return Value of the element
	*/
	inline T& operator[](int index)
	{
		return array[index - 1];
	}
};
}

#endif // DYNRPG_ARRAY_BASE_ONE_H
