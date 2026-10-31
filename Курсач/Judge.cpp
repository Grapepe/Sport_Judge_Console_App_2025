#include "Judge.h"
#include <iomanip>
#include <iostream>
#include <fstream>

Judge::Judge()
{
	this->jc = simple_cat;
	this->stat = available;
	this->js = no_spec;

	this->id_number = 0;
	this->comp_num = 0;
	this->age = 0;

	this->fio = "Неизвестно";
	this->adress = "Неизвестно";
	this->gender = "Неизвестно";
	this->email = "Неизвестно";
	this->phone_number = "Неизвестно";

	this->certif_val_period.day = 0;
	this->certif_val_period.month = 0;
	this->certif_val_period.year = 0;

	this->date_of_birth.day = 0;
	this->date_of_birth.month = 0;
	this->date_of_birth.year = 0;

}

Judge::~Judge() {}

ofstream& operator<<(ofstream& ofs, Judge& judge)
{
	size_t size;
	ofs.write((char*)&judge.jc, sizeof(judge.jc));
	ofs.write((char*)&judge.stat, sizeof(judge.stat));
	ofs.write((char*)&judge.js, sizeof(judge.js));

	ofs.write((char*)&judge.id_number, sizeof(judge.id_number));
	ofs.write((char*)&judge.comp_num, sizeof(judge.comp_num));
	ofs.write((char*)&judge.age, sizeof(judge.age));

	size = sizeof(judge.fio); ofs.write((char*)&size, sizeof(size)); ofs.write(judge.fio.c_str(), size);
	size = sizeof(judge.gender); ofs.write((char*)&size, sizeof(size)); ofs.write(judge.gender.c_str(), size);
	size = sizeof(judge.email); ofs.write((char*)&size, sizeof(size)); ofs.write(judge.email.c_str(), size);
	size = sizeof(judge.phone_number); ofs.write((char*)&size, sizeof(size)); ofs.write(judge.phone_number.c_str(), size);
	size = sizeof(judge.adress); ofs.write((char*)&size, sizeof(size)); ofs.write(judge.adress.c_str(), size);

	ofs.write((char*)&judge.date_of_birth, sizeof(judge.date_of_birth));

	ofs.write((char*)&judge.certif_val_period, sizeof(judge.certif_val_period));
	
	size = judge.sports.size(); ofs.write((char*)&size, sizeof(size));

	for (const string& sport : judge.sports) {
		size = sport.size();
		ofs.write((char*)&size, sizeof(size));
		ofs.write(sport.c_str(), size);
	}
	return ofs;
}

ifstream& operator>>(ifstream& ifs, Judge& judge)
{
	size_t size;
	ifs.read((char*)&judge.jc, sizeof(judge.jc));
	ifs.read((char*)&judge.stat, sizeof(judge.stat));
	ifs.read((char*)&judge.js, sizeof(judge.js));

	ifs.read((char*)&judge.id_number, sizeof(judge.id_number)); 
	ifs.read((char*)&judge.comp_num, sizeof(judge.comp_num));
	ifs.read((char*)&judge.age, sizeof(judge.age));

	ifs.read((char*)&size, sizeof(size)); judge.fio.resize(size); ifs.read(&judge.fio[0], sizeof(size));
	ifs.read((char*)&size, sizeof(size)); judge.gender.resize(size); ifs.read(&judge.gender[0], sizeof(size));
	ifs.read((char*)&size, sizeof(size)); judge.email.resize(size); ifs.read(&judge.email[0], sizeof(size));
	ifs.read((char*)&size, sizeof(size)); judge.phone_number.resize(size); ifs.read(&judge.phone_number[0], sizeof(size));
	ifs.read((char*)&size, sizeof(size)); judge.adress.resize(size); ifs.read(&judge.adress[0], sizeof(size));

	ifs.read((char*)&judge.date_of_birth, sizeof(judge.date_of_birth));

	ifs.read((char*)&judge.certif_val_period, sizeof(judge.certif_val_period));

	ifs.read((char*)&size, sizeof(size));

	for(int i = 0; i < size; i++)
	{
		size_t len;
		ifs.read((char*)&len, sizeof(len));
		string sport(len, '\0');
		ifs.read(&sport[0], sizeof(sport));
		judge.sports.insert(sport);
	}
	return ifs;
}

bool operator<(const Judge& j1, const Judge& j2)
{
	return (j1.jc < j2.jc) && (j1.stat < j2.stat);
}

bool operator>(const Judge& j1, const Judge& j2)
{
	return (j1.jc > j2.jc) && (j1.stat > j2.stat);
}

fstream& operator<<(fstream& ofs, Judge& judge)
{
	size_t size;
	ofs.write((char*)&judge.jc, sizeof(judge.jc));
	ofs.write((char*)&judge.stat, sizeof(judge.stat));
	ofs.write((char*)&judge.js, sizeof(judge.js));

	ofs.write((char*)&judge.id_number, sizeof(judge.id_number));
	ofs.write((char*)&judge.comp_num, sizeof(judge.comp_num));
	ofs.write((char*)&judge.age, sizeof(judge.age));

	size = sizeof(judge.fio); ofs.write((char*)&size, sizeof(size)); ofs.write(judge.fio.c_str(), size);
	size = sizeof(judge.gender); ofs.write((char*)&size, sizeof(size)); ofs.write(judge.gender.c_str(), size);
	size = sizeof(judge.email); ofs.write((char*)&size, sizeof(size)); ofs.write(judge.email.c_str(), size);
	size = sizeof(judge.phone_number); ofs.write((char*)&size, sizeof(size)); ofs.write(judge.phone_number.c_str(), size);
	size = sizeof(judge.adress); ofs.write((char*)&size, sizeof(size)); ofs.write(judge.adress.c_str(), size);

	ofs.write((char*)&judge.date_of_birth, sizeof(judge.date_of_birth));

	ofs.write((char*)&judge.certif_val_period, sizeof(judge.certif_val_period));

	size = judge.sports.size(); ofs.write((char*)&size, sizeof(size));

	for (const string& sport : judge.sports) {
		size = sport.size();
		ofs.write((char*)&size, sizeof(size));
		ofs.write(sport.c_str(), size);
	}
	return ofs;
}

