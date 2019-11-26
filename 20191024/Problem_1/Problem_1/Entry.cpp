#include "Entry.h"

class Entry {
private:
	string key;
	char* value;
public:
	Entry() {
		key = { 0 };
		value = new char[10];
	}
	Entry(string key, char* value) {
		this->key = key;
		this->value = new char[sizeof(value)];
		this->value = value;
	}
	void setKey(string key) { this->key = key; }
	void setValue(char* value) {
		this->value = new char[sizeof(value)];
		this->value = value;
	}
	string getKey() {return key;}
	char* getValue() { return value; }

};