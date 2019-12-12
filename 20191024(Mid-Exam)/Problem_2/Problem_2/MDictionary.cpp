#include "MDictionary.h"

class MDictionary {
private:
	ExtEntry extEntries[100];
public:
	MDictionary() { }
	ExtEntry* find(string key) {
		ExtEntry* temp;
		for (int i = 0; i < 100; i++)
			if (extEntries[i].getKey() == key) {
				temp->setKey(extEntries[i].getKey());
				temp->setValue(extEntries[i].getValue());
				break;
			}
		try {
			return temp;
		}
		catch (my_exception& e) {
			cout << e.what() << endl;
			return 0;
		}
	}
	ExtEntry** find(char* value) {
		ExtEntry** temp;
		int j = 0;
		for (int i = 0; i < 100; i++)
			if (extEntries[i].hasValue(value)) {
				temp[j]->setKey(extEntries[i].getKey());
				temp[j]->setValue(extEntries[i].getValue());
				j++;
			}
		return temp;
	}
	ExtEntry* insert(string key, char* value) {
		if (find(key) == NULL)
		{
			ExtEntry *temp = new ExtEntry(key, value);
			return temp;
		}
	}
	string deletion(string key) {

	}
};