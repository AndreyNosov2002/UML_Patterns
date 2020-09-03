#pragma once
#include<string>
#include<iostream>


using namespace std;


class TextEditor
{
public:
	void createCode()
	{
		cout << "��������� ����" << endl;
	}
	void save()
	{
		cout << "���������� ����" << endl;
	}
};


class Compiller
{
public:
	void compile()
	{
		cout << "���������� ����" << endl;
	}

};


class Debager
{
public:
	void execute()
	{
		cout << "��������� ������ �������" << endl;
	}
	void finish()
	{
		cout << "���������� ������ ����������" << endl;
	}
};


class VisualStudioFassade
{
	TextEditor* te;
	Compiller* comp;
	Debager* deb;
public:
	VisualStudioFassade()
	{
		te = new TextEditor;
		comp = new Compiller;
		deb = new Debager;
	}
	void start()
	{
		te->createCode();
		te->save();
		comp->compile();
		deb->execute();
	}
	void stop()
	{
		deb->finish();
	}
};




/////////////////////////////////////////
//VisualStudioFassade* vs2019 = new VisualStudioFassade;
//vs2019->start();
//vs2019->stop();

