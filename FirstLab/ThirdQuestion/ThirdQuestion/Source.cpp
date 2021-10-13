#include <iostream>

//Функция strcmp.
//Формат int strcmp(const char* s1, const char* s2).
//Функция сравнивает строку s1 со строкой s2 в лексикографическом порядке.Если s1<s2,
//	то результат равен - 1, если s1 = s2, то 0, если s1>s2, то 1

int checkString(char str1[], char str2[])
{

	for (int i = 0; i < 30; i++) {
		if (str1[i] == str2[i])return 0;
		if (str1[i] > str2[i]) return 1;
		if (str1[i] < str2[i]) return -1;

	}

}

void processArray() {
	char str1[30], str2[30];

	std::cout << "Write first string"<< std::endl;
	std::cin >> str1;
	std::cout << "Write second string" << std::endl;
	std::cin >> str2;
	std::cout << "Writed strings: " << std::endl;
	std::cout << str1 << std::endl;
	std::cout << str2 << std::endl;
	
	

	if (checkString(str1,str2) == 0 ){
		std::cout << "Writed strings are similar" << std::endl;
	}
	else if (checkString(str1,str2) == 1)
	{
		std::cout << "First writed string are larger";
	}
	else if (checkString(str1,str2) == -1)
	{
		std::cout << "Second writed strind are larger";
	}


	std::cin.get();
}





int main() {
	processArray();
}