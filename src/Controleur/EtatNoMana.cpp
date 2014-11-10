/**
*Fichier EtatNoMana.cpp
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
EtatNoMana::EtatNoMana(Jeu* j)
{
	this->jeu = j;
}

/////////////////////////////////////////////////////////////////////////
/**
* Destructeur
*/
EtatNoMana::~EtatNoMana()
{
}

/////////////////////////////////////////////////////////////////////////
/**
* Methode qui renvoie le jeu
*@return jeu le jeu
*/
Jeu* EtatNoMana::getJeu()
{
  return this->jeu;  
}

/////////////////////////////////////////////////////////////////////////
/**
* Methode qui termine le tour en cours, et lance le suivant
*/
void EtatNoMana::finTour()
{
  jeu->setEtat(jeu->getEtatDebutTour());
  jeu->echangeJoueur();
  jeu->jouer();
}

/////////////////////////////////////////////////////////////////////////
/**
* Methode qui termine le tour en cours, et lance le suivant
*/
int EtatNoMana::afficherChoixEtat()
{
	int choix = -1;
	int choixcarte;
	int choixcarte1, choixcarte2;
	int pdmn = jeu->getJoueurCourant()->getPersonnage().getPdm();
	
	cout << "\nETAT NO MANA\n" << endl;
	
	jeu->getVue().afficherChoixNoMana();
	choix = jeu->getVue().getChoixJoueur();
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
					jeu->getVue().afficherPersonnageAutre(jeu->getJoueurAutre());
    				break;
    		}
    		case 5:
    		{
    				jeu->getVue().afficherChoixCvC();
    				choixcarte1 = jeu->getVue().getChoixJoueur();
    				choixcarte2 = jeu->getVue().getChoixJoueur();
    				jeu->attaqueCvC(choixcarte1, choixcarte2);
    				
    				if (jeu->testNoAttaque() == true )
    				{
    					jeu->setEtat(jeu->getEtatDoubleNo());
		   		 	}		   		 
    					
    		}
    		case 6:
    		{		
    				jeu->getVue().afficherChoixCvJ();
    				choixcarte1 = jeu->getVue().getChoixJoueur();
    				jeu->attaqueCvJ(choixcarte1);
    				if (jeu->testNoAttaque() == true )
    				{
    					jeu->setEtat(jeu->getEtatNoAttaque());
		   		 	}		   		 
    				break;	
    		}
		}
	
	return choix;



}

