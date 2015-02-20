namespace RPG {
	/*! \brief Access to variable names.
		\sa RPG::variables::name(int)
		\sa RPG::variables
	*/
	class Variable {
		public:
			void **vTable;
			void **id; // Not needed since its index is used in RPG::variables
			DStringPtr name; //!< The name of the variable
	};

	/*! \brief Provides easy access to in-game variables

		You may also use RPG::System::variables, but the RPG::Variables class
		will also tolerate negative indexes and is less to type.
		\sa RPG::variables
	*/
	class Variables {
		public:
			//! Array access operator
			inline int &operator[](int index) {
				if(index > 0) return system->variables[index];
				return dummy = 0;
			}

			//! \cond
			int dummy;
			//! \endcond
			
			/*! \brief Gets the name of a variable
				\return The name of the variable
			*/
			DStringPtr name(int index);
	};
	
	DStringPtr RPG::Variables::name(int index) {
		RPG::NamedCatalogPtr<RPG::Variable *> &n = (**reinterpret_cast<RPG::NamedCatalogPtr<RPG::Variable *> **>(0x4CDFC4));
		return n[index]->name;
	}

	/*! \ingroup game_objects
		\brief %Variables array
	*/
	static RPG::Variables variables __attribute__((unused));
}
