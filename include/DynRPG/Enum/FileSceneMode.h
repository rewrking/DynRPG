#ifndef DYNRPG_FILE_SCENE_MODE_H
#define DYNRPG_FILE_SCENE_MODE_H

namespace RPG
{
/*! \brief Possible values for RPG::SceneFile::mode
*/
enum FileSceneMode
{
	FILE_LOAD,
	FILE_SAVE
};

//! One-byte version of RPG::FileSceneMode
typedef unsigned char FileSceneMode_T;
}

#endif // DYNRPG_FILE_SCENE_MODE_H
