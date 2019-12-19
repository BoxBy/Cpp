#include "Board.h"
#include <fstream>

int compare(string str1, string str2) {
	if (str1.size() > str2.size())
		return 1;
	else if(str1.size() < str2.size())
		return -1;
	else
		return 0;
}

int main() {
	ifstream ifs("wordlist.txt");
	vector<string> wordlist;

	string temp;
	vector<string>::const_iterator it;

	srand(time(NULL)); // for anagram

	while (ifs >> temp) {
		it = wordlist.begin();

		if (wordlist.size() == 0) {
			wordlist.push_back(temp);
			wordlist.push_back(" ");
		}
		else {
			for (int i = 0; ; it++, i++) {
				if (temp.size() > wordlist[i].size())
					wordlist.insert(it, temp);
			}
		}

	}
	ifs.close();
	
	it = wordlist.begin();

	cout << "Word List" << endl;
	cout << setw(40) << setfill("-") << endl;
	while (it != wordlist.end()) {
		cout << *it << endl;
		it++;
	}
	cout << setw(40) << setfill("-") << endl;

	Board WordPuzzle;
	cout << "Cross Word Puzzle" << endl;
	
	WordPuzzle.placeList(wordlist);
	WordPuzzle.printBoard(wordlist);


	return 0;
}