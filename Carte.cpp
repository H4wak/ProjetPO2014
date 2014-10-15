/* 
   Fichier Carte.cpp

   Définition des méthodes de Carte
*/


#include <iostream>
#include <sstream> // pour les conversions en chaine
#include <typeinfo>

using namespace std;

/////////////////////////////////////////////////////////////////////////
Carte::Carte(int pdv, int pa, std::string nom, int coutmana)
{
   this->pdv = pdv;
   this->pa = pa;
   this->nom = nom;
   this->coutmana = coutmana;

}

Carte::Carte()
{
   this->pdv = -1;
   this->pa = -1;
   this->nom = "";
   this->coutmana = -1;
}


/////////////////////////////////////////////////////////////////////////
Carte::~Carte()
{

}

/////////////////////////////////////////////////////////////////////////
int Carte::getPdv()
{
  return this->pdv;  
}

/////////////////////////////////////////////////////////////////////////
void Carte::setPdv(int i)
{
  this->pdv = i;
}

/////////////////////////////////////////////////////////////////////////
int Carte::getPa()
{
	return this->pa; 
}

/////////////////////////////////////////////////////////////////////////
void Carte::setPa(int i)
{
  this->pa = i;
}

/////////////////////////////////////////////////////////////////////////
string Carte::getNom()
{
	return this->nom; 
}

/////////////////////////////////////////////////////////////////////////
void Carte::setNom(string n)
{
  this->nom = n; 
}

/////////////////////////////////////////////////////////////////////////
int Carte::getCoutmana()
{
	return this->coutmana;
}

/////////////////////////////////////////////////////////////////////////
void Carte::setCoutmana(int i)
{
  this->coutmana = i;
}

/////////////////////////////////////////////////////////////////////////
string Carte::toString()
{
   string Spdv = static_cast<ostringstream*>( &(ostringstream() << this->pdv) )->str(); 
   string Spa = static_cast<ostringstream*>( &(ostringstream() << this->pa) )->str();
   string Scm = static_cast<ostringstream*>( &(ostringstream() << this->coutmana) )->str();

   return "Nom: " + this->nom +" Attaque: " + Spdv + " PDV:" + Spa + " Cout mana:" + Scm ;
}

