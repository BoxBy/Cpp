#pragma once
#include "Entry.h"

class ExtEntry : public Entry {
private:
public:
	ExtEntry();
	ExtEntry(string key, char* value);
	void setKey(string key);
	void setValue(char* value);
	void setValues(char* value);
	void addValue(char* value);
	string getKey();
	char* getValue();
	char* getValues();
	bool hasValue(char* value);
};