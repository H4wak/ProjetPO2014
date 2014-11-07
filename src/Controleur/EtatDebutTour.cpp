/**
*Fichier EtatDebutTour.cpp
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
EtatDebutTour::EtatDebutTour(Jeu* j)
{
	this->jeu = j;
}

/////////////////////////////////////////////////////////////////////////
/**
* Destructeur
*/
EtatDebutTour::~EtatDebutTour()
{
}

/////////////////////////////////////////////////////////////////////////
/**
* Methode qui renvoie le jeu
*@return jeu le jeu
*/
Jeu* EtatDebutTour::getJeu()
{
  return this->jeu;  
}

/////////////////////////////////////////////////////////////////////////
/**
* Methode qui termine le tour en cours, et lance le suivant
*/
void EtatDebutTour::finTour()
{
  jeu->setEtat(jeu->getEtatDebutTour());
  jeu->echangeJoueur();
  jeu->jouer();
}

/////////////////////////////////////////////////////////////////////////
/**
* Methode qui termine le tour en cours, et lance le suivant
*/
int EtatDebutTour::afficherChoixEtat()
{
	int choix = -1;
	int choixcarte;
	int choixcarte1, choixcarte2;
	int pdmn = jeu->getJoueurCourant()->getPersonnage().getPdm();
	jeu->vue.afficherChoixDebutTour();
	choix = jeu->vue.getChoixActionTour();
		switch (choix)
		{
		    case 1: {
					jeu->vue.afficherMain(joueurCourant);
					break;
		    }
		    case 2:  {
		   		jeu->vue.afficherJouerCarte();
		   		choixcarte = jeu->vue.getChoixCarteAJouer();
		   		if ( jeu->getJoueurCourant()->getMain()->at(choixcarte-1).getCoutmana() <= pdmn)
		   		{
		   			jeu->getJoueurCourant()->ajouterBoard(jeu->getJoueurCourant()->getMain()->at(choixcarte-1));
		   			pdmn = pdmn - jeu->joueurCourant->getMain()->at(choixcarte-1).getCoutmana();
		   			jeu->vue.afficherPdmnRestant(pdmn);
		   		 	jeu->getJoueurCourant()->supprimerMain(choixcarte);
		   		 	
		   		 	if (jeu->testNomana() == true )
		   		 	{
		   		 		jeu->setEtat(jeu->getEtatNoMana());
		   		 	}		   		 
		   		 	
		   		}else{
		   			
		   			jeu->vue.afficherPasAssezDeMana();
		      	}
		      break;
		    }
		    case 3: {	
				  jeu->vue.afficherBoard(jeu->getJoueurCourant());
				  break;
    		}
    		case 4:
    		{
					jeu->vue.afficher2Board(jeu->getJoueurCourant(),jeu->getJoueurAutre());
    				break;
    		}
    		case 5:
    		{
					jeu->vue.afficherPersonnage(jeu->getJoueurCourant());
    				break;
    		}
    		case 6:
    		{
    				choixcarte1 = jeu->vue.getChoixCarteAJouer();
    				choixcarte2 = jeu->vue.getChoixCarteAJouer();
    				jeu->attaqueCvC(choixcarte1, choixcarte2);
    				
    				if (jeu->testNoAttaque() == true )
    				{
    					jeu->setEtat(jeu->getEtatNoAttaque());
		   		 	}		   		 
    				break;	
    		}
    		case 7:
    		{
    			cout << "POUVOIR" << endl
    		}
		}
	
	return choix;



}

