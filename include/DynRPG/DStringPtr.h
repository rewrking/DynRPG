#ifndef DYNRPG_DSTRING_PTR_H
#define DYNRPG_DSTRING_PTR_H

#include <DynRPG/DString.h>

#include <string>

namespace RPG
{
/*! \brief Mighty wrapper class for DString pointers, <i>the</i>
	string class for %RPG Maker strings

	This class can also be used to assign a Delphi string. The string will
	then automatically be reallocated if necessary.
	\warning Please mind the \ref rules about strings!
	\sa DString
*/
class DStringPtr
{
public:
	DString* str; //!< Pointer to the actual string data

	DStringPtr(); //!< Constructor (initializes the pointer to zero)
	DStringPtr(DStringPtr& s); //!< Copy constructor
	DStringPtr(std::string s); //!< Constructor (uses a \c std::string as template)
	~DStringPtr(); //!< Destructor (deallocates the string when the class is destroyed)

	operator std::string(); //!< Cast operator for \c std::string (recommended)
	operator char*(); //!< Cast operator for <tt>char *</tt>
	const DStringPtr& operator=(std::string rhs); //!< Assignment operator for \c std::string (recommended)
	const DStringPtr& operator=(char* rhs); //!< Assignment operator for <tt>char *</tt>
	const DStringPtr& operator=(const char* rhs); //!< Assignment operator for <tt>const char *</tt>
	const DStringPtr& operator=(DString* rhs); //!< Can be used to copy a string by writing <tt>newString = oldString.str;</tt>
	bool operator==(std::string rhs); //!< Comparison operator for \c std::string
	bool operator==(const char* rhs); //!< Comparison operator for \c char *
	bool operator==(DStringPtr& rhs); //!< Comparison operator for other DStringPtr classes

	//! Clears the string
	void clear();

	//! Assigns the string from a <tt>char *</tt> which may contain null bytes.
	void assign(char* s, int len);

	//! Explicit conversion function to \c std::string (recommended)
	std::string s_str();

	//! Returns the length of the string
	int length();
};
}

#endif // DYNRPG_DSTRING_PTR_H
