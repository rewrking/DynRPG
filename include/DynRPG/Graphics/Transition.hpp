#ifndef RPG_TRANSITION_HPP
#define RPG_TRANSITION_HPP

#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
//! Screen transitions
enum class Transition : uchar
{
	Fade,
	Dissolve,
	DissolveUp,
	DissolveDown,
	Blinds,
	VerticalStripes,
	HorizontalStrips,
	RecidingSquare,
	ExpandingSquare,
	ShiftUp,
	ShiftDown,
	ShiftLeft,
	ShiftRight,
	VerticalSplit,
	HorizontalSplit,
	FourWaySplit,
	Zoom,
	Mosaic,
	WaverScreen,
	Instant,
	None, //!< Used for "Erase" transitions to indicate that the screen should not be erased
	Default = 255 //!< Default transition from the database
};

//! One-byte version of RPG::Transition
//typedef uchar Transition_T;
}

#endif // RPG_TRANSITION_HPP
