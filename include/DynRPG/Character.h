#ifndef DYNRPG_CHARACTER_H
#define DYNRPG_CHARACTER_H

#include <DynRPG/Enum/AnimationType.h>
#include <DynRPG/Enum/Direction.h>
#include <DynRPG/Enum/Facing.h>
#include <DynRPG/Enum/Layer.h>

#include <DynRPG/DStringPtr.h>
#include <DynRPG/MoveRoute.h>

#include <string>

namespace RPG
{
/*! \brief Used for movable entities on the map, i.e. events, the hero (and vehicles, but they are not supported yet)
	\sa RPG::Event
	\sa RPG::Map::events
	\sa RPG::Hero
	\sa RPG::hero
	\sa RPG::Direction
	\sa RPG::Facing
	\sa RPG::Layer
	\sa RPG::AnimationType
	\sa RPG::MoveRoute
*/
class DYNRPG_API Character
{
public:
	void** vTable;
	int id; //!< ID of the event (zero if not an ordinary event)
	int _unknown_8;
	bool enabled; //!< Is the event visible and enabled?
	int mapId; //!< %Map ID (only relevant for vehicles)
	int x; //!< X coordinate (tiles)
	int y; //!< Y coordinate (tiles)
	Direction_T direction; //!< Direction for moving (see RPG::Direction)
	Facing_T facing; //!< Direction for facing (see RPG::Facing)
	/*! \brief Current step value (see details)

		Possible values:
			<ul><li>\c 0: Left</li>
			<li>\c 1: Middle</li>
			<li>\c 2: Right</li>
			<li>\c 3: Middle</li></ul>
	*/
	int step; //!< The stepping frame of the charset graphic
	int transparency; //!< Transparency value, between \c 0 (completely visible) to \c 8 (completely invisible)
	/*! \brief Frames left until movement is completed (see details)

		This value is zero if the movement is completed. Otherwise it
		means the frames left until it is completed. This value,
		together with \ref direction, is used to calculate the current
		screen coordinates.
	*/
	int movementFramesLeft;
	int frequency; //!< Current movement frequency (\c 1 to \c 8)
	int originalFrequency; //!< Original movement frequency (use for "Move event" commands with a frequency different from the current one)
	Layer_T layer; //!< %Layer (below/same level as/above hero, see RPG::Layer)
	bool forbidEventOverlap; //!< \c true if the event cannot move onto a tile occupied by another event
	/*! \brief Animation type of the event (see details and RPG::AnimationType)

		This member is used for the animation type as defined in the
		event editor. However, it does not control whether the facing
		is locked or not, i.e. if you set it to RPG::ANI_FIXED_GRAPHIC,
		the event may still not have locked facing. Thus, you should
		use the \ref setAnimationType function which automatically sets
		the \ref fixedDirection member to the correct value.
		\sa setAnimationType
		\sa RPG::AnimationType
	*/
	AnimationType_T animationType;
	bool fixedDirection; //!< Is the facing direction (\ref facing) fixed?
	int speed; //!< Current speed of the character (\c 1 to \c 6, see also \ref customExactSpeed)
	MoveRoute* moveRoute; //!< Current move route (can also be set by "Move Event" commands)
	bool moving; //!< Is the character currently moving?
	/*! \brief Horizontal offset for drawing the event graphic (see details)

		The \ref offsetX and \ref offsetY members can be used to control
		the screen coordinates on which the event is drawn. You specify
		an offset value which will be added to the normal value.

		For example, you might set <tt>offsetX = 8</tt> and
		<tt>offsetY = -16</tt> - and then the event will always be
		drawn 8 pixels to the right and 16 pixels higher than it would
		normally be. This way, you can do a finer movement and even
		do a "fake" pixel movement.

		\note This is a special feature of the DynRPG patch.
	*/
	char offsetX;
	char offsetY; //!< Vertical offset for drawing the event graphic (see \ref offsetX)
	/*! \brief Custom exact speed (see details)

		You can the speed of a character in a finer way than the normal
		six speed values provide. One speed unit means 3.75 pixels per
		second (or 1/16 pixel per frame). For example
		<tt>customExactSpeed = 20</tt> will set the speed to 75 pixels
		per second (1.25 pixels per frame).

		If you set \ref customExactSpeed to \c 0, the speed which is set
		in \ref speed will be used.
		\note This is a special feature of the DynRPG patch.
	*/
	char customExactSpeed;
	int moveRoutePosition; //!< Position in move route
	bool moveRouteDone; //!< Has the move route finished?
	bool isHidden; //!< Only works on hero. Determine if hidden.
	bool slipThrough;
	bool stopAnimation;
	bool phasing; //!< Is the "phasing mode" on?
	int stepFrameCounter; //!< Internally used, for stepping
	int stepTimer; //!< Internally used, for stepping (\c -1 if a fixed step is used, see \ref setFixedStep)
	int frequencyTimer; //!< Internally used, for movement frequency
	bool eventJumping; //!< Is the event jumping?
	int beforeJumpX; //!< Map's X value Before jumping
	int beforeJumpY; //!< Map's Y value Before jumping
	bool isFlying; //!< Flying flag for airship
	DStringPtr charsetFilename; //!< Filename of the current charset
	int charsetId; //!< ID of the current charset
	bool eventUpdatedThisFrame; // corrected from onMap
	int flashR; //!< The red value for sprite flashing
	int flashG; //!< The green value for sprite flashing
	int flashB; //!< The blue value for sprite flashing
	int _unknown_84; // Strength slider?
	int flashIntensity; //!< This is not the same as strength/power
	int _unknown_8C;
	int flashTimer; //!< The flash timer. Starts at time*6 & decreases each frame
	// Continues to RPG::Hero

