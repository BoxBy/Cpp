class MyString {
private:
	char* string_content; // string 내용
	int string_length; // string 길이
	int memory_capacity; // 메모리 크기
public:
	MyString() // default constructor
	{
		string_content = new char[0];
		string_length = 0;
		memory_capacity = 0;
	}
	MyString(const char* str) // 문자열 생성자
	{
		string_length = strlen(str);
		string_content = new char[string_length];
		memory_capacity = string_length;

		for (int i = 0; i != string_length; i++)
			string_content[i] = str[i];
	}
	MyString(const MyString& str) // 복사 생성자
	{
		string_length = str.string_length;
		memory_capacity = string_length;
		string_content = new char[string_length];
		for (int i = 0; i != string_length; i++)
			string_content[i] = str.string_content[i];
	}
	~MyString() // delete[] string_content
	{
		delete[] string_content;
	}


	void setString(const char* str) // string일 경우 set
	{
		string_length = strlen(str);
		string_content = new char[string_length];
		memory_capacity = _msize(string_content);
		for (int i = 0; i != string_length; i++)
			string_content[i] = str[i];
	}

	MyString getMyString() const // return MyString class
	{
		MyString temp;
		temp.setString(string_content);
		return temp;
	}
	char* getString() const // return string_content
	{
		return string_content;
	}
	int length() const // return string length
	{
		return string_length;
	}
	int capacity() const // return memory_capacity
	{
		return memory_capacity;
	}
	void reserve(int size) // 할당할 문자열 크기 reserve, 예약
	{
		char* temp = string_content;
		if (memory_capacity < size){
			string_content = new char[size];
			for (int i = 0; i < size; i++)
				string_content[i] = temp[i];
			memory_capacity = _msize(string_content);
		}
		if (temp)
			delete[] temp;
	}

	void println() const // 출력 함수
	{
		for (int i = 0; i != string_length; i++)
			std::cout << string_content[i];
		std::cout << std::endl;
	}

	// 문자, 문자열 변경
	MyString& assign(const MyString& str)
	{
		if (str.length() > memory_capacity)
			reserve(str.length());
	}
	MyString& assign(const char* str)
	{
		if (strlen(str) > memory_capacity)
			reserve(strlen(str));
	}

	char at(int i) const // i 위치 문자 리턴
	{
		return string_content[i];
	}
	// 문자열 삽입
	MyString& insert(int loc, const MyString& str)
	{
		if (loc < 0 || loc > string_length) return *this;
		if (string_length + str.string_length > memory_capacity) {
			memory_capacity = string_length + str.string_length;
			char* prev_string_content = string_content;
			string_content = new char[memory_capacity];
			int i;
			for (i = 0; i < loc; i++)
				string_content[i] = prev_string_content[i];

			for (int j = 0; j != str.string_length; j++)
				string_content[i + j] = str.string_content[j];

			for (; i < string_length; i++)
				string_content[str.string_length + i] = prev_string_content[i];

			delete[] prev_string_content;

			string_length = string_length + str.string_length;
			return *this;
		}

		for (int i = string_length - 1; i >= loc; i--)
			string_content[i + str.string_length] = string_content[i];

		for (int i = 0; i < str.string_length; i++)
			string_content[i + loc] = str.string_content[i];

		string_length = string_length + str.string_length;
		return *this;
	}

	MyString& insert(int loc, const char* str)
	{
		MyString temp(str);
		return insert(loc, temp);
	}


	int find(int find_from, const MyString& str) const
	{
		int count, incount;
		if (str.string_length == 0) return -1;
		for (count = find_from; count < string_length - str.string_length; count++) {
			for (incount = 0; incount < str.string_length; incount++) {
				if (string_content[count + incount] != str.string_content[incount]) break;
			}

			if (incount == str.string_length) return count;
		}

		return -1;
	}

	int find(int find_from, const char* str) const
	{
		MyString temp(str);
		return find(find_from, temp);
	}

	//삭제
	MyString& erase(int loc, int num) {
		if(num < 0 || loc < 0 || loc > string_length)
			return *this;

		for (int i = loc + num; i < string_length; i++)
			string_content[i - num] = string_content[i];

		string_length -= num;
		return *this;
	}
};