fstream& operator>>(fstream& ifs, Judge& judge)
{
	size_t size;
	ifs.read((char*)&judge.jc, sizeof(judge.jc));
	ifs.read((char*)&judge.stat, sizeof(judge.stat));
	ifs.read((char*)&judge.js, sizeof(judge.js));

	ifs.read((char*)&judge.id_number, sizeof(judge.id_number));
	ifs.read((char*)&judge.comp_num, sizeof(judge.comp_num));
	ifs.read((char*)&judge.age, sizeof(judge.age));

	ifs.read((char*)&size, sizeof(size)); judge.fio.resize(size); ifs.read(&judge.fio[0], sizeof(size));
	ifs.read((char*)&size, sizeof(size)); judge.gender.resize(size); ifs.read(&judge.gender[0], sizeof(size));
	ifs.read((char*)&size, sizeof(size)); judge.email.resize(size); ifs.read(&judge.email[0], sizeof(size));
	ifs.read((char*)&size, sizeof(size)); judge.phone_number.resize(size); ifs.read(&judge.phone_number[0], sizeof(size));
	ifs.read((char*)&size, sizeof(size)); judge.adress.resize(size); ifs.read(&judge.adress[0], sizeof(size));

	ifs.read((char*)&judge.date_of_birth, sizeof(judge.date_of_birth));

	ifs.read((char*)&judge.certif_val_period, sizeof(judge.certif_val_period));

	ifs.read((char*)&size, sizeof(size));

	for (int i = 0; i < size; i++)
	{
		size_t len;
		ifs.read((char*)&len, sizeof(len));
		string sport(len, '\0');
		ifs.read(&sport[0], sizeof(sport));
		judge.sports.insert(sport);
	}
	return ifs;
}

void Judge::set_person_info()
{
	int choice;
	cin.ignore(10, '\n');
	cout << "Имя судьи: ";
	getline(cin, fio, '\n');
	cout << "Введите дату рождения через пробелы:";
	cin >> date_of_birth.day >> date_of_birth.month >> date_of_birth.year;
	cout << "Введите возраст: ";
	cin >> age;
	cin.ignore(10, '\n');
	cout << "Введите пол: ";
	cin >> gender;
	cout << "Введите ID судьи: ";
	cin >> id_number;
	cout << "Выберите категорию: \n1-Судья по спорту\n2-Судья первой категории\n3-Судья национальной категории\n4-Судья высшей национальной категории\nНомер категории: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		jc = simple_cat;
		break;
	case 2:
		jc = first_cat;
		break;
	case 3:
		jc = national_cat;
		break;
	case 4:
		jc = highest_national_cat;
		break;
	}
	cout << "Виды спорта:";
	do
	{
		cin.ignore(10, '\n');
		string tmp;
		getline(cin, tmp, '\n');
		sports.insert(tmp);
		cout << "Хотите продолжить? (1-ДА): ";
		cin >> choice;
	} while (choice == 1);
	cout << "В скольких СММ участвовал в качестве судьи: ";
	cin >> comp_num;
	cout << "Дата окончания действия удостоверения";
	cin >> certif_val_period.day >> certif_val_period.month >> certif_val_period.year;
	cout << "Статус судьи в данный момент:\n1-Свободен\n2-В отпуске\n3-Отстранен\nВаш выбор: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		stat = active;
		break;
	case 2:
		stat = on_leave;
		break;
	case 3:
		stat = dismissed;
		break;
	}
	cin.ignore(10, '\n');
	cout << "Введите адрес судьи: ";
	cin >> adress;
	cout << "Вы хотите ввести контактную информацию? (1-ДА, 2 - НЕТ)\nВаш выбор: ";
	cin >> choice;
	if (choice == 1)
	{
		cout << "Введите номер телефона: ";
		cin >> phone_number;
		cout << "Введите Email: ";
		cin >> email;
	}
	cout << "Судья создан!";
}

void Judge::get_person_info() const
{
	cout << "ID: " << setw(20) << left << id_number << ":" << "ФИО: " << fio << endl
		<< "Категория: ";
	switch (jc)
	{
	case simple_cat:
		cout << setw(50) << left << "Судья по спорту";
		break;
	case first_cat:
		cout << setw(50) << left << "Судья первой категории";
		break;
	case national_cat:
		cout << setw(50) << left << "Судья национальной категории";
		break;
	case highest_national_cat:
		cout << setw(50) << left << "Судья высшей национальной категории";
		break;
	default:
		cout << setw(50) << left << "Неизвестный";
	}
	cout << ": Статус: " << stat << endl
		<< "Количество мероприятий: " << setw(30) << left << comp_num << " : Телефон: " << phone_number
		<< "Пол: " << setw(45) << left << gender << " : Email: " << email << endl
		<< "Возраст: " << setw(40) << left << age << " : Адрес: " << adress << endl
		<< "Дата рождения: " << ((date_of_birth.day < 10) ? "0" : "") << date_of_birth.day << ":"
		<< ((date_of_birth.month < 10) ? "0" : "") << date_of_birth.month << ":"
		<< date_of_birth.year << endl;
	for (string sport : sports)
	{
		cout << sport;
	}
}

int Judge::get_id_number()
{
	return id_number;
}