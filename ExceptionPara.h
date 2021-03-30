#include <exception>
#include <iostream>

using namespace std;

#ifndef EXCEPTION_H
#define EXCEPTION_H

class ExceptionPara : public exception
{
	private :
	string data;
	public :
	ExceptionPara(string);
	string message();
};

#endif
