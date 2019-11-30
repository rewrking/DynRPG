#ifndef RPG_MOVE_TYPE_HPP
#define RPG_MOVE_TYPE_HPP

namespace RPG
{
/*! \brief "Move event" command type

	A few of these commands take parameters, see details. For information
	how to use these commands, see the RPG::Character::move documentation.
	\sa RPG::Character::move
	\note <b>Not all enumeration values are documented here</b>, scroll to the top
	to see all possible values (in the general enum overview)!
*/
enum class MoveType : char
{
	MoveUp,
	MoveRight,
	MoveDown,
	MoveLeft,
	MoveUpRight,
	MoveDownRight,
	MoveDownLeft,
	MoveUpLeft,
	MoveRandomly,
	MoveTowardHero,
	MoveAwayFromHero,
	MoveForward,
	FaceUp,
	FaceRight,
	FaceDown,
	FaceLeft,
	TurnRight,
	TurnLeft,
	TurnAround,
	TurnRandomly,
	FaceRandomly,
	FaceTowardHero,
	FaceAwayFromHero,
	Wait,
	BeginJump,
	EndJump,
	LockFacing,
	UnlockFacing,
	IncreaseSpeed,
	DecreaseSpeed,
	IncreaseFrequency,
	DecreaseFrequency,
	/*! \brief Turns a switch ON

		This command takes one integer parameter: The switch ID.
		\sa RPG::MT_SWITCH_OFF
		\sa RPG::Switches
	*/
	SwitchOn,
	/*! \brief Turns a switch OFF

		This command takes one integer parameter: The switch ID.
		\sa RPG::MT_SWITCH_ON
		\sa RPG::Switches
	*/
	SwitchOff,
	/*! \brief Changes the charset graphic of the character

		This command takes two parameters:
			<ul><li>The charset filename (string)</li>
			<li>The charset sprite ID (integer)</li></ul>
	*/
	ChangeGraphic,
	/*! \brief Plays a sound effect

		This command takes four parameters:
			<ul><li>The sound filename (string)</li>
			<li>The sound volume (integer)</li>
			<li>The sound speed (integer)</li>
			<li>The sound pan value (integer)</li></ul>
		\sa RPG::Sound
	*/
	PlaySoundEffect,
	PhasingModeOn,
	PhasingModeOff,
	StopAnimation,
	ResumeAnimation,
	IncreaseTransparency,
	DecreaseTransparency
};
}

#endif // RPG_MOVE_TYPE_HPP
