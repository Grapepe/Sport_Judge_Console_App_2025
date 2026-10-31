#pragma once
#include <set>
#include "Enums.h"
#include "Judge_List_Struct.h"
#include "Document.h"
#include "Judge.h"
#include "Date_Time.h"


class Request : public Document
{
	string to_whom;
	judge_list j_list;
	qualif_reqirements q_reqire;
	exp_requirements exp_reqire;
	string description;
	string place;
	Date event_date;
	Date deadline;
	int num_of_teams;
	int num_of_partic;
	unsigned int num_of_judges;
public:
	void show() const;
	void fill();
	void publish(string) const;
	Request();
	~Request();
};
