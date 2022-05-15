#ifndef DYNRPG_MAP_LMU_FILE_H
#define DYNRPG_MAP_LMU_FILE_H

namespace RPG
{
/*! \brief The paramaters for the LMU (map) files.

	\sa RPG::MapProperties
*/
class MapLmuFile
{
public:
	void** vTable;
	int mapWidth; //!< The width of the map
	int mapHeight; //!< The height of the map
	bool horWrapping; //!< Is horizontal wrapping enabled?
	bool verWrapping; //!< Is vertical wrapping enabled?
	char _unknown_0E;
	char _unknown_0F;
	void* _unknown_10;
	int _unknown_14;
	void* _unknown_18; // MapProperties? (0 if not used)
};
}

#endif // DYNRPG_MAP_LMU_FILE_H
