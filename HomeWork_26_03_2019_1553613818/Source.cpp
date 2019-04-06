#include<iostream>
#include<iomanip>
#include<fstream>			
#include<Windows.h>
#include<locale.h>




// VladimirOrlovA /HomeWork_26_03_2019_1553613818

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


using namespace std;

int cur_size = 0;
int buf_size = 0;

template<typename T>
void add(T *&fs, T el)
{
	if (buf_size == 0)
	{
		buf_size = 4;
		fs = new T[buf_size];
	}
	else
	{
		if (cur_size == buf_size)
		{
			buf_size *= 2;
			T *tmp = new T[buf_size];
			for (int i = 0; i < cur_size; i++)
			{
				tmp[i] = fs[i];
			}
			delete[] fs;
			fs = tmp;
		}
	}
	fs[cur_size++] = el;
}

void Task1()
{
	/*1. Телефон состоит из нескольких частей (код города и три двузначных числа). Разработайте структуру, 
	описывающую номер телефона. Используйте битовые поля. Реализуйте функции для работы с этой структурой 
	(заполнение, печать).*/

	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask1\n\n";
	SetConsoleTextAttribute(hConsole, 7);
	
	struct Number
	{
		int code : 11, n1 : 8, n2 : 8, n3 : 8;
		void print()
		{
			cout << code << " " << n1 << " " << n2 << " " << n3 << endl;
		}
	};

	Number el;
	Number *fs = 0;
	ifstream fin("DataBaseTask1.txt");
	int tmp;

	if (!fin)
		{
			cout << "file does not exist" << endl;
		}
	else
	{
		while (!fin.eof())
		{
			fin >> tmp;
			el.code = tmp;
			fin >> tmp;
			el.n1 = tmp;
			fin >> tmp;
			el.n2 = tmp;
			fin >> tmp;
			el.n3 = tmp;
			add(fs, el);
		}
		int a = 0;
		do
		{
			cout << "Menu:\n1 - All list\n2 - Add new\n";
			int choose;
			cin >> choose;
			switch (choose)
			{
			case 1:
			{
				for (int i = 0; i < cur_size; i++)
				{
					fs[i].print();
				}
				break;
			}
			case 2:
			{
				cout << "Write the number: code and three two-digit numbers: ";
				cin >> tmp;
				el.code = tmp;
				cin >> tmp;
				el.n1 = tmp;
				cin >> tmp;
				el.n2 = tmp;
				cin >> tmp;
				el.n3 = tmp;
				add(fs, el);
				break;
			}
			}
			cout << "Do you want to open menu? 1/0: ";
			cin >> a;
		} while (a == 1);
	}
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

	struct Student
	{
		char surname[15];
		char name[15];
		char patronymic[20];
		
		int grade1 : 5, grade2 : 4, grade3 : 5, grade4 : 5, grade5 : 4;
		int grade6 : 4, grade7 : 5, grade8 : 4, grade9 : 4, grade10 : 5;
		
		void print()
		{
			cout << surname << " " << name << " " << patronymic << " " << endl;
			cout << grade1 << " " << grade2 << " " << grade3 << " " << grade4 << " " << grade5 << "\n";
			cout << grade6 << " " << grade7 << " " << grade8 << " " << grade9 << " " << grade10;
			cout << endl;
		}
		void averGrade()
		{
			int sum;
			float aver;
			sum = grade1 + grade2 + grade3 + grade4 + grade5 + grade6 + grade7 + grade8 + grade9 + grade10;
			aver = float(sum) / 10;
			cout << "Средняя оценка: " << aver << endl;
		}
	};

	

	cur_size = 0;
	buf_size = 0;
	Student *arrSt = 0;
	Student st;
	int tmp;
	ifstream fin("DataBaseTask2.txt");
	
	if (!fin)
	{
		cout << "file does not exist" << endl;
	}
	else
	{

		while (!fin.eof())
		{
			fin >> st.surname >> st.name >> st.patronymic;
			fin >> tmp; st.grade1 = tmp; fin >> tmp; st.grade2 = tmp; fin >> tmp; st.grade3 = tmp;
			fin >> tmp; st.grade4 = tmp; fin >> tmp; st.grade5 = tmp; fin >> tmp; st.grade6 = tmp;
			fin >> tmp; st.grade7 = tmp; fin >> tmp; st.grade8 = tmp; fin >> tmp; st.grade9 = tmp;
			fin >> tmp; st.grade10 = tmp;
			add(arrSt, st);
		}

		char flag;

		do
		{
			cout << "Выбор действия:\n\n (1) - Добавить студента \n (2) - Средняя оценка студентов \n (3) - Полный список \n";
			int choose;
			cout << "\n -> ";
			cin >> choose;
			switch (choose)
			{
			case 1:
			{
				cout << "Введите имя, фамилию и отчество студента: ";
				cin >> st.surname >> st.name >> st.patronymic;
				cout << "Внесите 10 оценок студента -> \n";
				cin >> tmp; st.grade1 = tmp; cin >> tmp; st.grade2 = tmp; cin >> tmp; st.grade3 = tmp;
				cin >> tmp; st.grade4 = tmp; cin >> tmp; st.grade5 = tmp; cin >> tmp; st.grade6 = tmp;
				cin >> tmp; st.grade7 = tmp; cin >> tmp; st.grade8 = tmp; cin >> tmp; st.grade9 = tmp;
				cin >> tmp; st.grade10 = tmp;
				add(arrSt, st);
				break;
			}
			case 2:
			{
				for (int i = 0; i < cur_size; i++)
				{
					arrSt[i].print();
					arrSt[i].averGrade();
				}
				break;
			}
			case 3:
			{
				for (int i = 0; i < cur_size; i++)
					arrSt[i].print();
				break;
			}
			}
			cout << "Вы хотите продолжить? \n\n если Да нажмите (y) если НЕТ нажмите любую кнопку -> ";
			cin >> flag;
		} while (flag == 'y');
	}

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