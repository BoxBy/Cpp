#include <iostream>
#include <cstdlib>

using namespace std;

class BoundCheckIntArray {
private:
	int* arr;
	int arrlen;
	BoundCheckIntArray(const BoundCheckIntArray& arr) {}
	BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) {}
public:
	BoundCheckIntArray(int len) : arrlen(len) {
		arr = new int[len];
	}
	int& operator[](int idx) {
		if (idx < 0 || idx > arrlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int operator[](int idx) const {
		if (idx < 0 || idx > arrlen) {
			cout << "Array index out of bound exception" << endl;
				exit(1);
		}
		return arr[idx];
	}
	int getArrlen() const { return arrlen; }
	~BoundCheckIntArray() { delete[] arr; }
};

class BoundCheck2DIntArray {
private:
	BoundCheckIntArray **arr;
	int arrlen;
	BoundCheck2DIntArray(const BoundCheck2DIntArray& arr) {}
	BoundCheck2DIntArray& operator=(const BoundCheck2DIntArray& arr) {}
public:
	BoundCheck2DIntArray(int n, int m) : arrlen(m){
		arr = new BoundCheckIntArray*[m];
		for (int i = 0; i < arrlen; i++)
			arr[i] = new BoundCheckIntArray(n);
	}
	BoundCheckIntArray& operator[](int idx) {
		if (idx < 0 || idx > arrlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return *(arr[idx]);
	}
	int getArrlen() const { return arrlen; }
	~BoundCheck2DIntArray() { 
		for (int i = 0; i < arrlen; i++)
			delete arr[i];
		delete[] arr; }
};

int main() {
	BoundCheck2DIntArray arr2d(3, 4);

	for (int n = 0; n < 3; n++) {
		for (int m = 0; m < 4; m++) {
			arr2d[n][m] = n + m;
		}
	}
	for (int n = 0; n < 3; n++) {
		for (int m = 0; m < 4; m++) {
			cout << arr2d[n][m] << ' ';
		}
		cout << endl;
	}

	return 0;
}