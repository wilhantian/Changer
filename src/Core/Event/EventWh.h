#ifndef _EVENT_WH_H_
#define _EVENT_WH_H_

#include <functional>
#include <string>
#include <vector>
#include <map>

#define NAMESPACE_WH_BEGIN namespace wh{
#define NAMESPAVE_WH_END }

#define USING_WH_NAMESPACE using namespace wh

NAMESPACE_WH_BEGIN

typedef std::function<bool(const char*, void*)> Callback;
typedef unsigned Handle;
typedef int Index;

struct HandleMap{
    static Handle _handleNum;
    
    Callback callback;
    Handle handle;
    Index index;
    
    HandleMap(Callback callback, Index index = 0)
    : callback(callback)
    , index(index)
    {
        handle = _handleNum++;
    }
};

class Event
{
public:
    static void pause();
    
    static void resume();

public:
	static Handle on(const char* name, Callback callback);
    
    static Handle onOnce(const char* name, Callback callback);

	static bool off(Handle handle, const char* name = nullptr);

    
	static bool offAll();

	static bool offAll(const char* name);

	
    static void emit(const char* name, ...);
    
protected:
    std::map<std::string, std::vector<HandleMap>> _handlers;
    
    static Event _instance;
};

NAMESPAVE_WH_END

#endif