#ifndef RPG_MENU_COMMAND_HPP
#define RPG_MENU_COMMAND_HPP

namespace RPG
{
//! Possible values for RPG::DBSystem::menuCommand
enum class MenuCommand : short
{
	None,
	Item,
	Skill,
	Equip,
	Party,
	Status,
	Position,
	Order,
	AtbMode
};

//! Two-byte version of RPG::MenuCommand
//typedef short MenuCommand_T;
}

#endif // RPG_MENU_COMMAND_HPP
