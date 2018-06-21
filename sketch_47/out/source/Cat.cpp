#include "stdafx.h"
#include "Cat.h"

void Cat::speak() {
	if (!hungry) {
		std::cout << "Myow! I'm a cat!" << std::endl;
	}
	else {
		std::cout << "Grr! I'm a hungry cat!!!" << std::endl;
	}
}

void Cat::starve(){
	hungry = true;
}

void Cat::feed() {
	hungry = false;
}