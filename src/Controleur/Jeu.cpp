/**
*Fichier Jeu.cpp
* @author Pierre Gaultier & Theo Dolez
*/


#include <iostream>
#include <sstream> // pour les conversions en chaine
#include <typeinfo>

using namespace std; // seulement dans le .cpp !

/////////////////////////////////////////////////////////////////////////
/**
* Constructeur
* @param j1 Joueur 1
* @param j2 Joueur2
*/
Jeu::Jeu(Joueur* j1, Joueur* j2)
{
   this->joueurCourant = j1;
   this->joueurAutre = j2;
   this->tourJoueur1 = new TourJoueur1(this);
   this->tourJoueur2 = new TourJoueur2(this);
   this->tourCourant = this->tourJoueur1;
}

/////////////////////////////////////////////////////////////////////////
/**
* Destructeur
*/
Jeu::~Jeu()
{
}

/////////////////////////////////////////////////////////////////////////
/**
* Methode qui retourne le joueur courant
* @return joueurCourant le joueur courant
*/
Joueur* Jeu::getJoueurCourant()
{
  return this->joueurCourant;  
}

/////////////////////////////////////////////////////////////////////////
/**
* Methode qui retourne le joueur autre
* @return joueurAutre le joueur autre
*/
Joueur* Jeu::getJoueurAutre()
{
  return this->joueurAutre;  
}

/////////////////////////////////////////////////////////////////////////
/**
* Methode qui echange le joueurCourant avec le joueur autre
*/
void Jeu::echangeJoueur()
{
  Joueur* tmp = this->joueurCourant;
  joueurCourant = this->joueurAutre; 
  joueurAutre = tmp;
}

/////////////////////////////////////////////////////////////////////////
/**
* Methode qui renvoie le tour courant
* @return tourCourant le tour courant
*/
Tour* Jeu::getTourCourant()
{
  return this->tourCourant;  
}

/////////////////////////////////////////////////////////////////////////
/**
* Methode qui renvoie le tour du joueur1
* @return tourCourant le tour du joueur1
*/
Tour* Jeu::getTourJoueur1()
{
  return this->tourJoueur1;  
}

/////////////////////////////////////////////////////////////////////////
/**
* Methode qui renvoie le tour du joueur2
* @return tourCourant le tour du joueur2
*/
Tour* Jeu::getTourJoueur2()
{
  return this->tourJoueur2;  
}	

/////////////////////////////////////////////////////////////////////////
/**
* Methode qui change le tourCourant
* @param t le nouveau tour
*/
void Jeu::setTour(Tour* t)
{
	this->tourCourant = t;
}

/////////////////////////////////////////////////////////////////////////
/**
* Methode qui appelle la methode finTour() sur le tour courant
*/
void Jeu::finTour()
{
	this->tourCourant->finTour();
}
/////////////////////////////////////////////////////////////////////////
/**
* Methode qui lance le jeu
*/
void Jeu::jouer()
{
	
	int pdmn = this->joueurCourant->getPersonnage().getPdm();
	if (this->joueurCourant->getPersonnage().getPdm() < 10)
	{
		this->joueurCourant->setPDM(this->joueurCourant->getPersonnage().getPdm()+1);	
	}
 	this->joueurCourant->ajouterMain(this->joueurCourant->getDeck()->tirerCarte());
  
  	
	enleverMalinvoc();
	
	vue.afficherDebutTour(joueurCourant);
	
	
	int choix = -1;
	int choixcarte;
	int choixcarte1, choixcarte2;
	
	while (choix != 0) {	
	vue.afficherChoix();
	choix = vue.getChoixActionTour();
		switch (choix)
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
					vue.afficher2Board(joueurCourant,joueurAutre);
    				break;
    		}
    		case 5:
    		{
					vue.afficherPersonnage(joueurCourant);
    				break;
    		}
    		case 6:
    		{
    				choixcarte1 = vue.getChoixCarteAJouer();
    				choixcarte2 = vue.getChoixCarteAJouer();
    				attaqueCvC(choixcarte1, choixcarte2);
    		}
		}
	}
	vue.afficherFinTour();
	this->finTour();
}
/////////////////////////////////////////////////////////////////////////
void Jeu::attaqueCvC(int index1, int index2)
{
	int pdv1,pdv2,attac1,attac2;
	
	if ( joueurCourant->getBoard()->at(index1-1).getMalinvoc() == true )
	{
		cout << "Cette carte vient d'être invoquée ! Impossible d'attaquer !" << endl;
	} else {
		
		pdv1 = joueurCourant->getBoard()->at(index1-1).getPdv();
		pdv2 = joueurAutre->getBoard()->at(index1-1).getPdv();
		attac1 = joueurCourant->getBoard()->at(index1-1).getPa();
		attac2 = joueurAutre->getBoard()->at(index1-1).getPa();
		
		joueurCourant->getBoard()->at(index1-1).setPdv(pdv1-attac2);
		joueurAutre->getBoard()->at(index1-1).setPdv(pdv2-attac1);
		
		if ( joueurCourant->getBoard()->at(index1-1).getPdv() <= 0 )
		{	
			joueurCourant->supprimerBoard(index1);
			cout << "Votre carte est tombée au combat !" << endl;
		}
		
		if ( joueurAutre->getBoard()->at(index1-1).getPdv() <= 0 )
		{	
			joueurAutre->supprimerBoard(index2);
			cout << "Vous avez triomphé de votre adversaire !" << endl;
		}
	}
	
	cout << "attaque terminée"<< endl;

}
/////////////////////////////////////////////////////////////////////////
void Jeu::enleverMalinvoc()
{
	int i,j;
	for ( i = 0; i < joueurCourant->getBoard()->size() ; i++ )
	{
		if ( joueurCourant->getBoard()->at(i).getMalinvoc() == true )
		{
			joueurCourant->getBoard()->at(i).setMalinvoc(false);
		}
	}
		
	for (j = 0; j < joueurAutre->getBoard()->size() ; j++ )
	{
		if ( joueurAutre->getBoard()->at(i).getMalinvoc() == true )
		{
			joueurAutre->getBoard()->at(i).setMalinvoc(false);
		}
	}
}
		
		
		
		
		
		


