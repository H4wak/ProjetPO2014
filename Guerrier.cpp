/*
   Fichier Guerrier.cpp

   Définition des méthodes de Guerrier
*/


#include <iostream>
#include <sstream> // pour les conversions en chaine
#include <typeinfo>

using namespace std; // seulement dans le .cpp !

/////////////////////////////////////////////////////////////////////////

Guerrier::Guerrier()
{
	this->setCP(new ComportementPouvoirGuerrier());
}

/////////////////////////////////////////////////////////////////////////

Guerrier::~Guerrier()
{
}


