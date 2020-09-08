#pragma once

#include<iostream>



using namespace std;


class Handler
{

public:
	virtual void sendPayment(int sum) = 0;
	virtual Handler* setHandler(Handler* h) = 0;
};

class Client : public Handler
{
	Handler* nextHandler;
public:
	Client() {}
	Client(Handler* nh) :nextHandler(nh) {}
	Handler* setHandler(Handler* h)
	{
		nextHandler = h;
		return nextHandler;
	}
	void sendPayment(int sum)
	{
		if (nextHandler)
		{
			nextHandler->sendPayment(sum);
		}
	}
};


class EconomistHandler :public Handler
{
	Handler* nextHandler;
public:
	EconomistHandler() {}
	EconomistHandler(Handler* nh) :nextHandler(nh) {}
	Handler* setHandler(Handler* h)
	{
		nextHandler = h;
		return nextHandler;
	}
	void sendPayment(int sum)override
	{
		if (sum > 1000)
		{
			if (nextHandler)
				nextHandler->sendPayment(sum);
		}
		else
			cout << "Платёж проведен экономистом" << endl;
	}
};



class BuhgalterHandler :public Handler
{
	Handler* nextHandler;
public:
	BuhgalterHandler() {}
	BuhgalterHandler(Handler* nh) :nextHandler(nh) {}
	Handler* setHandler(Handler* h)
	{
		nextHandler = h;
		return nextHandler;
	}
	void sendPayment(int sum)override
	{
		if (sum > 5000)
		{
			if (nextHandler)
				nextHandler->sendPayment(sum);
		}
		else
			cout << "Платёж проведен бухгалтером" << endl;

	}
};


class DirectorHandler : public Handler
{
	Handler* nextHandler;
public:
	DirectorHandler() {}
	DirectorHandler(Handler* nh) :nextHandler(nh) {}
	Handler* setHandler(Handler* h)
	{
		nextHandler = h;
		return nextHandler;
	}
	void sendPayment(int sum) override
	{
		if (sum > 10000)
		{
			if (nextHandler)
				nextHandler->sendPayment(sum);
			else
				cout << "Нужен совет директоров, а у нас его нет! Платеж проведён не будет. " << endl;
		}
		else
		{
			cout << "Платёж проведен директором" << endl;
		}
	}
};






//////////////////////////////////////////////////////////
//Client* client = new Client;
//client->
//setHandler(new EconomistHandler)->
//setHandler(new BuhgalterHandler)->
//setHandler(new DirectorHandler);
//client->sendPayment(1200);