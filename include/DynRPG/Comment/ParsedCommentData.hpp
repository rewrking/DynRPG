#ifndef RPG_PARSED_COMMENT_DATA_HPP
#define RPG_PARSED_COMMENT_DATA_HPP

#include <DynRPG/Comment/ParsedCommentParameter.hpp>

namespace RPG
{

/*! \brief Used for parsed event comments (see \ref event_comments guidelines)
	\sa RPG::ParsedCommentParameter
*/
struct ParsedCommentData
{
	char command[200]; //!< Command name (empty if it's no "special" comment at all)
	int parametersCount; //!< Number of parameters
	ParsedCommentParameter parameters[100]; //!< Parsed parameters
};
}

#endif // RPG_PARSED_COMMENT_DATA_HPP