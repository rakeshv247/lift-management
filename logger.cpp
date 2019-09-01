#include "logger.h"
#include "config.h"
#include <string.h>

Logger* Logger::_self = nullptr;

Logger::Logger(const std::string& path) : _path(path)
{
}

void Logger::Init(const std::string& path)
{
  if ( !Logger::_self ) {
    Logger::_self = new Logger(path);
  }

  if ( !Logger::_self->_fp ) {
    fprintf(stderr, "Initiating Logger");
    Logger::_self->_fp = fopen(path.c_str(), "w");
    if ( !Logger::_self->_fp ) {
      fprintf(stderr, "Logger Init Error");
    }
  }
}

void Logger::Destroy()
{
  write(INFO, "Destroying Logger");
  if ( Logger::_self ) {
    if ( Logger::_self->_fp ) {
      fclose( Logger::_self->_fp );
      Logger::_self->_fp = nullptr;
    }
    delete Logger::_self;
  }
}

void Logger::write(LogMode mode, const char *fmt, ...)
{
  va_list vl1, vl2;
  va_start(vl1, fmt);
  va_copy(vl2, vl1);

  const int num = vsnprintf(0, 0, fmt, vl1);
  char temp[num+1];
  memset(temp, 0, sizeof(temp));
  vsnprintf(temp, (num+1), fmt, vl2);

  fprintf(Logger::_self->_fp, "%s", temp);
}
