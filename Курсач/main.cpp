#include <iostream>
#include <Windows.h>
//#include "Enums.h"
//#include "User.h"
//#include "Menus.h"
#include "Request.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Request a;
	a.fill();
	/*int cont = 1;
	user_category uc = unknown;

	while (!User::security(uc));

	switch (uc)
	{
	case org_secr:
		org_sec_interface();
		break;
	case jud_secr:
		jud_sec_interface();
		break;
	default:
		cout << "Îøèáêà\n";
		return 0;
	}*/
}