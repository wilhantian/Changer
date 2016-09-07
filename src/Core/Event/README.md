# EventWh
Simple Event Library for C++11
``` cpp
#include "EventWh.h"
using namespace wh;
```

## Event::on (name, callback) -> handler
Handle events of type name with callback.

### Parameters
- std::string **name**
- std::function **function**

### Return
- An event handler instance.

### Example
``` cpp
Event::on("run", [](std::string name, void* param){
    /// todo something
});
```
