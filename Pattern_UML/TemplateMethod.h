
# define _CRT_SECURE_NO_WARNINGS_
#pragma once
#include<string>
#include<iostream>                                              



using namespace std;

class HouseBuilder
{
protected:
	virtual void buildWall() = 0;
	virtual void buildDoor() = 0;
	virtual void buildWindow(int count) = 0;
	virtual void buildRoof() = 0;
	virtual void hookBuildPool() = 0;
	

public:
	void buildHouse(int wind)
	{
		buildWall();
		buildDoor();
		buildWindow(wind);
		hookBuildPool();
		buildRoof();
	}
	virtual string getResult() = 0;
};

class StandartHouse:public HouseBuilder
{
	string house="";
public:
	void buildWall()override
	{
		house += "Обычные стены\n";
	}
	void buildDoor()override
	{
		house += "Обычные двери\n";
	}
	void buildWindow(int count)override
	{
		house += " Обычные окна - ";
		char buff[10];
//		_itoa(count, buff, 10);
		house += buff;
		house+="шт.\n";
	}
	void buildRoof() override
	{
		house += "Обычная крыша\n";
	}
	void hookBuildPool() override
	{
		house += "В обычном доме отсутствует \n";
	}
	string getResult() { return house; }
};





class SuperHouse :public HouseBuilder
{
	string house = "";
public:
	void buildWall()override
	{
		house += "Каменные стены\n";
	}
	void buildDoor()override
	{
		house += "Гаражные ворота\n";
	}
	void buildWindow(int count)override
	{
		house += " Металл опластиковые окна - ";
		char buff[10];
//		_itoa(count, buff, 10);
		house += buff;
		house += "шт.\n";
	}
	void buildRoof() override
	{
		house += "Металлическая крыша\n";
	}
	void hookBuildPool() override
	{
		house += "Бассейн на 500 литров \n";
	}
	string getResult() { return house; }
};