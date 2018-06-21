// sketch_48.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include "Cat.h"

int main()
{
	{
		Cat cat1;
		cat1.starve();
		cat1.speak();
	}

	Cat cat2;
	cat2.feed();
	cat2.speak();
	return 0;
}

