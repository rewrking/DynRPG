#ifndef RPG_BATTLE_SETTINGS_HPP
#define RPG_BATTLE_SETTINGS_HPP

#include <DynRPG/Battle/BattleCommand.hpp>
#include <DynRPG/Battle/BattleLayout.hpp>
#include <DynRPG/Battle/RandomEncounterDeath.hpp>
#include <DynRPG/Battler/Battler.hpp>
#include <DynRPG/Catalog/CatalogPtr.hpp>
#include <DynRPG/Teleport/Teleport.hpp>
#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
//! \cond
// struct BattleCommand;
//! \endcond

/*! \brief Used for battle settings (layout, etc.)
	\sa RPG::battleSettings
	\sa RPG::BattleLayout
	\sa RPG::BattleCommands
	\sa RPG::RandomEncounterDeath
	\sa RPG::System
*/
struct BattleSettings
{
	// clang-format off
	void** vTable;
	int characterPlacement; //!< Manual (0) or Automatic (1)?
	BattleLayout layout; //!< Battle layout
		int _unknown_C;
	// Documented as WindowSize	(0|1 = large|small) (dword), which suggests the opposite...
	bool largeWindows; //!< Are the "large windows" active?
		bool _unknown_11;
		bool _unknown_12;
		bool _unknown_13;
	bool transparentWindows; //!< Are transparent windows active? (This affects the whole game even though the %RPG Maker guys have put it into the battle settings.)
	CatalogPtr<BattleCommand*> battleCommands; //!< Pointer to the RPG::BattleCommands array
		int _unknown_1C;
	BattleRow rowShown; //!< The current row shown?
	RandomEncounterDeath randomEncounterDeath; //!< Does a random encounter death cause a game over, or call a common event? (see RPG::RandomEncounterDeath)
	int commonEventId; //!< The ID of the common event to call
	bool deathTeleportFlag; //!< Teleport before executing the common event?
	int deathTeleportMapId; //!< The Map ID to teleport to upon death
	int deathTeleportX; //!< The Map's X coordinate to teleport to upon death
	int deathTeleportY; //!< The Map's Y coordinate to teleport to upon death
	TeleportDirection deathTeleportFacingDirection; //!< The direction to face in upon teleporting after death (see RPG::TeleportDirection)
	// clang-format on
};

/*! \ingroup game_objects
	\brief Battle settings

	Please mind that this object is not saved and loaded automatically, but only initialized once at startup.
*/
static BattleSettings*& battleSettings = (**reinterpret_cast<BattleSettings***>(0x4CDD60));
}

#endif // RPG_BATTLE_SETTINGS_HPP