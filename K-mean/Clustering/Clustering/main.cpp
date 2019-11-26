#include <cstdlib>
#include <ctime>
#include "Kmeans.h"

int main() {
	double** result = new double* [10];
	for (int i = 0; i < 10; i++) {
		result[i] = new double[20]; // ��� ����
		result[i][0] = { 0 };
	}
	srand((unsigned int)time(NULL));

	int temp;
	for (int count = 0; count < 3; count++) {
		cout << "1. Random or 2. Select? : " << endl;
		cin >> temp;
		if (temp == 1) {
			temp = rand() % 11 + 9;
		}
		else {
			cout << "K(9 ~ 20) : " << endl;
			cin >> temp;
		}
		Kmeans K(temp); // K�� �� ����
		cout << "K : " << temp << endl;
		
		ifstream Matrix("termDocMatrix.txt");
		K.setArray(Matrix);

		ifstream Dict("wordDict-docTitle.txt");
		K.setValue(Dict);

		K.print(result);

		cout << "     1��     ��     2��     ��     3��     ��     4��     ��     5��     ��     6��     ��     7��     ��     8��     ��     9��     ��     10��     ��" << endl;
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 10; j++)
				cout << setw(14) << result[j][i] << " ";
			cout << endl;
		}
	}
	for (int i = 0; i < 10; i++)
		delete[] result[i];
	delete[] result;
	return 0;
}