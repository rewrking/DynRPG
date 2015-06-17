namespace RPG {
	/*! \brief Access to switch names.
		\sa RPG::switches::name(int)
		\sa RPG::switches
	*/
	class Switch {
		public:
			void **vTable;
			void **id; // Not needed since its index is used in RPG::switches
			DStringPtr name; //!< The name of the switch
	};
	
	/*! \brief Provides easy access to in-game switches

		You may also use RPG::System::switches, but the RPG::Switches class
		will also tolerate negative indexes and is less to type.
		\sa RPG::switches
	*/
	class Switches {
		public:
			//! Array access operator
			inline bool &operator[](int index) {
				if(index > 0) return system->switches[index];
				return dummy = false;
			}
			
			//! \cond
			bool dummy;
			//! \endcond
			
			/*! \brief Gets the name of a switch
				\return The name of the switch
			*/
			static DStringPtr name(int index);
	};
	
	DStringPtr RPG::Switches::name(int index) {
		RPG::NamedCatalogPtr<RPG::Switch *> &n = (**reinterpret_cast<RPG::NamedCatalogPtr<RPG::Switch *> **>(0x4CE060));
		return n[index]->name;
	}
	
	/*! \ingroup game_objects
		\brief %Switches array
	*/
	static RPG::Switches switches __attribute__((unused));

}
