#ifndef _LOGGER_H_
#define _LOGGER_H_

class Logger
{
public:
	static void debug(const char *str, ...);
	static void warn(const char *str, ...);
	static void error(const char *str, ...);

private:
	Logger(){};
};

#endif