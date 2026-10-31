#include "Request.h"
#include "Judge_Type_Strings.h"
#include "Enums.h"
#include <fstream>
#include <iostream>
#include <iomanip>

void Request::show() const
{

}

void Request::fill()
{
	cout << "Введите заголовок документа: ";
	getline(cin, title, '\n');
	cout << "Введите номер документа: ";
	cin >> num;
	cin.ignore(10, '\n');
	cout << "Введите название мероприятия: ";
	getline(cin, event_name, '\n');
	cout << "Введите место проведения мероприятия: ";
	getline(cin, place, '\n');
	cout << "Введите через пробел день/месяц/год проведения мероприятия: ";
	cin >> event_date.day >> event_date.month >> event_date.year;
	cin.ignore(10, '\n');
	cout << "Введите ФИО получателя/название компании: ";
	getline(cin, to_whom, '\n');
	cout << "Введите через пробел день/месяц/год оформления документа: ";
	cin >> doc_date.day >> doc_date.month >> doc_date.year;
	cin.ignore(10, '\n');
	cout << "В следующем блоке кратко опишите соревнование: \n";
	getline(cin, description, '\n'); 
	cout << "Введите введите количество команд и участников через пробел: ";
	cin >> num_of_teams >> num_of_partic;
	cout << "Введите предполагаемое число участников коллегии: ";
	cin >> num_of_judges;
	cin.ignore(10, '\n');
	while (true)
	{
		for (string j : judge_types)
		{
			cout << "Введите количество судей должности \"" << j << "\": ";
			if (j == "Главный судья")
			{
				cin >> j_list.chief_judge_num;
			}
			else if(j == "Гланый секретарь")
			{
				cin >> j_list.judge_secr_num;
			}
			else if (j == "Заместитель главного судьи")
			{
				cin >> j_list.judge_deputy_num;
			}
			else if (j == "Линейный судья")
			{
				cin >> j_list.line_judge_num;
			}
			else if (j == "Техничесикй судья")
			{
				cin >> j_list.tech_judge_num;
			}
			else
			{
				cin >> j_list.secure_judge_num;
			}
			cin.ignore(10, '\n');
		}
		if ((j_list.chief_judge_num + j_list.judge_secr_num + j_list.judge_deputy_num + j_list.line_judge_num + j_list.secure_judge_num + j_list.tech_judge_num) > num_of_judges)
		{
			cout << "Количество требуемых от вас пользователей не соответствует введенным ранее параметрам!\n";
		}
		else
		{
			break;
		}
	}
	for (string j : judge_types)
	{
			cout << "Введите требования для квалификации судей должности \"" << j << "\": ";
			if (j == "Главный судья")
			{
				q_reqire.chief_judge_qual = category_choice();
			}
			else if (j == "Гланый секретарь")
			{
				q_reqire.judge_secr_qual = category_choice();
			}
			else if (j == "Заместитель главного судьи")
			{
				q_reqire.judge_deputy_qual = category_choice();
			}
			else if (j == "Линейный судья")
			{
				q_reqire.line_judge_qual = category_choice();
			}
			else if (j == "Техничесикй судья")
			{
				q_reqire.tech_judge_qual = category_choice();
			}
			else
			{
				q_reqire.secure_judge_qual = category_choice();
			}
	}

	for (string j : judge_types)
	{
		cout << "Введите требования к стажу для судей должности \"" << j << "\": ";
		if (j == "Главный судья")
		{
			cin >> exp_reqire.chief_judge_exp;
		}
		else if (j == "Гланый секретарь")
		{
			cin >> exp_reqire.judge_secr_exp;
		}
		else if (j == "Заместитель главного судьи")
		{
			cin >> exp_reqire.judge_deputy_exp;
		}
		else if (j == "Линейный судья")
		{
			cin >> exp_reqire.line_judge_exp;
		}
		else if (j == "Техничесикй судья")
		{
			cin >> exp_reqire.tech_judge_exp;
		}
		else
		{
			cin >> exp_reqire.secure_judge_exp;
		}
	}
	cout << "Требования были записаны!\n\nВведите через пробел дату срока предоставления плана: ";
	cin >> deadline.day >> deadline.month >> deadline.year;
	string final_title = title + " " + to_string(deadline.day) + "-" + to_string(deadline.month) + "-" + to_string(deadline.year) + ".txt";
	publish(final_title);
	cout << "Требования были записан в файл!";
}

void Request::publish(string title) const
{
	ofstream file;
	file.open(title);
	if (!file.is_open()) {
		cout << "Ошибка: файл не открылся!\n";
	}
	file << setw(50) << "ОТ: " << applicant_fio << endl
		<< setw(50) << "КОМУ: " << to_whom << endl << endl
		<< setw(50) << this->title << endl << endl
		<< "Место проведения: " << place << endl
		<< "Дата мероприятия: " << event_date.day << "." << event_date.month << "." << event_date.year << endl
		<< "Краткое описание: " << description << endl << endl
		<< "Количество команд: " << num_of_teams << endl
		<< "Количество участников соревнования: " << num_of_partic << endl
		<< "Требуемое количество судей: " << num_of_judges << endl << endl
		<< setw(30) << "Положение :" << setw(30) << "Кол-во :" << setw(40) << "Квалификация :" << endl
		<< "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
	for (string j : judge_types)
	{
		if (j == "Главный судья")
		{
			file << setw(28) << j << " :" << setw(28) << j_list.chief_judge_num << " :" << setw(40) << qual_to_str(q_reqire.chief_judge_qual) << " :" << endl;
		}
		else if (j == "Главный секретарь")
		{
			file << setw(28) << j << " :" << setw(28) << j_list.judge_secr_num << " :" << setw(40) << qual_to_str(q_reqire.judge_secr_qual) << " :" << endl;
		}
		else if (j == "Заместитель главного судьи")
		{
			file << setw(28) << j << " :" << setw(28) << j_list.judge_deputy_num << " :" << setw(40) << qual_to_str(q_reqire.judge_deputy_qual) << " :" << endl;
		}
		else if (j == "Линейный судья")
		{
			file << setw(28) << j << " :" << setw(28) << j_list.line_judge_num << " :" << setw(40) << qual_to_str(q_reqire.line_judge_qual) << " :" << endl;
		}
		else if (j == "Технический судья")
		{
			file << setw(28) << j << " :"  << setw(28) << j_list.tech_judge_num << " :" << setw(40) << qual_to_str(q_reqire.tech_judge_qual) << " :" << endl;
		}
		else
		{
			file << setw(28)  << j << " :"  << setw(28) << j_list.secure_judge_num << " :" << setw(40) << qual_to_str(q_reqire.secure_judge_qual) << " :" << endl;
		}
	}
	file << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl
		<< "Срок сдачи плана: " << deadline.day << ":" << deadline.month << ":" << deadline.year << endl << endl
		<< "Подписи: " << setw(45) << "------------" << setw(20) << "------------" << endl;
	file.close();
}

Request::Request()
{

}

Request::~Request()
{

}