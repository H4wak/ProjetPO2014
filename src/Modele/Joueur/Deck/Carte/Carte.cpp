/* 
   Fichier Carte.cpp

   Définition des méthodes de Carte
*/


#include <iostream>
#include <sstream> // pour les conversions en chaine
#include <typeinfo>

using namespace std;

/////////////////////////////////////////////////////////////////////////
Carte::Carte(int pdv, int pa, std::string nom, int coutmana, bool charge, bool provoc)
{
   this->pdv = pdv;
   this->pdvmax = pdv;
   this->pa = pa;
   this->nom = nom;
   this->coutmana = coutmana;
   this->charge = charge;
   this->provoc = provoc;
   if (charge == 1 ){
   	this->malinvoc = 0;
   } else {
   	this->malinvoc = 1;
   }
   
}

Carte::Carte()
{
   this->pdv = -1;
   this->pdvmax = -1;
   this->pa = -1;
   this->nom = "";
   this->coutmana = -1;
   this->charge = false;
   this->provoc = false;
   this->malinvoc = false;
   
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
int Carte::getPdvmax()
{
  return this->pdvmax;  
}

/////////////////////////////////////////////////////////////////////////
void Carte::setPdvmax(int i)
{
  this->pdvmax = i;
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
bool Carte::getCharge(){
	return this->charge;
}
/////////////////////////////////////////////////////////////////////////
void Carte::setCharge(bool c){
	this->charge =c;
}
/////////////////////////////////////////////////////////////////////////
bool Carte::getProvoc(){
	return this->provoc;
}
/////////////////////////////////////////////////////////////////////////
void Carte::setProvoc(bool p){
	this->provoc =p;
}

/////////////////////////////////////////////////////////////////////////
bool Carte::getMalinvoc(){
	return this->malinvoc;
}
/////////////////////////////////////////////////////////////////////////
void Carte::setMalinvoc(bool m){
	this->malinvoc = m;
}
/////////////////////////////////////////////////////////////////////////

string Carte::toString()
{
   string result;
   
   string Spdv = static_cast<ostringstream*>( &(ostringstream() << this->pdv) )->str(); 
   string Spa = static_cast<ostringstream*>( &(ostringstream() << this->pa) )->str();
   string Scm = static_cast<ostringstream*>( &(ostringstream() << this->coutmana) )->str();
   
   result = "Nom: " + this->nom +" Attaque: " + Spa + " PDV:" + Spdv + " Cout mana:" + Scm ;
   
   if (this->charge == true)
   {
   		result += " Charge ";
   }
   
   if (this->provoc == true)
   {
   		result += " Provocation ";
   }

   return result ;
}

