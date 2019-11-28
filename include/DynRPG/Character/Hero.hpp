#ifndef RPG_HERO_HPP
#define RPG_HERO_HPP

#include <DynRPG/Character/Character.hpp>
#include <DynRPG/Character/HeroControlMode.hpp>
#include <DynRPG/Character/HeroPanTransitionSpeed.hpp>
#include <DynRPG/Character/HeroVehicle.hpp>
#include <DynRPG/Event/EventTrigger.hpp>

namespace RPG
{
/*! \brief Used for the hero as subtype of characters
	\sa RPG::hero
*/
struct Hero : Character
{
	// clang-format off
	// sizeof(Character) == 0x94
		int _unknown_94;
	bool isEnteringVehicle; //!< Only true if the hero is entering a vehicle
	bool isInVehicle; //!< True when the hero has entered a vehicle
	HeroVehicle vehicle; //!< Tells you whether the hero is in a vehicle at the moment
	bool isLeavingVehicle; //!< Only true if the hero is dismounting a vehicle
		int _unknown_A4;
		bool _unknown_A8;
	bool screenPanUnlocked; //!< Can screen panning be used?
	int mapOffsetX; // ??
	int mapOffsetY; // ??
	int mapHeroOffsetX; //!<  (default = 9*256) ??
	int mapHeroOffsetY; //!<  (default = 7*256) ??
	HeroPanTransitionSpeed panTransitionSpeed; //!< Same as Pan Screen Transition Speed^4 (4: Normal would be 16)
		int _unknown_C0;
		int _unknown_C4;
		int _unknown_C8;
		int _unknown_CC;
	// clang-format on

	/*! \brief Returns the current hero control mode
		\note This is a special feature of the DynRPG patch.
		\return Current control mode
		\sa setControlMode
	*/
	HeroControlMode getControlMode();

	/*! \brief Sets the hero control mode
		\note This is a special feature of the DynRPG patch.
		\param controlMode The new control mode
		\sa getControlMode
	*/
	void setControlMode(HeroControlMode controlMode);

	/*! \brief Built-in function to run various checks after a step has been made (NOT map collision!)... enemy encounters most importantly, event-related checks (not all known)

		Use this function if the hero's movement behavior is being altered dramatically (pixel movement for instance), but still need enemy encounter checks.
	*/
	void act();

	void checkEventOverlapTrigger(EventTrigger triggerType, bool startedByActionButton);

	void checkEventInFrontTrigger(EventTrigger triggerType, bool startedByActionButton);
};

/*! \ingroup game_objects
	\brief The hero (which moves around on the map, similar to an event)
*/
static Hero*& hero = (**reinterpret_cast<Hero***>(0x4CDE54));
}

#endif // RPG_HERO_HPP
