#include "Judge_Database.h"
#include "Judge.h"

#include <fstream>
#include <iostream>
#include <string>
#include <string.h>

void Judge_Database::add_to_database()
{
    
}

void Judge_Database::open_database()
{
	
}

void Judge_Database::change_in_database()
{
  /*  fstream file("JudgeDatabase.dat", ios::binary | ios::in | ios::out);
    if (!file)
    {
        cout << "Ошибка открытия файла!\n";
        return;
    }

    unsigned int target_id;
    cout << "Введите ID судьи, запись о котором хотите изменить: ";
    cin >> target_id;

    Judge temp;
    streamoff pos;

    while (file.peek() != EOF)
    {
        pos = file.tellp();
        file >> temp;

        if (temp.id_number == target_id)
        {
            cout << "\nНайден судья с таким ID:\n";
            temp.get_person_info();
            cout << "\nВведите новые данные:\n";
            temp.set_person_info();
            file.seekp(pos);
            file << temp;
            cout << "\nЗапись успешно изменена!\n";
            break;
        }
    }*/
}

//multiset<Judge> Judge_Database::judges;