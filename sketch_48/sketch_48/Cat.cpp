#include "stdafx.h"
#include <iostream>
#include "Cat.h"

Cat::Cat() {
	std::cout << "birthed a cat" << std::endl;
	hungry = true;
}

Cat::~Cat() {
	std::cout << "killed a cat" << std::endl;
}

void Cat::speak() {
	if (hungry) {
		std::cout << "Grr! I'm a hungry cat!!!" << std::endl;
	} else {
		std::cout << "Myow! I'm a cat!" << std::endl;
	}
}

void Cat::starve() {
	hungry = true;
}

void Cat::feed() {
	hungry = false;
}