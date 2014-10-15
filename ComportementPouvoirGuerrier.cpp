/*
   Fichier Guerrier.cpp

   Définition des méthodes de ComportementPouvoirGuerrier
*/


#include <iostream>
#include <sstream> // pour les conversions en chaine
#include <typeinfo>

using namespace std; // seulement dans le .cpp !

/////////////////////////////////////////////////////////////////////////

ComportementPouvoirGuerrier::ComportementPouvoirGuerrier()
{

}

/////////////////////////////////////////////////////////////////////////

ComportementPouvoirGuerrier::~ComportementPouvoirGuerrier()
{
}

/////////////////////////////////////////////////////////////////////////

void ComportementPouvoirGuerrier::pouvoir()
{
   cout << "POUR HURLENFER!";
}


