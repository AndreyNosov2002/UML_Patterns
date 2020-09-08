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

using namespace std;


int main()
{
	setlocale(LC_ALL, "");
	ManagerMediator* manager = new ManagerMediator;
	Colleague* customer = new CustomerCollegue(manager);
	Colleague* programmer = new ProgrammerCollegue(manager);
	Colleague* tester = new TesterCollegue(manager);
	manager->customer = customer;
	manager->programmer = programmer;
	manager->tester = tester;

	customer->send("Есть заказ, надо сделать программу");
	programmer->send("Программа готова, нужно протестировать");
	tester->send("Программа протестирована, готова к продаже");
	


	system("pause");
}