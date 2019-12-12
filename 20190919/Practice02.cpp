#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
	char temp;
	string first, second;
	char temp2[100];
	bool isHex;

	ifstream fIn("calculation.txt");

	while (fIn >> first >> temp >> second >> temp2) {
		int firstInt, secondInt;
		isHex = false;
		if ((firstInt = stoi(first)) == 0) { // 16진수 분기점
			isHex = true;
			firstInt = stoi(first, nullptr, 16);
			secondInt = stoi(second, nullptr, 16); // 앞 숫자가 16진수이므로 자동으로 뒤 숫자도 16진수
		}
		else
			secondInt = stoi(second);
		if (isHex == false) { // 10진수 출력
			cout << left << setw(6) << first << setw(2) << temp << setw(6) << second << " = ";
			switch (temp) {
			case '+':
				cout << setw(4) << right << firstInt + secondInt;
				break;
			case '-':
				cout << setw(4) << right << firstInt - secondInt;
				break;
			case '/':
				cout << setw(4) << right << showpoint << setprecision(3) << (float)firstInt / secondInt;
				break;
			case '*':
				cout << setw(4) << right << firstInt * secondInt;
				break;
			}
		}
		else {
			cout << left << setw(6) << first << setw(2) << temp << setw(6) << second << " = ";
			switch (temp) {
			case '+':
				cout << setw(4) << right << hex << firstInt + secondInt;
				break;
			case '-':
				cout << "0x" << setw(2) <<  setfill('0') <<  right << hex << firstInt - secondInt;
				break;
			case '/':
				cout << setw(4) << right << hex << (float)firstInt / secondInt;
				break;
			}
		}
		cout << endl;
	}
	fIn.close();
	system("pause");
	return 0;
}