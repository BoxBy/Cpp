#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define PUSH_FRONT 1
#define PUSH_BACK 2
#define POP_FRONT 3
#define POP_BACK 4
#define SIZE 5
#define EMPTY 6
#define FRONT 7
#define BACK 8

int switch_on(string str) {
	if (!str.compare(0, 3, "push")) {//push老 版快
		if (!str.compare(5, 9, "front"))
			return PUSH_FRONT;
		else
			return PUSH_BACK;
	}
	else if (!str.compare(0, 2, "pop")) { // pop老 版快
		if (!str.compare(4, 8, "front"))
			return POP_FRONT;
		else
			return POP_BACK;
	}
	else if (!str.compare("size"))
		return SIZE;
	else if (!str.compare("empty"))
		return EMPTY;
	else if (!str.compare("front"))
		return FRONT;
	else if (!str.compare("back"))
		return BACK;
	else
		return 0;
}


int pushNum(string str, int num) {
	if (num == PUSH_FRONT)
		return stoi(str.substr(11, str.length() - 11), nullptr, 10);
	else
		return stoi(str.substr(10, str.length() - 10), nullptr, 10);
}

int main() {
	vector<int> deque;
	int temp;
	string command;

	cout << "First push : ";
	cin >> temp;
	deque.push_back(temp);

	while (true) {
		int num = 0;
		cout << "Next Command : ";
		cin >> command;
		temp = switch_on(command);
		if (temp == PUSH_FRONT || temp == PUSH_BACK) {
			cin >> num;
			cout << "PUSH" << endl;
		}
		switch (temp)
		{
		case PUSH_FRONT:
			deque.insert(deque.begin(), num);
			break;
		case PUSH_BACK:
			deque.push_back(num);
			break;
		case POP_FRONT:
			if (deque.empty() == true)
				num = -1;
			else {
				num = deque.front();
				deque.erase(deque.begin());
			}
			break;
		case POP_BACK:
			if (deque.empty() == true)
				num = -1;
			else {
				num = deque.back();
				deque.pop_back();
			}
			break;
		case SIZE:
			num = deque.size();
			break;
		case EMPTY:
			if (deque.empty() == true)
				num = 1;
			else
				num = 0;
			break;
		case FRONT:
			if (deque.empty() == true)
				num = -1;
			else
				num = deque.front();
			break;
		case BACK:
			if (deque.empty() == true)
				num = -1;
			else
				num = deque.back();
			break;
		default:
			break;
		}
		cout << num << endl;
	}
}
