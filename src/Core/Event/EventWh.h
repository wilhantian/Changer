///
/// (EventWh)[https://github.com/wilhantian/EventWh]
/// Simple Event Library for C++11
/// Under the MIT license.
///

#ifndef _EVENT_WH_H_
#define _EVENT_WH_H_

#include <functional>
#include <string>
#include <map>
#include <vector>

#define NAMESPACE_WH_BEGIN namespace wh{
#define NAMESPAVE_WH_END }

#define USING_WH_NAMESPACE using namespace wh

NAMESPACE_WH_BEGIN

typedef unsigned Handler;
typedef std::function<void(std::string, void*)> Callback;

struct HandlerData
{
	Handler handle;
	Callback callback;
	bool isOnce;

	HandlerData(Callback callback, bool isOnce = false)
		: callback(callback)
		, handle(_gid++)
        , isOnce(isOnce){}
    
    static Handler _gid;
};

/// EventWh
class Event
{
public:
	/// Subscribe to an event.
	static Handler on(std::string name, Callback callback);

	/// Subscribe to an event and fire only once.
	static Handler once(std::string name, Callback callback);

	/// Remove an event callback.
	static void off(std::string name, Handler handle);

	/// Remove an all callback.
	static void offAll(std::string name);

	/// Clear all event.
	static void clear();

	/// Emit an event.
	static void emit(std::string name, void* param);


private:
	static std::map<std::string, std::vector<HandlerData>> _handleDatas;
};

NAMESPAVE_WH_END

#endif