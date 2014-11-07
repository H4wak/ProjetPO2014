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
	jeu->vue.afficherChoixNoMana();
	choix = jeu->vue.getChoixActionTour();
		switch (choix)
		{
		    case 1: {
					jeu->vue.afficherMain(jeu->getJoueurCourant());
					break;
		    }
		   
		    case 2: {	
				  jeu->vue.afficherBoard(jeu->getJoueurCourant());
				  break;
    		}
    		case 3:
    		{
					jeu->vue.afficher2Board(jeu->getJoueurCourant(),jeu->getJoueurAutre());
    				break;
    		}
    		case 4:
    		{
					jeu->vue.afficherPersonnage(jeu->getJoueurCourant());
    				break;
    		}
    		case 5:
    		{
    				choixcarte1 = jeu->vue.getChoixCarteAJouer();
    				choixcarte2 = jeu->vue.getChoixCarteAJouer();
    				jeu->attaqueCvC(choixcarte1, choixcarte2);
    				
    				if (jeu->testNoAttaque() == true )
    				{
    					jeu->setEtat(jeu->getEtatDoubleNo());
		   		 	}		   		 
    					
    		}
		}
	
	return choix;



}