	int getScreenX(); //!< Returns the current X screen coordinate
	int getScreenY(); //!< Returns the current Y screen coordinate

	/*! \brief Sets a fixed step

		You can use this function to set a fixed step position and keep
		it until \ref setNormalStep is called.
		\param newStep New step position, for possible values see
		\ref step
		\note This is a special feature of the DynRPG Patch.
		\sa setNormalStep
		\sa step
	*/
	void setFixedStep(int newStep);

	/*! \brief Removes a fixed step position and goes back to normal
		\sa setFixedStep
	*/
	void setNormalStep();

	/*! \brief Sets the animation type

		This function sets the \ref animationType and \ref fixedDirection
		members to the correct values.
		\param type New animation type
		\sa animationType
		\sa RPG::AnimationType
	*/
	void setAnimationType(RPG::AnimationType type);

	/*! \brief Checks whether a certain move is possible

		This function if the character will be able to complete a
		certain move, taking event layer, \ref forbidEventOverlap, other
		blocking events and the tileset attributes into account.
		\param fromX X coordinate (tiles) of the source position
		\param fromY Y coordinate (tiles) of the source position
		\param toX X coordinate (tiles) of the destination position
		\param toY Y coordinate (tiles) of the destination position
		\return \c true if the move is possible, otherwise \c false
		\warning This is an experimental function.
	*/
	bool isMovePossible(int fromX, int fromY, int toX, int toY);

	/*! \brief Returns the name of the character

		This function returns the event name which was set in the event
		editor or the name of the first actor in the party in case the
		character is the hero.
		\return The name of the character (event or hero name)
	*/
	std::string getName();

	/*! \brief Moves a character

		This function will move a character (event or hero) the same
		way the "Move event" command does.

		The \c data parameter is a pointer to a \c char array containing
		the encoded data. You can find a list of possible movement
		commands at the RPG::MoveType documentation. For most
		movement commands, you will just use one byte containing the
		move type.

		Example:
		\code
char moves[] = {RPG::MT_MOVE_UP, RPG::MT_MOVE_RIGHT, RPG::MT_MOVE_RIGHT, RPG::MT_TURN_RANDOMLY, RPG::MT_MOVE_FORWARD};
RPG::hero->move(moves, sizeof(moves));
		\endcode

		There are, however, a few commands which take parameters:
		RPG::MT_SWITCH_ON, RPG::MT_SWITCH_OFF, RPG::MT_CHANGE_GRAPHIC
		and RPG::MT_PLAY_SE. If you want to use these commands, you
		better use a \c std::string. You need to add the parameters to
		the string right after the command byte, using the functions
		\ref RPG::encode(int) for numerical parameters and
		\ref RPG::encode(std::string) for string parameters.

		Example:
		\code
std::string moves = "";
moves += (char)RPG::MT_MOVE_UP;
moves += (char)RPG::MT_FACE_DOWN;
moves += (char)RPG::MT_PLAY_SE;
moves += RPG::encode("chicken"); // filename
moves += RPG::encode(100); // volume
moves += RPG::encode(100); // speed
moves += RPG::encode(50); // pan
moves += (char)RPG::MT_WAIT;
moves += (char)RPG::MT_TURN_AROUND;
RPG::hero->move(moves.c_str(), moves.length());
		\endcode
		\param data Pointer to the movement data
		\param length Length of the movement data
		\param repeatPattern \c true if the pattern should be repeated
		until \ref stop is called
		\param ignoreImpossible Should impossible movements be ignored?
		\param frequency Frequency of the movement
		\note RPG::MT_INCREASE_FREQUENCY and RPG::MT_DECREASE_FREQUENCY
		commands will not take permanent effect after the movement
		ended unless the movement was started with the same frequency
		as in the \ref frequency member of the character.
		\warning This is an experimental function.
		\sa RPG::MoveType
		\sa stop
		\sa doStep
	*/
	void move(const char* data, int length, bool repeatPattern = false, bool ignoreImpossible = true, int frequency = 8);

	/*! \brief Stops the current movement
		\warning This is an experimental function.
		\sa move
	*/
	void stop();

	/*! \brief Does one step (moves the character one tile into a certain direction)
		\param direction Direction to move into
		\warning This is an experimental function.
		\sa move
	*/
	void doStep(RPG::Direction direction);
};
}

#endif // DYNRPG_CHARACTER_H
