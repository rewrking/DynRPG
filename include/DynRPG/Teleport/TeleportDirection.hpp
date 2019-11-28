#ifndef RPG_TELEPORT_DIRECTION_HPP
#define RPG_TELEPORT_DIRECTION_HPP

namespace RPG
{
/*! \brief Possible values for RPG::Teleport::facingDirection

	The teleport direction
*/
enum class TeleportDirection
{
	RetainFacing,
	Up,
	Right,
	Down,
	Left
};
}

#endif // RPG_TELEPORT_DIRECTION_HPP
