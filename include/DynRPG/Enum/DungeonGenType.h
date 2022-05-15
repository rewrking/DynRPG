#ifndef DYNRPG_DUNGEON_GEN_TYPE_H
#define DYNRPG_DUNGEON_GEN_TYPE_H

namespace RPG
{
//! Possible values for the RPG::MapProperties::dGenType member
enum DungeonGenType
{
	DGT_SINGLE_PASSAGE,
	DGT_LINKED_ROOMS,
	DGT_MAZE_LIKE,
	DGT_OPEN_ROOM
};
}

#endif // DYNRPG_DUNGEON_GEN_TYPE_H
