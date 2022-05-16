#ifndef DYNRPG_ATB_MODE_H
#define DYNRPG_ATB_MODE_H

namespace RPG
{
//! Possible values for RPG::System::atbMode
enum ATBMode
{
	ATBM_ACTIVE, //!< "Active" mode (enemies also attack in selection menus)
	ATBM_WAIT //!< "Wait" mode
};

//! One-byte version or RPG::ATBMode
typedef unsigned char ATBMode_T;
}

#endif // DYNRPG_ATB_MODE_H
