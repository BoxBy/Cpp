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
		lines = new string*[line_count]; // 동적할당
		counts = new int* [line_count];
		for (int i = 0; i < line_count; i++) {
			lines[i] = new string[word_count];
			counts[i] = new int[word_count];
		}
	}
/*
	void setlines(proverb temp) { // 재선언을 위한 복사함수
		cout << "word_count : " << word_count << "\nline_count : " << line_count << endl;
		for (int line = 0; line < line_count; line++)
			for (int word = 0; word < word_count; word++)
				lines[line][word] = temp.getProverb(line, word);
	}
	void setlines(string** temp) { // 재선언을 위한 복사함수2
		for (int line = 0; line < line_count; line++)
			for (int word = 0; word < word_count; word++)
				lines[line][word] = temp[line][word];
	}
*/
	string getProverb(int line, int word) {
		cout << "실행됨" << endl;
		return lines[line][word];
	}
	void in(string s) { // getline으로 받아옴
		int temp = 0, cnt = 0;
		for (int word = 0; word <= s.length(); word++) {
			if (s[word] == ' ' || s[word] == '.') { // 공백 있으면 단어가 끝났다는 뜻
//				if (temp >= word_count)
//					expandwords();
				lines[pointer][temp] = s.substr(word - cnt, cnt); // 단어 넣어줌
				if (lines[pointer][temp][lines[pointer][temp].size() - 1] == ';') // 세미콜론이 붙어있는 경우 떼줍니다
					lines[pointer][temp].back();
				compareCount(pointer, temp);
				cnt = 0;
				temp++;
			}
			else {// 공백 없으면 알파벳이라는 뜻
				cnt++;//그냥 넘어가면 됨
			}
		}
		for (; temp < word_count; temp++) {
			lines[pointer][temp].clear();
			counts[pointer][temp] = 0;
		}
		pointer++;
//		if (line_count == pointer) // 라인이 넘어가면
//			expandlines(); // 확장
	}
/*
	void expandwords(){ // 단어가 넘어가면 확장
		proverb temp = proverb(word_count, line_count);
		temp.setlines(lines);// 복사
		for (int line = 0; line < line_count; line++) // 제거
			delete[] lines[line];
		word_count *= 2;
		proverb(word_count, line_count); // 재생성
		setlines(temp);
	}
	void expandlines() { // 속담이 넘어가면 확장
		proverb temp = proverb(word_count, line_count); // 복사
		temp.setlines(lines);
		for (int line = 0; line < line_count; line++) // 제거
			delete[] lines[line];
		line_count *= 2;
		proverb(word_count, line_count); // 재생성
		setlines(temp);
	}
*/
	void compareCount(int line, int word) { // 개수 카운트
		counts[line][word] = 0;
		int l, w;
		for (l = 0; l < line; l++)
			for (w = 0; lines[line][w].size() != 0; w++)
				if (lines[line][word].compare(lines[l][w]) == 0) { // 같은 단어가 존재하면
					counts[line][word] = counts[l][w] + 1; // 카운트가 올라갑니다
					cout << " 같은 단어 등장 " << endl;
					cout << "counts[" << line << "][" << word << "] : " << counts[line][word] << " counts[" << l << "][" << w << "] : " << counts[l][w] << endl;
				}
		cout << endl;
		if (counts[line][word] == 0) // 같은 단어가 없으면
			counts[line][word] = 1; // 카운트가 1이 됩니다
	}

	void bigFive() {
		int fiveCount[5] = { 0 };
		string fiveWords[5];
		int i;
		for (int count = 0; count < 5; count++) {
			for (int line = 0; line < line_count; line++) {
				for (int word = 0; word < word_count; word++) { // 전부다 확인해보기
					if (counts[line][word] > fiveCount[count]) // 들어가 있는 값보다 크면
						for (i = 0; i < count; i++) // 들어있는 값들과 비교해봅니다
							if (lines[line][word].compare(fiveWords[i]) == 0) { // 같으면 루프문을 깨줍니다
								i = 6;
								break;
							}
					if (i != 6) { // i가 6이 아니라면, 들어있는 값들과 같은 단어가 없는겁니다
						fiveCount[count] = counts[line][word];
						fiveWords[count] = lines[line][word]; // 단어, 값 둘다 저장해줍니다
					}
				}
			}
		}
		for (int i = 0; i < 5; i++) // 출력해줍니다
			cout << i+1 << "번째 : " << fiveWords[i] << endl;
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
	try { // 해당 txt 파일이 없는 경우
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
