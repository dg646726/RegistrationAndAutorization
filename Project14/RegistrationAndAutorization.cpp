#include "RegistrationAndAutorization.h"
#include<iostream>
#include<Windows.h>
#include<math.h>
#include<ctime>
#include<string>
#include<conio.h>
#include<list>
#include<fstream>


using namespace std;
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

#define CLEAR system("cls")
#define PAUSE system("pause")
#define ENDL cout<<endl

list<LoginDetails> login_details;
const string fileName = "LoginDetails.txt";

void init()
{
	ifstream fin;
	fin.open(fileName);
	bool isOpen = fin.is_open();

	if (isOpen == false) {
		cout << "Error" << endl;
	}
	else {
		int currentString = 0;
		string data;
		LoginDetails old_data;
		while (!fin.eof()) {
			currentString++;

			getline(fin, data);
			if (currentString == 1) {
				old_data.FullName = data;
			}
			else if (currentString == 2) {
				old_data.email = data;
			}
			else {
				old_data.password = data;
				currentString = 0;
				login_details.push_back(old_data);
				old_data = LoginDetails();
			}
		}
	}
}

void registration()
{
	CLEAR;
	LoginDetails newcontact;
	cout << "Enter full name:";
	cin.ignore();
	getline(cin, newcontact.FullName);
	cout << "Enter email:";
	cin >> newcontact.email;
	cout << "Enter password:";
	cin >> newcontact.password;
	login_details.push_back(newcontact);

	ofstream fout;
	fout.open(fileName, fstream::app);

	bool isOpen = fout.is_open();
	if (isOpen == false) {
		cout << "Error: Application can't connecting to database file" << endl;
	}
	else {
		fout << newcontact.FullName << endl;
		fout << newcontact.email << endl;
		fout << newcontact.password << endl;

	}
	fout.close();
	PAUSE;
	CLEAR;
}

void autorization()
{
	CLEAR;
	string email;
	string password;
	int index = 0;
	cout << "Enter email and password(email password):";
	cin >> email >> password;
	for (LoginDetails item : login_details)
	{
		if (email == item.email && password == item.password) {
			cout << "Hello " << item.FullName << endl;
			index++;
		}
	}
	if (index == 0) {
		cout << "Invalid email or password" << endl;
	}
	else {
		index--;
	}
	PAUSE;
	CLEAR;
}
