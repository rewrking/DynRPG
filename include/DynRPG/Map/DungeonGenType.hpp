#ifndef RPG_DUNGEON_GEN_TYPE_HPP
#define RPG_DUNGEON_GEN_TYPE_HPP

namespace RPG
{
//! Possible values for the RPG::MapProperties::dGenType member
enum class DungeonGenType
{
	SinglePassage,
	LinkedRooms,
	MazeLike,
	OpenRoom
};
}

#endif // RPG_DUNGEON_GEN_TYPE_HPP
