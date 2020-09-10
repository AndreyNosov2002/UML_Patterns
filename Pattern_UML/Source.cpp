
#include<iostream>
#include"FactoryMethod.h"
#include"AbstractFactory.h"
#include"Singleton.h"
#include"Prototype.h"
#include"Decorator.h"
#include"Fassade.h"
#include"Flyweight.h"
#include"Proxy.h"
#include"State.h"
#include"ChainOfResponsibilty.h"
#include"Command.h"
#include"Mediator.h"
//#include"Visitor.h"
#include"TemplateMethod.h"

using namespace std;


int main()
{
	setlocale(LC_ALL, "");
	HouseBuilder* house1 = new StandartHouse;
	house1->buildHouse(4);
	cout << house1->getResult() << endl;
	

	HouseBuilder* house2 = new SuperHouse;
	house1->buildHouse(4);
	cout << house1->getResult() << endl;
	system("pause");
}