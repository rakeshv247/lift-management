#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <stdarg.h>
#include <stdio.h>

typedef enum LogMode
{
  INFO = 0,
  ERROR,
  DEBUG
} LogMode;

class Logger
{
public:
  static void write(LogMode mode, const char *fmt, ...);
  static void Init(const std::string& path);
  static void Destroy();

private:
  FILE *_fp;
  std::string _path;
  static Logger *_self;
  Logger(const std::string& path);
};

#endif
