#pragma once

#include <map>
#include "Document.h"
#include "Date_Time.h"

class Judge_Plan : public Document
{
public:
	void show() const;
	void fill();
	void publish(string) const;
	Judge_Plan();
	~Judge_Plan();
};