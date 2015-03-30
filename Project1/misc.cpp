#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include "misc.h"

void saveError(const std::string &c)
{
	std::fstream outStream;
	outStream.open("debug.log", std::ofstream::app);

	if (!outStream.good())
	{
		printf("ERROR: Could not open \"debug.log\"!\n");
		return;
	}

	outStream << c;

	outStream.close();
}

void KGprintError(const char *functionName, const char *errorType, const char *errorDescription, const char *otherInfo, void *pointerVal, const void *classThis, const void *parentPointer, const char *severity)
{
	std::stringstream c;
	
	c << "-BEGIN DEBUG-\n"
		<< "Hey you just encountered an error!\nPlease send this error log to support@knoobgroup.com\nif you can't easily resolve the problem\n"
		<< "Calling function=" << functionName
		<< "\nerror type=" << errorType
		<< "\nerror description=" << errorDescription
		<< "\naddress=" << (unsigned long)pointerVal
		<< "\nadress data (if applicible)=" << (const char*)pointerVal
		<< "\nparent adress (if applicible)=" << (unsigned long)parentPointer
		<< "\nparent adress data (if applicible)=" << ((parentPointer) ? (const char*)parentPointer : "null")
		<< "\nadditional info=" << otherInfo
		<< "\nseverity level=" << severity
		<< "\n--END DEBUG--\n";

	printf(c.str().c_str());
	saveError(c.str());
}