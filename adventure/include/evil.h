/**
 * @file evil.h
 * @author Manuel Gachs Ballegeer
 */
 
#include<string>

#ifndef _EVIL_H
#define _EVIL_H
/**
 * TDA Goblin
 * El TDA Goblin representa a un trasgo, con su nombre y sus puntos de vida
 */
struct Goblin {
	int hp; ///> Puntos de vida del trasgo
	std::string name; ///> Nombre del trasgo
};
/**
 * @brief Crea un trasgo
 * @param _name Nombre del trasgo
 * @param _hp Puntos de vida del trasgo
 * @return El trasgo creado
 */
Goblin goblin(std::string _name,int _hp);
/**
 * @brief Comprueba si un trasgo está muerto
 * @param g Trasgo del que se quiere comprobar su estado
 * @return @retval true Si el trasgo está muerto (hp<=0)
 * 	   @retval false Si el trasgo sigue vivo
 */
bool died(const Goblin &g);
/**
 * @brief Determina si un golpe acierta en el trasgo
 * @param g Trasgo al que se le golpea. ES MODIFICADO
 * @param dmg Daño que se le hace al goblin si es golpeado
 */
void hit(Goblin &g,int dmg);
/**
 * @brief Crea un trasgo aleatorio
 * @return El trasgo creado
 */
Goblin randomise();

#endif
