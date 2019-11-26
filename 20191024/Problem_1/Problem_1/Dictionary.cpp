#include "Dictionary.h"

class Dictionary {
private:
	Entry entries[100];
public:
	Dictionary() {}
	Entry* find(string key) {
		try {
			for (int i = 0; i < 100; i++) {
				if (entries[i].getKey() == key) {
					Entry* temp = new Entry();
					temp->setKey(entries[i].getKey());
					temp->setValue(entries[i].getValue());
				}
			}
		}
		catch (my_exception& e)
		{
			cout << e.what() << endl;
			return NULL;
		}


	}
	Entry** find(char* value) {

	}
	Entry* insert(string key, char* value) {
		if (find(key) == 0)
			Entry* temp = new Entry(key, value);
		else
			cout << "ERROR: Not Found" << endl;
		return NULL;
	}
	Entry* modify(string key, char* value) {

	}
	string deletion(string key) {

	}
};