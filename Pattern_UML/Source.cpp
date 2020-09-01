#include<iostream>
#include"FactoryMethod.h"
#include"AbstractFactory.h"
#include"Singleton.h"
#include"Prototype.h"
#include"Decorator.h"


using namespace std;


int main()
{
	setlocale(LC_ALL, "");
	Pizza* pizza1 = new ItalianPizza;
	cout << pizza1->getname() << endl;
	cout << "Цена: " << pizza1->getCoast() << endl;

	pizza1 = new Tomato(pizza1);
	pizza1 = new Cheese(pizza1);
	cout << pizza1->getname() << endl;
	cout << "Цена: " << pizza1->getCoast() << endl;
	system("pause");
}