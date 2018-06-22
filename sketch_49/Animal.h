#pragma once
#include "stdafx.h"
#include <iostream>

using namespace std;

class Animal {
private:
	string life;
	
public:
	Animal();
	void slay(string newLife);
	string toString();
};