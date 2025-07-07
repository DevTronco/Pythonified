#include <iostream>
#include <string>
#include <typeinfo>
#include <random>

#include "pythonified.hpp"
using namespace pythonified;

//usage = print("Hello World"); -> Hello World!
template<typename T>
T print(const T& value, ...) {
	std::cout << value;
	return value;
}

//usage = printLn("Hello"); -> Hello
//		  print("World");      World
template<typename T>
T printLn(const T& value, ...) {
	std::cout << value << std::endl;
	return value;
}


//usage = input<int>("Enter your age: "); 
template<typename T>
T input(const std::string& prompt = "") {
	T value;
	if constexpr (std::is_same_v<T, std::string>) {
		std::getline(std::cin, value);
	}
	else {
		std::cin >> value;
	}

	return value;
}

//usage = getType(some_var_your_created) -> "type";
template<typename T>
std::string getType(const T& value) {
	if constexpr (std::is_same_v<T, int>) return "int";
	else if constexpr (std::is_same_v<T, std::string>) return "string";
	else if constexpr (std::is_same_v<T, bool>) return "bool";
	else if constexpr (std::is_same_v<T, char>) return "char";
	else if constexpr (std::is_same_v<T, float>) return "float";
	else if constexpr (std::is_pointer_v<T>) return "pointer";
	else if constexpr (std::is_array_v<T>) return "array";
	else return typeid(T).name();
}

template<typename T>
int len(const T& container) {
	if constexpr (requires{container.size()}) return static_cast<int>(container.size());
	else static_assert(sizeof(T) == 0, "The type passed to len() doesnt have the size() method");
}

template<typename T, std::size_t N>
int len(const T(&array)[N]) {
	return static_cast<int>(N);
}

bool isTrue(const bool condition) {
	return condition;
}

template<typename T>
T random::randint(T min, T max) {
	static std::random_device rd;
	static std::mt19937 gen(rd());

	if constexpr (std::is_integral<T>::value) {
		std::uniform_int_distribution<T> dist(min, max);
		return dist(gen);
	}
	else if constexpr (std::is_floating_point<T>::value) {
		std::uniform_real_distribution<T> dist(min, max);
		return dist(gen);
	}
	else {
		static_assert(std::is_arithmetic<T>::value, "Randint only supports numerical types");
	}
}