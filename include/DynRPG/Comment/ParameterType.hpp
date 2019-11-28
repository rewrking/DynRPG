#ifndef RPG_PARAMETER_TYPE_HPP
#define RPG_PARAMETER_TYPE_HPP

namespace RPG
{
/*! \brief Type of a parsed comment parameter
	\sa RPG::ParsedCommentParameter
	\sa RPG::ParsedCommentData
*/
enum class ParameterType
{
	Number, //!< The parameter is a number
	String, //!< The parameter is a string
	Token //!< The parameter is a token
};
}

#endif // RPG_PARAMETER_TYPE_HPP
