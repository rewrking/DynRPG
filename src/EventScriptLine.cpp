#include <DynRPG/EventScriptLine.h>

namespace RPG
{
int EventScriptLine::parameter(int index)
{
	if (index < 0 || index >= parameters.size)
		return 0;
	return parameters[index];
}
}
