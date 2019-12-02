#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <list>
#include <fstream>

using namespace std;

class WordList {
private:
	vector<string> dictonary;
	list<string> wordlist;
public:
	WordList();
	void CheckDictionary(string str);
	void CheckDuplication(string str);
	void CheckConfirm(string str);
	void add(string str);
	void startGame();
};

int main() {
	WordList wl;
	wl.startGame();

	system("pause");
	return 0;
}

WordList::WordList()
{
	ifstream ifs("dict.txt");

	string temp;

	while (!ifs.eof()) {
		ifs >> temp;
		dictonary.push_back(temp);
	}
	ifs.close();
}
void WordList::CheckDictionary(string str) {
	for (unsigned int i = 0; i < dictonary.size(); i++) {
		if (dictonary.at(i) == str)
			return;
	}
	throw string("Not exist word in dictionary");
}
void WordList::CheckDuplication(string str) {
	list<string>::iterator iter;
	for (iter = wordlist.begin(); iter != wordlist.end(); iter++) {
		if (*iter == str)
			throw string("It's Duplication");
	}
}
void WordList::CheckConfirm(string str) {
	if (wordlist.size() == 0)
		return;
	string temp = wordlist.back();
	if (temp.at(temp.size()-1) != str[0])
		throw string("Not same as the previous word alphabet");
}

void WordList::add(string str) {
	static ofstream ofs("result.txt");
	try {
		CheckDictionary(str);
		CheckDuplication(str);
		CheckConfirm(str);
	}
	catch (string reason) {
		cout << "You Lose. ";
		ofs.close();
		throw reason;
	}

	wordlist.push_back(str);
	list<string>::iterator iter;
	for (iter = wordlist.begin(); iter != wordlist.end(); iter++)
		cout << *iter << " ";
	cout << endl;


	ofs << str << " ";

}

void WordList::startGame() {
	cout << "Game Start" << endl;
	string input;
	try {
		while (true) {
			cout << "Input word : ";
			cin >> input;
			for (int i = 0; i < input.size(); i++)
				if (!((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z')))
					throw string("It is not English");
			add(input);
		}
	}
	catch (string reason) {
		cout << reason << endl;
	}
}
