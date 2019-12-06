#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void print(int math, int first, int second, int result, ofstream& ofs) {
	ofs << setw(10) << left << dec << first << " " << (char)math << " " << setw(10) << second << " = ";
	ofs << setw(10) << right << "dec : " << dec << result << " oct : " << setw(4) << setfill('0') << oct << result << " hex : " << hex << internal << setw(4) << setfill('0') << showbase << result << setfill(' ') << endl;
}

int main() {
	ifstream ifs("calculation.txt");
	string calculation[3];
	int calculationChar[5][3] = { 0 };

	for (int i = 0; i < 5; i++) {
		ifs >> calculation[0] >> calculation[1] >> calculation[2];
		calculationChar[i][0] = calculation[0][0]; // ¿¬»êÀÚ 
		calculationChar[i][1] = stoi(calculation[1], nullptr, 0); // first num
		calculationChar[i][2] = stoi(calculation[2], nullptr, 0); // second num
	}

	ifs.close();

	ofstream ofs("result.txt");

	for (int i = 4; i >= 0; i--) {
		switch (calculationChar[i][0])
		{
		case '+':
			print(calculationChar[i][0], calculationChar[i][1], calculationChar[i][2], calculationChar[i][1] + calculationChar[i][2], ofs);
			break;
		case '-':
			print(calculationChar[i][0], calculationChar[i][1], calculationChar[i][2], calculationChar[i][1] - calculationChar[i][2], ofs);
			break;
		case '/':
			ofs << left << setw(10) << dec << calculationChar[i][1] << " " << (char)calculationChar[i][0] << " " << setw(10) << calculationChar[i][2] << " = ";
			ofs.width(60);
			ofs.setf(ios_base::right, ios_base::adjustfield);
			ofs.precision(2);
			ofs << showpoint << calculationChar[i][1] / (double)calculationChar[i][2] << endl;
			break;
		case '*':
			print(calculationChar[i][0], calculationChar[i][1], calculationChar[i][2], calculationChar[i][1] * calculationChar[i][2], ofs);
			break;
		default:
			ofs << "It is Wrong!" << endl;
		}
	}
	
	ofs.close();
	system("pause");
	return 0;
}