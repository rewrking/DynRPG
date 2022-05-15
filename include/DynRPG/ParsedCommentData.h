#ifndef DYNRPG_PARSED_COMMENT_DATA_H
#define DYNRPG_PARSED_COMMENT_DATA_H

#include <DynRPG/ParsedCommentParameter.h>

namespace RPG
{

/*! \brief Used for parsed event comments (see \ref event_comments guidelines)
	\sa RPG::ParsedCommentParameter
*/
class ParsedCommentData
{
public:
	char command[200]; //!< Command name (empty if it's no "special" comment at all)
	int parametersCount; //!< Number of parameters
	ParsedCommentParameter parameters[100]; //!< Parsed parameters
};
}

#endif // DYNRPG_PARSED_COMMENT_DATA_H
