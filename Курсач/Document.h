#pragma once

#include <string>

#include "Date_Time.h"

using namespace std;

class Document
{
protected:
	unsigned int num;
	string title;
	string event_name;
	string org_name;
	string applicant_fio;
	string applicant_phone_num;
	string applicant_email;
	Date doc_date;
public:
	virtual void show() const = 0;
	virtual void fill() = 0;
	virtual void publish(string) const = 0;
};