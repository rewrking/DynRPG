#ifndef RPG_EVENT_MOVE_FREQUENCY_HPP
#define RPG_EVENT_MOVE_FREQUENCY_HPP

namespace RPG
{
//! Possible values for the RPG::EventPage::moveSpeed member
enum class EventMoveFrequency
{
	OneEighthNormal = 1,
	OneFourthNormal,
	OneHalfNormal,
	Normal,
	TwiceNormal,
	FourTimesNormal
};
}

#endif // RPG_EVENT_MOVE_FREQUENCY_HPP
