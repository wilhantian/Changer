#ifndef _UTILS_H_
#define _UTILS_H_

#include "Core/Logger/Logger.h"

#define SAFE_DELETE(_PTR_) \
if(_PTR_){ \
	delete _PTR_; \
	_PTR_ = nullptr; \
}

#define SAFE_DELETE_ARRAY(_PTR_) \
if(_PTR_){ \
	delete[] _PTR_; \
	_PTR_ = nullptr; \
}

#define IF_COM_NULL_CONTINUE(_COM_)\
if (_COM_.empty()) \
{ \
	Logger::debug("%s: is null", #_COM_); \
	continue; \
}

#endif