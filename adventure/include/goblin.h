/**
 * @file goblin.h
 * @author Manuel Gachs Ballegeer
 */
 
#include<string>

#ifndef _EVIL_H
#define _EVIL_H

struct Goblin {
	int hp;
	std::string name;
};

Goblin goblin(std::string _name,int _hp);
bool died(const Goblin &g);
void hit(Goblin &g,int dmg);
Goblin randomise();

#endif
