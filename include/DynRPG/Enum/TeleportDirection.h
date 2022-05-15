#ifndef DYNRPG_TELEPORT_DIRECTION_H
#define DYNRPG_TELEPORT_DIRECTION_H

namespace RPG
{
/*! \brief Possible values for RPG::Teleport::facingDirection

	The teleport direction
*/
enum TeleportDirection
{
	TP_DIR_RETAIN_FACING,
	TP_DIR_UP,
	TP_DIR_RIGHT,
	TP_DIR_DOWN,
	TP_DIR_LEFT
};
}

#endif // DYNRPG_TELEPORT_DIRECTION_H
