#include "Board.h"

Board::Board()
{
	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 15; j++)
			data[i][j] = 0;
	
	for (int i = 0; i < 20; i++) {
		direction[i] = '0';
		location[i][0] = 0;
		location[i][1] = 0;
	}

}

char Board::getSpot(int row, int col){ return data[row][col]; }

void Board::setSpot(char val, int row, int col){ data[row][col] = val; }

string Board::getDir(int i){ return direction[i]; }

void Board::setDir(string dir, int i){ direction[i] = dir; }

int Board::getLoc(int i, int j){ return location[i][j]; }

void Board::setLoc(int val, int i, int j){ location[i][j] = val; }

void Board::placeList(vector<string>& list)
{
	vector<string>::const_iterator it = list.begin();

	string temp = *it;
	int i = 0, j = 0;

	j = 7 - (int)(temp.size() / 2);

	for (i = 0; i < temp.size(); i++) { // first string
		setSpot(temp[i], 7, j);
		j++;
	}

	setDir("Horizontal", 0);

	it++;

	int count = 1;
	
	while (it != list.end()) {
		temp = *it;

		for (j = 0; j < 15; j++) {
			for (i = 0; i < 15; i++) {
				if (isCorrect(temp, i, j) != 0) {
					if (isHor(temp, i, j) == true)
						push("Horizontal", temp, i, j, count);
					else
						push("Vertical", temp, i, j, count);
				}
			}
		}
	}
}

void Board::printBoard(vector<string>& list) // 추가적으로 필요한 멤버 변수 작성 가능
{
	vector<string>::const_iterator it = list.begin();

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++)
			cout << data[i][j] << " ";
		cout << endl;
	}
	cout << setw(40) << setfill("-") << endl;
	cout << "Hint" << endl << endl;

	cout << left << setw(14) << "Location" << setw(14) << "Direction" << setw(14) << "Word" << setw(14) << "Anagram" << endl;
	cout << setw(56) << setfill("=") << endl;

	for (int i = 0; i < 20; i++) {
		cout << setw(14) << "( " << getLoc(i, 0) << ", " << getLoc(i, 1) << " )";
		cout << setw(14) << getDir(i);
		cout << setw(14) << *it;
		cout << setw(14) << Anagram(*it);
		it++;
	}
	cout << setw(56) << setfill("=") << endl;
}

string Board::Anagram(string dir) {
	string temp;
	char tempCh;
	int size = dir.size();
	int count = 0;
	while (count == size) {
		tempCh = dir[rand() % size];
		if (tempCh == ' ')
			continue;
		temp[count] = tempCh;
		count++;
	}
	return temp;
}

char Board::isCorrect(string dir, int row, int col) {
	for (int i = 0; i < dir.size(); i++) {
		if (dir[i] == getSpot(row, col))
			return i;
	}
	return 0;
}

bool Board::isHor(string dir, int row, int col) { // if True = Hor, False = Ver
	char Hor[15] = { 0 };
	char Ver[15] = { 0 };
	bool result = true;

	for (int i = 0; i < 15; i++)
		Hor[i] = getSpot(row, i);

	for (int i = 0; i < 15; i++)
		Ver[i] = getSpot(i, col);

	for (int i = row - isCorrect(dir, row, col); i < 15; i++) { // is Vertical
		if (Ver[i] != 0)
			result = false;
	}

	if (result == false) {
		for (int i = col - isCorrect(dir, row, col); i < 15; i++) // is Horizontal
			if (Hor[i] != 0)
				return result;
		return true;
	}

	return result;
}

void Board::push(string dir, string str, int row, int col, int count) {
	setDir(dir, count);

	if (dir == "Horizontal") {

	}

	else if (dir == "Vertical") {
	}
}