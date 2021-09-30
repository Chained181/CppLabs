#include <iostream>
#include <random>
using namespace std;

void processArray() {
	char s1[30], s2[30];

	cout << "Write first string"<< endl;
	cin >> s1;
	cout << "Write second string" << endl;
	cin >> s2;
	cout << "Writed strings: " << endl;
	cout << s1 << endl;
	cout << s2 << endl;
	//int strcmp(const char* s1, const char* s2);
	int flag = strcmp(s1, s2);
	if (flag == 0)
	{
		cout << "Writed strings are similar"<< endl;
	}
	else if ( flag > 0)
	{
		cout << "First writed string are larger";
	}
	else if (flag < 0)
	{
		cout << "Second writed strind are larger";
	}
	cin.get();
}

int main() {
	processArray();
}