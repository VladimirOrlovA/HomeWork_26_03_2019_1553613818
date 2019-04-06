#include<iostream>
#include<iomanip>
#include<fstream>			
#include<Windows.h>
#include<locale.h>




// VladimirOrlovA /HomeWork_26_03_2019_1553613818

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


using namespace std;



void Task1()
{
	/*1. Телефон состоит из нескольких частей (код города и три двузначных числа). Разработайте структуру, 
	описывающую номер телефона. Используйте битовые поля. Реализуйте функции для работы с этой структурой 
	(заполнение, печать).*/

	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask1\n\n";
	SetConsoleTextAttribute(hConsole, 7);

	
}

void Task2()
{
	/* 2.	Реализуйте структуру, которая хранит ФИО студента и 10 битовых полей. Каждое поле – это оценка (сдал/не сдал). 
А)*Создайте один экземпляр этой структуры и реализуйте для него следующие действия:
	Заполнить структуру
	Вывод информации
	Печать среднего балла
*/

	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask2\n\n";
	SetConsoleTextAttribute(hConsole, 7);

	

}


int main()
{
	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n Orlov Vladimir HomeWork_26_03_2019_1553613818 \n\n";
	SetConsoleTextAttribute(hConsole, 7);

	/*SetConsoleCP(1251);
	SetConsoleOutputCP(1251);*/

	setlocale(LC_ALL, "");

	int number;
	char flag;

	do
	{
		cout << endl << "Enter number of Task (1) to (2) => ";
		cin >> number;

		switch (number)
		{
		case 1: {Task1(); } break;
		case 2: {Task2(); } break;

		default: cout << "\nEntered number of Task does not exist...\n\n";

		}

		SetConsoleTextAttribute(hConsole, 10);
		cout << "\n--------------------------------------------------------------------------\n\n";
		SetConsoleTextAttribute(hConsole, 7);

		cout << "Do you want to continue? \n\nIf YES press (y) if NO press any keys => ";
		cin >> flag;

	} while (flag == 'y');
}