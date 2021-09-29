#include <iostream>
#include <random>
#include <time.h>
#include <cmath>
using namespace std;

void processArray() {
	srand(time(0));
	float Array[20] = {};
	int maxMassElement = Array[0];
	float delArray[20] = {};
	
	float x;
	float a = 1;
	for (int i = 0; i < 20; i++) 
	{
		Array[i] = -20 + rand() % +90;
		cout<< Array[i] << " ";
		
		if (Array[i] > maxMassElement) {
			maxMassElement = Array[i];
		}
		
	}
	cout<< " \n";
	cout << "Max mass Element = " << maxMassElement << "\n";
	for (int i = 0; i < 20; i++) {
		delArray[i] = Array[i] / abs(maxMassElement);
		cout << delArray[i] << " ";
	}
	cout << "\n";
	cout << "Put number X"<< "\n";
	cin >> x;
	cout << "\n";

	for (int i = 0; i < 20; i++) {
		
		if (delArray[i] == a) {
			delArray[i] = x;
			
			for (int i = 0; i < 20; i++) {
				delArray[i] = x;
			}
			cout << delArray[i] << " ";
		}
		else
		{
			cout << delArray[i] << " ";
		}
		
		
	}
	
	
}

int main() {
	processArray();
}
