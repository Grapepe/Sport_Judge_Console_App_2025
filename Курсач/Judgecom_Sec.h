#pragma once

#include <iostream>
#include <vector>
#include "User.h"
#include "Judge.h"
#include "Judge_Database.h"
#include "Judge_Plan.h"

class Judgecom_Sec: public User, public Person
{
	//static vector<Judge> reserve;
	//static vector<string> req_list;
public:
	void set_person_info();
	void get_person_info();
	void make_plan();
	void make_reserve();
	void make_change_in_plan();
	void make_conclusion();
};

