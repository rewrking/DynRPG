#ifndef RPG_VEHICLE_HPP
#define RPG_VEHICLE_HPP

#include <DynRPG/Character/Character.hpp>
#include <DynRPG/Character/HeroVehicle.hpp>

namespace RPG
{
/*! \brief Used for the vehicles as subtype of characters
	\sa RPG::vehicleSkiff
	\sa RPG::vehicleShip
	\sa RPG::vehicleAirship
	\sa RPG::hero
*/
struct Vehicle : Character
{
	HeroVehicle type; //!< The id of the vehicle
	int takeOffTimer; //!< Timer for when taking off. 256-0 when rising into the air (if RPG::HeroVehicle is RPG::HV_AIRSHIP)
	int landingTimer; //!< Timer for landing. 256-0 when rising into the air (if RPG::HeroVehicle is RPG::HV_AIRSHIP)
};

/*! \ingroup game_objects
	\brief The skiff vehicle (which moves around on the map, similar to an event)
*/
static Vehicle*& vehicleSkiff = (**reinterpret_cast<Vehicle***>(0x4CE00C));
/*! \ingroup game_objects
	\brief The ship vehicle (which moves around on the map, similar to an event)
*/
static Vehicle*& vehicleShip = (**reinterpret_cast<Vehicle***>(0x4CE034));
/*! \ingroup game_objects
	\brief The airship vehicle (which moves around on the map, similar to an event)
*/
static Vehicle*& vehicleAirship = (**reinterpret_cast<Vehicle***>(0x4CDE68));
}

#endif // RPG_VEHICLE_HPP
