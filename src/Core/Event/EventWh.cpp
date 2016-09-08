#include "EventWh.h"

wh::Handler wh::HandlerData::_gid = 0;

wh::Handler wh::Event::on(std::string name, Callback callback)
{
	HandlerData data(callback);
	_handleDatas[name].push_back(data);
	return data.handle;
}

wh::Handler wh::Event::once(std::string name, Callback callback)
{
	HandlerData data(callback, true);
	_handleDatas[name].push_back(data);
	return data.handle;
}

void wh::Event::off(std::string name, Handler handle)
{
	auto& list = _handleDatas[name];

	std::vector<HandlerData>::iterator  it_pos;
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
	_handleDatas[name].clear();
}

void wh::Event::clear()
{
	_handleDatas.clear();
}

void wh::Event::emit(std::string name, void* param)
{   
	auto& list = _handleDatas[name];

	std::vector<HandlerData>::iterator  it_pos;
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

std::map<std::string, std::vector<wh::HandlerData>> wh::Event::_handleDatas;
