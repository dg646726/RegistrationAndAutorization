#include<iostream>
#include<Windows.h>
#include<math.h>
#include<ctime>
#include<string>
#include<conio.h>
#include<list>
#include<fstream>
#include "RegistrationAndAutorization.h"

using namespace std;



int main() {
	setlocale(LC_CTYPE, "");
	srand(time(0));

	init();
	int action = 0;

	do
	{

		cout << "\tMenu" << endl;
		cout << "1.Registration" << endl;
		cout << "2.Autorization" << endl;
		cout << "3.Exit" << endl;
		cout << endl;
		cout << "Select action:";
		cin >> action;
		cout << endl;
		switch (action)
		{
		case 1:
			registration();
			break;
		case 2:
			autorization();
			break;
		case 3:
			cout << "Bye" << endl;
			break;
		default:
			cout << "Please select action (1 - 3)" << endl;
			break;
		}
	} while (action != 3);




	system("pause");
	return 0;
}