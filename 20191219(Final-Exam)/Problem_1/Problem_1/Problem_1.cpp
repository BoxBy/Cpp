#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

ostream& ptab(string hdr_str[], int* val_array[], int row1, int col1, int row2, int col2) {
	cout << setw(35) << setfill("-") << endl;

	for (int i = col1; i <= col2; i++)
		cout << setw(6) << right << hdr_str[i];

	cout << endl << setw(35) << setfill("=") << endl;

	for (int i = row1; i <= row2; i++) {
		for (int j = col1; j <= col2; j++)
			cout << setw(6) << right << val_array[i][j];
		cout << endl;
	}

	cout << setw(35) << setfill("-") << endl;

	return;
}


class ptab {
private:
	string hdr_str[6];
	int val_array[10][6];
	int row1, row2, col1, col2;
public:
	ptab(string hdr_str[], int* val_array[], int row1, int col1, int row2, int col2) {
		for (int j = 0; j < 10; j++) {
			for (int i = 0; i < 6; i++) {
				this->hdr_str[i] = hdr_str[i];
				this->val_array[j][i] = val_array[j][i];
			}
		}
		this->col1 = col1, this->col2 = col2, this->row1 = row1, this->row2 = row2;
	}

	ostream& operator<<(ostream& os, string hdr_str[], int* val_array[], int row1, int col1, int row2, int col2);

};

ostream& ptab::operator<<(ostream& os, string hdr_str[], int* val_array[], int row1, int col1, int row2, int col2){

	return os << endl;
}

ostream& prave(string hdr_str[], int* val_array[], int row1, int col1, int row2, int col2) {
	cout << setw(60) << setfill("-") << endl;

	for (int i = row1; i <= row2; i++)
		cout << setw(6) << right << hdr_str[i];

	cout << endl << setw(60) << setfill("=") << endl;

	int temp;
	for (int i = row1; i <= row2; i++) {
		temp = 0;
		for (int j = col1; j <= col2; j++)
			temp += val_array[i][j];
		temp /= (col2 + 1);
		cout << setw(6) << right << temp;
	}
	cout << endl << setw(60) << setfill("-") << endl;

	return;
}

ostream& pcave(string hdr_str[], int* val_array[], int row1, int col1, int row2, int col2) {
	cout << setw(30) << setfill("-") << endl;

	for (int i = row1; i <= row2; i++)
		cout << setw(6) << right << hdr_str[i];

	cout << endl << setw(30) << setfill("=") << endl;

	int temp;
	for (int i = col1; i <= col1; i++) {
		temp = 0;
		for (int j = row1; j <= row2; j++)
			temp += val_array[j][i];
		temp /= (row2 + 1);
		cout << setw(6) << right << temp;
	}
	cout << endl << setw(30) << setfill("-") << endl;

	return;
}

int main() {
	string hdr1[6];
	int val[10][6];

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
