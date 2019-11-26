#pragma once
#include <iostream>
#include <exception>
using namespace std;

class my_exception : public exception {
	const char* what(){
		return "ERROR: Not Found";
	}
};