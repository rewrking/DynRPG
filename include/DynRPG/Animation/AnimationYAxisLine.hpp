#ifndef RPG_ANIMATION_Y_AXIS_LINE_HPP
#define RPG_ANIMATION_Y_AXIS_LINE_HPP

#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
/*! \brief Possible values for RPG::Animation::yLine

	Where does the vertical center of the animation lie?
*/
enum class AnimationYAxisLine : uchar
{
	High,
	Center,
	Low
};

//! One-byte version of RPG::AnimationYAxisLine
//typedef uchar AnimationYAxisLine_T;

}

#endif // RPG_ANIMATION_Y_AXIS_LINE_HPP
