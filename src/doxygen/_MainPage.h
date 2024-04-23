/*!
	\mainpage About DynRPG

	\author David "Cherry" Trapp

	<dl class="section author">
		<dt>Contributers (v0.30+)</dt>
		<dd>Andrew King (PepsiOtaku)</dd>
		<dt></dt>
		<dd>bugmenot</dd>
	</dl>

	<i><b>Also visit the main page, <a href="http://cherrytree.at">Cherry
	Tree</a>!</b></i>

	\section download Download
	Yes, this is the first paragraph, because I know people are looking for it
	most of the time, probably. So be it.

	<b><a href="http://share.cherrytree.at/showfile-30511/dynrpg_0_32_02_25_2017.rar">Click me hard!</a></b>

	\section contact Contact
	And yes, this is the second paragraph, because people seek this information
	very often too.

	If you have any questions, you may either ask in of the following forum
	threads:
		<ul><li><b>English:</b> <a href="http://rpgmaker.net/forums/topics/10254/">Thread on RMN</a></li>
		<li><b>German:</b> <a href="http://www.multimediaxis.de/threads/134256">Thread on Multimediaxis</a></li>
		<li><b>French:</b> <a href="http://www.rpg-maker.fr/index.php?page=forum&id=19911">Thread on Oniromancie</a> (my reponses will be in English though)</ul>
	...or write me an e-mail at <a href="mailto:dynrpg@cherrytree.at">dynrpg@cherrytree.at</a>!

	Oh, and if you find errors in this documentation, or bugs in the patch or
	the SDK, please tell me too!

	\section introduction Introduction
	DynRPG is a plugin SDK for %RPG Maker 2003. "SDK" means "Standard Development
	Kit", and in this case it means that <b>everyone can create his own
	extensions to the %RPG Maker software now</b>, as long as he knows how to use
	C++. DynRPG not only offers the average programmer access to the world of
	"patching", but it also provides the basis for far more powerful extensions
	than all "patches" made for the %RPG Maker before.

	DynRPG works using plugins. Plugins can be written in C++, they will be
	loaded when the game starts and they are notified of certain events (like
	the drawing of a new frame, the writing to a variable, etc.) and are
	allowed to react to these events.

	What in past were "patches" are now going to be simple plugins. Any game
	using DynRPG can be extended by a new feature by simply putting a plugin
	file into a folder called \c DynPlugins. That's far easier than "patching",
	something which many game makers are even afraid of, because they think it
	might harm their game. And if somebody doesn't like a certain plugin, all
	he needs to do is deleting it.

	So, DynRPG is beneficial to both <b>plugin makers</b> and <b>game
	makers</b>:
		<ul><li>Plugin makers can use a simple C++ library to write powerful
		plugins and distribute them to other game makers!</li>
		<li>Game makers get many new possibilities just by adding these plugins
		to their game!</li>
		<li>Professional game makers are able to write plugins which exactly fit
		to their game's needs, for example they might write part of their action
		battle system in C++ or apply a custom design to the default battle
		system, or maybe they even create a whole minigame using DynRPG... the
		possibilities are endless!</li></ul>

	\section important_links Important links
	<b>Are you a game maker?</b> Then look at \ref patch to find out how to
	install and use the DynRPG Patch and what features it has!

	<b>Are you a plugin maker?</b> Then you might start with the
	\ref getting_started section, and make sure you follow the \ref guidelines!
	Of course, you can also explore the SDK documentation using the navigation
	bar and the search function. The two main sections you need are the RPG
	namespace and the \ref callbacks.

	\section parts Parts
	The name "DynRPG" means this project as a whole... but actually, it consists
	of several parts:
		<ul><li><b>The DynRPG Patch:</b> This is the only real patch here. Yes,
		I was not completely honest: The game makers don't get <i>completely</i>
		rid of "patching", since they have to install this one patch. It is a
		small patch for %RPG Maker 2003 version 1.08, which loads the DynRPG
		Loader at startup, notifies it of game events and also applies several
		bugfixes to the %RPG Maker. The DynRPG Loader then looks for plugins,
		loads them and later forwards game events to them. The DynRPG Patch is
		compatible with most of the other %RPG Maker 2003 patches out
		there. More information here: \ref patch</li>
		<li><b>The DynRPG Patcher:</b> This simple tool installs the DynRPG
		Patch for you.</li>
		<li><b>The DynRPG Loader:</b> That's a little DLL file called
		\c dynloader.dll which is the middle-man between the DynRPG Patch
		and the plugins.</li>
		<li><b>The DynRPG SDK:</b> That's the library and the C++ header files
		which allow you to create your own plugins for DynRPG very easily. (If
		you are no programmer but just a game maker looking for ready-made
		plugins, you don't need to bother yourself with this.)</li>
		<li><b>The plugins:</b> Although not actually part of the DynRPG
		project, the plugins are what makes the whole thing useful. They can
		extend the features of the %RPG Maker (as in the past patches did), but
		in a far more powerful way. A plugin is a simple DLL file which is
		placed in the \c DynPlugins folder of a game.</ul>

	\section Credits
	I want to thank <b>Bananen-Joe</b> for helping me when I had questions -
	all the time since I got to know him... and also for his Destiny Patch
	because it gave me the competition I needed. :-)

	I also want to thank <b>MagicMaker</b> for testing all my stuff before.
	Although he wasn't able to test DynRPG itself, his contribution also
	helped me with my previous research... and that research is the base
	of DynRPG.

	And last but not least, I want to thank <b>Crash-Override</b> alias
	<b>WordsBG</b> for trying to "own me" years ago when I created my first
	"patch" (the RM2k(3) Font Changer)... I think if he hadn't challenged me,
	I wouldn't have dug into reverse engineering and I would never have come
	this far. (Explanation: After I published the font changer tool, he
	created a thingy called "RM Binary Patcher" which basically did the same
	as my font changer and Miroku's "Maker Ultimative" patcher combined. The
	latter had several bugs, and because he commented his tool with "because
	I just wanted to own you", I took that as a challenge and created a better
	tool, <a href="http://cherrytree.at/download/?did=9">Hyper Patcher 1</a>,
	which did the same as his tool, but without bugs and with more features.
	He then admitted that I had won.)
*/
