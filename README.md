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
getType() -> returns the type of the argument variable
len() -> returns number of letters in strings, data in arrays... (everything that works with .size() in c++)
isTrue() -> simply returns if the argument variable is true or false

EXAMPLES
'''cpp
#include <std::string>
#include "pythonified.h"
using namespace pythonified;

auto name = input<std::string>("your name: ");
auto age = input<int>("your age: ");
print(name + std::to_string(age));
printLn(name + std::to_string(age))

bool real = true;
isTrue(real); -> returns true

std::string name = "John";
print(len(name)); -> returns 4

int array[] = {1, 2, 3};
print(len(array[])); -> returns 3