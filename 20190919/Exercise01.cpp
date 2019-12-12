#include <iostream>
using namespace std;

namespace X {
	int i, j, k;
}

int k;

void f1() {
	using namespace X;
	i++;
	j++;
	k++;

	X::k++;
	::k++;

}

void f2() {
	int i = 0;

	using X::i;
	//X::i++;
	i++;

	using X::j;
	using X::k;
	j++;
	k++;
}

int main() {
	f1();
	cout << "i, j, k in namespace X : " << X::i << X::j << X::k << endl;
	cout << "Global variable k : " << ::k << endl << endl;
	f2();
	cout << "i, j, k in namespace X : " << X::i << X::j << X::k << endl;

	return 0;
}