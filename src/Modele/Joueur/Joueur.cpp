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
			string index = static_cast<ostringstream*>( &(ostringstream() << i+1) )->str();
			string lel = this->main->at(i).toString();
			result +=  index +". " + lel + "\n";
			
			i++;
		}
	}
	
	
	return result;
	
	
}


/////////////////////////////////////////////////////////////////////////
string Joueur::afficherBoard()
{
	string result;
	int i =0;
	int size;
	
	size = this->board->size();
	
	if (size == 0) 
	{
		return "Board vide!";
	} else {
	
		while ( i < size)
		{
			string index = static_cast<ostringstream*>( &(ostringstream() << i+1) )->str();
			string lel = this->board->at(i).toString();
			result +=  index +". " + lel + "\n";
			
			
			i++;
		}
	}
	
	
	return result;
	
	
}

/////////////////////////////////////////////////////////////////////////
bool Joueur::ajouterMain(Carte c)
{
	
	
	if (this->main->size() >= tailleMain)
	{
		cout << "Main pleine !" << endl;
		return false;
	} else {
		 main->push_back (c);
		 return true;
	}
		
	
}

//////////////////////////////////////////////////////////////////////////
bool Joueur::ajouterBoard(Carte c)
{
	
	if (this->board->size() >= tailleBoard)
	{
		cout << "Board plein !" << endl;
		return false;
	} else {
		 board->push_back (c);
		 return true;
	}
		
	
}

//////////////////////////////////////////////////////////////////////////
bool Joueur::supprimerMain(int index)
{
	string sindex = static_cast<ostringstream*>( &(ostringstream() << index) )->str();
	if (index-1 >= tailleMain || index-1 < 0 || index > this->main->size() )
	{	
		cout << "Index "+ sindex +" hors de la Main !!" << endl;
		return false;
	} else {
		main->erase (this->main->begin()+index-1);
		cout << " la carte n°"+ sindex + " a été enlevée de la main"<< endl;
		return true;
	}
}
		
//////////////////////////////////////////////////////////////////////////
bool Joueur::supprimerBoard(int index)
{
	string sindex = static_cast<ostringstream*>( &(ostringstream() << index) )->str();
	if (index-1 >= tailleBoard || index-1 < 0 || index > this->board->size()) 
	{	
		cout << "Index "+ sindex+" hors du Board !!" << endl;
		return false;
	} else {
		board->erase (this->board->begin()+index-1);
		cout << " la carte n°"+ sindex + " a été enlevée du board"<< endl;
		return true;
	}
}
//////////////////////////////////////////////////////////////////////////
void Joueur::setPDM(int npdm)
{
	this->p.setPdm(npdm);

}



