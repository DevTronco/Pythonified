Hi!
I'm a 15 years old Italian developer from Veneto, Italy.
I decided to create Pythonified for 2 clear reasons:
    -Help those who switch from Python to C++
    -Use C++ speed altoghether with Python simplicity

I know this library might not be very clear, but its an attempt, and its my first try attempting those kind of things.

EXPLANATIONS:

print() -> just the classic Python print
printLn() -> print but it goes to a new line after printing
input() -> requires to specify the type, can display text like normal Python input() (check examples)

EXAMPLES
'''cpp
#include "pythonified.h"
using namespace pythonified;

auto name = input<std::string>("your name: ");
auto age = input<int>("your age: ");
print(name + std::to_string(age));
printLn(name + std::to_string(age))
