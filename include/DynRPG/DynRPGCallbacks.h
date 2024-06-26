#ifndef DYNRPG_CALLBACKS_H
#define DYNRPG_CALLBACKS_H

#ifdef AUTO_DLLMAIN
	#warning AUTO_DLLMAIN is deprecated as automatically adding a DllMain function is the default behaviour now. Use #define CUSTOM_DLLMAIN to achieve the reverse.
#endif

extern "C"
{
#ifndef NOT_MAIN_MODULE
	int DYNLOADER_EXPORT linkVersion = DYNRPG_LINK_VERSION;
	#ifndef CUSTOM_DLLMAIN
	HINSTANCE hInstance;

	BOOL APIENTRY DllMain(HINSTANCE hInst, DWORD reason, LPVOID reserved)
	{
		if (reason == DLL_PROCESS_ATTACH)
			hInstance = hInst;
		return TRUE;
	}
	#endif // CUSTOM_DLLMAIN
#endif // NOT_MAIN_MODULE

	/*! \ingroup callbacks
		\brief Called when the plugin was loaded

		This callback handler should be used to check for fatal problems, like
		missing files. You can abort the loading process from this function.
		\param pluginName The name of the plugin. This is the filename with the
		extension stripped. For its supposed usage, see \ref configuration.
		\return \c true on success, \c false on failure. In the latter case,
		other plugins which were already loaded will receive the \ref onExit
		call and be unloaded and the game will not be started.
		\warning Do not try to access RPG objects from this function, since the
		game hasn't been initialized yet.
		\sa onInitFinished
		\sa onExit
	*/
	bool DYNLOADER_EXPORT __cdecl onStartup(char* pluginName);

	/*! \ingroup callbacks
		\brief Called after the RPG objects were initialized

		Unlike in \ref onStartup, it is safe to access RPG objects from this
		function.
		\sa onStartup
	*/
	void DYNLOADER_EXPORT __cdecl onInitFinished();

	/*!	\ingroup callbacks
		\brief Called before the title screen is initialized

		This function is called before the title screen fades in.
	*/
	void DYNLOADER_EXPORT __cdecl onInitTitleScreen();

	//! Called before the player starts a new game
	void DYNLOADER_EXPORT __cdecl onNewGame();

	/*! \ingroup callbacks
		\brief Called before the player loads a game from a savestate

		DynRPG loads plugin data which was previously saved in the
		\ref onSaveGame function and passes it to this handler. See \ref ingame_data
		for details.
		\param id Savestate ID
		\param data Pointer to plugin data
		\param length Length of plugin data
		\note \c data may be \c 0 if there is no data.
		\sa onLoadGame
	*/
	void DYNLOADER_EXPORT __cdecl onLoadGame(int id, char* data, int length);

	/*! \ingroup callbacks
		\brief Called before the player saves a game

		Use the function passed in the \c savePluginData parameter to save
		custom plugin data which will be passed back to the plugin when the
		player loads the same savestate. See \ref ingame_data for details.
		\param id Savestate ID
		\param savePluginData Call this function to save custom plugin data
		\note If you call \c savePluginData more than once, only the last
		call will take effect.
		\sa onLoadGame
	*/
	void DYNLOADER_EXPORT __cdecl onSaveGame(int id, void __cdecl (*savePluginData)(char* data, int length));

	/*! \ingroup callbacks
		\brief Called before the game exits

		\note It's recommended to wrap your code in a <tt>try..catch</tt> block
		because if the game exits after an error (before \ref onInitFinished was
		called), the state of the memory is undefined. Also, if you want to save
		data, check whether there is anything to save before you do it.
		The RPG objects may or may not be initialized, depending on whether this
		function is called before (early exit) or after \ref onInitFinished.
		\warning This handler may also be called while another callback handler
		is active, in case the other handler is pumping messages (for example,
		it is currently displaying a message box).
	*/
	void DYNLOADER_EXPORT __cdecl onExit();

	/*! \ingroup callbacks
		\brief Called every frame, before the screen is refreshed (see details!)

		This function is called after every frame (see details below!), right after the current game
		scene was drawn, but before it becomes visible to the player. You may
		draw on the screen in this function and it will appear on top of the
		normal graphics.

		You can even define your own scene and use this callback to draw it.

		However: <b>If the game is too slow, frames may be skipped</b>. If
		this happens, the screen is not refreshed every frame, to save time. In
		this case, the \c onFrame handler is called only when the screen is
		refreshed. You can use RPG::System::frameCounter to find out how many
		frames were skipped (by comparing it with a value you saved at the last
		\c onFrame call), because when the scene is updated (even though the
		\c onFrame handler wasn't called), the RPG::System::frameCounter will
		still be incremented. This way, the game won't be "slower" than normal
		even when the framerate drops below 60.

		\param scene Game scene which was drawn
		\note The \c scene parameter does not necessarily equal to
		<tt>RPG::system->scene</tt>, e.g. when a transition from one scene to
		another is active.
		\sa RPG::System::scene
		\sa RPG::System::frameCounter
	*/
	void DYNLOADER_EXPORT __cdecl onFrame(RPG::Scene scene);

	/*! \ingroup callbacks
		\brief Called before an in-game variable is set

		This function can be used to give "Change Variable" commands a special
		meaning. This might be suitable for applications for which a full
		\ref onComment implementation would be overkill, like a key check.
		\param id ID of the variable to be changed
		\param value Value to be assigned
		\return \c false will prevent the variable from being changed and other
		plugins from receiving this notification, use \c true otherwise
		\note This callback is not only triggered by the "Change Variable"
		command, but by any action which writes to a variable.
		\sa onSetSwitch
	*/
	bool DYNLOADER_EXPORT __cdecl onSetVariable(int id, int value);

	//! \cond
	/*! \ingroup callbacks
		\brief Called before an in-game variable is read

		This function can be used to give variables special functions, for
		example reading the mouse position. You may change the variable in
		this function for that reason.
		\param id ID of the variable to be read
		\return \c false will prevent other plugins from receiving this
		notification, use \c true otherwise
		\sa onSetVariable
		\sa onSetSwitch
		\sa onGetSwitch
	*/
	//bool DYNLOADER_EXPORT __cdecl onGetVariable(int id); // slow!
	//! \endcond

	/*! \ingroup callbacks
		\brief Called before an in-game switch is set

		This function can be used to give "Change Switch" commands a special
		meaning.
		\param id ID of the switch to be changed
		\param value Value to be assigned
		\return \c false will prevent the switch from being changed and other
		plugins from receiving this notification, use \c true otherwise
		\note This callback is not only triggered by the "Change Switch"
		command, but by any action which writes to a switch.
		\sa onSetVariable
	*/
	bool DYNLOADER_EXPORT __cdecl onSetSwitch(int id, bool value);

	//! \cond
	/*! \ingroup callbacks
		\brief Called before an in-game switch is read

		This function can be used to give switches special functions, for
		example reading a key's status. You may change the switch in this
		function for that reason.
		\param id ID of the switch to be read
		\return \c false will prevent other plugins from receiving this
		notification, use \c true otherwise
		\sa onSetVariable
		\sa onGetVariable
		\sa onSetSwitch
	*/
	//bool DYNLOADER_EXPORT __cdecl onGetSwitch(int id); // slow!
	//! \endcond

	/*! \ingroup callbacks
		\brief Called before an event command is executed

		You can use this function to intercept event commands, use them for a
		different purpose or change their parameters.

		By changing the \c nextLineId, you can decide which line in the
		script is to be executed next. By default, the value of \c *nextLineId
		is \c -1, which means that the default behavior is executed. You can
		change it to another line number to jump to a different line. Use
		<tt>*nextLineId = lineId;</tt> to repeat the command, this way you can
		create a "wait until done" behavior by initiating some action the first
		time and then repeatedly checking whether it is finished.

		You can use the \c scriptData parameter to read other event commands
		in the current script.
		\param scriptLine The event script line which is about to be executed
		\param scriptData Pointer to the RPG::EventScriptData object of the
		current event script
		\param eventId The ID of the current event (negative for common events,
		zero for battle events)
		\param pageId The ID of the current event page (zero for common and
		battle events - sorry, no battle event page ID yet)
		\param lineId The zero-based line number
		\param nextLineId Pointer to the next executed line number (\c -1 for
		default)
		\return \c false will prevent the event script line from being executed
		and other plugins from receiving this notification, use \c true
		otherwise
		\note You may change the \c scriptLine object if you want, so that it is
		executed with different parameters. After the line was executed, all changes
		will be undone automatically.\n\n
		The "don't execute if you return false" feature works by setting bit
		31 in the \c command member of the \c scriptLine so that it becomes an
		invalid (and thus ignored) command. DynRPG automatically clears this bit
		later.
		\warning Do not create loops which include several commands without
		a "Wait 0.0" (and also tell the user not to do so in case you provide
		an event command which jumps back in the script), otherwise the game
		will hang. If you loop to the <i>same</i> line using <tt>*nextLineId =
		lineId;</tt>, an automatic one-frame wait (equal to a "Wait 0.0") is
		inserted.\n\n
		Do not use the \c nextLineId member if the current event command calls
		another event or ends the current event (e.g. when the command is
		RPG::EVCMD_STOP_EVENT).
		\sa onComment
	*/
	bool DYNLOADER_EXPORT __cdecl onEventCommand(RPG::EventScriptLine* scriptLine, RPG::EventScriptData* scriptData, int eventId, int pageId, int lineId, int* nextLineId);

	/*! \ingroup callbacks
		\brief Called when a "Comment" event command is encountered

		You can use this function to provide functions which are executed when
		a special event comment is encountered. Please stick to the
		\ref event_comments guidelines! The \c parsedData parameter brings you
		the data already parsed according to the guidelines.

		You will get all comment lines at once (separated by newline
		characters) in the \c text parameter. This way you don't need to do
		the parsing of the next event script lines (because internally, each
		comment line is a new event command).

		You may use the comment function as "modifier" for event commands, thus
		there is the \c nextScriptLine parameter which allows you to modify
		the parameters of the next script line. For modifying event commands
		please also read the note at the \ref onEventCommand documentation!

		\param text The comment's content as simple text
		\param parsedData The already parsed data
		\param nextScriptLine The next event script line after the comment
		\param scriptData Pointer to the RPG::EventScriptData object of the
		current event script
		\param eventId The ID of the current event (negative for common events,
		zero for battle events)
		\param pageId The ID of the current event page (zero for common and
		battle events - sorry, no battle event page ID yet)
		\param lineId The zero-based line number
		\param nextLineId Pointer to the next executed line number (\c -1 for
		default)
		\return \c false will prevent other plugins from receiving this
		notification, use \c true otherwise
		\note For information how to use the \c nextLineId parameter, please
		refer to the \ref onEventCommand documentation.
		\sa onEventCommand
	*/
	bool DYNLOADER_EXPORT __cdecl onComment(const char* text, const RPG::ParsedCommentData* parsedData, RPG::EventScriptLine* nextScriptLine, RPG::EventScriptData* scriptData, int eventId, int pageId, int lineId, int* nextLineId);

	/*! \ingroup callbacks
		\brief Called when the screen is drawn on the game window

		Unlike \ref onFrame, this function is called when the screen content
		is actually drawn on the game window. This means that if a section
		of the window is invalidated (for example because it was overlapped
		by another window or minimized), this function will be called again,
		even though the game screen itself didn't change.
		\warning The screen might already contain changes done by you in the
		\ref onDrawScreen handler before. Also, it is possible that only
		a <i>part</i> of the screen is invalidated and redrawn. Thus, you
		should only use this callback if you need to draw something during
		certain screen transitions (where \ref onFrame doesn't work).
		\sa onFrame
	*/
	void DYNLOADER_EXPORT __cdecl onDrawScreen();

	/*! \ingroup callbacks
		\brief Called before a picture is drawn

		You can use this function to draw something below a certain picture,
		or instead of the picture.
		\param picture The picture which is about to be drawn
		\return \c false will prevent the original picture from being drawn
		and other plugins from receiving this notification, use \c true
		otherwise
		\note If you return \c false, the \ref onPictureDrawn handlers will
		still be called.
		\sa onPictureDrawn
	*/
	bool DYNLOADER_EXPORT __cdecl onDrawPicture(RPG::Picture* picture);

	/*! \ingroup callbacks
		\brief Called after a picture was drawn (or was supposed to be drawn)

		You can use this function to draw something above a certain picture.
		\param picture The picture which is was drawn (or was supposed to be
		drawn)
		\return \c false will other plugins from receiving this notification,
		use \c true otherwise
		\note This function will be called regardless if a plugin returned
		\c false from its \ref onDrawPicture handler for this picture.
		\sa onDrawPicture
	*/
	bool DYNLOADER_EXPORT __cdecl onPictureDrawn(RPG::Picture* picture);

	/*! \ingroup callbacks
		\brief Called every frame to check whether an event should be drawn
		even though it is out of sight

		Use this function in case you want to draw larger graphics instead of an
		event's normal graphic (using \ref onDrawEvent). Normally, events which
		are out of sight are not drawn at all, thus neither \ref onDrawEvent
		nor \ref onEventDrawn would be called for this event. Return \c false
		from this function to force the drawing of the event.
		\param character The event to be drawn (can also be the hero)
		\return \c false <b>if the event should be drawn</b> even though it is
		out of sight and also to prevent other plugins from receiving this
		notification, use \c true otherwise
		\warning Do not initiate any actions from this function, only check
		whether you need to draw this event or not. If a previous plugin
		returned \c false, your plugin won't receive this notification, even
		though it might receive the \ref onDrawEvent and \ref onEventDrawn
		notifications!
		\sa onDrawEvent
		\sa onEventDrawn
	*/
	bool DYNLOADER_EXPORT __cdecl onCheckEventVisibility(RPG::Character* character);

	/*! \ingroup callbacks
		\brief Called before an event or the hero is drawn

		You can use this function to draw something below a certain event,
		or instead of the event.
		\param character The character which is about to be drawn (can also be
		the hero)
		\param isHero \c true if the \c character is the hero
		\return \c false will prevent the original event from being drawn
		and other plugins from receiving this notification, use \c true
		otherwise
		\note If you return \c false, the \ref onEventDrawn handlers will
		still be called.\n\n
		Vehicles are not supported yet.\n\n
		This function is only called when the event is in sight <i>or</i> an
		\ref onCheckEventVisibility handler has returned \c false for this
		event.
		\sa onEventDrawn
	*/
	bool DYNLOADER_EXPORT __cdecl onDrawEvent(RPG::Character* character, bool isHero);

	/*! \ingroup callbacks
		\brief Called after an event or the hero was drawn (or was supposed to
		be drawn)

		You can use this function to draw something above a certain event.
		\param character The character which was drawn or supposed to be drawn
		(can also be the hero)
		\param isHero \c true if the \c character is the hero
		\return \c false will prevent other plugins from receiving this
		notification, use \c true otherwise
		\note This function will be called regardless if a plugin returned
		\c false from its \ref onDrawEvent handler for this event.\n\n
		Vehicles are not supported yet.\n\n
		This function is only called when the event is in sight <i>or</i> an
		\ref onCheckEventVisibility handler has returned \c false for this
		event.
		\sa onDrawEvent
	*/
	bool DYNLOADER_EXPORT __cdecl onEventDrawn(RPG::Character* character, bool isHero);

	/*! \ingroup callbacks
		\brief Called before a battler is drawn

		You can use this function to draw something below a certain battler,
		or instead of the battler.
		\param battler The battler which is about to be drawn
		\param isMonster \c true if the \c battler is a monster
		\param id Zero-based party member ID of the \c battler
		\return \c false will prevent the original battler from being drawn
		and other plugins from receiving this notification, use \c true
		otherwise
		\note If you return \c false, the \ref onBattlerDrawn handlers will
		still be called.\n\n
		This function is not called for hidden monsters. For dead monsters it
		is only called while they are still partly visible (i.e. while they are
		fading out).
		\sa onBattlerDrawn
	*/
	bool DYNLOADER_EXPORT __cdecl onDrawBattler(RPG::Battler* battler, bool isMonster, int id);

	/*! \ingroup callbacks
		\brief Called after a battler was drawn (or supposed to be drawn)

		You can use this function to draw something above a certain battler.
		\param battler The battler which was drawn (or supposed to be drawn)
		\param isMonster \c true if the \c battler is a monster
		\param id Zero-based party member ID of the \c battler
		\return \c false will prevent other plugins from receiving this
		notification, use \c true otherwise
		\note This function will be called regardless if a plugin returned
		\c false from its \ref onDrawBattler handler for this event.\n\n
		This function is not called for hidden monsters. For dead monsters it
		is only called while they are still partly visible (i.e. while they are
		fading out).
		\sa onDrawBattler
	*/
	bool DYNLOADER_EXPORT __cdecl onBattlerDrawn(RPG::Battler* battler, bool isMonster, int id);

	/*! \ingroup callbacks
		\brief Called before the battle status window is drawn

		You can use this function to draw below the battle status window, or to
		replace it entirely.

		In the "Traditional" and "Alternative" battle layouts, there are two
		different status windows: One used as actual <i>status</i> window, one
		used as target selection window for actions with actors as targets.
		The latter is drawn <i>above</i> the skill/item selection window, while
		the former is drawn <i>below</i> it. Use the \c isTargetSelection
		parameter to find out which window you are dealing with.

		You can also use this function (when \c isTargetSelection is \c false)
		to draw something above all battlers and below all windows.
		\param x The current X coordinate of the left side of the window
		\param selection The zero-based party member ID of the currently
		selected actor
		\param selActive \c true if the \c selection parameter contains a valid
		value and a choice bar is drawn
		\param isTargetSelection \c true if it is the target selection window,
		\c false if it is the "normal" status window
		\param isVisible \c true if the window is visible
		\return \c false will prevent the original window from being drawn
		and other plugins from receiving this notification, use \c true
		otherwise
		\note If you return \c false, the \ref onBattleStatusWindowDrawn
		handlers will still be called. However, the "finger" cursor which
		points to the selected hero will not be drawn if you return \c false
		when the \c isTargetSelection parameter is \c true.\n\n
		This function is also called when the window is invisible. In this
		case, \c isVisible will be \c false.
		\sa onBattleStatusWindowDrawn
	*/
	bool DYNLOADER_EXPORT __cdecl onDrawBattleStatusWindow(int x, int selection, bool selActive, bool isTargetSelection, bool isVisible);

	/*! \ingroup callbacks
		\brief Called after the battle status window was drawn (or supposed to
		be drawn)

		You can use this function to draw something above the battle status
		window.
		\param x The current X coordinate of the left side of the window
		\param selection The zero-based party member ID of the currently
		selecter actor
		\param selActive \c true if the \c selection parameter contains a valid
		value and a choice bar is drawn
		\param isTargetSelection \c true if it is the target selection window,
		\c false if it is the "normal" status window
		\param isVisible \c true if the window is visible
		\return \c false will prevent other plugins from receiving this
		notification, use \c true otherwise
		\note This function will be called regardless if a plugin returned
		\c false from its \ref onDrawBattleStatusWindow handler for this
		window.\n\n
		This function is also called when the window is invisible. In this
		case, \c isVisible will be \c false.\n\n
		Please see the \ref onDrawBattleStatusWindow documentation to find out
		more about the \c isTargetSelection parameter!
		\sa onDrawBattleStatusWindow
	*/
	bool DYNLOADER_EXPORT __cdecl onBattleStatusWindowDrawn(int x, int selection, bool selActive, bool isTargetSelection, bool isVisible);

	/*! \ingroup callbacks
		\brief Called before the battle action window is drawn

		You can use this function to draw below the battle action window, or to
		replace it entirely.

		You can also use this function to move the window by modifying \c *x
		and \c *y.
		\param x Pointer to the X coordinate of the upper-left corner of the
		window
		\param y Pointer to the Y coordinate of the upper-right corner of the
		window
		\param selection Zero-based index of the current selection
		\param selActive \c true if the \c selection parameter contains a valid
		value and a choice bar is drawn
		\param isVisible \c true if the window is visible
		\return \c false will prevent the original window from being drawn
		and other plugins from receiving this notification, use \c true
		otherwise
		\note The \c selection parameter does <b>not</b> contain the database
		ID of the selected battle command, but only a zero-based index based on all
		choices which are displayed. Use the RPG::Actor object to find out which battle
		commands are available for an actor. You probably need to store the
		\c selection parameter from your \ref onDrawBattleStatusWindow to find
		out which actor is currently selected. You can then use something like
		<tt>RPG::Actor::partyMember(battleStatusWindowSelection)->getBattleCommand(battleActionWindowSelection)</tt>
		to get the database ID of the currently selected battle command.\n\n
		This function is also called when the window is invisible. In this
		case, \c isVisible will be \c false.
		\sa onBattleStatusWindowDrawn
	*/
	bool DYNLOADER_EXPORT __cdecl onDrawBattleActionWindow(int* x, int* y, int selection, bool selActive, bool isVisible);

	/*! \ingroup callbacks
		\brief Called before a battler's action is executed

		This function can be used to modify a battler's action before it is
		executed. For example, you might add a "random" skill which randomly
		executes certain skills and use this function to set the actual skill.
		\param battler The battler which is executing its action
		\param firstTry \c true if this is the first attempt to execute this
		action. Make sure you include a check for this parameter to be \c true
		if you want your code to be run only once per action!
		\note If executing the action fails (due to another action being
		executed), the %RPG Maker will repeatedly try again. You will then
		receive multiple calls to this callback, but only at the first call
		\c firstTry will be set to \c true.
		\return \c false will prevent other plugins from receiving this
		notification, use \c true otherwise
		\note Using this function, you can also use targets for a skill (or
		the "Attack" and "Double Attack" functions) which are normally not
		possible.\n\n
		To prevent an action completely, change it to the basic action
		RPG::BA_NONE. Do not use RPG::AK_NONE because this can cause errors
		later in the battle.
		\sa onBattlerActionDone
		\sa RPG::Action
	*/
	bool DYNLOADER_EXPORT __cdecl onDoBattlerAction(RPG::Battler* battler, bool firstTry);

	/*! \ingroup callbacks
		\brief Called after a battler's action is executed

		\param battler The battler which is executing its action
		\param success \c true if the action was successfully executed or
		\c false if the action couldn't be executed yet because another
		action or something else was active
		\return \c false will prevent other plugins from receiving this
		notification, use \c true otherwise
		\note If \c success if \c false, the %RPG Maker will repeatedly try
		again to execute the action, until it succeeds, at which point
		\c success will be \c true. Please note that this will also lead
		to multiple calls to \ref onDoBattlerAction.
		\warning You must not modify the battler's action from this function,
		because it might not be <i>fully</i> completed. For example, "Attack"
		commands will immediately be finished although the attack animation
		and damage display haven't been done yet.
		\sa onDoBattlerAction
		\sa RPG::Action
	*/
	bool DYNLOADER_EXPORT __cdecl onBattlerActionDone(RPG::Battler* battler, bool success);

	/*! \ingroup callbacks
		\brief Called after the system background was drawn

		This function can be used to draw your custom background in the menu,
		etc.
		\param rect Area which has been (re)drawn
		\note In the save/load menu, there is only the small part at the top
		drawn, in the other menus, the whole screen is painted. Pay attention
		to the \c rect parameter.
	*/
	bool DYNLOADER_EXPORT __cdecl onSystemBackgroundDrawn(RECT* rect);
}

#endif // DYNRPG_CALLBACKS_H
