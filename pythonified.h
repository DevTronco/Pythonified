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

}