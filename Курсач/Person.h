#pragma once

#include <string>
#include "Date_Time.h"

using namespace std;

template<typename T>
class Person
{
protected:
	string fio;
	int age;
	int id_number;
	Date date_of_birth;
	string gender;
	string adress;
	string phone_number;
	string email;
public:
	virtual void set_person_info() = 0;
	virtual void get_person_info() const = 0;
};
