#pragma once
#include<iostream>
#include<string>

using namespace std;


class Mothership
{
protected:
	int copper;
	int steel;
	int aluminum;
	int batteries;
	int mbase;
public:
	Mothership() {};
	Mothership(string filename);
	~Mothership();

	void Active();
	void ToString();

};

