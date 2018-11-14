/**
 * @file dungeon.cpp
 * @author Manuel Gachs Ballegeer
 */

#include<chrono>
#include<thread>
#include<iostream>
#include<time.h> 
#include<stdlib.h>
#include"dungeon.h"

void start() {
	srand(time(NULL));
}

int event(Goblin &g) {
	int dmg = 0;
	std::cout<<"You encounter a goblin!\n";
	std::cout<<g.name<<" - Taste my club, scum!\n";
	do {
		std::cout<<"Enter the force of your attack: ";
		std::cin>>dmg;
		std::this_thread::sleep_for(std::chrono::seconds(1));
		dmg = punch();
		hit(g,dmg);
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout<<g.name<<"'s club does nothing to your armor\n";		
	}while (!died(g));
	
	int coins = rand() % 5;
	std::cout<<"Wow, "<<g.name<<" had "<<coins<<" gold coins!\n";
	return coins;
}

bool walk(int &coins) {
	int move = 1;
	bool dead = false;
	std::string encounter;
	bool get_goblin = false;
	Goblin gobbo;
	
	while (!dead) {
		std::cout<<"Choose your movement:\n";
		std::cout<<"		0	exit\n";
		std::cout<<"		1	foward\n";
		std::cout<<"		2	left\n";
		std::cout<<"		3	right\n";
		std::cout<<"		4	backwards\n";
		std::cout<<"Your move: ";
		std::cin>>move;
		if (move==0 || move>4) {
			std::cout<<"You kill yourself with your own sword\n";
			dead = true;
		} else {
			encounter = happens(dead,get_goblin,coins);
			std::cout<<encounter<<std::endl;
			if (get_goblin) {
				gobbo = randomise();
				coins += event(gobbo);
			}
		}
	}
	return dead;
}

int punch() {
	int aux = rand() % 6 + 1;
	std::cout<<"You try to hit the stinky goblin for "<<aux<<" damage\n";
	return aux;
}

std::string happens(bool &dead,bool &goblin,int &coins) {
	int rng = rand() % 3;
	std::string encounter;
	
	switch (rng) {
		case 0:
			encounter = "You fall into a pit full of spikes. Sadly, you die";
			dead = true;
			break;
		case 1:
			encounter = "You find a treasure that contains 5 coins!";
			dead = false;
			coins += 5;
			break;
		case 2:
			encounter = "You enter a corridor full of human skulls, spooky as hell";
			dead = false;
			goblin = true;
			break;
		case 3:
			encounter = "You start running as you hear a strange sound";
			dead = false;
			goblin = true;
			break;
		default:
			encounter = "You suddenly fall and hit in the head. All turns black";
			dead = true;
			break;
	}
	return encounter;
}
