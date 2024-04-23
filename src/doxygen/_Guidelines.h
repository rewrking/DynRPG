/*!
	\page guidelines Rules and guidelines for plugin developers
	\section rules Rules
	The %RPG Maker is written in Delphi (and I didn't have access to the source
	code of its classes, etc.), while my SDK uses C++. Thus, many things are
	not working the way you might expect.

	There is a set of rules which you must follow under all circumstances when
	you are developing a DynRPG Plugin:
		<ul><li><b>Do not try to use members which are not documented.</b> They
		are either unknown or used internally and dangerous. (Of course, if you
		<i>know</i> what a member does, it's a different story.)</li>
		<li><b>Do not instantiate RPG classes.</b> Always use pointers to
		existing instances you get from DynRPG. It is especially dangerous to
		use these "home-made" objects with functions from the RPG namespace. It
		might seem to work, but will most likely corrupt data. This will cause
		the game to behave strangely or suddenly crash some minutes later.
		<b>An exception to this rule are the RPG::Music and RPG::Sound
		classes.</b></li>
		<li><b>Do not assign RPG objects.</b> The result is mostly undefined.
		An exception are pointers to RPG::Image objects, as long as you don't
		forget to destroy the old object using RPG::Image::destroy (unless you
		want to use it before).</li>
		<li><b>Do not randomly return \c false from a callback
		function.</b> This will "lock out" all plugins which are called after
		yours. Only return \c false if you really want this behavior.</li>
		<li><b>Never change the \c vTable member of a class.</b> This will
		make the game crash sooner or later (probably sooner).</li>
		<li><b>Never assign a <tt>char *</tt> to an RPG::DString pointer.</b>
		It will appear to work, but it will cause the game to crash with an
		"Invalid pointer operation" error when the %RPG Maker tries to free the
		string. Also, do not store RPG::DStringPtr objects or RPG::DString
		pointers inside your plugin, but copy their content to a
		\c std::string instead, since RPG::DString objects may suddenly
		vanish.</li>
		<li><b>Do not change the current directory.</b></li>
		<li><b>Do not do stuff every frame which takes longer than one
		millisecond.</b> This is alredy the very maximum. The less time
		you use, the better. If you need to do something which takes
		longer, do it in another thread. An exception are things which
		happen only rarely, like when a game is loaded or saved, or once
		when a battle starts, etc. If something should intentionally take
		longer than one frame, you could use the \ref RPG::Screen::update or
		RPG::updateBattle function, respectively.</ul>

	\section guidelines_sec Guidelines
	There is also a set of guidelines which you are strongly advised to follow,
	but there might be cases in which there is a better solution.

	\subsection event_comments Event comments
	Comments in event scripts are a great way to let events scripts invoke
	functions of your plugin. Please follow the following guidelines:
		<ul><li>Use the following pattern for "special comments":
			\code{.txt}
			@command parameter1, parameter2, parameter3, ...
			\endcode
		</li>
		<li>New-line characters should be generally ignored.</li>
		<li>The comment has to start with an <tt>\@</tt> sign, immediately
		followed by the command name.</li>
		<li>The command name is case-insensitive.</li>
		<li>There should be three possible types of parameters:
			<ul><li><b>Number:</b> A simple number. Can also use the decimal
			point and the scientific notation (e.g. <tt>5.5e+6</tt> for 5.5
			million).</li>
			<li><b>String:</b> A simple string. Must be put between
				doublequotes. To use a doublequote in a string, it is
				written twice (e.g. <tt>He said ""hello"" and smiled</tt>)</li>
			<li><b>Token:</b> Some identifier. Tokens are not put between
			quotes, and they may not contain spaces (spaces are removed).
			Tokens are case-insensitive. They may be used for keywords.</li></ul>
			There are special tokens for referencing variables and actor
			names:
			<ul><li><b>Variables:</b> To reference a variable, the user should
			be able to write a \c V character prior to the variable ID. This
			should also work with multiple levels of dereferencing.</li>
			<li><b>Actor names:</b> To reference an actor's name, the user
			should be able to write a \c N character prior the the actor ID.
			This should also work together with \c V.</li></ul>
			<li>The command name and tokens should be case-insensitive.</li>
			<li>Always return \c false from \ref onComment when you found
			a known command, regardless whether the parameters were valid or
			not.</li>
			<li>Always return \c true from \ref onComment when you didn't
			find a known command, even though you may have found an <tt>\@</tt>
			sign at the beginning of the comment.</li></ul>

		<b>Use the \c parsedData parameter of your \ref onComment handler to get
		the comment data in an already nicely parsed form!</b>
		\note The maximum number of parameters is 100. The maximum number of
		characters per parameter (or command name) is 200. You have to parse the
		comment yourself if you need more.

		Example for a "special" comment:
		\code{.txt}
		@FooBar 123, "abc", V55, VV66, N7, NV8, Nothing
		\endcode
		The command name is \c foobar.\n
		The first parameter is numerical.\n
		The	second parameter is a string.\n
		The third parameter is a numerical value read from variable \#55.\n
		The fourth parameter is a numerical value read from the variable
		whose ID is stored in variable \#66.\n
		The fifth parameter is a string, read from the name of actor \#7.\n
		The sixth parameter is a string, read from the name of the actor
		whose ID is stored in variable \#8.\n
		The seventh parameter is a token named \c nothing.

		You might advise users to download
		<a href="http://cherrytree.at/ultimate">RPG Maker 2009 Ultimate</a>
		if they need to enter comments longer than 4 lines.

		\subsection configuration Configuration
		Many plugins need some kind of configuration. An important rule is:
		<b>Make as many things configurable as possible.</b>

		If possible, store configuration in a \c DynRPG.ini file. Also,
		you should use your plugin's name which you get as parameter to the
		\ref onStartup function as section name. If you need several sections,
		you can append an underscore and an additional identifier to the name
		and use it as section name. This will prevent conflicts with other
		plugins while still combining all relevant configuration of a game in
		one file.

		You may use the RPG::loadConfiguration function as a convenient way to
		load configuration data to a <tt>std::map\<std::string,
		std::string\></tt> in the \ref onStartup function.

		If you need more or more complex configuration, like XML data, use a
		filename containing your plugin's name.

		\subsection ingame_data In-game data
		Your plugin may also use data which is changed in-game and needs to be
		preserved. Savestate-independent data (like a highscore) should be
		stored in the \c DynRPG.ini file together with configuration
		(use the WinAPI function
		<a href="http://msdn.microsoft.com/en-us/library/windows/desktop/ms725501(v=vs.85).aspx">WritePrivateProfileString</a>).

		Savestate-related data (data which should be saved when the user saves
		the game and loaded when the use loads a saved game) should be saved
		using the function passed as \c savePluginData parameter to the
		\ref onSaveGame function. When the user loads the savestate again, you
		will get the same data back, in the parameters to the \ref onLoadGame
		function. Internally, this data is saved in a file called
		\c SaveXX.dyn where \c XX is the savestate ID.

		An example usage of savestate-related plugin data is shown here:
		\code{.cpp}
		// Plugin-related data
		int score;
		int level;

		// ...

		void onLoadGame(int id, char *data, int length) {
			if(length == sizeof(int) * 2) { // make sure it is valid data
				int *dataArray = (int *)data;
				score = dataArray[0];
				level = dataArray[1];
			}
		}

		void onSaveGame(int id, void __cdecl (*savePluginData)(char *data, int length)) {
			int[2] dataArray;
			dataArray[0] = score;
			dataArray[1] = level;
			savePluginData((char *)dataArray, sizeof(dataArray));
		}
		\endcode
		(Of course, the same result could have been achieved by saving \c score
		and \c level in in-game variables which are automatically saved.)

		\subsection optimization Optimization
		<b>Time is a very important factor.</b> Especially with many plugins,
		it is important to use as little time as possible in your callback
		handlers, otherwise the game will eventually start lagging. Thus, try to
		optimize your code where you can. If possible, always test your plugin
		with several other plugins in a "real-life situation" to see whether
		your plugin slows the game down too much. Remember that most of your
		code will be executed a minimum of 60 times per second (many parts more
		often than that, for example \ref onCheckEventVisibility will be called
		900 times per second if there are 150 events on the map).

		Here is a bit of advice how to optimize your plugin code:
			<ul><li><b>Do not allocate and deallocate memory or objects over and
			over again.</b> Try to use static variables wherever
			possible.</li>
			<li>Try to use functions in the RPG::Image and RPG::Canvas classes
			as little as possible. The slowest functions are
			RPG::Image::drawText and RPG::Canvas::draw.
			<li>Try to cache text in an RPG::Image if possible, only
			update it if necessary.</li>
			<li>Try to cache as much with the same palette as possible on
			the same RPG::Image so that you don't have to call
			RPG::Canvas::draw too often.</li>
			<li>If possible, don't use a transparent color in
			RPG::Image::draw (set \c maskColor to
			RPG::MASK_NONE). The same rule applies for RPG::Canvas::draw,
			see also RPG::Image::useMaskColor.</li>
			<li>Try to skip frames if possible. This means: Try to update some
			things only every 2 or 3 frames if possible.</li>
			<li>If you are "WinAPI-literate", you can use the
			RPG::Canvas::bitmap member and the
			RPG::DBitmap::getHBITMAP and RPG::DBitmap::getHDC functions to get
			handles to the corresponding GDI objects and manipulate them
			directly.</li>
			<li>If you need to calculate something more complex (like a 3D
			image, etc.) you better do this in a new thread, cache its graphics
			and draw them to the screen only after calculation was finished,
			without letting the main thread wait.</li></ul>
*/
