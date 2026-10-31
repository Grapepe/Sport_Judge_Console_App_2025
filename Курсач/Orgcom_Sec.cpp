#include "Orgcom_Sec.h"
#include "Judge_List_Struct.h"
#include <string.h>
#include "Request.h"

void Orgcom_Sec::make_requirements() const
{
	while(true)
	{
		int ans;
		Request request;
		request.fill();
		cout << "Хотите продолжить? (1-да): ";
		cin >> ans;
		if (ans == 1) continue;
		else break;
	}
}

