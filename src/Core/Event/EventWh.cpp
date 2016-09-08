#include "EventWh.h"

wh::Handle wh::HandleMap::_handleNum = 0;

wh::Handle wh::Event::on(const char* name, Callback callback)
{
    auto handler = HandleMap(callback);
    _instance._handlers[name].push_back(handler);
    return handler.handle;
}

bool wh::Event::off(Handle handle, const char* name)
{
    if(name)
    {
        for(auto handler : _instance._handlers[name])
        {
            if(handle == handler.handle){return true;}
        }
    }
	return false;
}

bool wh::Event::offAll()
{
    _instance._handlers.clear();
	return false;
}

bool wh::Event::offAll(const char* name)
{
    _instance._handlers[name].clear();
	return false;
}

void wh::Event::emit(const char* name, ...)
{
    for (auto handler : _instance._handlers[name])
    {
        if(handler.callback(name, nullptr))
        {
            return;
        }
    }
}

wh::Event wh::Event::_instance = Event();
