#include "Dictionary.h"
#include <fstream>

int main() {
	Dictionary d;
	char* temp;
	int t;
	ifstream inFile;
	inFile.open("dictonary.txt");
	while(inFile >> temp){

	}
	cout << "Find key 'Apple'" << endl;
	cout << d.find("Apple") << endl;
	
	cout << "1. Modify 'Apple' meaning and 2. Find again key 'Apple'" << endl;
	cin >> t;
	if (t == 1) {
		cout << "Input : " << endl;
		cin >> temp;
		d.modify("Apple", temp);
	}
	else
		cout << d.find("Apple") << endl;

	cout << "Find Key 'Orange'" << endl;
	cout << d.find("Orange") << endl;

	cout << "1. Delete 'Orange' and 2. Find again key 'Orange'" << endl;
	cin >> t;
	if (t == 1) {
		cout << "Orange" << endl;
		d.deletion("Orange");
	}
	cout << d.find("Orange") << endl;
}