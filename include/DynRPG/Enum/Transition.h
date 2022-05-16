#ifndef DYNRPG_TRANSITION_H
#define DYNRPG_TRANSITION_H

namespace RPG
{
//! Screen transitions
enum Transition
{
	TRANS_FADE,
	TRANS_DISSOLVE,
	TRANS_DISSOLVE_UP,
	TRANS_DISSOLVE_DOWN,
	TRANS_BLINDS,
	TRANS_VERTICAL_STRIPES,
	TRANS_HORIZONTAL_STRIPES,
	TRANS_RECIDING_SQUARE,
	TRANS_EXPANDING_SQUARE,
	TRANS_SHIFT_UP,
	TRANS_SHIFT_DOWN,
	TRANS_SHIFT_LEFT,
	TRANS_SHIFT_RIGHT,
	TRANS_VERTICAL_SPLIT,
	TRANS_HORIZONTAL_SPLIT,
	TRANS_4_WAY_SPLIT,
	TRANS_ZOOM,
	TRANS_MOSAIC,
	TRANS_WAVER_SCREEN,
	TRANS_INSTANT,
	TRANS_NONE, //!< Used for "Erase" transitions to indicate that the screen should not be erased
	TRANS_DEFAULT = 255 //!< Default transition from the database
};

//! One-byte version of RPG::Transition
typedef unsigned char Transition_T;
}

#endif // DYNRPG_TRANSITION_H
