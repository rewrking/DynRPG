#ifndef DYNRPG_WINDOW_SAVE_FILE_H
#define DYNRPG_WINDOW_SAVE_FILE_H

#include <DynRPG/Image.h>
#include <DynRPG/Window.h>

namespace RPG
{
/*! \brief Used for individual save files within the Save/load menu.

	\sa RPG::SceneMenu
*/
class DYNRPG_API WindowSaveFile : public Window
{
public:
	int saveSlotId; //!< The ID of the save slot currently selected
	Image* partyFaceImage[4]; //!< Array for the facesets of the 4 party members
	int _unknown_8C;
	int timeStamp; //!< The timestamp of the save?
};
}

#endif // DYNRPG_WINDOW_SAVE_FILE_H
