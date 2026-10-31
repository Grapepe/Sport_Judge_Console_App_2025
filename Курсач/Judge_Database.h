#pragma once
#include "Judge.h"
#include "Judgecom_Sec.h"
#include "Orgcom_Sec.h"

class Judge_Database
{
	//static multiset<Judge> judges;
public:
	static void add_to_database();
	static void open_database();
	static void change_in_database();
	friend class Judgecom_Sec;
};