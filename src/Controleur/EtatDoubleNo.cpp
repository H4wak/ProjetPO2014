/**
*Fichier EtatDoubleNo.cpp
* @author Pierre Gaultier & Theo Dolez
*/


#include <iostream>
#include <sstream> // pour les conversions en chaine
#include <typeinfo>

using namespace std; // seulement dans le .cpp !

/////////////////////////////////////////////////////////////////////////
/**
* Constructeur.
* @param j le jeu 
*/
EtatDoubleNo::EtatDoubleNo(Jeu* j)
{
	this->jeu = j;
}

/////////////////////////////////////////////////////////////////////////
/**
* Destructeur
*/
EtatDoubleNo::~EtatDoubleNo()
{
}

/////////////////////////////////////////////////////////////////////////
/**
* Methode qui renvoie le jeu
*@return jeu le jeu
*/
Jeu* EtatDoubleNo::getJeu()
{
  return this->jeu;  
}

/////////////////////////////////////////////////////////////////////////
/**
* Methode qui termine le tour en cours, et lance le suivant
*/
void EtatDoubleNo::finTour()
{
  jeu->setEtat(jeu->getEtatDebutTour());
  jeu->echangeJoueur();
  jeu->jouer();
}
/////////////////////////////////////////////////////////////////////////
int EtatDoubleNo::afficherChoixEtat()
{
	int choix = -1;
	int choixcarte;
	int choixcarte1, choixcarte2;
	int pdmn = jeu->getJoueurCourant()->getPersonnage().getPdm();
	
	
	cout << "\nETAT DOUBLE NO\n" << endl;
	
	jeu->getVue().afficherChoixDoubleNo();
	choix = jeu->getVue().getChoixActionTour();
		switch (choix)
		{
		    case 1: {
					jeu->getVue().afficherMain(jeu->getJoueurCourant());
					break;
		    }
		    
		    case 2: {	
				  jeu->getVue().afficherBoard(jeu->getJoueurCourant());
				  break;
    		}
    		case 3:
    		{
					jeu->getVue().afficher2Board(jeu->getJoueurCourant(),jeu->getJoueurAutre());
    				break;
    		}
    		case 4:
    		{
					jeu->getVue().afficherPersonnage(jeu->getJoueurCourant());
    				
    		}
    		
		}
	
	return choix;



}

