#define DYNRPG_STATIC
#include <DynRPG/Switch/Switches.hpp>

#include <DynRPG/Catalog/NamedCatalogPtr.hpp>
#include <DynRPG/Switch/Switch.hpp>

namespace RPG
{
/******************************************************************************
 *
 *****************************************************************************/
DStringPtr Switches::name(int index)
{
	NamedCatalogPtr<Switch*>& n = (**reinterpret_cast<NamedCatalogPtr<Switch*>**>(0x4CE060));
	return n[index]->name;
}
}
