#include "ExtEntry.h"

class ExtEntry : public Entry {
private:
public:
	ExtEntry() {
		Entry();
	}
	ExtEntry(string key, char* value) {
		Entry(key, value);
	}
	void setKey(string key) { Entry::setKey(key);	}
	void setValue(char* value) {
		char* temp;
		for (int i = 0; i < ; i++) {
			if (value[i] == '/')
				break;
			else
				temp[i] = value[i];
		}
		Entry::setValue(temp);
	}
	void setValues(char* value) { Entry::setValue(value); }
	void addValue(char* value) {
		char* temp = getValues();
		temp += '//';
		for (int i = 0; i < ; i++)
			temp += value[i];
		setValues(temp);
	}
	string getKey() { Entry::getKey(); }
	char* getValue() {
		char* temp;
		char* temp2;
		temp = getValues();
		for (int i = 0; i < ; i++) {
			if (temp[i] == '/') {
				temp2 = new char[i];
				for (int j = 0; j < i; j++)
					temp2[j] = temp[j];
				break;
			}

		}
		return temp2;
	}
	char* getValues() { Entry::getValue(); }
	bool hasValue(char* value) {
		for (int i = 0; i < ; i++) {
			if(this->getValues()[i] == value[i])
				for (int j = 0; j < ; j++) {
					if (this->getValues[i + j] != value[i + j])
						break;
					return true;
				}
		}
		return false
	}
};
