#ifndef DYNRPG_VEHICLE_H
#define DYNRPG_VEHICLE_H

#include <DynRPG/Enum/HeroVehicle.h>

#include <DynRPG/Character.h>

namespace RPG
{
/*! \brief Used for the vehicles as subtype of characters
	\sa RPG::vehicleSkiff
	\sa RPG::vehicleShip
	\sa RPG::vehicleAirship
	\sa RPG::hero
*/
class DYNRPG_API Vehicle : public Character
{
public:
	HeroVehicle type; //!< The id of the vehicle
	int takeOffTimer; //!< Timer for when taking off. 256-0 when rising into the air (if RPG::HeroVehicle is RPG::HV_AIRSHIP)
	int landingTimer; //!< Timer for landing. 256-0 when rising into the air (if RPG::HeroVehicle is RPG::HV_AIRSHIP)
};

/*! \ingroup game_objects
	\brief The skiff vehicle (which moves around on the map, similar to an event)
*/
extern DYNRPG_API RPG::Vehicle*& vehicleSkiff;
/*! \ingroup game_objects
	\brief The ship vehicle (which moves around on the map, similar to an event)
*/
extern DYNRPG_API RPG::Vehicle*& vehicleShip;
/*! \ingroup game_objects
	\brief The airship vehicle (which moves around on the map, similar to an event)
*/
extern DYNRPG_API RPG::Vehicle*& vehicleAirship;
}

#endif // DYNRPG_VEHICLE_H
