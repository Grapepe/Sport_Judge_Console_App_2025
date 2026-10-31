#pragma once
#include <iostream>
#include "User.h"
#include "Person.h"

class Orgcom_Sec: public User, public Person
{
public:
	void make_requirements() const;
	Orgcom_Sec() {};
	~Orgcom_Sec() {};
};