#pragma once
#include<string>
using namespace std;

struct LoginDetails {

	string FullName;
	string email;
	string password;

};

void init();
void registration();
void autorization();