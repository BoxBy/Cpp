#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

#define TAB 1
#define RAVE 2
#define CAVE 3

class myManip {
private:
	string* hdr_str;
	int val_array[10][6];
	int row1, row2, col1, col2, selector;
public:
	myManip(string* hdr_str, int* val_array[], int row1, int col1, int row2, int col2, int selector) : hdr_str(hdr_str), row1(row1), col1(col1), row2(row2), col2(col2), selector(selector) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 10; j++) {
				myManip::val_array[j][i] = val_array[j][i];
			}
		}

	}

	friend ostream& operator<<(ostream& os, myManip);

};

ostream& operator<<(ostream& os, myManip source) {
	if (source.selector == TAB) {
		os << setw(36) << setfill('-') << '-' << endl;

		for (int i = source.col1; i <= source.col2; i++)
			os << setfill(' ') << setw(6) << right << source.hdr_str[i];

		os << endl << setw(36) << setfill('=') << '=' << endl;

		for (int i = source.row1; i <= source.row2; i++) {
			for (int j = source.col1; j <= source.col2; j++)
				os << setfill(' ') << setw(6) << right << source.val_array[i][j];
			os << endl;
		}

		os << setw(36) << setfill('-') << '-';
	}
	else if (source.selector == RAVE) {
		os << setw(60) << setfill('-') << '-' << endl;

		for (int i = source.row1; i <= source.row2; i++)
			os << setfill(' ') << setw(6) << right << source.hdr_str[i];

		os << endl << setw(60) << setfill('=') << '=' << endl;

		int temp;

		for (int i = source.row1; i <= source.row2; i++) {
			temp = 0;
			for (int j = source.col1; j <= source.col2; j++)
				temp += source.val_array[i][j];
			temp /= (source.col2 + 1);
			os << setfill(' ') << setw(6) << right << temp;
		}

		os << endl << setw(60) << setfill('-') << '-';

	}
	else if (source.selector == CAVE) {
		os << setw(30) << setfill('-') << '-' << endl;

		for (int i = source.col1-1; i < source.col2; i++)
			os << setfill(' ') << setw(6) << right << source.hdr_str[i];

		os << endl << setw(30) << setfill('=') << '=' << endl;

		int temp;
		for (int i = source.col1; i <= source.col2; i++) {
			temp = 0;
			for (int j = source.row1; j <= source.row2; j++)
				temp += source.val_array[j][i];
			temp /= (source.row2 + 1);
			os << setfill(' ') << setw(6) << right << temp;
		}

		os << endl << setw(30) << setfill('-') << '-' << endl;

	}

	return os << setfill(' ') << endl;
}


myManip ptab(std::string* hdr_str, int** val_array, int row1, int col1, int row2, int col2) {
	return myManip(hdr_str, val_array, row1, col1, row2, col2, TAB);
}

myManip prave(std::string* hdr_str, int** val_array, int row1, int col1, int row2, int col2) {
	return myManip(hdr_str, val_array, row1, col1, row2, col2, RAVE);
}

myManip pcave(std::string* hdr_str, int** val_array, int row1, int col1, int row2, int col2) {
	return myManip(hdr_str, val_array, row1, col1, row2, col2, CAVE);
}

int main() {
	string hdr1[6];
	int** val;
	val = new int* [10];
	for (int i = 0; i < 10; i++)
		val[i] = new int[6];

	string hdr2[10] = { "no 1", "no 2", "no 3", "no 4", "no 5", "no 6", "no 7", "no 8", "no 9", "no 10" };
	string hdr3[5] = { "math", "eng", "phy", "chem", "hist" };

	ifstream ifs("score.txt");

	//hdr1 in
	ifs >> hdr1[0] >> hdr1[1] >> hdr1[2] >> hdr1[3] >> hdr1[4] >> hdr1[5];

	//val in
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 6; j++)
			ifs >> val[i][j];

	cout << "Score Table" << endl << ptab(hdr1, val, 0, 0, 9, 5) << endl;
	cout << "Average per student" << endl << prave(hdr2, val, 0, 1, 9, 5) << endl;
	cout << "Average per subject" << endl << pcave(hdr3, val, 0, 1, 9, 5) << endl;

	return 0;
}
