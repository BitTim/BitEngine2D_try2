#pragma once

#include <string>

class Logger
{
public:
  Logger();
  ~Logger();

  static std::string getTimeFilename();
  static std::string getTime();

  static void initLogPath();
  static void log(std::string tag, std::string message, bool silent = false);

private:
  static std::string path;
};