// sketch_50.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Person.h"

using namespace std;
int main()
{	
	Person person1;
	Person person2("Jane", 30);
	cout << person1.toString() << endl;
	cout << person2.toString() << endl;
    return 0;
}

