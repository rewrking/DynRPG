#ifndef RPG_MAP_LMU_FILE_HPP
#define RPG_MAP_LMU_FILE_HPP

#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
/*! \brief The paramaters for the LMU (map) files.

	\sa RPG::MapProperties
*/
struct MapLmuFile
{
	// clang-format off
	void** vTable;
	int mapWidth; //!< The width of the map
	int mapHeight; //!< The height of the map
	bool horWrapping; //!< Is horizontal wrapping enabled?
	bool verWrapping; //!< Is vertical wrapping enabled?
		char _unknown_0E;
		char _unknown_0F;
		StubPtr _unknown_10;
		int _unknown_14;
		StubPtr _unknown_18; // MapProperties? (0 if not used)
	// clang-format on
};
}

#endif // RPG_MAP_LMU_FILE_HPP