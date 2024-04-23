/*!
	\page changelog Changelog
	\section v0_32 Version 0.32 Unofficial (2017/02)
		<ul><li>Added RPG::Battler::getAttackPower() & RPG::Battler::getSkillPower() (Thanks Cherry!)</li>
		<li>Corrected an issue with RPG::Canvas::convert16To24Bit() (Thanks Cherry!)</li>
		<li>Added RPG::Hero::checkEventOverlapTrigger() & RPG::Hero::checkEventInFrontTrigger() (Thanks Cherry!)</li>
		<li>Fixed RPG::isBattleTest</li>
		<li>Added data members for areas to RPG::MapTreeProperties: top-left X & Y, bottom-right X & Y (Thanks Ginyu!), corrected isArea to isNotArea (whoops...)</li>
		<li>Added RPG::Monster::loadMonsterGroup() (Thanks Cherry!)</li>
		<li>Added some members related to 2k3's "Play Movie" command, contained in RPG::Screen. Experimental.</li>
		<li>Added RPG::SystemGraphic::change(), RPG::SystemGraphic::systemTiled && RPG::SystemGraphic::systemFont, & placeholder vTable for RPG::SystemGraphic::font, the structure used for all text drawing (although unknown at this point)</li>
		<li>Added RPG::WindowMessageBox && RPG::WindowMessage::text (finally! Thanks Ginyu!)</li>
		<li>Documented more members that were previously undocumented</li></ul>
	\section v0_31 Version 0.31 Unofficial (2016/05)
		<ul><li>Added RPG::Action::switchIdOn & RPG::Action::switchIdOn</li>
		<li>Updated RPG::Input (thanks bugmenot!)</li>
		<li>Updated RPG::Map::getTerrainId(int tileId) since that did not actually use the X & Y coordinates.</li>
		<li>Added RPG::Map::getEventAt(int x, int y)</li>
		<li>Added RPG::MapGraphics::chipsetImage</li>
		<li>Added RPG::SceneMenu::scrollUpCountItem & RPG::SceneMenu::scrollUpCountSkill</li>
		<li>Added RPG::SystemGraphic::exFont</li>
		<li>Updated RPG::Window and various sub-classes, although only editing existing windows works well. Most functions have been marked as experimental for now.</li>
		<li>Added RPG::ScreenEffect</li>
		<li>Added RPG::Actor::getTwoWeaponAttack() & RPG::Actor::getTwoWeaponAgility</li>
		<li>Added RPG::Image::drawString(int x, int y, std::string text, int color) as a DynRPG 0.20+ version of drawText, since that function seems to be broken</li>
		<li>Added some custom RPG::Scene and RPG::MenuSubScreen definitions to prevent duplicate ID usage</li>
		<li>Added RPG::SceneFile::doesSaveExist(int saveId), RPG::SceneFile::saveFile(int saveId), RPG::SceneFile::loadFile(int saveId), RPG::SceneFile::loadFileUnpatch(), RPG::SceneFile::loadFileSimple(int saveId)</li>
		<li>Added RPG::getDiceRoll(int maxValue)</li>
		<li>Added RPG::goToTitle()</li>
		<li>Added RPG::quitGame()</li>
		<li>Added RPG::getAvgPartyAgl()</li>
		<li>Added RPG::getAvgMonsterPartyAgl()</li>
		<li>Added RPG::openMenu(RPG::MenuSubScreen screen, int heroId, int skillOrItemId) & RPG::OpenMenuUnpatch(). Both experimental so far (thanks bugmenot!)</li>
		<li>Added RPG::Actor::isSkillKnown(int skillId)</li>
		<li>Added RPG::Monster::transform(int monsterId)</li>
		<li>Added RPG::Screen::toggleFullScreen(bool fullScreen) & RPG::Screen::toggleLargeWindow(bool largeWindow)</li>
		<li>Added RPG::Inventory::isItemOwned(int id)</li>
		<li>Added RPG::Hero::act() & RPG::Event::act()</li>
		<li>Changed RPG::Character::onMap to RPG::Character::eventUpdatedThisFrame. (thanks EasyRPG team!)</li>
		<li>Changed RPG::Actor::autoBattle to RPG::Actor::aiControl to match common RPG Advocate translation</li>
		<li>Added resizeValue to DArray template to fix a resizing issue with conditions and attributes within RPG::DBClass, RPG::DBActor and RPG::DBMonster (and documented expected behavior)</li>
		<li>Updated various other bits of documentation</li></ul>
	\section v0_30 Version 0.30 Unofficial (2015/01)
		<p>(Not including enumerations. Review them in the classes as needed)</p>
		<ul><li>Added RPG::Animation and RPG::battleAnimations object.</li>
		<li>Added RPG::AnimationEffect</li>
		<li>Added RPG::AnimationFrame</li>
		<li>Added RPG::AnimationFrameCel</li>
		<li>Added RPG::Animation2 and RPG::battlerAnimations object.</li>
		<li>Added RPG::Animation2Pose</li>
		<li>Added RPG::Animation2Weapon</li>
		<li>Added RPG::AnimationCurrent, RPG::AnimationInBattle and RPG::currentBattleAnimation object.</li>
		<li>Added RPG::Item, RPG::AnimationWeapon and RPG::items object.</li>
		<li>Added RPG::BattleData and RPG::battleData object.</li>
		<li>Added RPG::BattleEvent</li>
		<li>Added RPG::BattleEventPage</li>
		<li>Added RPG::BattleEventTrigger</li>
		<li>Added RPG::BattleCommand</li>
		<li>Added RPG::DBMonster and RPG::dbMonsters object.</li>
		<li>Added RPG::DBMonsterGroup and RPG::dbMonsterGroups object.</li>
		<li>Added RPG::MonsterBehavior</li>
		<li>Added RPG::Skill, RPG::AnimationSkill and RPG::skills object.</li>
		<li>Added RPG::Inventory and RPG::inventory object.</li>
		<li>Added RPG::Attribute and RPG::attributes object.</li>
		<li>Added RPG::Condition and RPG::conditions object.</li>
		<li>Added RPG::SceneMenu and RPG::menu object.</li>
		<li>Added RPG::SceneShop and RPG::shop object.</li>
		<li>Added RPG::SceneEnterName and RPG::enterName object.</li>
		<li>Added RPG::SceneTitle and RPG::title object.</li>
		<li>Added RPG::SceneFile and RPG::fileSaveLoad object.</li>
		<li>Added RPG::SceneGameOver and RPG::gameOver object.</li>
		<li>Added RPG::SceneDebug and RPG::debug object. (because I could)</li>
		<li>Added RPG::Teleport and RPG::teleportHero() function.</li>
		<li>Added RPG::Panorama and RPG::panorama object.</li>
		<li>Added RPG::vocabulary object.</li>
		<li>Added RPG::Vehicle (part of Character.h) as well as RPG::vehicleSkiff, RPG::vehicleShip, and RPG::vehicleAirship objects</li>
		<li>Added RPG::Window</li>
		<li>Added RPG::WindowMessage and RPG::winMessage object.</li>
		<li>Added RPG::WindowMenuTarget, RPG::WindowMenuItem, RPG::WindowMenuSkill, RPG::WindowMenuEquip, RPG::WindowMenuEnd, RPG::WindowMenuStatus, RPG::WindowMenuOrder, RPG::WindowSaveFile</li>
		<li>Updated RPG::Character, RPG::Event, RPG::Hero</li>
		<li>Updated RPG::Actor</li>
		<li>Updated RPG::DBActor & added RPG::SkillProgression</li>
		<li>Updated RPG::DBSystem</li>
		<li>Updated RPG::BattleSettings</li>
		<li>Updated RPG::Character and RPG::Hero</li>
		<li>Updated RPG::Map</li>
		<li>Functions added: RPG::getDiceRoll(int), RPG::goToTitle(), RPG::getAvgPartyAgl(), RPG::getAvgMonsterPartyAgl(), RPG::Battler::flash( int, int, int, int, int), RPG::Map::getLowerLayerTileId(int, int), RPG::Map::getUpperLayerTileId(int, int), RPG::Map::getTerrainId(int)</li>
		<li>and more... (to be documented & added)</li></ul>
	\section v0_20 Version 0.20 (2013/12/31)
		<ul><li>On-the-fly patching using IPS files or quick patches
		in DynRPG.ini added. See the corresponding \ref onthefly_ips and
		\ref quickpatches sections.</li>
		<li>Partial Hyper Patcher 2 picture limit changing support removed,
		it never worked correctly in the first place.</li>
		<li>\c AUTO_DLLMAIN define removed, now a \c DllMain function is always
		inserted by default, use <tt>\#define CUSTOM_DLLMAIN</tt> to prevent
		this behaviour.</li>
		<li>The automatic \c DllMain function now stores the plugin's instance
		handle in the global variable \c hInstance (only if \c CUSTOM_DLLMAIN
		is not defined).</li>
		<li><b>Critical bug fixed:</b> Game could hang when loading a game after
		a new plugin has been added due to an infinite loop bug during \c Save??.dyn
		file parsing.</li>
		<li><b>Critical bug fixed:</b> Transparency of events (including the hero)
		behaved weirdly (changed depending on Y position) and was thus unusable.
		This bug also slowed down the event rendering a lot.</li>
		<li><b>Bug fixed:</b> Class RPG::DList had members \c count and \c items
		swapped. Because DynRPG classes need to have the same memory layout as the
		%RPG Maker's internal Delphi counterparts, all accesses of RPG::DList
		classes (most notably RPG::monsters) crashed the game.</li>
		<li><b>Bug fixed:</b> RPG::Catalog::count didn't work (tried to access
		\c list.count where it should have been \c list.list->count, causing a
		compiler error.)</li>
		<li><b>Bug fixed:</b> RPG::Image::copy was broken (didn't set the new image
		size but silently leaked an RPG::Image instance instead).</li>
		<li><b>Bug fixed:</b> RPG::Actor and RPG::System methods sometimes returned
		wrong strings (i.e. for RPG::Actor::getName) if they encountered a default
		value in the database.</li>
		<li><b>Bug fixed:</b> Due to missing string termination, the
		RPG::ParsedCommentParameter::text member of a comment command's last
		parameter often had garbage appended at the end.</li>
		<li><b>Bug fixed:</b> Negative numbers in comment command parameters were
		incorrectly parsed as RPG::PARAM_TOKEN instead of RPG::PARAM_NUMBER.</li>
		<li><b>Bug fixed:</b> RPG::Event::doesEventPageExist was broken.</li>
		<li><b>Bug fixed:</b> RPG::transparentWindowsEverywhere was
		broken.</li>
		<li>Modified library to work with newer GCC compilers. Now GCC version
		4.7.1 is required. (For tech-guys: Why the hell can GCC now use the \c ESP
		register for an inline asm parameter with the \c "g" constraint?!)</li>
		<li><b>Bug fixed:</b> The "cross-map" pictures \#1001 to \#2000 were not
		erased when a new game was started.</li>
		<li>Fixed an %RPG Maker bug which caused the HP display in the save menu
		to be misaligned when the HP had 4 digits.</li>
		<li>Removed the longer skill/item window visibility "improvement" for most
		scenarious because it turned out to disrupt battle event processing.
		Only the info window shown when a monster executes a skill is still shown
		longer, but now only for 50 frames (old DynRPG used 90 frames which
		turned out to be annoyingly long, original %RPG Maker used 30 frames which
		I think is too short to be readable).</li>
		<li>Fixed an %RPG Maker bug which would cause the game to crash when
		a "Link to Event" battle command was used right after the item menu
		has been opened and then closed with ESC.</li>
		<li>Added RPG::Actor::twoWeapons, RPG::Actor::lockEquipment,
		RPG::Actor::autoBattle and RPG::Actor::mightyGuard fields.</li>
		<li>RPG::System::pedestrianBGM added. Funny name, I know.</li>
		<li>The maximum number of plugins has been raised from 30 to 50.</li>
		<li><b>Bug fixed:</b> Under some circumstances, the game would crash
		during event command execution. It's hard to describe the exact triggers,
		but they included "Erase event" commands in common events, loading a game
		which was saved while a "Wait until key press" was active and some other,
		rarer situations.</li>
		<li>Fixed two %RPG Maker bugs with "Small window" mode in battle: The
		action, item and skill selection windows had an empty line at the bottom
		even though there would have been enough space. This was especially
		confusing for the battle action window because it looked like the actor
		had only 3 commands available. Also, the selection cursor for "Show choice"
		windows in battle was not correctly aligned with the choice texts.</li>
		<li>Removed the "higher action window" workaround for the small battle
		window mode because a real fix has been implemented now.</li>
		<li><b>Bug fixed:</b> DynRPG would sometimes refuse to load a plugin
		with no valid reason, depending on the constellation of files in the
		DynPlugins directory.</li>
		<li>Fixed an %RPG Maker bug which would crash the game with a "Division
		by zero" error on certain edge cases of picture operations (especially
		pictures with small zoom level partially outside the screen). This bug also
		affected RPG::Canvas::drawCenteredZoomed.</li>
		<li><b>Bug fixed:</b> The enemy attack sound was also played if the enemy
		wasn't doing anything at all. Additionally, sometimes sleeping or paralyzed
		enemies would even flash white and the "Punch A" sound would play.</li>
		<li>Fixed an %RPG Maker bug which caused enemies to be flashed even when
		they executed the "Do nothing" action.</li>
		<li>The \ref onDoBattlerAction callback has now a second parameter
		\c firstTry which will be \c true only at the first attempt of executing
		the action. This allows plugins to execute code only once per action. Before,
		the \ref onDoBattlerAction callback could be called multiple times without
		a way to distinguish between a new action and a new attempt to execute
		the same action. Because the information about an action's success has
		to be stored somewhere, the RPG::Action::userData2 member has been
		repurposed and is now called RPG::Action::retrying. Old plugin DLLs which
		are unaware of the new \c firstTry parameter will still work, but if any
		old plugin tries to use the RPG::Action::userData2 member it will cause
		problems. However I've got the impression that it's unlikely that there
		is such a plugin out there.</li>
		<li>The member RPG::Action::userData1 has been removed from public access
		because I realized it's not a good idea to have generic fields without
		defined purpose, as this could easily cause conflicts between different
		plugins.</li></ul>

	\section v0_14a Version 0.14a (2012/02/15)
	Only the SDK was updated. The patch still shows version 0.13b.
		<ul><li>RPG::Character::mapID was renamed to RPG::Character::mapId to
		follow the naming convention used at all other places.</li>
		<li>The documentation now doesn't show inherited members anymore unless
		you click <tt>List of all members</tt>.</li>
		<li><b>Bug fixed:</b> RPG::Map::getWidth and RPG::Map::getHeight were
		returning nonsense due to a typo (again).</li></ul>

	\section v0_14 Version 0.14 (2012/02/15)
	Only the SDK was updated. The patch still shows version 0.13b.
		<ul><li>RPG::isBattleTest and RPG::showTitle added.</li>
		<li><b>Critical bug fixed:</b> The big bugfix done in version 0.13 created
		new bugs because I forgot to update a few things in the changed \c asm
		statements. Sorry for that.</li>
		<li><b>Bug fixed:</b> I had confused the parameters of RPG::Character::move.</li>
		<li><b>Bug fixed:</b> Nasty typo in RPG::encode caused it to produce garbage.</li>
		<li>Type of \c message parameter of RPG::showError changed from <tt>char *</tt>
		to <tt>std::string</tt>.</li>
		<li>Type of \c data parameter of RPG::Character::move changed from <tt>char *</tt>
		to <tt>const char*</tt>.</li></ul>

	\section v0_13b Version 0.13b (2012/02/15)
		<ul><li><b>Bug fixed:</b> If version 0.13a was patched over version 0.13,
		the game wouldn't start anymore. Patching 0.13b over 0.13a should fix the
		problem.</li></ul>
	\section v0_13a Version 0.13a (2012/02/13)
		<ul><li><b>Bug fixed:</b> Due to a silly typo the game crashed as soon
		as you would try to buy something in a shop.</li></ul>
	\section v0_13 Version 0.13 (2012/02/11)
		<ul><li><b>Critical bug fixed:</b> The \c asm statements in the SDK didn't
		properly tell the compiler that the \c eax, \c edx and \c ecx registers may
		be changed even though they often aren't used as output registers. This could
		randomly lead to faulty code (depending on the surrounding code and the
		compiler options) which would then result in strange crashes. <b>Please
		recompile all modules of your plugin with the new version of the header files
		and the library!</b></li>
		<li><b>Bug fixed:</b> The RPG::ParsedCommentData::command string wasn't
		terminated properly.</li>
		<li>I realized that Code::Blocks is far better than Dev-C++ and changed the
		\ref getting_started page accordingly.</li>
		<li>The RPG::showError function was added.</li></ul>

	\section v0_12 Version 0.12 (2012/02/07)
		<ul><li>RPG::Canvas::drawStretched and RPG::Canvas::drawCenteredZoomed added.</li>
		<li><b>Bug fixed:</b> The DynRPG Patch caused the battle status window to be always
		fully opaque in battle layout "alternative", even if "transparent" was
		enabled. If the latter was the case, additionally the ATB bar wasn't
		shown.</li>
		<li>Added "Powered by" on top of the DynRPG logo.</li></ul>

	\section v0_11 Version 0.11 (2012/02/06)
	Only the SDK was updated. The patch still shows version 0.10.
		<ul><li>RPG::BattleSettings class and RPG::battleSettings object added.</li></ul>

	\section v0_10 Version 0.10 (2012/02/05)
	This is the first release. I started this project on 2012/01/23, by the way. Just in case somebody wants to know.
*/
