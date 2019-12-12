#include <iostream>
#include <string>

using namespace std;

class stepws2 {
private:
	static string count;
public:
	stepws2(string s) {
		if (s == "")
			count.clear();
		else
			count += s;
	}

	friend ostream& operator<<(ostream&, stepws2);
};

string stepws2::count = "";

ostream& operator<<(ostream& out, stepws2 manip) {
	return out << stepws2::count;
}

ostream& stepws(ostream& out) {
	static string count;
	count += " ";
	return out << count;
}

int main() {
	cout << 10 << endl;
	cout << stepws << 20 << endl;
	cout << stepws << 30 << endl;
	cout << stepws << 40 << endl;
	cout << 50 << endl;
	cout << stepws << 60 << endl;
	cout << stepws << 70 << endl;

	cout << endl << endl;
	cout << 10 << endl;
	cout << stepws2("#") << 20 << endl;
	cout << stepws2("#") << 30 << endl;
	cout << stepws2("$") << 40 << endl;
	cout << stepws2("") << 50 << endl;
	cout << stepws2("*") << 60 << endl;
	cout << stepws2("$") << 70 << endl;

	system("pause");
	return 0;
}	