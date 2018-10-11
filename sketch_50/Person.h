#pragma once
#include <iostream>
#include <string>

using  namespace std;
class Person
{
private:
	string name;
	int age;
public:
	Person():name("John Doe"), age(0) {};
	Person(string name, int age) : name(name), age(age) {};

	string toString();

};

