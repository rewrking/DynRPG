#ifndef RPG_PLUGIN_CONFIG_HPP
#define RPG_PLUGIN_CONFIG_HPP

#include <functional>
#include <map>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <type_traits>
#include <vector>

namespace RPG
{
/*! \brief Returns a std::map containing configuration from an INI file

	This function should be used to load configuration for a plugin. See
	the \ref configuration guidelines for more information.
	\param sectionName Name of the section to load from the INI file
	\param filename Name of the INI file (defaults to \c DynRPG.ini)
	\return All keys and values of the specified section from the INI file
*/
std::map<std::string, std::string> loadConfiguration(char* sectionName, char* filename = nullptr);

struct PluginConfig
{
	PluginConfig() = default;
	PluginConfig(char*& pluginName);

	void load(char*& pluginName);

	const int getInt(const std::string& inKey);

	const bool getBool(const std::string& inKey);

	const std::string getString(const std::stringstream& inKey);

	const std::string getString(const std::string& inKey);

	template <typename T>
	const std::vector<T> getVector(const std::string& inKey, const std::string& inDelimiter)
	{
		std::string value = getString(inKey);

		std::vector<T> ret;
		size_t pos = 0;
		T token;

		while ((pos = value.find(inDelimiter)) != std::string::npos)
		{
			token = convert<T>(value.substr(0, pos));
			ret.push_back(token);
			value.erase(0, pos + inDelimiter.length());
		}
		token = convert<T>(value);
		ret.push_back(token);

		return ret;
	}

private:
	std::map<std::string, std::string> m_config;

	template <typename T>
	typename std::enable_if_t<std::is_same_v<T, bool>, bool>
	convert(const std::string& inString)
	{
		return inString == "true" || inString == "1";
	}

	template <typename T>
	typename std::enable_if_t<std::is_same_v<T, long long>, long long>
	convert(const std::string& inString)
	{
		return atoll(inString.c_str());
	}

	template <typename T>
	typename std::enable_if_t<!std::is_same_v<T, bool> && std::is_integral_v<T>, int>
	convert(const std::string& inString)
	{
		return atoi(inString.c_str());
	}

	template <typename T>
	typename std::enable_if_t<std::is_floating_point_v<T>, double>
	convert(const std::string& inString)
	{
		return atof(inString.c_str());
	}

	template <typename T>
	typename std::enable_if_t<std::is_same_v<T, std::string>, std::string>
	convert(const std::string& inString)
	{
		return inString;
	}
};

}

#endif // RPG_PLUGIN_CONFIGURATION_HPP