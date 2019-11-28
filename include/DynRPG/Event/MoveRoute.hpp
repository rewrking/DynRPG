#ifndef RPG_MOVE_ROUTE_HPP
#define RPG_MOVE_ROUTE_HPP

#include <DynRPG/Delphi/DArray.hpp>
#include <DynRPG/Delphi/DListPtr.hpp>

namespace RPG
{
//! Not implemented yet
using MoveRouteItem = void;

/*! \brief Used for the move route of an character (also set by the "Move Event" command)
	\sa RPG::MoveType
	\sa RPG::Character::move
*/
struct MoveRoute
{
	void** vTable;
	DListPtr<MoveRouteItem*> moves; //!< List of movement commands (internal storage, not yet implemented)
	DArray<char> encodedMoves; //!< Encoded movement command list (see RPG::Character::move)
	bool repeatPattern; //!< \c true if the movement should be repeated until RPG::Character::stop (or "Halt all movement") is called
	bool ignoreImpossible; //!< \c true if impossible movement commands should be skipped
};
}

#endif // RPG_MOVE_ROUTE_HPP
