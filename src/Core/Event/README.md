# EventWh
Simple Event Library for C++11
> EventWh used my game [Changer][1]

----------


# Quick Look
``` cpp
#include "EventWh.h"
using namespace wh;

auto handler = Event::on("hi", [](std::string name, void* param){
	log("hi %s", (char*)param); // "hi jack"
});

Event::emit("hi", "jack"); // emit an event and give a param

Event::off("hi", handler); // remove an event handler
```



# Installation

Just copy the `EventWh.h` and `EventWh.cpp` file wherever you want it. Then write this in any c++ file where you want to use it:
``` cpp
#include "EventWh.h"
```



# API

## Event::on (name, callback) -> handler
Handler events of type name with callback.

***Parameters***
- `std::string` **name** event name
- `std::function` **function** callback

***Return***
- An event handler instance.

***Example***
``` cpp
Event::on("hi", [](std::string name, void* param){
    /// todo something
});
```

## Event::once(name, callback) -> handler

Handler only once event of type name with callback

***Parameters***
- `std::string` **name** event name
- `std::function` **function** callback

***Return***
- An event handler instance.

***Example***
``` cpp
Event::once("hi", [](std::string name, void* param){
	/// todo something
});
```

## Event::off(name, handler) -> void
Remove an event callback

***Parameters***
- `std::string` **name** event name
- `Handler` **handler**

***Example***
``` cpp
Handler handler = Event::on("hi", [](std::string name, void* param){});
Event::off("hi", handler); // remove event callback
```

## Event::offAll(name) -> void
Remove all event callbacks

***Parameters***
- `std::string` **name** event name

***Example***
``` cpp
Event::offAll("hi");
```

## Event::clear() -> void
Clear all events

***Example***
``` cpp
Event::clear();
```



# License

EventWh is distributed under the [MIT license][2].


[1]: https://github.com/wilhantian/Changer
[2]: https://github.com/wilhantian/EventWh/blob/master/LICENSE