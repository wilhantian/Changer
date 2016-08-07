#include "Logger.h"
#include <stdarg.h>
#include <stdio.h>

void Logger::debug(const char *str, ...)
{
	va_list ap;
	va_start(ap, str);
	vprintf("[DEBUG]", NULL);
	int n = vprintf(str, ap);
	vprintf("\n", NULL);
	va_end(ap);
}

void Logger::warn(const char *str, ...)
{
	va_list ap;
	va_start(ap, str);
	vprintf("[WARNING]", NULL);
	int n = vprintf(str, ap);
	vprintf("\n", NULL);
	va_end(ap);
}

void Logger::error(const char *str, ...)
{
	va_list ap;
	va_start(ap, str);
	vprintf("[ERROR]", NULL);
	int n = vprintf(str, ap);
	vprintf("\n", NULL);
	va_end(ap);
}

