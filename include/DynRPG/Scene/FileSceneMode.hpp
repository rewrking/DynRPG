#ifndef RPG_FILE_SCENE_MODE_HPP
#define RPG_FILE_SCENE_MODE_HPP

#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
/*! \brief Possible values for RPG::SceneFile::mode
*/
enum class FileSceneMode : uchar
{
	Load,
	Save
};

//! One-byte version of RPG::FileSceneMode
//typedef uchar FileSceneMode_T;
}

#endif // RPG_FILE_SCENE_MODE_HPP
