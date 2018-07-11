#include "stdafx.h"
#include "Mothership.h"
#include<fstream>

Mothership::Mothership(string filename)
{
	ifstream FILE;
	FILE.open(filename, ios::in | ios::binary);
	
	string sample;
	getline(FILE, sample);
	copper = (sample[sample.size() - 5] - '0') * 1000;
	getline(FILE, sample);
	steel = (sample[sample.size() - 5] - '0') * 1000; 
	getline(FILE, sample);
	aluminum = (sample[sample.size() - 5] - '0') * 1000;
	getline(FILE, sample);
	batteries = (sample[sample.size() - 5] - '0') * 1000;
	mbase = 0;
	FILE.close();
}



Mothership::~Mothership()
{
}

void Mothership::Active()
{
	ifstream FILE;
	string filename = "activities.dat";
	FILE.open(filename, ios::in | ios::binary);

	string sample=" ";

	while (sample != "")
	{
		getline(FILE, sample);
		if (sample != "")
		{
			if (sample[0] == 'A')	// robot Alpha
			{
				if (sample[6] == 'M')	// activity Move
					batteries -= ((sample[sample.size() - 2] - '0') * 4);
				else	// activity Build 
					batteries -= ((sample[sample.size() - 2] - '0') * 10), mbase++;
			}
			else // robot Beta
			{
				batteries -= ((sample[sample.size() - 2] - '0') * 5);
			}
		}
	}
	
	int i = 0;
	while (i <= mbase)
	{
		copper -= 100;
		steel -= 200;
		aluminum -= 300;
		i++;
	}
}

void Mothership::ToString()
{
	cout << "Copper = " << copper << endl;
	cout << "Steel = " << steel << endl;
	cout << "Aluminum = " << aluminum << endl;
	cout << "Batteries = " << batteries << endl;
}

