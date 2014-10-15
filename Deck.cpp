/* 
   Fichier Deck.cpp

   Définition des méthodes de Deck
*/


#include <iostream>
#include <sstream> // pour les conversions en chaine
#include <typeinfo>

using namespace std;

/////////////////////////////////////////////////////////////////////////
Deck::Deck(string fichier)
{
  int pdv,pa,cm,i;
  i = 0;  
  string ligne,nom;  
  ifstream ifs(fichier.c_str());
  if(ifs)
	{
		while(getline(ifs,ligne))
		{

			istringstream iss(ligne);
			iss >> pdv;
			iss >> pa;
			iss >> nom;
			iss >> cm;
			//cout << pdv << " " << pa << " " << nom << " " << cm << endl;
			Carte * c = new Carte(pdv,pa,nom,cm);
			d.push(*c);
			i++;
			
			//cout << c->toString() << endl;
		}
	}
	else
	{
		cout<<"erreur"<<endl;
	}

  this->taille = i;
}

/////////////////////////////////////////////////////////////////////////
Deck::~Deck()
{

}


/////////////////////////////////////////////////////////////////////////
int Deck::getTaille()
{
  return this->taille;  
}

/////////////////////////////////////////////////////////////////////////
void Deck::setTaille(int t)
{
  this->taille = t;
}

/////////////////////////////////////////////////////////////////////////
Carte Deck::tirerCarte()
{
	Carte c = d.top();
	d.pop();
	return c;
	
}

/////////////////////////////////////////////////////////////////////////
stack<Carte> Deck::getStack()
{
  return this->d;  
}





