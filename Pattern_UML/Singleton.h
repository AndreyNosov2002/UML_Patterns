#pragma once

#include<string>
#include<iostream>
#include<fstream>

using namespace std;

class Logger
{
	Logger(){}
	static Logger* obj;
public:
	static Logger* getInstance();
	void sengMessage(string message);

};

Logger* Logger::obj = nullptr;
Logger* Logger::getInstance()
{
	if (!obj)
		obj = new Logger;
	return obj;
}



void Logger::sengMessage(string message)
{
	ofstream out("log.txt", ios::app);
	out << message << " - " << __DATE__ << " - " << __TIME__ << endl;
	out.close();
}




//Logger* logger = Logger::getInstance();
//logger->sengMessage("Error #1");
//logger->sengMessage("Error #2");