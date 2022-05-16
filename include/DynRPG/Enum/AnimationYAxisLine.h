#ifndef DYNRPG_ANIMATION_YAXIS_LINE_H
#define DYNRPG_ANIMATION_YAXIS_LINE_H

namespace RPG
{
/*! \brief Possible values for RPG::Animation::yLine

	Where does the vertical center of the animation lie?
*/
enum AnimationYAxisLine
{
	ANIM_YAXIS_HIGH,
	ANIM_YAXIS_CENTER,
	ANIM_YAXIS_LOW
};

//! One-byte version of RPG::AnimationYAxisLine
typedef unsigned char AnimationYAxisLine_T;
}

#endif // DYNRPG_ANIMATION_YAXIS_LINE_H
