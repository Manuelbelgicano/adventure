/**
 * @file dungeon.h
 * @author Manuel Gachs Ballegeer
 */

#include"goblin.h"
#include<string>

#ifndef _DUNGEON_H
#define _DUNGEON_H

/**
 * @brief Comienza la semilla de números aleatorios
 */
void start();
/**
 * @brief Describe un enfrentamiento con un trasgo
 * @param g Trasgo al que se enfrenta el usuario. ES MODIFICADO
 * @return El número de monedas ganadas en el enfrentamiento
 */
int event(Goblin &g);
/** 
 * @brief Describe una aventura por la mazmorra
 * @param coins Monedas ganadas por el usuario durante la aventura. ES MODIFICADO
 * @return @retval true Si el usuario está vivo
 * 	   @retval false Si el usuario ha muerto
 */
bool walk(int &coins);
/**
 * @brief Calcula el daño de un golpe
 * @return El daño del golpe
 */
int punch();
std::string happens(bool &dead,bool &goblin,int &coins);

#endif
