/* 
   Fichier Deck.cpp

   Définition des méthodes de Deck
*/


#include <iostream>
#include <sstream> // pour les conversions en chaine
#include <typeinfo>

using namespace std;

/////////////////////////////////////////////////////////////////////////
int myrandom (int i) { return rand()%i;}
/////////////////////////////////////////////////////////////////////////
Deck::Deck(string fichier)
{
  int pdv,pa,cm,i,j,sz,r1;
  i = 0;
  j = 0;  
  string ligne,nom;
  bool charge,provoc;  
  vector<Carte> myvector;
  ifstream ifs(fichier.c_str());
  
  srand(time(0));
  
  if(ifs)
	{
		while(getline(ifs,ligne))
		{

			istringstream iss(ligne);
			iss >> pdv;
			iss >> pa;
			iss >> nom;
			iss >> cm;
			iss >> charge;
			iss >> provoc;
			//cout << pdv << " " << pa << " " << nom << " " << cm << endl;
			Carte * c = new Carte(pdv,pa,nom,cm,charge,provoc);
			
			myvector.push_back(*c);
			//d.push(*c);
			
			std::random_shuffle ( myvector.begin(), myvector.end() );

			// using myrandom:
  			std::random_shuffle ( myvector.begin(), myvector.end(), myrandom);
  			
			i++;
			
			//cout << c->toString() << endl;
		}
	}
	else
	{
		cout<<"erreur"<<endl;
	}
	
  sz = myvector.size();
   
  for (j=0; j < sz ; j++)
  {
  	d.push(myvector[j]);
  }
  
  
  this->taille = i;
  
  usleep(2000000);
  
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




