#ifndef DYNRPG_HERO_H
#define DYNRPG_HERO_H

#include <DynRPG/Enum/EventTrigger.h>
#include <DynRPG/Enum/HeroControlMode.h>
#include <DynRPG/Enum/HeroPanTransitionSpeed.h>
#include <DynRPG/Enum/HeroVehicle.h>

#include <DynRPG/Character.h>

namespace RPG
{
/*! \brief Used for the hero as subtype of characters
	\sa RPG::hero
*/
class DYNRPG_API Hero : public Character
{
public:
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

	/*! \brief Check for event overlap
	*/
	void checkEventOverlapTrigger(EventTrigger triggerType, bool startedByActionButton);

	/*! \brief Check for event in front
	*/
	void checkEventInFrontTrigger(EventTrigger triggerType, bool startedByActionButton);
};

/*! \ingroup game_objects
	\brief The hero (which moves around on the map, similar to an event)
*/
extern DYNRPG_API RPG::Hero*& hero;
}

#endif // DYNRPG_HERO_H
