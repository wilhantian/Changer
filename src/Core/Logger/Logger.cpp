#include "Logger.h"
#include <stdarg.h>
#include <stdio.h>
#include <assert.h>

void Logger::debug(const char *str, ...)
{
	va_list ap;
	va_start(ap, str);
    printf("[DEBUG]");
	vprintf(str, ap);
	printf("\n");
	va_end(ap);
}

void Logger::warn(const char *str, ...)
{
	va_list ap;
	va_start(ap, str);
    printf("[WARNING]");
    vprintf(str, ap);
	printf("\n");
	va_end(ap);
}

void Logger::error(const char *str, ...)
{
	va_list ap;
	va_start(ap, str);
	printf("[ERROR]");
	vprintf(str, ap);
	printf("\n");
	va_end(ap);
}

void Logger::assertion(int e, const char* str)
{
	assert(e);
	//Logger::error(str);
}

