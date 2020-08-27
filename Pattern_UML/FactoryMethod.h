#pragma once
#include<string>
#include<iostream>

using namespace std;
//Product
class Transport
{
public:
	virtual ~Transport(){}
	virtual void delivery(string adress) const = 0;
	virtual string name()const = 0;
};

class Track : public Transport
{
public:
	void delivery(string adress)const override
	{
		cout << " Груз доставлен по адрессу:" << adress << endl;
	}
	string name ()const
	{
		return "Задействован новый грузовик:";
	}
};


class Ship : public Transport
{
public:
	void delivery(string adress)const override
	{
		cout << " Груз доставлен по адрессу:" << adress << endl;
	}
	string name ()const
	{
		return "Задействован новый пароход:";
	}
};
class Plane : public Transport
{
public:
	void delivery(string adress)const override
	{
		cout << " Груз доставлен по адрессу:" << adress << endl;
	}
	string name()const
	{
		return "Задействован новый самолет:";
	}
};


class Creator
{
public:
	virtual ~Creator(){}
	virtual Transport* createTransport()const = 0;
	Transport *create()
	{
		Transport* transport = this->createTransport();
		cout << transport->name();
		return transport;
	}
};


class TrackCreator :public Creator
{
public:
	 Transport* createTransport()const override
	{
		return new Track();
	}
};

class ShipCreator :public Creator
{
public:
     Transport* createTransport()const override
	{
		return new Ship();
	}
};

class PlaneCreator :public Creator
{
public:
	Transport* createTransport()const override
	{
		return new Plane();
	}
};