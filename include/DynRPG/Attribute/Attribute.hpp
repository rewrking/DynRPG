#ifndef RPG_ATTRIBUTE_HPP
#define RPG_ATTRIBUTE_HPP

#include <DynRPG/Attribute/AttributeType.hpp>
#include <DynRPG/Catalog/NamedCatalogPtr.hpp>
#include <DynRPG/Delphi/DStringPtr.hpp>

namespace RPG
{
/*! \brief Used for the data of attributes which can be accessed or changed in-game.

	\sa RPG::attributes
	\sa RPG::AttributeType
*/
struct Attribute
{
	void** vTable;
	int id; //!< ID of the attribute
	DStringPtr name; //!< The name of the attribute
	AttributeType type; //!< The attribute's type (see RPG::AttributeType)
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
static NamedCatalogPtr<Attribute*>& attributes = (**reinterpret_cast<NamedCatalogPtr<Attribute*>**>(0x4CDE44));
}

#endif // RPG_ATTRIBUTE_HPP