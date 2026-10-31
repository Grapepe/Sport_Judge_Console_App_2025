#pragma once
#include "Enums.h"
#include <string>
using namespace std;

struct judge_list
{
	unsigned int chief_judge_num;
	unsigned int judge_secr_num;
	unsigned int judge_deputy_num;
	unsigned int line_judge_num;
	unsigned int tech_judge_num;
	unsigned int secure_judge_num;
};

struct qualif_reqirements
{
	judge_category chief_judge_qual;
	judge_category judge_secr_qual;
	judge_category judge_deputy_qual;
	judge_category line_judge_qual;
	judge_category tech_judge_qual;
	judge_category secure_judge_qual;
};

struct exp_requirements
{
	unsigned int chief_judge_exp;
	unsigned int judge_secr_exp;
	unsigned int judge_deputy_exp;
	unsigned int line_judge_exp;
	unsigned int tech_judge_exp;
	unsigned int secure_judge_exp;
};

string qual_to_str(judge_category);
judge_category category_choice();