#pragma once

#include "Person.h"
#include "Judgecom_Sec.h"
#include "Enums.h"
#include <set>

class Judge : public Person<string>
{
	judge_category jc;
	judge_specialization js;
	Date certif_val_period;
	set<string> sports;
	status stat;
	unsigned int comp_num;
public:
	Judge();
	~Judge();
	void set_person_info();
	void get_person_info() const;
	int get_id_number();
	friend ofstream& operator<<(ofstream&, Judge&);
	friend ifstream& operator>>(ifstream&, Judge&);
	friend bool operator<(const Judge&, const Judge&);
	friend bool operator>(const Judge&, const Judge&);
	friend fstream& operator<<(fstream& ofs, Judge& judge);
	friend fstream& operator>>(fstream& ofs, Judge& judge);
	friend class Judge_Database;
	friend class Judgecom_Sec;
};
