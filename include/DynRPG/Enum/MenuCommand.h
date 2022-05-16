#ifndef DYNRPG_MENU_COMMAND_H
#define DYNRPG_MENU_COMMAND_H

namespace RPG
{
//! Possible values for RPG::DBSystem::menuCommand
enum MenuCommand
{
	MENU_CMD_NONE,
	MENU_CMD_ITEM,
	MENU_CMD_SKILL,
	MENU_CMD_EQUIP,
	MENU_CMD_PARTY,
	MENU_CMD_STATUS,
	MENU_CMD_POSITION,
	MENU_CMD_ORDER,
	MENU_CMD_ATB_MODE
};

//! Two-byte version of RPG::MenuCommand
typedef short MenuCommand_T;
}

#endif // DYNRPG_MENU_COMMAND_H
