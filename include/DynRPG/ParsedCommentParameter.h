#ifndef DYNRPG_PARSED_COMMENT_PARAMETER_H
#define DYNRPG_PARSED_COMMENT_PARAMETER_H

#include <DynRPG/Enum/ParsedCommentParameterType.h>

namespace RPG
{
/*! \brief Used for parameters of parsed event comments (see \ref event_comments guidelines)
	\sa RPG::ParsedCommentData
*/
class ParsedCommentParameter
{
public:
	ParsedCommentParameterType type; //!< Type of the parameter
	double number; //!< Numerical value (if \c type is RPG::PARAM_NUMBER)
	char text[200]; //!< Text value (if \c type is RPG::PARAM_STRING or RPG::PARAM_TOKEN)
};
}

#endif // DYNRPG_PARSED_COMMENT_PARAMETER_H
