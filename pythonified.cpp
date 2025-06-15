#include <iostream>
#include <string>

#include "pythonified.h"

using namespace pythonified;


//usage = print("Hello World"); -> Hello World!
template<typename T>
T print(const T& value) {
	std::cout << value;
	return value;
}

//usage = printLn("Hello"); -> Hello
//		  print("World");      World
template<typename T>
T printLn(const T& value) {
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

template<typename T>
std::string getType(const T& value) {
	if constexpr (std::is_same_v<T, int>) {
		return "int";
	}
	else if constexpr (std::is_same_v<T, std::string>) {
		return "string";
	}
	else if constexpr (std::is_same_v<T, bool>{
		return "bool";
	}
	else if constexpr (std::is_same_v<T, char>{
		return "char";
	}
	else if constexpr (std::is_same_v<T, float>) {
		return "float";
	}
	else if constexpr (std::is_pointer_v<T>) {
		return "pointer";
	}
	else if constexpr (std::is_array_v<T>) {
		return "array";
	}
}