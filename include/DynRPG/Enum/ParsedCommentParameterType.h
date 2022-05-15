#ifndef DYNRPG_PARSED_COMMENT_PARAMETER_TYPE_H
#define DYNRPG_PARSED_COMMENT_PARAMETER_TYPE_H

namespace RPG
{
/*! \brief Type of a parsed comment parameter
	\sa RPG::ParsedCommentParameter
	\sa RPG::ParsedCommentData
*/
enum ParsedCommentParameterType
{
	PARAM_NUMBER, //!< The parameter is a number
	PARAM_STRING, //!< The parameter is a string
	PARAM_TOKEN //!< The parameter is a token
};
}

#endif // DYNRPG_PARSED_COMMENT_PARAMETER_TYPE_H
