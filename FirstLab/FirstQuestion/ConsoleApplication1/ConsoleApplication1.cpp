#include <cstdio>
#include <random>
#include <time.h>
#include <cmath>
using namespace std;
//Выполнил: Брова Александр Сергеевич
//Группа ИВТ-5 (1-й уск)
// Объявить массив из n=20 вещественных чисел, проинициализировать нулями. Функция 
//processArray() должна заполнить массив случайными числами от - 20.0 до 70.0, а
//затем отнормировать массив, т.е.поделить каждый элемент массива на максимальное
//по модулю значение в массиве.Это значение она также должна вернуть на выходе.
//Сформировать выходной вещественный массив, в котором все элементы, стоящие до
//позиции максимального элемента включительно, повторяют элементы входного
//массива, а остальные равны x(число x ввести с клавиатуры).Вывести на экран
//результирующие массивы.
int processArray() {
	srand(time(0));
	float Array[20] = {};
	int maxMassElement = Array[0];
	float delArray[20] = {};
	
	float x = 0;
	float a = 1;
	for (int i = 0; i < 20; i++) 
	{
		Array[i] = -20 + rand() % +90;
		printf("%.0f", Array[i]);
		printf(" ");
			
		if (Array[i] > maxMassElement) {
			maxMassElement = Array[i];
		}
		
	}
	printf("\n");
	printf("Max mass element = ");
	printf("%d", maxMassElement);
	printf("\n");
	for (int i = 0; i < 20; i++) {
		delArray[i] = Array[i] / abs(maxMassElement);
		printf("%f", delArray[i]);
	}
	printf("\n");
	printf("Put number X \n");
	scanf_s("%f", &x);

	for (int i = 0; i < 20; i++) {
		
		if (delArray[i] == a) {
			delArray[i] = x;
			for (int i = 0; i < 20; i++) {
				delArray[i] = x;
			}
		}
		else
		{
			printf("%.2f" " ",delArray[i]);
		}
		
		
	}
	
	return 0;
}

int main() {
	processArray();
}
