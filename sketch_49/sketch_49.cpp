// sketch_49.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Animal.h"
#include <string>

using namespace std;
int main()
{
	Animal beast;
	cout << "hello" << endl;
	cout << beast.toString() << endl;

	beast.slay("ded");
	cout << beast.toString() << endl;


    return 0;
}

