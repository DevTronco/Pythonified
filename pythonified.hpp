#pragma once

#include <iostream>
#include <string>

namespace pythonified{
	template<typename T>
	T print(const T& value);

	template<typename T>
	T printLn(const T& value);

	template<typename T>
	T input(const std::string& prompt = "");

	template<typename T>
	std::string getType(const T& value);

	template<typename T>
	int len(const T& container);

	template<typename T, std::size_t N>
	int len(const T(&array)[N]);

	bool isTrue(const bool condition);
}