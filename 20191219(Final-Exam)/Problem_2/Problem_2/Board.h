#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <time.h>

using namespace std;

class Board {
private:
	char data[15][15];
	string direction[20];
	int location[20][2];
public:
	Board();
	char getSpot(int row, int col);
	void setSpot(char val, int row, int col);
	string getDir(int i);
	void setDir(string dir, int i);
	int getLoc(int i, int j);
	void setLoc(int val, int i, int j);
	void placeList(vector<string>& list);
	void printBoard(vector<string>& list);
	string Anagram(string dir);
	char isCorrect(string dir, int row, int col);
	bool isHor(string dir, int row, int col);
	void push(string dir, string str, int row, int col, int count);
};
