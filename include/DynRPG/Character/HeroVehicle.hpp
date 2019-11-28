#ifndef RPG_HERO_VEHICLE_HPP
#define RPG_HERO_VEHICLE_HPP

namespace RPG
{
//! Possible values for RPG::Hero::vehicle and RPG::Vehicle::type
enum class HeroVehicle
{
	None, //!< Hero is in no vehicle
	Skiff, //!< Hero is in the skiff
	Ship, //!< Hero is in the ship
	Airship //!< Hero is in the airship
};
}

#endif // RPG_HERO_VEHICLE_HPP
