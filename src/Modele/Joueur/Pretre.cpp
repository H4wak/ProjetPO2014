/**
*Fichier Pretre.cpp
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
Pretre::Pretre(string nom,string fichier): Joueur(nom,fichier)
{
  ComportementPouvoirPretre* CPP = new ComportementPouvoirPretre(this);
  this->setCP(CPP);
}

/////////////////////////////////////////////////////////////////////////
/**
* Destructeur
*/
Pretre::~Pretre()
{
}

