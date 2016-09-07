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

typedef unsigned Handle;
typedef std::function<void(std::string, void*)> Callback;

struct HandleData
{
	Handle handle;
	Callback callback;
	bool isOnce;

	static Handle _gid;

	HandleData(Callback callback, bool isOnce = false)
		: callback(callback)
		, handle(_gid++)
		, isOnce(isOnce)
	{
	}
};

/// EventWh
class Event
{
public:
	/// Subscribe to an event.
	static Handle on(std::string name, Callback callback);

	/// Subscribe to an event and fire only once.
	static Handle once(std::string name, Callback callback);

	/// Remove an event callback.
	static void off(std::string name, Handle handle);

	/// Remove an all callback.
	static void offAll(std::string name);

	/// Clear all event.
	static void clear();

	/// Emit an event.
	static void emit(std::string name, void* param);


private:
	Event();
	~Event();

	std::map<std::string, std::vector<HandleData>> _handleDatas;

private:
	static Event _instance;
};

NAMESPAVE_WH_END

#endif