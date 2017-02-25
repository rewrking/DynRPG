namespace RPG {
	/*! \brief Used for monsters as subtype of battlers
		\sa RPG::monsters
		\sa RPG::Battler
		\sa RPG::Actor
	*/
	class Monster : public Battler { // TLcfgMonsterItem
		public:
			// sizeof(Battler) == 0xD8
			int databaseId; //!< The database ID of the monster
			Image *image; //!< The image of the monster's graphic
			Image *imageMirrored; //!< The <b>mirrored</b> image of the monster's graphic (used when \ref RPG::Battler::mirrored is \c true)
			/*! \brief Frames left until damage blinking is done

				If a monster takes damage, it blinks a few time. The blinking
				is started by setting \c blinkTimer to the number of frames the
				blinking should take. The \c blinkTimer is then increased by
				one each frame (while the image will be shown and hidden
				repeatedly), until it reaches zero at which point the blinking
				will be stopped.
			*/
			int blinkTimer; //!< Internal timer for when a monster is flashing
			int deathTimer; //!< Internal timer for when a monster is dying
			int explodeTimer; //!< Internal timer for when a monster is... exploding?? (wat)
			
			/*! \brief Returns the battle animation information for when an animation
				is playing over a monster (being attacked or healed)
				\return Pointer to the AnimationInBattle class for the monster party
				\sa RPG::Actor::animData
			*/
			static RPG::AnimationInBattle *&animData;
			
			/*! \brief Built-in RM2k3 function that transforms an enemy into a new monster (ATB unaltered)
				\param id The database ID of the monster to transform into
			*/
			void transform(int monsterId);
			
			/*! \brief Built-in RM2k3 function that loads a new monster group into the current one (retains battle commands).
			
				Call by using RPG::Monster::loadMonsterGroup(int) since each of the RPG::monsters[i] get replaced.
				\param id The database ID of the new monster group to load
			*/
			static void loadMonsterGroup(int id);
	};
	
	RPG::AnimationInBattle *&RPG::Monster::animData = (**reinterpret_cast<RPG::AnimationInBattle ***>(0x4CDE64));

	/*! \ingroup game_objects
		\brief Array of monsters in the current monster group.

		Use the zero-based party member ID as index for accessing a monster.

		Example:
		\code
int slimeHp = RPG::monsters[2]->hp; // read HP of third monster
		\endcode
		\sa RPG::Battler
		\sa RPG::actors
		\sa RPG::Actor::partyMember
	*/
	static RPG::CatalogPtr<RPG::Monster *> &monsters = (**reinterpret_cast<RPG::CatalogPtr<RPG::Monster *> **>(0x4CDE64));
	
	void RPG::Monster::transform(int monsterId) {
		asm volatile("call *%%esi"
			: "=a" (RPG::_eax), "=d" (RPG::_edx)
			: "S" (0x4BDDD8), "a" (this), "d" (monsterId)
			: "ecx", "cc", "memory");
	}
	
	void RPG::Monster::loadMonsterGroup(int id) {
		asm volatile("call *%%esi" 
			: "=a" (RPG::_eax), "=d" (RPG::_edx) 
			: "S" (0x4BE8E0), "a" (RPG::monsters.ptr), "d" (id) 
			: "ecx", "cc", "memory");
	}
}
