#pragma once

#include <string>
#include "Enums.h"

using namespace std;

class User
{
protected:
	string login;
	string password;
	user_category user_cat;
public:
	User();
	static bool security(user_category&);
	static void log_in(user_category&);
	static void user_reg();
	friend ofstream& operator<<(ofstream&, User&);
	friend ifstream& operator>>(ifstream&, User&);
};