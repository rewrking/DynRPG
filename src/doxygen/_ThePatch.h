/*!
	\page patch The Patch
	\section installation_patch Installation
	It couldn't be easier: You just run the patcher (that's the file called
	\c dynrpg_patcher.exe), select your project's \c RPG_RT.exe file and that's
	it, at least in most of the cases. DynRPG should be compatible with all
	other 1.08-based patches.

	In case you don't have \c RPG_RT.exe version 1.08, the patcher will	offer
	you to install it. However, this will remove all existing modifications
	(other patches, custom icon, etc.). But don't worry, in case anything goes
	wrong there is always a backup (that's the file with the <tt>.bak</tt>
	extension). If you install the patch "over" an existing (older) version of
	the DynRPG Patch, there will also be a backup of the \c dynloader.dll
	file.

	You don't need to include the backup files (ending with <tt>.bak</tt>) in
	your finished game. Also, players don't need to install anything special to
	run a game which uses DynRPG.

	The patcher will also automatically create a \c DynPlugins folder for you,
	so you can immediately start adding and using plugins.

	\section features_patch Extra Features
	Of course, the main feature of the DynRPG Patch is interfacing the DynRPG
	Loader, which then loads the plugins. (See \ref parts for more information.)
	\note You cannot use more than 50 plugins at the same time.

	But that's not everything, the patch also comes with several <b>improvements
	and bugfixes</b> for the %RPG Maker:
		<ul><li><b>Improvement: <i>More pictures!</i></b> You can now use 2000 pictures instead of
		50, and pictures \#1001 to \#2000 are not erased when the player goes
		to a new map! Please read the \ref more_pics section below to find
		out what you need to know about this feature.</li>
		<li><b>Improvement: <i>On-the-fly application of IPS patches!</i></b>
		This means that IPS patches can now be used in a similar manner as plugins,
		by simply copying them to a folder. This means they can easily be removed
		again by deleting the file. Please read the \ref onthefly_ips section
		for further details.</li>
		<li><b>Improvement: <i>Quickpatches!</i></b> This feature allows you to
		add simple patches as small lines of text which can easily be shared on
		the Internet. Those simple patches can also be customized (such as having
		a configurable value for something). Please read the \ref quickpatches
		section below for detailed instructions!</li>
		<li><b>Improvement:</b> Monsters are now flashed more intensively
		when they do their turn. Before, it was hard to follow what was going on
		in battle, especially if a monster used the "Attack" command.</li>
		<li><b>Improvement:</b> Picture operations now also work while a message
		is displayed. (Yes, that's the same thing the
		<a href="http://cherrytree.at/download/?did=16">UnlockPics Patch</a>
		does.)</li>
		<li><b>Improvement:</b> The game doesn't completely close when an error
		occurs. Instead it goes back to the title screen.</li>
		<li><b>Improvement:</b> You can now press \c F11 to go to the save
		menu at any time (in test play only).</li>
		<li><b>Improvement:</b> The "Input Number" event command will now use
		the existing value in the variable as initial value. Before, it always
		started with zero.</li>
		<li><b>Improvement:</b> When you press \c ESC at a "Show Choice"
		command where the cancel behavior is set to "Ignore", now the buzzer
		sound is played.</li>
		<li><b>Improvement:</b> Transparent message windows will now also work
		with the "Traditional" battle layout (at least out of the battle). You
		have to change the battle layout so that the "Transparent" checkbox
		becomes enabled, check or uncheck it and then change the battle layout
		back.</li>
		<li><b>Bugfix:</b> The game would crash when you removed an actor in
		battle when this actor was the last to do his turn.</li>
		<li><b>Bugfix:</b> The "Enemy Attack" sound was never played.
		<li><b>Bugfix:</b> The game would crash if a skill was reflected on an
		actor with an ID higher than the number of actors in the party.</li>
		<li><b>Bugfix:</b> The battle status window was gone while the skill
		selection window was open.</li>
		<li><b>Bugfix:</b> If you had selected "Small Window" in the "Battle
		Layout" tab of the database, the action selection window would only
		display 3 lines plus an ugly empty one at the bottom and also the item
		and skill selection windows would not display the last line correctly.
		Additionally, the selection cursor for "Show choice" windows was
		misaligned in battle.</li>
		<li><b>Bugfix:</b> The "Order" menu (used for rearranging party members)
		didn't play the cancel sound when you exited.</li>
		<li><b>Bugfix:</b> When the shop system was used, the events weren't
		updated, which means that if you bought an item in the shop, events
		which used this item as start condition wouldn't execute
		immediately.</li>
		<li><b>Bugfix:</b> HP display in the save menu was misaligned when the
		HP had 4 digits.</li>
		<li><b>Bugfix:</b> The game would crash if the player would open the
		item window in battle, then close it again using ESC and then execute
		a battle command of type "Link to Event".</li>
		<li><b>Bugfix:</b> The game would crash with a "Division by zero"
		error on certain edge cases of picture operations (especially pictures
		with small zoom level partly outside the screen).</li>
		<li><b>Bugfix:</b> Enemies were flashed even when they executed the
		"Do nothing" action.</li></ul>

	\section more_pics About the pictures
	The DynRPG patch increases the picture limit to 2000. You might have heard
	that <a href="http://cherrytree.at/download/?did=10">Hyper Patcher 2</a> is
	able to increase this limit to a crazy 9999, but this is not so healthy in
	this case. Using that many pictures takes several seconds to load on
	starting or loading a game or going to title screen, plus you would have
	very bad performance with DynRPG because the DynRPG SDK allows plugins to
	intercept picture drawing. Each plugin is called once before and once after
	the picture is to draw, so you can imagine that 9999 pictures would mean 5
	times more plugin calls than 2000 pictures, so I decided that 2000 pictures
	would be the best compromise.

	Please keep in mind that <b>only pictures \#1 to \#1000 will be erased on
	map change</b>! The fact that pictures with an ID greater than 1000 won't be
	erased automatically allows you to use pictures for cross-map purposes more
	easily.

	However, there is one thing you need to do (unless you are already using
	<a href="http://cherrytree.at/download/?did=19">PicPointerPatch</a>): You
	need to modify the %RPG Maker editor itself too, otherwise you won't be able
	to select picture IDs greater than 50 in the event editor. There are two
	ways to do this:
		<ul><li><b>The easy way:</b> You need to use
		<a href="http://cherrytree.at/ultimate">%RPG Maker 2009 Ultimate</a>.
		You then just need to create a file called \c morepictures.ini (or
		whatever name you like) in %RPG Maker 2009 Ultimate's \c uimod folder
		and put the following text into it:
		\code{.ini}
		[FormEvCmd11110]
		DialEdit1.MaxValue=100000

		[FormEvCmd11120]
		DialEdit1.MaxValue=100000

		[FormEvCmd11130]
		DialEdit1.MaxValue=100000
		\endcode
		Then you need to edit the \c ultimate.ini file: Open it in a text
		editor, go to the section <tt>[UIMod]</tt> and add your file at the end
		of the section.</li>
		<li><b>The hard way:</b> If you do not want to use %RPG Maker 2009
		Ultimate, you need to directly edit your \c RPG2003.exe file:
			<ol><li>Download
			<a href="http://www.snapfiles.com/get/resourcehacker.html">Resource
			Hacker</a>.</li>
			<li>Open your \c RPG2003.exe file in it.</li>
			<li>Navigate to <tt>RCDATA \> TFORMEVCMD11110 \> 0</tt>.</li>
			<li>In the script on the right side, look for the following line:
			\code{.txt}
			MaxValue = 50
			\endcode
			If you have an older %RPG Maker version, it might be \c 40
			instead of \c 50. Increase this value, for example, to
			\c 100000. The reason we use such a high value is that higher
			values might be used for extra features (for example, with the
			<a href="http://cherrytree.at/download?did=19">PicPointerPatch</a>).</li>
			<li>Click <tt>Compile Script</tt>.</li>
			<li>Repeat steps 4 and 5 for the pages <tt>RCDATA \> TFORMEVCMD11120
			\> 0</tt> and <tt>RCDATA \> TFORMEVCMD11130 \> 0</tt>.
			<li>Save your changes and exit Resource Hacker.</li></ul></ul>

	\section onthefly_ips On-the-fly IPS patches
	DynRPG can parse IPS files and apply them to the game in memory. This means
	you can add IPS patches without actually modifying any file on your harddisk,
	making it easy to remove the patch again. There is a folder \c DynPatches
	in which the loader will look for IPS files and apply them on-the-fly. Please
	note that the loader will fail to apply a patch if it tries to modify regions
	of the \c RPG_RT.exe which would affect DynRPG itself or lie outside of the
	areas which are mapped to memory. (Don't worry, nothing will explode, it will
	just trigger an error message.)

	\section quickpatches Quickpatches
	Quickpatches are simple text "codes" which instruct DynRPG to modify certain
	bytes in the game's memory. They are added to a special section in your
	\c DynRPG.ini file called <tt>[QuickPatches]</tt>. Each quickpatch has a name,
	which can be arbitrary and is completely ignored by the loader.

	<b>End users:</b> Simply copy and paste a quickpatch from the Internet into
	your <tt>[QuickPatches]</tt> section (create the section if it does not exist).
	If you don't like it, remove it again or disable it by prepending a
	semicolon. Quickpatches may contain configurable values, the developer
	should normally tell you what their effect is.

	<b>Developers:</b> The format of quickpatches is very simple:
	\code{.ini}
	PatchName=Address1,Values1,Address2,Values2,Address3,Values3,...
	\endcode
	You can specify one of more virtual address to modify, together with the
	values to write to that address. These "values" may use one of those 3
	formats:
	<ul><li><b>Hex bytes:</b> One or more bytes in simple two-digit hexadecimal
	notation. For example, <tt>401234,90</tt> will write byte \c 0x90 at address
	\c 0x401234, <tt>401234,1A2B3C</tt> will write byte \c 0x1A at address
	\c 0x401234, byte \c 0x2B at address \c 0x401235 and byte \c 0x3C at address
	\c 0x401236.</li>
	<li><b>8-bit decimal value:</b> Decimal value (may be negative) prepended by
	a percent sign, which will occupy one byte. Meant to be easily customizable
	by end users. For example, <tt>401234,%32</tt> will write byte \c 0x20 at
	address \c 0x401234.</li>
	<li><b>32-bit decimal value:</b> Decimal value (may be negative) prepended by
	a sharp sign, which will occupy four bytes. Meant to be easily customizable
	by end users. For example, <tt>401234,#1000</tt> will write byte \c 0xE8 at
	address \c 0x401234, byte \c 0x03 at address \c 0x401235, and two \c 0x00 bytes
	at addresses \c 0x401236 and \c 0x401237.</li></ul>

	Example for two "real-life" quickpatches:
	\code{.ini}
	; Hides EXP in main menu and save screen
	HideEXP=49E148,EB71,49F1CA,EB67,49F095,EB21
	; Moves the window on the title screen to coordinates 144/56
	MoveTitleWindow=490821,#144,490828,#56
	\endcode
	For this example please note that the %RPG Maker uses the X coordinate for the
	middle of the window, while the Y coordinate is used for the top of the window.

*/
