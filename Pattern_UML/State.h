#pragma once
#include<string>
#include<iostream>
#include<map>


using namespace std;
class Water;

class IWaterState
{
public:
	virtual void heat(Water* water) = 0;
	virtual void frost(Water* water) = 0;
};

class Water
{
	IWaterState* state;
public:
	Water(IWaterState* ws) :state(ws){}
	void setState(IWaterState* ws) {state = ws;}
	void heat()
	{
		state->heat(this);

	}
	void frost()
	{
		state->frost(this);
	}
};

class SolidWaterState :public IWaterState
{
public:
	void heat(Water* water);
	
	void frost(Water* water)
	{
		cout << "���������� ������������ ��" << endl;
	}
};


class LiquidWaterState :public IWaterState
{
public:
	void heat(Water* water);

	void frost(Water* water)
	{
		cout << "����������� ���� � ��" << endl;
		water->setState(new SolidWaterState);
	}
};




class GasWaterState :public IWaterState
{
public:
	void heat(Water* water)
	{
		cout << "���������� ��������� ���" << endl;
	}
	void frost(Water* water)
	{
		cout << "����������� ���� � ����" << endl;
		water->setState(new LiquidWaterState);
	}
};





void SolidWaterState::heat(Water* water)
{
	cout << "����������� ���� � ����" << endl;
	water->setState(new LiquidWaterState);
}




void LiquidWaterState::heat(Water* water)
{
	cout << "����������� ���� � ���" << endl;
	water->setState(new GasWaterState);
}







////////////////////////////////////////////////////////////
//Water* water = new Water(new SolidWaterState);
//water->heat();
//water->heat();
//water->heat();
//water->heat();
//water->frost();
//water->frost();
//water->frost();
//water->frost();