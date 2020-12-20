namespace RPG {
	/*! \brief Possible values for RPG::Attribute::type
	
		The type of attribute as defined in the database.
	*/
	enum AttributeType {
		ATTRIBUTE_WEAPON,
		ATTRIBUTE_MAGIC
	};
	
	//! One-byte version or RPG::AttributeType
	typedef unsigned char AttributeType_T;

	/*! \brief Used for the data of attributes which can be accessed or changed in-game.

		\sa RPG::attributes
		\sa RPG::AttributeType
	*/
	class Attribute {
		public:
			void **vTable;
			int id; //!< ID of the attribute
			DStringPtr name; //!< The name of the attribute
			AttributeType_T type; //!< The attribute's type (see RPG::AttributeType)
			int dmgA; //!< The A value of the attribute
			int dmgB; //!< The B value of the attribute
			int dmgC; //!< The C value of the attribute
			int dmgD; //!< The D value of the attribute
			int dmgE; //!< The E value of the attribute
			
	};
	
	/*! \ingroup game_objects
		\brief Array of attributes from the database, used for default values and
		properties which are not supposed to be changed in-game.

		Use the database ID as index for accessing a attributes.

		Example:
		\code
int attribPercentage = RPG::attributes[4]->dmgA;
		\endcode
	*/
	static RPG::NamedCatalogPtr<RPG::Attribute *> &attributes = (**reinterpret_cast<RPG::NamedCatalogPtr<RPG::Attribute *> **>(0x4CDE44));
}
