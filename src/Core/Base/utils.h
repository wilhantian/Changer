#ifndef _UTILS_H_
#define _UTILS_H_

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

#endif