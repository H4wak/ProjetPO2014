/**
*Fichier Demoniste.cpp
* @author Pierre Gaultier & Theo Dolez
*/


#include <iostream>
#include <sstream> // pour les conversions en chaine
#include <typeinfo>

using namespace std; // seulement dans le .cpp !

/////////////////////////////////////////////////////////////////////////
/**
* Constructeur.
*/
Demoniste::Demoniste(string nom,string fichier): Joueur(nom,fichier)
{
  ComportementPouvoirDemoniste* CPD = new ComportementPouvoirDemoniste(this);
  this->setCP(CPD);
}

/////////////////////////////////////////////////////////////////////////
/**
* Destructeur
*/
Demoniste::~Demoniste()
{
}

