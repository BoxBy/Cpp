#include <iostream>
#include <string>
using namespace std;

int operator/(string s1, string s2) {
	int count = 0;
	for (int i = 0; i < s1.size(); i++) {
		if (s1.find(s2, i) != -1) {
			i = s1.find(s2, i);
			count++;
		}
	}
	return count;
}

string operator-(string s1, string s2) {
	int count = s1.find(s2);
	s1.erase(count, s2.size());
	return s1;
}

string operator*(string s1, int i) {
	string temp;
	for (int j = 0; j < i; j++)
		temp += s1;
	return temp;
}

int main() {
	string s1("this is test string. test is ok.");
	string s2, s3, s4;
	int n;

	n = s1 / "test";
	cout << n << endl;
	s2 = s1 - "test";
	cout << s2 << endl;
	s3 = s2 - "test";
	cout << s3 << endl;
	n = s3 / "test";
	cout << n << endl;
	string word1 = "test";
	s4 = word1 * 3;
	cout << s4 << endl;
	string s5 = s1 - "test" - "this";
	cout << s5 << endl;
	string word2 = "bbaq";
	string s6 = word2 * 3 * 2;
	cout << s6 << endl;

	system("pause");
	return 0;
}