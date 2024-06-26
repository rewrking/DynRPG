#ifndef DYNRPG_ANIMATION2_H
#define DYNRPG_ANIMATION2_H

#include <DynRPG/Enum/Animation2DisplaySpeed.h>

#include <DynRPG/Animation2Pose.h>
#include <DynRPG/Animation2Weapon.h>
#include <DynRPG/CatalogPtr.h>
#include <DynRPG/DStringPtr.h>
#include <DynRPG/NamedCatalogPtr.h>

namespace RPG
{
/*! \brief Used to define a battler's character animation.
	\sa RPG::battlerAnimations
	\sa RPG::Anim2DisplaySpeed
	\sa RPG::Animation2Pose
	\sa RPG::Animation2Weapon
*/
class Animation2
{
public:
	void** vTable;
	int id; //!< ID of the pose
	DStringPtr name; //!< The name of the pose
	CatalogPtr<Animation2Pose*> poses; //!< The array of poses for the battler
	CatalogPtr<Animation2Weapon*> weapons; //!< The array of weapons for the battler
	int _unknown_14;
	int _unknown_18;
	Animation2DisplaySpeed displaySpeed; //!< The animation's display speed
};

/*! \ingroup game_objects
	\brief Array of battle animations from the database, used for default values and
	properties which are not supposed to be changed in-game.

	Use the database ID as index for accessing an animation.

	Example:
	\code
	std::string animation2Name = RPG::battlerAnimations[4]->name.s_str());
	\endcode
*/
extern DYNRPG_API RPG::NamedCatalogPtr<RPG::Animation2*>& battlerAnimations;
}

#endif // DYNRPG_ANIMATION2_H
