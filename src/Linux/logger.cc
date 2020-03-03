#include "../lib/logger.hh"
#include <fstream>
#include <ctime>

std::string Logger::path = "";

Logger::Logger() { }
Logger::~Logger() { }

std::string Logger::getTimeFilename()
{
  char buf[16];
  time_t now = time(0);

  tm *ltm = localtime(&now);
  sprintf(buf, "%02d-%02d-%04d_%02d-%02d-%02d",
    ltm->tm_mday, 1 + ltm->tm_mon, 1900 + ltm->tm_year, ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
  
  return buf;
}

std::string Logger::getTime()
{
  char buf[16];
  time_t now = time(0);

  tm *ltm = localtime(&now);
  sprintf(buf, "%02d.%02d.%04d - %02d:%02d:%02d",
    ltm->tm_mday, 1 + ltm->tm_mon, 1900 + ltm->tm_year, ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
  
  return buf;
}

void Logger::initLogPath()
{
  path = "log/log_";
  path.append(getTimeFilename());
  path.append(".log");
}

void Logger::log(std::string tag, std::string message, bool silent)
{
  char buf[256];
  std::string tmp;
  std::ofstream logFile;
  logFile.open(Logger::path, std::ios_base::app);

  sprintf(buf, "(%s): [%s] %s\n", getTime().c_str(), tag.c_str(), message.c_str());
  tmp = buf;
  
  logFile.write(tmp.c_str(), tmp.length());
  if(!silent) printf("%s", buf);
}