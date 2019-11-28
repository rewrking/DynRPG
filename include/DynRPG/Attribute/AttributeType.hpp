#ifndef RPG_ATTRIBUTE_TYPE_HPP
#define RPG_ATTRIBUTE_TYPE_HPP

#include <DynRPG/Utility/Types.hpp>

namespace RPG
{
/*! \brief Possible values for RPG::Attribute::type

	The type of attribute as defined in the database.
*/
enum class AttributeType : uchar
{
	Weapon,
	Magic
};

//! One-byte version or RPG::AttributeType
//typedef uchar AttributeType_T;
}

#endif // RPG_ATTRIBUTE_TYPE_HPP
