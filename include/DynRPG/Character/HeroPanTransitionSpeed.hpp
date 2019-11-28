#ifndef RPG_HERO_PAN_TRANSITION_SPEED_HPP
#define RPG_HERO_PAN_TRANSITION_SPEED_HPP

namespace RPG
{
//! Hero pan speed (see RPG::Hero::panTransitionSpeed)
enum class HeroPanTransitionSpeed
{
	OneEighthNormal = 4,
	OneFourthNormal = 8,
	OneHalfNormal = 16,
	Normal = 32,
	TwiceNormal = 64,
	FourTimesNormal = 128
};
}

#endif // RPG_HERO_PAN_TRANSITION_SPEED_HPP
