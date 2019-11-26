#include "Kmeans.h"

Kmeans::Kmeans(int cluster) {

	K = cluster;
	Kvalue = new double* [cluster];
	for (int i = 0; i < cluster; i++) {
		Kvalue[i] = new double[4423];
	}
	J = 0;

	array = new double*[4423];
	group = new int[500];
	for (int i = 0; i < 4423; i++) {
		array[i] = new double [500];
		for (int j = 0; j < 500; j++)
			group[j] = 0;
	}
	word = new string[4423];
	dict = new string[500];
}
void Kmeans::resetK() {

	for (int k = 0; k < K; k++) {
		int j = rand() % 500;
		for (int i = 0; i < 4423; i++)
			Kvalue[k][i] = array[i][j]; // Kvalue �ʱ�ȭ
	}
	for (int j = 0; j < 500; j++)
		group[j] = 0;

}
void Kmeans::setK()
{
	int* count = new int[K];

	double** temp = new double*[K];
	for (int i = 0; i < K; i++) {
		temp[i] = new double[4423];
		count[i] = 0;
		for (int j = 0; j < 4423; j++)
			temp[i][j] = 0;
	}

	for (int j = 0; j < 500; j++) {
		for (int k = 0; k < K; k++)
			if (group[j] == k) {
				groupSum(temp[k], array, j);
				count[k] += 1;
			}
		if (j % 100 == 0)
			cout << ".";
	}
	
	for (int k = 0; k < K; k++)
		for(int i = 0; i < 4423; i++)
			Kvalue[k][i] = temp[k][i] / count[k];

	for (int i = 0; i < K; i++) {
		delete[] temp[i];
	}
	delete[] temp;
	delete[] count;

}
void Kmeans::setArray(ifstream& Matrix) {
	cout << "including termDicMatrix.txt";
	for (int i = 0; i < 4423; i++) {
		if (i % 1000 == 0)
			cout << ".";
		for (int j = 0; j < 500; j++)
			Matrix >> array[i][j];
	}
	cout << "Complete" << endl;
}

void Kmeans::setValue(ifstream& Dict) {
	cout << "including wordDict-docTitle.txt";
	string temp;
	Dict >> temp;
	Dict >> temp;
	Dict >> temp;
	for (int i = 0; i < 4423; i++) {
		if (i % 2000 == 0)
			cout << ".";
		Dict >> temp;
		word[i] = clear(temp);
	}
	cout << ".";
	Dict >> temp;
	Dict >> temp;
	Dict >> temp;
	Dict >> temp;
	for (int i = 0; i < 500; i++) {
		if (i % 200 == 0)
			cout << ".";
		Dict >> temp;
		dict[i] = clear(temp);
	}
	cout << "Complete" << endl;

}
void Kmeans::setJ()
{
	cout << "setting K";
	setK();
	cout << "Complete" << endl;
	cout << "setting J";
	double temp = 0;

	for (int j = 0; j < 500; j++) {
		for (int k = 0; k < K; k++) {
			temp += groupMulSum(array, j, (int)group[j]);
		}
		if (j % 100 == 0)
			cout << ".";
	}

	J = temp / 500;
	cout << "Complete" << endl;
}

double Kmeans::getJ(){	return J; }
double Kmeans::clustering()
{

	cout << "Clustering Start";

	double*** name = new double** [K]; // K��
	for (int i = 0; i < K; i++) {
		name[i] = new double* [5]; // 5�� �����ؼ� ���
		for (int j = 0; j < 5; j++) {
			name[i][j] = new double[2]; // Distance DictNum ������ ��
			name[i][j][0] = 1;
			name[i][j][1] = -1;
		}
	}
	double temp, dicttemp = 1;
	int ktemp = 0;

	for (int j = 0; j < 500; j++){
		temp = 1;
		for (int k = 0; k < K; k++) {
			if (distance(Kvalue[k], array, j) < temp || k == 0) {// ���̰� ���� ª������ ã�Ƽ� �ӽ÷� �ִ´�
				temp = distance(Kvalue[k], array, j); // ���� �ӽ� ����
				ktemp = k; // K�� �ӽ� ����
			}
		}
		group[j] = ktemp; // group�� K�� �־��ְ�
		dicttemp = j; //���°���� �ӽ� �������ְ�
		for (int l = 0; l < 5; l++) // �־�����, ���� ������� Ȯ���ϰ� �־��ش�
			if (name[ktemp][l][0] > temp) {
				swap(dicttemp, name[ktemp][l][1]); // ���� ����
				swap(temp, name[ktemp][l][0]); // ���� ����
			}
		if (j % 100 == 0)
			cout << ".";
	}
	
 // �� ���� ������� K�� J�� ���Ѵ�

	cout << "Complete" << endl;

	setJ();

	cout << "Top 5 Dicts" << endl;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < K; j++)
			if ((int)name[j][i][1] == -1)
				cout << setw(30);
			else
				cout << setw(30) << name[j][i][0]; // �Ÿ��� ���;� �ǰ�
		cout << endl;
		for (int j = 0; j < K; j++)
			if ((int)name[j][i][1] == -1)
				cout << setw(30);
			else
				cout << setw(30) << dict[(int)name[j][i][1]];
		cout << endl;
	}



	for (int i = 0; i < K; i++) {
		for (int j = 0; j < 5; j++)
			delete[] name[i][j];
		delete[] name[i];
	}
	delete[] name;

	return J;
}
int Kmeans::getK() {return K;}
void Kmeans::print(double** result)
{
	int i = 0;
	for (int i = 0; i < 10; i++){
		resetK();
		for (int j = 0; j < 20; j++) {
			cout << endl;
			cout << endl;
			cout << j + 1 << "th Clustering" << endl;
			result[i][j] = clustering();
		}
	}
}
string Kmeans::clear(string dict) { // " �����ִ� �Լ�
	string temp;
	for (unsigned int i = 1; i <= dict.length()-2; i++)
		temp += dict[i];
	return temp;
}

double Kmeans::distance(double* k, double** dest, int i) {
	double temp = 0;
	for (int j = 0; j < 4423; j++)
		temp += pow(k[j] - dest[j][i], 2);
	return temp; 
}

double* Kmeans::groupSum(double* k, double** value, int i) // k = K��, value = �߰��� ��
{
	for (int j = 0; j < 4423; j++)
		k[j] += value[j][i];
	return k;
}

double Kmeans::groupMulSum(double** value, int i, int k)
{
	double temp = 0;
	for (int j = 0; j < 4423; j++)
		temp += pow(value[j][i] - Kvalue[k][j], 2);
	return temp;
}

