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
	
	int pdmn = this->joueurCourant->getPersonnage().getPdm();
	if (this->joueurCourant->getPersonnage().getPdm() < 10)
	{
		this->joueurCourant->setPDM(this->joueurCourant->getPersonnage().getPdm()+1);	
	}
  this->joueurCourant->ajouterMain(this->joueurCourant->getDeck()->tirerCarte());
	
	vue.afficherDebutTour(joueurCourant);
	
	
	int choix = 25;
	int choixcarte;
	

	while (choix != 0 && choix <5) {	
	vue.afficherChoix();
		switch (vue.getChoixActionTour())
		{
		    case 1: {
					vue.afficherMain(joueurCourant);
					break;
		    }
		    case 2:  {
		   		vue.afficherJouerCarte();
		   		choixcarte = vue.getChoixCarteAJouer();
		   		if ( this->joueurCourant->getMain()->at(choixcarte-1).getCoutmana() <= pdmn)
		   		{
		   			this->joueurCourant->ajouterBoard(this->joueurCourant->getMain()->at(choixcarte-1));
		   			pdmn = pdmn - this->joueurCourant->getMain()->at(choixcarte-1).getCoutmana();
		   			vue.afficherPdmnRestant(pdmn);
		   		 	this->joueurCourant->supprimerMain(choixcarte);
		   		 	
		   		}else{
		   			
		   			vue.afficherPasAssezDeMana();
		      }
		      break;
		    }
		    case 3: {	
				  vue.afficherBoard(joueurCourant);
				  break;
    		}
    		case 4:
    		{
					vue.afficherPersonnage(joueurCourant);
    			break;
    		}
		}
	}
	
	
	vue.afficherFinTour();
	this->finTour();

}