/**
 * @file main.cpp
 * @author Manuel Gachs Ballegeer
 */
#include"dungeon.h"
#include<iostream>

int main() {
	start();
	int coins = 0;
	bool dead = false;
	do {
		dead = walk(coins);
	} while (!dead);
	std::cout<<"YOU DIE. YOUR SCORE: "<<coins<<std::endl;
	return 0;
}
