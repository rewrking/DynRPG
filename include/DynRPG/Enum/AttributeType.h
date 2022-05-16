#ifndef DYNRPG_ATTRIBUTE_TYPE_H
#define DYNRPG_ATTRIBUTE_TYPE_H

namespace RPG
{
/*! \brief Possible values for RPG::Attribute::type

	The type of attribute as defined in the database.
*/
enum AttributeType
{
	ATTRIBUTE_WEAPON,
	ATTRIBUTE_MAGIC
};

//! One-byte version or RPG::AttributeType
typedef unsigned char AttributeType_T;
}

#endif // DYNRPG_ATTRIBUTE_TYPE_H
