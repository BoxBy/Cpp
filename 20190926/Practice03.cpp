#include <iostream>
#include <exception>
#include <fstream>
#include <string>

using namespace std;

class proverb {
private:
	string** lines;
	int** counts;
	int word_count;
	int line_count;
	int pointer = 0;

public:
	proverb(int word, int line) {
		word_count = word;
		line_count = line;
		lines = new string*[line_count]; // �����Ҵ�
		counts = new int* [line_count];
		for (int i = 0; i < line_count; i++) {
			lines[i] = new string[word_count];
			counts[i] = new int[word_count];
		}
	}
/*
	void setlines(proverb temp) { // �缱���� ���� �����Լ�
		cout << "word_count : " << word_count << "\nline_count : " << line_count << endl;
		for (int line = 0; line < line_count; line++)
			for (int word = 0; word < word_count; word++)
				lines[line][word] = temp.getProverb(line, word);
	}
	void setlines(string** temp) { // �缱���� ���� �����Լ�2
		for (int line = 0; line < line_count; line++)
			for (int word = 0; word < word_count; word++)
				lines[line][word] = temp[line][word];
	}
*/
	string getProverb(int line, int word) {
		cout << "�����" << endl;
		return lines[line][word];
	}
	void in(string s) { // getline���� �޾ƿ�
		int temp = 0, cnt = 0;
		for (int word = 0; word <= s.length(); word++) {
			if (s[word] == ' ' || s[word] == '.') { // ���� ������ �ܾ �����ٴ� ��
//				if (temp >= word_count)
//					expandwords();
				lines[pointer][temp] = s.substr(word - cnt, cnt); // �ܾ� �־���
				if (lines[pointer][temp][lines[pointer][temp].size() - 1] == ';') // �����ݷ��� �پ��ִ� ��� ���ݴϴ�
					lines[pointer][temp].back();
				compareCount(pointer, temp);
				cnt = 0;
				temp++;
			}
			else {// ���� ������ ���ĺ��̶�� ��
				cnt++;//�׳� �Ѿ�� ��
			}
		}
		for (; temp < word_count; temp++) {
			lines[pointer][temp].clear();
			counts[pointer][temp] = 0;
		}
		pointer++;
//		if (line_count == pointer) // ������ �Ѿ��
//			expandlines(); // Ȯ��
	}
/*
	void expandwords(){ // �ܾ �Ѿ�� Ȯ��
		proverb temp = proverb(word_count, line_count);
		temp.setlines(lines);// ����
		for (int line = 0; line < line_count; line++) // ����
			delete[] lines[line];
		word_count *= 2;
		proverb(word_count, line_count); // �����
		setlines(temp);
	}
	void expandlines() { // �Ӵ��� �Ѿ�� Ȯ��
		proverb temp = proverb(word_count, line_count); // ����
		temp.setlines(lines);
		for (int line = 0; line < line_count; line++) // ����
			delete[] lines[line];
		line_count *= 2;
		proverb(word_count, line_count); // �����
		setlines(temp);
	}
*/
	void compareCount(int line, int word) { // ���� ī��Ʈ
		counts[line][word] = 0;
		int l, w;
		for (l = 0; l < line; l++)
			for (w = 0; lines[line][w].size() != 0; w++)
				if (lines[line][word].compare(lines[l][w]) == 0) { // ���� �ܾ �����ϸ�
					counts[line][word] = counts[l][w] + 1; // ī��Ʈ�� �ö󰩴ϴ�
					cout << " ���� �ܾ� ���� " << endl;
					cout << "counts[" << line << "][" << word << "] : " << counts[line][word] << " counts[" << l << "][" << w << "] : " << counts[l][w] << endl;
				}
		cout << endl;
		if (counts[line][word] == 0) // ���� �ܾ ������
			counts[line][word] = 1; // ī��Ʈ�� 1�� �˴ϴ�
	}

	void bigFive() {
		int fiveCount[5] = { 0 };
		string fiveWords[5];
		int i;
		for (int count = 0; count < 5; count++) {
			for (int line = 0; line < line_count; line++) {
				for (int word = 0; word < word_count; word++) { // ���δ� Ȯ���غ���
					if (counts[line][word] > fiveCount[count]) // �� �ִ� ������ ũ��
						for (i = 0; i < count; i++) // ����ִ� ����� ���غ��ϴ�
							if (lines[line][word].compare(fiveWords[i]) == 0) { // ������ �������� ���ݴϴ�
								i = 6;
								break;
							}
					if (i != 6) { // i�� 6�� �ƴ϶��, ����ִ� ����� ���� �ܾ ���°̴ϴ�
						fiveCount[count] = counts[line][word];
						fiveWords[count] = lines[line][word]; // �ܾ�, �� �Ѵ� �������ݴϴ�
					}
				}
			}
		}
		for (int i = 0; i < 5; i++) // ������ݴϴ�
			cout << i+1 << "��° : " << fiveWords[i] << endl;
	}

	void memoryFree() {
		for (int i = 0; i < line_count; i++) {
			delete[] counts[i];
			delete[] lines[i];
		}
		delete[] lines;
		delete[] counts;
	}
};


int main() {
	ifstream inFile;
	string temp;
	proverb Proverbs = proverb(50, 100);
	try { // �ش� txt ������ ���� ���
		inFile.open("test.txt");
		getline(inFile, temp);
	}
	catch (ifstream::failure e) {
		cout << "Exception opening/reading file" << '\n';
	}

	do {
		Proverbs.in(temp);
	} while (getline(inFile, temp));

	Proverbs.bigFive();
	Proverbs.memoryFree();
	return 0;
}
