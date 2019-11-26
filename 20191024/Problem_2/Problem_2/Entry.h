#pragma once
#include <iostream>
#include "exception.h"
using namespace std;

class Entry {
private:
	string key;
	char* value;
public:
	Entry();
	Entry(string key, char* value);
	void setKey(string key);
	void setValue(char* value);
	string getKey();
	char* getValue();

};