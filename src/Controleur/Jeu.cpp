/*
   Fichier Jeu.cpp

   Définition des méthodes de Jeu
*/


#include <iostream>
#include <sstream> // pour les conversions en chaine
#include <typeinfo>

using namespace std; // seulement dans le .cpp !

/////////////////////////////////////////////////////////////////////////

Jeu::Jeu(Joueur* j1, Joueur* j2)
{
   this->joueurCourant = j1;
   this->joueurAutre = j2;
   this->tourJoueur1 = new TourJoueur1(this);
   this->tourJoueur2 = new TourJoueur2(this);
   this->tourCourant = this->tourJoueur1;
}

/////////////////////////////////////////////////////////////////////////

Jeu::~Jeu()
{
}

/////////////////////////////////////////////////////////////////////////
Joueur* Jeu::getJoueurCourant()
{
  return this->joueurCourant;  
}

/////////////////////////////////////////////////////////////////////////
Joueur* Jeu::getJoueurAutre()
{
  return this->joueurAutre;  
}

/////////////////////////////////////////////////////////////////////////
void Jeu::echangeJoueur()
{
  Joueur* tmp = this->joueurCourant;
  joueurCourant = this->joueurAutre; 
  joueurAutre = tmp;
}

/////////////////////////////////////////////////////////////////////////
Tour* Jeu::getTourCourant()
{
  return this->tourCourant;  
}

/////////////////////////////////////////////////////////////////////////
Tour* Jeu::getTourJoueur1()
{
  return this->tourJoueur1;  
}

/////////////////////////////////////////////////////////////////////////
Tour* Jeu::getTourJoueur2()
{
  return this->tourJoueur2;  
}	

/////////////////////////////////////////////////////////////////////////
void Jeu::setTour(Tour* t)
{
	this->tourCourant = t;
}

/////////////////////////////////////////////////////////////////////////
void Jeu::finTour()
{
	this->tourCourant->finTour();
}
/////////////////////////////////////////////////////////////////////////

void Jeu::jouer()
{
	cout << "C'est à " + this->joueurCourant->getNom() + " de jouer." << endl;	
	
	if (this->joueurCourant->getPersonnage().getPdm() < 10)
	{
		this->joueurCourant->setPDM(this->joueurCourant->getPersonnage().getPdm()+1);	
	}
	
	int pdmn = this->joueurCourant->getPersonnage().getPdm();
	cout <<  "Vous avez " ;
	cout <<  pdmn ;
	cout << " points de Mana." << endl;
	
	cout << "pioche" << endl;
	
	this->joueurCourant->ajouterMain(this->joueurCourant->getDeck()->tirerCarte());
	
	
	cout << this->joueurCourant->afficherMain() << endl;
	
	
	int choix = 25;
	int choixcarte;
	

	while (choix != 0) {	
	
	cout << "Que voulez vous faire ?" << endl;
	
	cout << "0 -> passer votre tour. \n1 -> afficher votre main. \n2 -> jouer une carte. \n3 -> afficher le board. \n4 -> Afficher votre personnage." << endl;
	cin >> choix;
		switch (choix)
		{
		     case 1: {
		     	  cout << "\n●●--●●--●● VOTRE MAIN ●●--●●--●●" << endl;
		          cout <<  this->joueurCourant->afficherMain() << endl; 
		          cout << "●●--●●--●●--●●--●●--●●--●●--●●--●●\n" << endl;
		          break;
		    }
		    case 2:
		   {
		   		cout << "Quelle carte voulez-vous jouez ?" << endl;
		   		cin >> choixcarte;
		   	
		   		if ( this->joueurCourant->getMain()->at(choixcarte-1).getCoutmana() <= pdmn)
		   		{
		   			
		   			this->joueurCourant->ajouterBoard(this->joueurCourant->getMain()->at(choixcarte-1));
		   			
		   			pdmn = pdmn - this->joueurCourant->getMain()->at(choixcarte-1).getCoutmana();
		   			cout << "Il vous reste ";
		   			cout <<  pdmn ;
		   			cout <<  " points de Mana." << endl;
		   		 	this->joueurCourant->supprimerMain(choixcarte);
		   		 	
		   		}else{
		   			
		   			cout << "Pas assez de Mana !" << endl;
		         }
		          break;
		    }
		    case 3:
		   {	cout << "\n°•. °•. °•. VOTRE BOARD .•° .•° .•°" << endl;
		   		cout << this->joueurCourant->afficherBoard() << endl;
		        cout << "°•. °•. °•. °•. °•. .•° .•° .•° .•° .•°\n" << endl; 
		          
				break;
    		}
    		
    		case 4:
    		{
    			int pdvv = this->joueurCourant->getPersonnage().getPdv();
    			int pdmm = this->joueurCourant->getPersonnage().getPdm();
    			int armm = this->joueurCourant->getPersonnage().getArmure();
    			string pdv = static_cast<ostringstream*>( &(ostringstream() << pdvv)  )->str();
    			string pdm = static_cast<ostringstream*>( &(ostringstream() << pdmn)  )->str();
    			string arm = static_cast<ostringstream*>( &(ostringstream() << armm)  )->str();
    			
    			cout << "\n Vous avez " + pdv + " points de vie. " << endl;
    			cout << " Vous avez " + pdm + " points de Mana. " << endl;
    			cout << " Vous avez " + arm + " points d'armure. \n" << endl;
    			
    			
    			break;
    		}
		}
	}
	
	
	cout << "\n▁ ▂ ▄ ▅ ▆ ▇ █ Fin du Tour █ ▇ ▆ ▅ ▄ ▂ ▁\n" << endl;
	this->finTour();


}


















