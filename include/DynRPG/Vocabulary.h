#ifndef DYNRPG_VOCABULARY_H
#define DYNRPG_VOCABULARY_H

#include <DynRPG/DStringPtr.h>

namespace RPG
{
/*! \brief Accesses the array of Strings in the database.

	\return The RPG::DStringPtr to a particular string.

	Example:
	\code
std::string victoryMessage = RPG::vocabulary[3]
	\endcode

	Indexes are:

	String Page 1

			0: Message at the Beginning of Each Battle
			1: Initiative Message
			2: Escape Failure Message
			3: Victory Message
			4: Defeat Message
			5: Experience Gain Message (Field 2)
			6: Money Acquisition Message (Field 1)
			7: Money Acquisition Message (Field 3)
			8: Item Discovery Message

	The following are not in the Strings tab... (but accessible via Resource Hacker)

			9: attacks
		10: A critical hit! (target = monster)
		11: A critical hit! (target = hero)
		12: defends.
		13: is waiting and watching.
		14: is building strength.
		15: pounces.
		16: runs away!
		17: transformed
		18: HP is lost (target = monster)
		19: Dodged (target = monster)
		20: HP is lost (target = hero)
		21: dodged (target = hero)
		22: got out of the way (magic)
		23: needs more practice (magic)
		24: was not affected (magic)
		25: dodged (physical)
		26: used
		27: recovered!
		28: raises!
		29: drops
		30: is taken!
		31: is taken!
		32: Defense increases!
		33: Defense decreases!

	Strings Page 2

		34: Level Up (Field 2)
		35: Skill Learned (Field 2)
		36: ??
		37: ??
		38: ??
		39: ??
		40: ??

	Strings Page 4

		41: Items Possessed
		42: Item Equipped
		43: Currency

	Strings Page 5

		44: Fight
		45: Auto-Fight
		46: Escape

	????

		47: "Attack"
		48: "Defend"

	Strings Page 5 (continued)

		49: Item
		50: Skill
		51: Equipment
		52: Save
		53: Quit
		54: New Game
		55: Load Game
		56: Quit Game
		57: Level
		58: HP
		59: MP
		60: Normal Status
		61: Experience
		62: Level (Short Form)
		63: HP (Short Form)
		64: MP (Short Form)
		65: MP Consumed
		66: Attack
		67: Defense
		68: Intelligence
		69: Agility
		70: Weapon
		71: Shield
		72: Armor
		73: Helmet
		74: Accessory
		75: Choosing a Save Slot
		76: Choosing Which Slot to Load
		77: Confirm Quit
		78: File
		79: Yes
		80: No
		81: Status
		82: Order
		83: Row
		84: Wait ON
		85: Wait OFF

	????

		86: ??

	String Page 1 (continued)

		87:  "Miss" Message
*/
extern DYNRPG_API DStringPtr*& vocabulary;
}

#endif // DYNRPG_VOCABULARY_H
