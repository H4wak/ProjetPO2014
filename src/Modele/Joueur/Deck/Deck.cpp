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
  int pdv,pa,cm,fct,i,j,sz,r1;
  i = 0;
  j = 0;  
  string ligne,nom,des;
  bool charge,provoc,sort;  
  vector<Carte> myvector;
  ifstream ifs(fichier.c_str());
  
  srand(time(0));
  
  if(ifs)
	{
		while(getline(ifs,ligne))
		{

			istringstream iss(ligne);
			iss >> pa;
			iss >> pdv;
			iss >> nom;
			iss >> cm;
			iss >> charge;
			iss >> provoc;
			iss >> sort;
			iss >> fct;
			iss >> des;
			//cout << pdv << " " << pa << " " << nom << " " << cm << endl;
			
			replace(nom.begin(),nom.end(),'_',' ');
			replace(des.begin(),des.end(),'_',' ');
			
			Carte * c = new Carte(pdv,pa,nom,cm,charge,provoc,sort,fct,des);
			
			myvector.push_back(*c);
			//d.push(*c);
			
			std::random_shuffle ( myvector.begin(), myvector.end() );

			// using myrandom:
  			std::random_shuffle ( myvector.begin(), myvector.end(), myrandom);
  			
			i++;
			
			cout << c->toString() << endl;
		}
	}
	else
	{
		cout<<"erreur dans la creation du deck"<<endl;
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





