#include "stdafx.h"
#include "Animal.h"
#include <string>

Animal::Animal() {
	life = "alive";
}

void Animal::slay(string newLife) {
	life = newLife;
}

 

string Animal::toString() {
	return "Animal is " + life;
	
}