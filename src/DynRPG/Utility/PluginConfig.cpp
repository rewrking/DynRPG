#define DYNRPG_STATIC

#include <DynRPG/Utility/PluginConfig.hpp>

namespace RPG
{
/******************************************************************************
 *
 *****************************************************************************/
PluginConfig::PluginConfig(char*& pluginName)
{
	load(pluginName);
}

/******************************************************************************
 *
 *****************************************************************************/
void PluginConfig::load(char*& pluginName)
{
	m_config = loadConfiguration(pluginName);
}

/******************************************************************************
 *
 *****************************************************************************/
const int PluginConfig::getInt(const std::string& inKey)
{
	return convert<int>(m_config[inKey]);
}

/******************************************************************************
 *
 *****************************************************************************/
const bool PluginConfig::getBool(const std::string& inKey)
{
	return convert<bool>(m_config[inKey]);
}

/******************************************************************************
 *
 *****************************************************************************/
const std::string PluginConfig::getString(const std::stringstream& inKey)
{
	return m_config[inKey.str()];
}

/******************************************************************************
 *
 *****************************************************************************/
const std::string PluginConfig::getString(const std::string& inKey)
{
	return m_config[inKey];
}
}
