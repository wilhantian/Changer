#include "EventWh.h"

wh::Handle wh::HandleData::_gid = 0;

wh::Handle wh::Event::on(std::string name, Callback callback)
{
	HandleData data(callback);
	_instance._handleDatas[name].push_back(data);
	return data.handle;
}

wh::Handle wh::Event::once(std::string name, Callback callback)
{
	HandleData data(callback, true);
	_instance._handleDatas[name].push_back(data);
	return data.handle;
}

void wh::Event::off(std::string name, Handle handle)
{
	auto& list = _instance._handleDatas[name];

	std::vector<HandleData>::iterator  it_pos;
	for (it_pos = list.begin(); it_pos != list.end();)
	{
		if (it_pos->handle == handle)
		{
			list.erase(it_pos);
			return;
		}
		it_pos++;
	}
}

void wh::Event::offAll(std::string name)
{
	_instance._handleDatas[name].clear();
}

void wh::Event::clear()
{
	_instance._handleDatas.clear();
}

void wh::Event::emit(std::string name, void* param)
{
	auto& list = _instance._handleDatas[name];

	std::vector<HandleData>::iterator  it_pos;
	for (it_pos = list.begin(); it_pos != list.end();)
	{
		auto& data = *it_pos;
		data.callback(name, param);
		if (data.isOnce)
		{
			it_pos = list.erase(it_pos);
		}
		else
		{
			it_pos++;
		}
	}
}

wh::Event::Event()
{
}

wh::Event::~Event()
{
}

wh::Event wh::Event::_instance = Event();
