#ifndef RPG_EVENT_TRIGGER_HPP
#define RPG_EVENT_TRIGGER_HPP

namespace RPG
{
//! Event trigger
enum class EventTrigger
{
	ActionKey,
	PlayerTouch,
	EventTouch,
	AutoStart,
	ParallelProcess,
	None
};
}

#endif // RPG_EVENT_TRIGGER_HPP
