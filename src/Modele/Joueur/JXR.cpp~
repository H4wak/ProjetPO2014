/**
*Fichier JXR.cpp
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
JXR::JXR(string nom,string fichier): Joueur(nom,fichier)
{
  ComportementPouvoirJXR* CPM = new ComportementPouvoirJXR(this);
  this->setCP(CPM);
}

/////////////////////////////////////////////////////////////////////////
/**
* Destructeur
*/
JXR::~JXR()
{
}

