#pragma once
#include<string>
#include<iostream>
#include<map>


using namespace std;
class IPages
{
public:
	virtual string getPage(int key) = 0;
};

class DataBase:public IPages
{
	map<int, string > base;
public:
	DataBase()
	{
		base[1] = "Page 1";
		base[2] = "Page 2";
		base[3] = "Page 3";
		base[4] = "Page 4";
		base[5] = "Page 5";
	}
	string getPage(int key) override
	{
		if (base.count(key))
			return base[key];
		else
			return "No page";
	}

};

class DataBaseProxy :public IPages
{
	map<int, string> cash;
	DataBase* base;
public:
	string getPage(int key) override
	{
		if ( cash.count(key))
		{
			cout << "Взято из кеша" << endl;
			return cash[key];
		}
		else
		{
			base = new DataBase;
			string page = base->getPage(key);
				cash[key] = page;
			cout << "Взято из базы" << endl;
			return page;
		}
	}
};



//////////////////////////////
//DataBaseProxy* bdproxy = new DataBaseProxy;
//int i = 1;
//while (i)
//{
//	cout << "Cтраница: ";
//	cin >> i;
//	cout << bdproxy->getPage(i);
//}