/*
   Fichier Personnage.cpp

   Définition des méthodes de Personnage
*/


#include <iostream>
#include <sstream> // pour les conversions en chaine
#include <typeinfo>

using namespace std; // seulement dans le .cpp !

/////////////////////////////////////////////////////////////////////////

Personnage::Personnage()
{
	this->pdv = 30;
	this->armure = 0;
	this->pdm = 0;
	this->CP = new ComportementPouvoirGuerrier();
}

/////////////////////////////////////////////////////////////////////////

Personnage::~Personnage()
{
}

/////////////////////////////////////////////////////////////////////////

int Personnage::getPdv()
{
   return this->pdv;
}

/////////////////////////////////////////////////////////////////////////

void Personnage::setPdv(int npdv)
{
   this->pdv = npdv;
}


/////////////////////////////////////////////////////////////////////////

int Personnage::getArmure()
{
   return this->armure;
}

/////////////////////////////////////////////////////////////////////////

void Personnage::setArmure(int narmure)
{
   this->armure = narmure;
}

/////////////////////////////////////////////////////////////////////////

int Personnage::getPdm()
{
   return this->pdm;
}

/////////////////////////////////////////////////////////////////////////

void Personnage::setPdm(int npdm)
{
   this->pdm = npdm;
}

/////////////////////////////////////////////////////////////////////////

string  Personnage::toString()
{
   string Spdv = static_cast<ostringstream*>( &(ostringstream() << this->pdv) )-> str();
   string Sarmure = static_cast<ostringstream*>( &(ostringstream() << this->armure) )-> str();
   string Spdm = static_cast<ostringstream*>( &(ostringstream() << this->pdm) )-> str();
   
   return "pdv: " +Spdv+ " armure: " +Sarmure+ " pdm: " +Spdm;
}


/////////////////////////////////////////////////////////////////////////

ComportementPouvoir* Personnage::getCP()
{
   return this->CP;
}

/////////////////////////////////////////////////////////////////////////

void Personnage::setCP(ComportementPouvoir* CP)
{
   this->CP = CP;
}

/////////////////////////////////////////////////////////////////////////

std::string Personnage::utiliserPouvoir()
{
   return this->CP->pouvoir();
}


