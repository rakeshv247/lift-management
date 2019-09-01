#include "config.h"

bool Config::_ParseAndLoad()
{
  return true;
}

void Config::SetConfigFile(const std::string& configFile)
{
  _configFile = configFile;
}

bool Config::LoadConfig(const std::string& configFile)
{
  SetConfigFile(_configFile);
  return _ParseAndLoad();
}

std::string Config::GetConfig(const std::string& configName)
{
  return _config[configName];
}
