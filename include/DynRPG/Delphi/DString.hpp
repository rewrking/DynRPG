#ifndef RPG_DSTRING_HPP
#define RPG_DSTRING_HPP

#include <string>

namespace RPG
{
/*! \brief Helper class representing a Delphi string

	This class has no members. It is only "virtual", which means an
	RPG::DString pointer can be used instead of a <tt>char *</tt> to be
	able to access the length information of the string and provide a
	nice automatic cast to std::string even when there are embedded nulls.
	\note In most cases, the RPG::DStringPtr class is used instead of an
	RPG::DString pointer.
	\warning Please mind the \ref rules about strings!
	\sa RPG::DStringPtr
*/
struct DString
{
	//! Cast operator returning a \c std::string (recommended)
	operator std::string() const;

	//! Cast operator returning a <tt>char *</tt>
	operator char*() const;

	//! Returns the length of the string
	int length();
};
}

#endif // RPG_DSTRING_HPP