#pragma once
#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;

class Kmeans {
private:
	double **array;
	int* group;
	int K;
	double J;
	double** Kvalue;
	string* word;
	string* dict;
public:
	Kmeans(int cluster);
	void resetK();
	void setK();
	void setArray(ifstream& Matrix);
	void setValue(ifstream& Dict);
	void setJ();
	double getJ();
	double clustering();
	int getK();
	void print(double** result);
	string clear(string dict);
	double distance(double* k, double** dest, int i);
	double* groupSum(double* k, double** value, int i);
	double groupMulSum(double** value, int i, int k);
};