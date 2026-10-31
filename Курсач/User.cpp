#include "User.h"
#include <fstream>
#include <iostream>

using namespace std;

bool User::security(user_category& uc)
{
	int choice;
	cout << "Что вы хотите сделать?\n1-Войти\n2-Зарегистрироваться\n\nВаш выбор: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		User::log_in(uc);
		return uc != unknown;
		break;
	case 2:
		User::user_reg();
		cout << "Теперь попробуйте войти\n\n";
		return false;
		break;
	default:
		cout << "Ошибка ввода, попробуйте еще раз\n\n";
		return false;
		break;
	}
}

void User::log_in(user_category& uc)
{
	string log, pass;
	cin.ignore(10, '\n');
	cout << "Введите логин: ";
	getline(cin, log, '\n');
	cout << "Введите пароль: ";
	getline(cin, pass, '\n');
	ifstream ifs("Users.dat", ios::binary);
	bool is_found = false;
	while (ifs.peek() != EOF)
	{
		User a;
		ifs >> a;
		if (a.login == log && a.password == pass)
		{
			uc = a.user_cat;
			is_found = true;
			break;
		}
	}
	if (is_found)
	{
		cout << "Добро пожаловать в систему!\n\n";
	}
	else
	{
		cout << "Данный пользователь не был найден!\n";
		uc = unknown;
	}
}

void User::user_reg()
{
	User user;
	cin.ignore(10, '\n');
	cout << "Введите логин: ";
	getline(cin, user.login, '\n');
	cout << "Введите пароль: ";
	getline(cin, user.password, '\n');
	cout << "Введите тип пользователя: \n1 - Секретарь Оргкома\n2 - член Судейсуой коллегии\n\nВаш выбор: ";
	int ans;
	cin >> ans;
	switch (ans)
	{
	case 1: 
		user.user_cat = org_secr;
		break;
	case 2:
		user.user_cat = jud_secr;
		break;
	default:
		cout << "Ошибка категории пользователя!\n\n";
		user.user_cat = unknown;
	}
	ofstream ofs("Users.dat", ios::binary);
	ofs << user;
	ofs.close();
}

ofstream& operator<<(ofstream& ofs, User& user)
{
	size_t size;
	size = user.login.size(); ofs.write((char*)&size, sizeof(size)); ofs.write(user.login.c_str(), size);
	size = user.password.size(); ofs.write((char*)&size, sizeof(size)); ofs.write(user.password.c_str(), size);
	ofs.write((char*)&user.user_cat, sizeof(user.user_cat));
	return ofs;
}

ifstream& operator>>(ifstream& ifs, User& user)
{
	size_t size;
	ifs.read((char*)&size, sizeof(size)); user.login.resize(size); ifs.read(&user.login[0], size);
	ifs.read((char*)&size, sizeof(size)); user.login.resize(size); ifs.read(&user.login[0], size);
	ifs.read((char*)user.user_cat, sizeof(user.user_cat));
	return ifs;
}

User::User()
{
	this->login = "Неизвестно";
	this->password = "NULL";
	this->user_cat = unknown;
}