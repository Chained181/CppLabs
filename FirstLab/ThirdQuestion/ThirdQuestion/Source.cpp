#include <iostream>

//������� strcmp.
//������ int strcmp(const char* s1, const char* s2).
//������� ���������� ������ s1 �� ������� s2 � ������������������ �������.���� s1<s2,
//	�� ��������� ����� - 1, ���� s1 = s2, �� 0, ���� s1>s2, �� 1

void processArray() {
	char s1[30], s2[30];

	std::cout << "Write first string"<< std::endl;
	std::cin >> s1;
	std::cout << "Write second string" << std::endl;
	std::cin >> s2;
	std::cout << "Writed strings: " << std::endl;
	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
	
	int strcmp(const char* s1, const char* s2);

	if (strcmp(s1,s2) == 0) {
		std::cout << "Writed strings are similar" << std::endl;
	}
	else if (strcmp(s1, s2) > 0)
	{
		std::cout << "First writed string are larger";
	}
	else if (strcmp(s1,s2) < 0)
	{
		std::cout << "Second writed strind are larger";
	}

	std::cin.get();
}

int main() {
	processArray();
}