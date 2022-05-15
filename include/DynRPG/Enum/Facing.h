#ifndef DYNRPG_FACING_H
#define DYNRPG_FACING_H

namespace RPG
{
//! Possible values for RPG::EventPage::charsetDir and RPG::Character::facing
enum Facing
{
	FACE_UP, //!< %Character looks up
	FACE_RIGHT, //!< %Character looks to the right
	FACE_DOWN, //!< %Character looks down
	FACE_LEFT //!< %Character looks to the left
};

//! One-byte version of RPG::Facing
typedef unsigned char Facing_T;
}

#endif // DYNRPG_FACING_H
