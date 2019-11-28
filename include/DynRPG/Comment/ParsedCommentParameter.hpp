#ifndef RPG_PARSED_COMMENT_PARAMETER_HPP
#define RPG_PARSED_COMMENT_PARAMETER_HPP

#include <DynRPG/Comment/ParameterType.hpp>

namespace RPG
{
/*! \brief Used for parameters of parsed event comments (see \ref event_comments guidelines)
	\sa RPG::ParsedCommentData
*/
struct ParsedCommentParameter
{
	ParameterType type; //!< Type of the parameter
	double number; //!< Numerical value (if \c type is RPG::PARAM_NUMBER)
	char text[200]; //!< Text value (if \c type is RPG::PARAM_STRING or RPG::PARAM_TOKEN)
};
}

#endif // RPG_PARSED_COMMENT_PARAMETER_HPP
