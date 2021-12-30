#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>
#include "Vector.cpp"
#include "Matrix.cpp"
#include "Fraction.h"
#include "Artist.h"
#include "ArraySorter.cpp"

//#define inline_function(params) \
//class \
//{ \
//    public: void operator() (params)\
//    {\
//
//#define with_name(value) \
//    }\
//} value;
//
//#define with_params(...) __VA_ARGS__

int main()
{
	const int row = 4, cell = 4;
	int num1 = 0, num2 = 0;
	char cf[] = "1/2";

	/* 
			Задание 1
				Написать классы Vector и Matrix для хранения и обработки одномерных и
			двумерных массивов, соответственно. Реализовать задание 2 лабораторной работы №1
			с помощью созданных классов. Все функции оформить в виде методов классов.
			В коде отразить следующее:
				1. Выделение и освобождение динамической памяти производить в конструкторах и
			деструкторах классов, соответственно.
				2. В классе Vector перегрузить оператор индексации []. В классе Matrix добавить
			методы T at(int i, int j) const и setAt(int i, int j, T val), которые
			позволяют получить и установить значение элемента массива с индексом [i][j], T –
			это тип элементов массива по варианту (int или double).
				3. Перегрузить операторы инкремента и декремента (как префиксного, так и
			постфиксного). Смысл инкремента / декремента всего массива заключается в
			инкременте / декременте каждого элемента массива.
	*/
	std::cout << std::endl << "Task 1: " << std::endl;
	{
		Matrix<float> tdArray = Matrix<float>::getMatrix(row, cell);

		std::cout << "\nMatrix: " << std::endl;
		for (size_t i = 0; i < tdArray.getRows(); i++)
		{
			for (size_t j = 0; j < tdArray.getCells(); j++)
			{
				std::cout << round(tdArray[i][j] * 100) / 100 << "\t";
			}
			std::cout << std::endl;
		}

		std::cout << "\Vector: " << std::endl;

		Vector<float> arr = Vector<float>::getConvertMatrix(tdArray, row, cell);

		for (size_t i = 0; i < row * cell; i++)
		{
			std::cout << round(arr[i] * 10000) / 10000 << " ";
		}
	}
	/* Task 2
			Написать класс Fraction для представления обыкновенных дробей (как отношения
			двух целых чисел x/y). 
				Перегрузить операторы +, -, *, / для дробей. 
				Реализовать метод void reduce() для сокращения дроби, а также статические методы:
				int gcd(int n, int m) функция для нахождения наибольшего общего делителя чисел n и m;
				void printAsFraction(double decimal_fraction)
				void printAsFraction(char* decimal_fraction)
			перегруженные методы вывода десятичной дроби в виде обыкновенной
			(например, при значении decimal_fraction = 0.43 на экране должно
			вывестись 43/100, при 0.25 – 1/4 и т.д.).
				Также реализовать в виде статического члена класса счетчик всех созданных на
			данный момент в программе экземпляров дробей.
				Продемонстрировать работу созданного класса. Создать несколько объектов дробей.
				Произвести операции сложения, вычитания, умножения и деления дробей. Вывести
			на экран результаты. Показать также результаты работы статических методов класса
	*/
	std::cout << std::endl << "\nTask 2: " << std::endl;
	{
		std::cout << "\n\nEnter first fraction: " << std::endl;
		std::cin >> num1;
		std::cout << "-\n";
		std::cin >> num2;
		Fraction f1(num1, num2);

		std::cout << "\nEnter second fraction: " << std::endl;
		std::cin >> num1;
		std::cout << "-\n";
		std::cin >> num2;
		Fraction f2(num1, num2);

		std::cout << "\nCount of fraction: " << Fraction::countF() << std::endl;
		std::cout << "Common division " << Fraction::gcd(num1, num2) << std::endl;

		std::cout << "Division: " << f1 / f2 << std::endl;
		std::cout << "Multiply: " << f1 * f2 << std::endl;
		std::cout << "Difference: " << f1 - f2 << std::endl;
		std::cout << "Sum: " << f1 + f2 << std::endl;

		Fraction::printAsFraction(f1 / f2);

		Fraction::printAsFraction(1.44);

		Fraction::printAsFraction(cf);
	}
	/* Task 3
			Написать собственный класс, в соответствии с вариантом. Продемонстрировать в коде
		инкапсуляцию данных, применение конструкторов без параметров и с параметрами
		для инициализации данных. 
			Класс должен содержать метод serialize() для
		сохранения данных класса в файл и метод deserialize() для чтения данных класса
		из файла по умолчанию в текущей директории, а также перегруженные методы
		serialize(const std::string& filename) и deserialize(const std::string&
		filename) для работы с файлом с указанным в параметре именем.
 
		Класс МУЗЫКАНТ.
			Данные: имя, фамилия, пол, год рождения, инструмент, рейтинг.
			Создать трех музыкантов в стеке и одного в куче. Данные первых трех заполнить с
		помощью сеттеров, а четвертый проинициализировать с помощью конструктора с
		параметрами. 
			В главной функции проимитировать три концерта и голосование
		зрителей по их результатам (нарастить рейтинг каждого музыканта на случайное число
		из диапазона 1..5). 
			Вывести список музыкантов в порядке убывания суммарного
		рейтинга, но клавишники должны идти впереди, независимо от рейтинга .
	*/
	std::cout << std::endl << "\nTask 3: " << std::endl;
	{
		setlocale(LC_ALL, "rus");

		enum Rating {
			VeryNice = 5, Good = 4, WellDone = 3, NotVery = 2, Boo = 1
		};
		std::string conc[] = { "Rostov", "Moscow", "Gorlovka" };

		void (*setprop)(Artist * obj, std::string name, std::string sname,
			std::string gender, std::string instrument, int yo, int rating) {
			[](Artist* obj, std::string name, std::string sname,
				std::string gender, std::string instrument, int yo, int rating) {
					obj->set_firstName(name);
					obj->set_secondName(sname);
					obj->set_gender(gender);
					obj->set_musicalInstrument(instrument);
					obj->set_rating(rating);
					obj->set_yearOld(yo);
			}
		};

		int (*rating)(std::map<Rating, int> & rating) {
			[](std::map<Rating, int>& rating) {
				return rating[Rating::VeryNice] +
					rating[Rating::Good] +
					rating[Rating::WellDone] +
					rating[Rating::NotVery] +
					rating[Rating::Boo];
			}
		};

		int (*concertRate)(std::map<std::string, Rating> & concert) {
			[](std::map<std::string, Rating>& concert) {
				return concert["Rostov"] +
					concert["Moscow"] +
					concert["Gorlovka"];
			}
		};

		std::cout << "\nRating first artist: " << std::endl;

		std::map<std::string, Rating> concertArtist1{
			{"Rostov", static_cast<Rating>(rand() % VeryNice)},
			{"Moscow", static_cast<Rating>(rand() % VeryNice)},
			{"Gorlovka", static_cast<Rating>(rand() % VeryNice)}
		};

		Artist a1("Nikita", "Kislov", "Guitar", "Male", concertRate(concertArtist1), 21);

		for (int i = 0; i < (sizeof(conc) / sizeof(*conc)); i++)
			std::cout << conc[i] << " rating: " << concertArtist1[conc[i]] << std::endl;

		std::cout << "\nRating second artist: " << std::endl;

		std::map<std::string, Rating> concertArtist2{
			{"Rostov", static_cast<Rating>(rand() % VeryNice)},
			{"Moscow", static_cast<Rating>(rand() % VeryNice)},
			{"Gorlovka", static_cast<Rating>(rand() % VeryNice)}
		};

		a1.serialize();

		Artist a2("Ivan", "Grachev", "Pianino", "Male", concertRate(concertArtist2), 20);

		for (int i = 0; i < (sizeof(conc) / sizeof(*conc)); i++)
			std::cout << conc[i] << " rating: " << concertArtist2[conc[i]] << std::endl;

		std::cout << "\nRating third artist: " << std::endl;

		std::map<std::string, Rating> concertArtist3{
			{"Rostov", static_cast<Rating>(rand() % VeryNice)},
			{"Moscow", static_cast<Rating>(rand() % VeryNice)},
			{"Gorlovka", static_cast<Rating>(rand() % VeryNice)}
		};

		Artist* a3 = new Artist();

		setprop(a3, "Alexander", "Kamod", "Male", "Bass", 25, concertRate(concertArtist3));

		for (int i = 0; i < (sizeof(conc) / sizeof(*conc)); i++)
			std::cout << conc[i] << " rating: " << concertArtist3[conc[i]] << std::endl;

		std::vector<Artist*> artists = { &a1, &a2, a3 };

		//bubble sort
		//inline_function(with_params(std::vector<Artist*>& artists, int n))
		//{
		//	for (int i = 1; i < n; i++)
		//		for (int j = 0; j < n - i; j++)
		//			if (artists[j]->get_musicalInstrument() == "Pianino" 
		//				&& artists[j]->get_rating() < artists[j + 1]->get_rating())
		//			{
		//				auto temp = artists[j];
		//				artists[j] = artists[j + 1];
		//				artists[j + 1] = temp;
		//			}
		//}
		//with_name(bubbleSort);

		ArraySorter::bubbleSorting<Artist*>(artists, [](Artist* s1, Artist* s2) {
			return s1->get_rating() < s2->get_rating() | s2->get_musicalInstrument() == "Pianino";
			});
		

		Serialize<std::vector<Artist*>> arrobject("objectVector.txt");

		for (auto item : artists)
		{
			std::cout << "\nName: " << item->get_firstName() 
				<< "\nSecond name: " << item->get_secondName()
				<< "\nGender: " << item->get_gender()
				<< "\nYears old: " << item->get_yearOld()
				<< "\nInstrument: " << item->get_musicalInstrument() 
				<< "\nRating: " << item->get_rating() << std::endl;

			arrobject.serialize(artists);
		}

		delete a3;
	}

	return 0;

}
