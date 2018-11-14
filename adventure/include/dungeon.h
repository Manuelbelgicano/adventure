/**
 * @file dungeon.h
 * @author Manuel Gachs Ballegeer
 */

#include"evil.h"
#include<string>

#ifndef _DUNGEON_H
#define _DUNGEON_H

void start();
int event(Goblin &g);
bool walk(int &coins);
int punch();
std::string happens(bool &dead,bool &goblin,int &coins);

#endif
