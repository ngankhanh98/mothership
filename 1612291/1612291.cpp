// 1612291.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"Mothership.h"
#include<fstream>

using namespace std;

int main()
{
	Mothership mom("mothership.dat");
	mom.ToString();
	cout << "____________________________________" << endl;
	cout << "               REPORT               " << endl;
	cout << "------------------------------------" << endl;
	mom.Active();
	mom.ToString();

	system("pause");
    return 0;
}

