#ifndef RPG_ATB_MODE_HPP
#define RPG_ATB_MODE_HPP

#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
//! Possible values for RPG::System::atbMode
enum class ATBMode : uchar
{
	Active, //!< "Active" mode (enemies also attack in selection menus)
	Wait //!< "Wait" mode
};

//! One-byte version or RPG::ATBMode
//typedef uchar ATBMode_T;
}

#endif // RPG_ATB_MODE_HPP
