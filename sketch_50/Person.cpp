#include "stdafx.h"
#include "Person.h"
#include <sstream>


string Person::toString() {
	stringstream ss;

	ss << "name: ";
	ss << name;
	ss << "; age: ";
	ss << age;
	return ss.str();
}