#ifndef DYNRPG_ATTRIBUTE_H
#define DYNRPG_ATTRIBUTE_H

#include <DynRPG/Enum/AttributeType.h>

#include <DynRPG/DStringPtr.h>
#include <DynRPG/NamedCatalogPtr.h>

namespace RPG
{
/*! \brief Used for the data of attributes which can be accessed or changed in-game.

	\sa RPG::attributes
	\sa RPG::AttributeType
*/
class Attribute
{
public:
	void** vTable;
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
extern DYNRPG_API RPG::NamedCatalogPtr<RPG::Attribute*>& attributes;
}

#endif // DYNRPG_ATTRIBUTE_H
