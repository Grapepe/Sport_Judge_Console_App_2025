#include "Judge_List_Struct.h"
#include <iostream>
using namespace std;

string qual_to_str(judge_category jc)
{
	switch (jc)
	{
	case simple_cat: return "Обычная категория"; break;
	case first_cat: return "Первая категория"; break;
	case national_cat: return "Национальная категория"; break;
	case highest_national_cat: return "Высшая национальная категория"; break;
	default: "Без категории";
	}
}

judge_category category_choice()
{
	int cat;
	cout << "Выберите требование к категории: \n1-Обычная категория\n2-Первая категория\n3-Национальная категория\n4-Высшая национальная категория\n\nВаш выбор: ";
	cin >> cat;
	switch (cat)
	{
	case 1: return simple_cat; break;
	case 2: return first_cat; break;
	case 3: return national_cat; break;
	case 4: return highest_national_cat; break;
	default: return no_cat;
	}
}