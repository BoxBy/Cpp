#pragma once
#include "Entry.h"

class Dictionary {
private:
	Entry entries[100];
public:
	Dictionary();
	Entry* find(string key);
	Entry** find(char* value);
	Entry* insert(string key, char* value);
	Entry* modify(string key, char* value);
	string deletion(string key);
};