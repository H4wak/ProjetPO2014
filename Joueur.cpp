/*
   Fichier Joueur.cpp

   Définition des méthodes de Joueur
*/


#include <iostream>
#include <sstream> // pour les conversions en chaine
#include <typeinfo>

using namespace std; // seulement dans le .cpp !

/////////////////////////////////////////////////////////////////////////

Joueur::Joueur(std::string nom, Personnage p, std::string fichier)
{
   this->nom = nom; 
   this->p = p;
   this->d = new Deck(fichier);
   this->main = new vector<Carte>();
   this->board = new vector<Carte>();
     
}

/////////////////////////////////////////////////////////////////////////

Joueur::~Joueur()
{
}

/////////////////////////////////////////////////////////////////////////
Deck* Joueur::getDeck()
{
  return this->d;  
}



/////////////////////////////////////////////////////////////////////////
vector<Carte>* Joueur::getMain()
{
  return this->main;  
}

/////////////////////////////////////////////////////////////////////////
vector<Carte>* Joueur::getBoard()
{
  return this->board;  
}

/////////////////////////////////////////////////////////////////////////
std::string Joueur::getNom()
{
  return this->nom;  
}

/////////////////////////////////////////////////////////////////////////
void Joueur::setNom(std::string n)
{
  this->nom = n;
}

/////////////////////////////////////////////////////////////////////////
Personnage Joueur::getPersonnage()
{
  return this->p;  
}

/////////////////////////////////////////////////////////////////////////
void Joueur::setPersonnage(Personnage p)
{
  this->p = p;
}
/////////////////////////////////////////////////////////////////////////
string Joueur::afficherMain()
{
	string result;
	int i =0;
	int size;
	
	size = this->main->size();
	
	if (size == 0) 
	{
		return "Main vide!";
	} else {
	
		while ( i < size)
		{
			string Spdv = static_cast<ostringstream*>( &(ostringstream()<<this->main->at(i).getPdv()) )->str();
			string Spa = static_cast<ostringstream*>( &(ostringstream() << this->main->at(i).getPa()) )->str();
			string Scm = static_cast<ostringstream*>( &(ostringstream() << this->main->at(i).getCoutmana()) )->str();
		
			result = "Nom: " + this->main->at(i).getNom() +" Attaque: " + Spdv + " PDV:" + Spa + " Cout mana:" + Scm + "\n";
			i++;
		}
	}
	
	
	return result;
	
	
}

/////////////////////////////////////////////////////////////////////////
bool Joueur::ajouterMain(Carte* c)
{
	
	int i = 0;
	
	if (this->main->size() >= tailleMain)
	{
		cout << "Main pleine !" << endl;
		return false;
	} else {
		 main->push_back (*c);
		 return true;
	}
		
	
}

//////////////////////////////////////////////////////////////////////////
bool Joueur::ajouterBoard(Carte* c)
{
	int i = 0;
	
	if (this->board->size() >= tailleBoard)
	{
		cout << "Board plein !" << endl;
		return false;
	} else {
		 board->push_back (*c);
		 return true;
	}
		
	
}

