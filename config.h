#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <map> 

class Config
{
public:
  bool LoadConfig(const std::string& configFile);
  std::string GetConfig(const std::string& configName);
  void SetConfigFile(const std::string& configFile);
private:
  bool _ParseAndLoad();
  std::map<std::string, std::string> _config;
  std::string _configFile;
};

#endif
