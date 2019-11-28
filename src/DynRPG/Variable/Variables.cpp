#define DYNRPG_STATIC
#include <DynRPG/Variable/Variables.hpp>

#include <DynRPG/Catalog/NamedCatalogPtr.hpp>
#include <DynRPG/Variable/Variable.hpp>

namespace RPG
{
/******************************************************************************
 *
 *****************************************************************************/
DStringPtr Variables::name(int index)
{
	NamedCatalogPtr<Variable*>& n = (**reinterpret_cast<NamedCatalogPtr<Variable*>**>(0x4CDFC4));
	return n[index]->name;
}
}
