#ifndef DYNRPG_HERO_VEHICLE_H
#define DYNRPG_HERO_VEHICLE_H

namespace RPG
{
//! Possible values for RPG::Hero::vehicle and RPG::Vehicle::type
enum HeroVehicle
{
	HV_NONE, //!< Hero is in no vehicle
	HV_SKIFF, //!< Hero is in the skiff
	HV_SHIP, //!< Hero is in the ship
	HV_AIRSHIP //!< Hero is in the airship
};
}

#endif // DYNRPG_HERO_VEHICLE_H
