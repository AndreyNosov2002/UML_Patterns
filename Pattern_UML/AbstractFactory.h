#pragma once
#include<string>
#include<iostream>

using namespace std;

class Component
{
public:
	virtual string toString()const = 0;
};


class Engine:public Component
{

};

class Transmission :public Component
{

};

class BodyType :public Component
{

};

class DiselEngine :public Engine
{
	string toString()const override
	{
		return "DiselEngine";
	}
};
class FuelEngine :public Engine
{
	string toString()const override
	{
		return "FuelEngine";
	}
};

class GasEngine :public Engine
{
	string toString()const override
	{
		return "GasEngine";
	}
};


class MechanicalTransmission :public Transmission
{
	string toString()const override
	{
		return "MechanicTransmission";
	}
};

class AuthomaticTransmission :public Transmission
{
	string toString()const override
	{
		return "AuthomaticTransmission";
	}
};

class RobotTransmission :public Transmission
{
	string toString()const override
	{
		return "RobotTransmission";
	}
};

class SedanBodyType :public BodyType
{
	string toString()const override
	{
		return "SedanBodyType";
	}
};

class UniversalBodyType :public BodyType
{
	string toString()const override
	{
		return "UniversalBodyType";
	}
};

class CrossoverBodyType : public BodyType
{
	string toString() const override
	{
		return "CrossoverBodyType";
	}
};


class Car
{
	Engine* engine = nullptr;
	Transmission* transmission = nullptr;
	BodyType* bodytype = nullptr;
public:
	Car(){}
	virtual ~Car()
	{
		if (engine)
			delete engine;
		if (transmission)
			delete transmission;
		if (bodytype)
			delete bodytype;
	}
	void setEngine(Engine* en) {		engine = en;	}
	void setTransmission(Transmission* tr) {		transmission = tr;}
	void setBodyType(BodyType* bt) {		bodytype = bt;}
	Engine* getEngine() {	return engine;}
	Transmission* getTransmission() {		return transmission;}
	BodyType* getBodyType() {		return bodytype;}
	void print()
	{
		cout << "Engine:" << engine->toString() << endl;
		cout << "Transmission:" << transmission->toString() << endl;
		cout << "BodyType:" << bodytype->toString() << endl;
	}

};

class ICarFactory
{
public:
	virtual Engine* createEngine() = 0;
	virtual Transmission* createTransmission() = 0;
	virtual BodyType* createBodyType() = 0;

};

class SportCar :public ICarFactory
{
public:
	Engine* createEngine() {return new FuelEngine;}
	Transmission* createTransmission() {return new RobotTransmission;}
	BodyType* createBodyType() {return new SedanBodyType;}
};

class TruckCar :public ICarFactory
{
public:
	Engine* createEngine() {
		return new DiselEngine;
	}
	Transmission* createTransmission() {
		return new MechanicalTransmission;
	}
	BodyType* createBodyType() {
		return new UniversalBodyType;
	}
};

class CarConfigurator
{
	ICarFactory* factory = nullptr;
public:
	~CarConfigurator()
	{
		if (factory)
			delete factory;
	}
	void setConfiguration(ICarFactory* f) {	factory = f;}
	void configurate(Car* car)
	{
		car->setEngine(factory->createEngine());
		car->setTransmission(factory->createTransmission());
		car->setBodyType(factory->createBodyType());
	}
};




          //Создание Машины SportCar
////////////////////////////////////////////////////
//Car* car1 = new Car;
//CarConfigurator* config = new CarConfigurator;
//config->setConfiguration(new SportCar);
//config->configurate(car1);
//car1->print();