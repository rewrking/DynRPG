#ifndef DYNRPG_MOVE_ROUTE_H
#define DYNRPG_MOVE_ROUTE_H

#include <DynRPG/DArray.h>
#include <DynRPG/DListPtr.h>
#include <DynRPG/Enum/MoveType.h>

namespace RPG
{
//! Not implemented yet
typedef void MoveRouteItem;

/*! \brief Used for the move route of an character (also set by the "Move Event" command)
	\sa RPG::MoveType
	\sa RPG::Character::move
*/
class MoveRoute
{
public:
	void** vTable;
	DListPtr<MoveRouteItem*> moves; //!< List of movement commands (internal storage, not yet implemented)
	DArray<char> encodedMoves; //!< Encoded movement command list (see RPG::Character::move)
	bool repeatPattern; //!< \c true if the movement should be repeated until RPG::Character::stop (or "Halt all movement") is called
	bool ignoreImpossible; //!< \c true if impossible movement commands should be skipped
};
}

#endif // DYNRPG_MOVE_ROUTE_H
