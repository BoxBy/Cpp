#pragma once
#include "ExtEntry.h"

class MDictionary {
private:
	ExtEntry extEntries[100];
public:
	MDictionary();
	ExtEntry* find(string key);
	ExtEntry** find(char* value);
	ExtEntry* insert(string key, char* value);
	string deletion(string key);
};