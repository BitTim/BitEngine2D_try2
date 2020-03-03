#pragma once

#include <string>

class Logger
{
public:
  Logger();
  ~Logger();

  static std::string getTime(std::string format);

  static void initLogPath();
  static void log(std::string tag, std::string message, bool silent = false);

private:
  static std::string path;
};