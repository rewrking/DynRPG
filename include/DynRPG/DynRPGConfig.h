#ifndef DYNRPG_CONFIG_H
#define DYNRPG_CONFIG_H

#ifndef __GNUC__
	#error Sorry, DynRPG does only work with the GNU C++ compiler! See gcc.gnu.org
#endif // __GNUC__

#ifndef __cplusplus
	#error Sorry, DynRPG is a C++ SDK! Mind the plus plus :-)
#endif // __cplusplus

#if __GNUC__ < 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ < 7 || (__GNUC_MINOR__ == 7 && __GNUC_PATCHLEVEL__ < 1)))
	#error Sorry, this DynRPG version needs at least GNU C++ version 4.7.1! See gcc.gnu.org
#endif

#define DYNLOADER_EXPORT __declspec(dllexport)

#if defined(DYNRPG_SHARED) && defined(__GNUC__)
	#define DYNRPG_API_EXPORT __declspec(dllexport)
	#define DYNRPG_API_IMPORT __declspec(dllimport)
#else
	#define DYNRPG_API_EXPORT
	#define DYNRPG_API_IMPORT
#endif

#if defined(DYNRPG_EXPORTS)
	#define DYNRPG_API DYNRPG_API_EXPORT
#else
	#define DYNRPG_API DYNRPG_API_IMPORT
#endif

#define DYNRPG_LINK_VERSION 3

#ifndef NULL
	#define NULL 0
#endif

#endif // DYNRPG_CONFIG_H