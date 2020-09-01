#pragma once
#include<string>
#include<iostream>


using namespace std;

class Pizza
{
	string name;
public:
	Pizza(string n):name(n){}
	string getname() {return name;}
	virtual int getCoast() const = 0;

};




class ItalianPizza :public Pizza
{
public:
	ItalianPizza() :Pizza("����������� �����"){}
	int getCoast() const override
	{
		return 100;
	}

};


class AmericanPizza :public Pizza
{
public:
	AmericanPizza() :Pizza("A����������� �����") {}
	int getCoast() const override
	{
		return 120;
	}

};


class PizzaDecorator :public Pizza
{
protected:
	Pizza* pizza;
public:
	PizzaDecorator(string n, Pizza* p):Pizza(n), pizza(p){}
	virtual ~PizzaDecorator() {	delete pizza;};
};


class Tomato :public PizzaDecorator
{
public:
	Tomato(Pizza* p):PizzaDecorator(p->getname()+", c ����������",p){}
	virtual ~Tomato(){}
	int getCoast()const override
	{
		return pizza->getCoast() + 20;
	}
};


class Cheese :public PizzaDecorator
{
public:
	Cheese(Pizza* p) :PizzaDecorator(p->getname() + ", c �����", p) {}
	virtual ~Cheese() {}
	int getCoast()const override
	{
		return pizza->getCoast() + 10;
	}
};