#include "ExceptionPara.h"

using namespace std;

ExceptionPara::ExceptionPara(string message)
{
	this->data=message;
}

/**********************************************************/

string ExceptionPara::message()
{
	return (this->data);
}
