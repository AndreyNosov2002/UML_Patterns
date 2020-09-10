
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
		house += "������� �����\n";
	}
	void buildDoor()override
	{
		house += "������� �����\n";
	}
	void buildWindow(int count)override
	{
		house += " ������� ���� - ";
		char buff[10];
//		_itoa(count, buff, 10);
		house += buff;
		house+="��.\n";
	}
	void buildRoof() override
	{
		house += "������� �����\n";
	}
	void hookBuildPool() override
	{
		house += "� ������� ���� ����������� \n";
	}
	string getResult() { return house; }
};





class SuperHouse :public HouseBuilder
{
	string house = "";
public:
	void buildWall()override
	{
		house += "�������� �����\n";
	}
	void buildDoor()override
	{
		house += "�������� ������\n";
	}
	void buildWindow(int count)override
	{
		house += " ������ ������������ ���� - ";
		char buff[10];
//		_itoa(count, buff, 10);
		house += buff;
		house += "��.\n";
	}
	void buildRoof() override
	{
		house += "������������� �����\n";
	}
	void hookBuildPool() override
	{
		house += "������� �� 500 ������ \n";
	}
	string getResult() { return house; }
};