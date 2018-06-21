#pragma once
#include "stdafx.h"

class Cat {
private:
	bool hungry;

public:
	void speak();
	void starve();
	void feed();
	Cat();
	~Cat();
};