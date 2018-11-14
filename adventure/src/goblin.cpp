/**
 * @file goblin.cpp
 * @author Manuel Gachs Ballegeer
 */
 
#include"evil.h"
#include<iostream>
#include<stdlib.h>

Goblin goblin(std::string _name,int _hp) {
	Goblin gobbo;
	gobbo.name = _name;
	gobbo.hp = _hp;
	return gobbo;
}

bool died(const Goblin &g) {
	if (g.hp<=0) {
		std::cout<<g.name<<" died! You can now resume\n";
		return true;
	} else {
		std::cout<<"You fool! "<<g.name<<" isn't dead\n";
		return false;
	}
}

void hit(Goblin &g,int dmg) {
	int aux = rand() % 4 + 1;
	if (aux%2==0) {
		g.hp -= dmg;
		std::cout<<"You hit "<<g.name<<" for "<<dmg<<" damage!\n";
	} else
		std::cout<<"You are very slow! "<<g.name<<" dodged your attack\n";
}

Goblin randomise() {
	Goblin gobbo;
	int aux = rand() % 3;
	switch (aux) {
		case 0:
			gobbo.name = "Konga Gigablade";
			gobbo.hp = 6;
			break;
		case 1:
			gobbo.name = "Mes Haggleclamp";
			gobbo.hp = 3;
			break;
		case 2:
			gobbo.name = "Kwanqeenk Fiercebeast";
			gobbo.hp = 5;
			break;
		case 3:
			gobbo.name = "Gune Fickledust";
			gobbo.hp = 4;
			break;
		default:
			gobbo.name = "Squee";
			gobbo.hp = 1;
			break;
	}
	return gobbo;
}
