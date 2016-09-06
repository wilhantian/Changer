#include "EventWh.h"

void wh::Event::init()
{

}

void wh::Event::destroy()
{

}

wh::Handle wh::Event::on(const char* name, Callback callback)
{
	return 0;
}

bool wh::Event::off(Handle handle)
{
	return false;
}

bool wh::Event::off(Callback callback)
{
	return false;
}

bool wh::Event::offAll()
{
	return false;
}

bool wh::Event::offAll(const char* name)
{
	return false;
}

void wh::Event::emit(const char* name, ...)
{

}
