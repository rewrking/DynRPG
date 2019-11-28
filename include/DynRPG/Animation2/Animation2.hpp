#ifndef RPG_ANIMATION2_HPP
#define RPG_ANIMATION2_HPP

#include <DynRPG/Animation2/Animation2Pose.hpp>
#include <DynRPG/Animation2/Animation2Weapon.hpp>
#include <DynRPG/Catalog/CatalogPtr.hpp>
#include <DynRPG/Catalog/NamedCatalogPtr.hpp>
#include <DynRPG/Delphi/DStringPtr.hpp>

namespace RPG
{
/*! \brief Used to define a battler's character animation.
	\sa RPG::battlerAnimations
	\sa RPG::Animation2DisplaySpeed
	\sa RPG::Animation2Pose
	\sa RPG::Animation2Weapon
*/
struct Animation2
{
	// clang-format off
	void** vTable;
	int id; //!< ID of the pose
	DStringPtr name; //!< The name of the pose
	CatalogPtr<Animation2Pose*> poses; //!< The array of poses for the battler
	CatalogPtr<Animation2Weapon*> weapons; //!< The array of weapons for the battler
		int _unknown_14;
		int _unknown_18;
	Animation2DisplaySpeed displaySpeed; //!< The animation's display speed
	// clang-format on
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
static NamedCatalogPtr<Animation2*>& battlerAnimations = (**reinterpret_cast<NamedCatalogPtr<Animation2*>**>(0x4CDC90));
}

#endif // RPG_ANIMATION2_HPP
