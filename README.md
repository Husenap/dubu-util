![Windows](https://github.com/Husenap/dubu-util/workflows/Windows/badge.svg)
![Ubuntu](https://github.com/Husenap/dubu-util/workflows/Ubuntu/badge.svg)

```
   _     _               _   _ _ 
 _| |_ _| |_ _ _ ___ _ _| |_|_| |
| . | | | . | | |___| | |  _| | |
|___|___|___|___|   |___|_| |_|_|
```

Collection of C++ Utilities

# Features

* TypeId
  * Fast threadsafe type identification
  * Is not reliable over multiple processes or sessions


# Examples

##### **`Type Id`**
```cpp
#include <dubu_util/dubu_util.h>

struct Foo{};
struct Bar{};

int main(){
  Foo foo;
  Bar bar;

  dubu::util::TypeId::Get<Foo>();   // 1
  dubu::util::TypeId::Get<Bar>();   // 2
  dubu::util::TypeId::Get(foo);     // 1
  dubu::util::TypeId::Get(bar);     // 2
}
```