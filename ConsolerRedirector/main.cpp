// ConsolerRedirector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ConsoleRedirector.h"
#include "ConsoleredirectorException.h"

int main()
{
	std::cout << "Hello World!\n";
	try
	{
		if (1)
		{
			ConsoleRedirector red("consoleLog.txt", true);
			std::cout << "console is to file";
			printf("\nconsole is to file");
		}
		std::cout << "\nconsole back to screen from cout";
		printf("\nconsole back to screen from printf");



		ConsoleRedirector red("consoleLog.txt", false);
		std::cout << "console is to file";
		printf("\nconsole is to file");
		red.Flush();
		std::cout << "more console is to file";
		printf("\nmore console is to file");
		red.Reset();
		std::cout << "\nconsole back to screen from cout";
		printf("\nconsole back to screen from printf");




	}
	catch (ConsoleRedirectorException& ex)
	{
		cout << "\ncException occured" << ex.what();
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
