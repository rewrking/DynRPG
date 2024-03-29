#ifndef DYNRPG_DBITMAP_H
#define DYNRPG_DBITMAP_H

#include <DynRPG/WinApi.h>

namespace RPG
{
//! Wrapper class for windows' HBITMAPs
class DYNRPG_API DBitmap
{
public:
	void** vTable;

	//! Returns the HBITMAP
	inline HBITMAP getHBITMAP()
	{
		HBITMAP ret;
		asm volatile("call *%%esi"
					 : "=a"(ret)
					 : "S"(0x428140), "a"(this)
					 : "edx", "ecx", "cc", "memory");
		return ret;
	}

	//! Returns the HDC
	inline HDC getHDC()
	{
		HDC ret;
		asm volatile("call *%%esi; call *%%edi"
					 : "=a"(ret)
					 : "S"(0x4280F8), "D"(0x423634), "a"(this)
					 : "edx", "ecx", "cc", "memory");
		return ret;
	}
};
}

#endif // DYNRPG_DBITMAP_H
