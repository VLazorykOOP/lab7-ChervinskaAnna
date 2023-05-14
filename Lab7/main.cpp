#include "pch.h"
#include <iostream>
#include <conio.h>
#include "Lab7.h"
using namespace std;
using namespace SpaceTask1;
using namespace SpaceTask2;
using namespace SpaceTask3;
using namespace SpaceTask4;



int main()
{
	std :: cout << " Lab #5  !\n";


	char ch;
	do {
		cout << "\nSelect Task: \n";
		cout << "    1.  Task1 \n";
		cout << "    2.  Task2 \n";
		cout << "    3.  Task3 \n";
		cout << "    4.  Task4 \n";
		cout << "    5.  Exit \n";

		ch = _getch();
		switch (ch) {
		case '1': mainTask1(); break;
		case '2': mainTask2(); break;
		case '3': mainTask3(); break;
	    case '4': mainTask4(); break;
		}
	} while (ch != '5');

}
