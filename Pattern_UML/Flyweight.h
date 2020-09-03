#pragma once

#include<string>
#include<iostream>
#include<map>


using namespace std; 


class House
{
protected:
	int floor;
public:
	virtual void build(float latitude, float longitude) = 0;

};


class PanelHouse :public House
{
public:
	PanelHouse() {floor = 9;}
	void build(float latitude, float longitude) override
	{
		cout << "ѕостроен панельный дом из " << floor << " этажей, координаты: "
			<< latitude << "* широты" << longitude << "* долготы" << endl;
	}
};

class BrickHouse :public House
{
public:
	BrickHouse() {
		floor = 5;
	}
	void build(float latitude, float longitude) override
	{
		cout << "ѕостроен кирпичный дом из " << floor << " этажей, координаты: "
			<< latitude << "* широты" << longitude << "* долготы" << endl;
	}
};


class HouseFactory
{
	map<string, House*> houses;
public:
	HouseFactory()
	{
		houses["Panel"] = new PanelHouse;
		houses["Brick"] = new BrickHouse;
	}

	House* getHouse(string key)
	{
		if (houses.count(key))
			return houses[key];
		else
			return nullptr;
	}
};


/////////////////////////////////
//float latitude = 50.3, longitude = 30.6;
//HouseFactory* houseFactory = new HouseFactory;
//for (int i = 0; i < 10; i++)
//{
//	House* panelHouse = houseFactory->getHouse("Panel");
//	if (panelHouse != nullptr)
//		panelHouse->build(latitude, longitude);
//	latitude += 0.2;
//	longitude += 0.5;
//}
//cout << endl;
//for (int i = 0; i < 10; i++)
//{
//	House* brickHouse = houseFactory->getHouse("Brick");
//	if (brickHouse != nullptr)
//		brickHouse->build(latitude, longitude);
//	latitude += 0.2;
//	longitude += 0.5;
//}