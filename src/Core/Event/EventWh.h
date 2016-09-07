#ifndef _EVENT_WH_H_
#define _EVENT_WH_H_

#include <functional>

#define NAMESPACE_WH_BEGIN namespace wh{
#define NAMESPAVE_WH_END }

#define USING_WH_NAMESPACE using namespace wh

NAMESPACE_WH_BEGIN

typedef unsigned Handle;
typedef std::function<bool(const char*, void*)> Callback;

class Event
{
public:
	static void init();

	static void destroy();

public:
	static Handle on(const char* name, Callback callback);

	static bool off(Handle handle);

	static bool off(Callback callback);

	static bool offAll();

	static bool offAll(const char* name);

	static void emit(const char* name, ...);
};

NAMESPAVE_WH_END

#endif