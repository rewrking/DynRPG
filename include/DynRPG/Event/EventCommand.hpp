#ifndef RPG_EVENT_COMMAND_HPP
#define RPG_EVENT_COMMAND_HPP

namespace RPG
{
/*! \brief %Event command type

	Each event command can have a number of parameters. Unfortunately,
	documenting all of them (nearly 150) is beyond my time resources
	at the moment. If you need to know how the parameters of a certain
	command work, you can write a simple plugin which logs event commands
	and their parameters and try it out yourself.
	\sa RPG::EventScriptLine
	\sa onEventCommand
	\note <b>Not all enumeration values are documented here</b>, scroll to the top
	to see all possible values (in the general enum overview)!
*/
enum class EventCommand
{
	EndOfEvent = 0, //!< End of the event command list
	EmptyLine = 10, //!< Empty line (<tt>\<\></tt>)
	ShowMessage = 10110, //!< First line of a "Show Message" command
	AddLineToMessage = 20110, //!< Additional lines of a "Show Message" command
	MessageOptions = 10120,
	SelectFace = 10130,
	ShowChoice = 10140, //!< First line of a "Show Choice" command
	ChoiceCase = 20140, //!< <tt>[XXXX] handler</tt> lines of a "Show Choice" command
	ChoiceEnd = 20141, //!< <tt>: End</tt> line of a "Show Choice" command
	InputNumber = 10150,
	ChangeSwitch = 10210,
	ChangeVariable = 10220,
	ChangeTimer = 10230,
	ChangeMoney = 10310,
	ChangeItems = 10320,
	ChangeParty = 10330,
	ChangeExp = 10410,
	ChangeLevel = 10420,
	ChangeStats = 10430,
	ChangeSkill = 10440,
	ChangeEquipment = 10450,
	ChangeHp = 10460,
	ChangeMp = 10470,
	ChangeCondition = 10480,
	FullRecovery = 10490,
	InflictDamage = 10500,
	ChangeHeroName = 10610,
	ChangeHeroTitle = 10620,
	ChangeHeroGraphic = 10630,
	ChangeHeroFace = 10640,
	ChangeVehicleGraphic = 10650,
	ChangeSystemBgm = 10660,
	ChangeSystemSoundEffect = 10670,
	ChangeSystemGraphic = 10680,
	ChangeTransition = 10690,
	StartCombat = 10710, //!< First line of a "Start Combat" command
	BattleVictory = 20710, //!< <tt>Victory handler</tt> line of a "Start Combat" command
	BattleEscape = 20711, //!< <tt>Escape handler</tt> line of a "Start Combat" command
	BattleDefeat = 20712, //!< <tt>Defeat handler</tt> line of a "Start Combat" command
	BattleEnd = 20713, //!< <tt>: End</tt> line of a "Start Combat" command
	CallShop = 10720, //!< First line of a "Call Shop" command
	ShopTransaction = 20720, //!< <tt>Transaction handler</tt> line of a "Call Shop" command
	ShopCancel = 20721, //!< <tt>Cancel handler</tt> line of a "Call Shop" command
	ShopEnd = 20722, //!< <tt>: End</tt> line of "Call Shop" command
	CallInn = 10730, //!< First line of a "Call Inn" command
	InnRest = 20730, //!< <tt>Rest handler</tt> line of a "Call Inn" command
	InnCancel = 20731, //!< <tt>Cancel handler</tt> line of a "Call Inn" command
	InnEnd = 20732, //!< <tt>: End</tt> line of a "Call Inn" command
	EnterHeroName = 10740,
	Teleport = 10810,
	MemorizeLocation = 10820,
	GoToMemorizedLocation = 10830,
	RideVehicle = 10840,
	TeleportVehicle = 10850,
	SetEventLocation = 10860,
	SwapTwoEventLocations = 10870,
	GetTerrainId = 10910,
	GetEventId = 10920,
	EraseScreen = 11010,
	ShowScreen = 11020,
	SetScreenTone = 11030,
	FlashScreen = 11040,
	ShakeScreen = 11050,
	PanScreen = 11060,
	WeatherEffects = 11070,
	ShowPicture = 11110,
	MovePicture = 11120,
	ErasePicture = 11130,
	ShowBattleAnimation = 11210, //!< "Show Battle Animation" in map/common events
	SetHeroOpacity = 11310,
	FlashEvent = 11320,
	MoveEvent = 11330,
	WaitUntilMoved = 11340,
	StopAllMovement = 11350,
	Wait = 11410,
	PlayBgm = 11510,
	FadeOutBgm = 11520,
	MemorizeBgm = 11530,
	PlayMemorizedBgm = 11540,
	PlaySoundEffect = 11550,
	PlayMovie = 11560,
	KeyInputProcessing = 11610,
	ChangeTileset = 11710,
	ChangePanorama = 11720,
	ChangeEncounterRate = 11740,
	ChangeSingleTile = 11750,
	ChangeTeleportTarget = 11810,
	EnableTeleport = 11820,
	SetEscapeLocation = 11830,
	EnableEscape = 11840,
	CallSaveMenu = 11910,
	EnableSave = 11930,
	CallMainMenu = 11950,
	EnableMainMenu = 11960,
	Fork = 12010, //!< First line of a "Conditional Branch" in map/common events
	ForkElseCase = 22010, //!< <tt>: Else Case</tt> line of a "Conditional Branch" in map/common events
	ForkEnd = 22011, //!< <tt>: End Case</tt> line of a "Conditional Branch" in map/common events
	Label = 12110,
	JumpToLabel = 12120,
	StartLoop = 12210, //!< "Loop" command
	EndLoop = 22210, //!< <tt>: End</tt> line of a "Loop"
	BreakLoop = 12220,
	StopEvent = 12310,
	DeleteEvent = 12320,
	CallEvent = 12330, //!< "Call Event" in map/common events
	Comment = 12410, //!< First line of a comment
	AddLineToComment = 22410, //!< Additional lines of a comment
	GameOver = 12420,
	GoToTitleScreen = 12510,
	ChangeClass = 1008,
	ChangeBattleCommands = 1009,
	ChangeEnemyHp = 13110,
	ChangeEnemyMp = 13120,
	ChangeEnemyCondition = 13130,
	ReviveEnemy = 13150,
	ChangeBackdrop = 13210,
	ShowBattleAnimationInBattle = 13260, //!< "Show Battle Animation" in battle events
	Enablecombo = 1007,
	ForceFlee = 1006,
	EndBattle = 13410,
	ForkInBattle = 13310, //!< First line of a "Conditional Branch" in battle events
	ForkInBattleElseCase = 23310, //!< <tt>: Else Case</tt> line of a "Conditional Branch" in battle events
	ForkInBattleEnd = 23311, //!< <tt>: End Case</tt> line of a "Conditional Branch" in battle events
	CallCommonEvent = 1005 //!< "Call Common Event" in battle events
};
}

#endif // RPG_EVENT_COMMAND_HPP
