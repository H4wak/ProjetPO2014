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
	
	cout << "\nETAT DEBUT TOUR\n" << endl;
	
	jeu->getVue().afficherChoixDebutTour();
	choix = jeu->getVue().getChoixActionTour();
		switch (choix)
		{
		    case 1: {
					jeu->getVue().afficherMain(jeu->getJoueurCourant());
					break;
		    }
		    case 2:  {
		   		jeu->getVue().afficherJouerCarte();
		   		choixcarte = jeu->getVue().getChoixCarteAJouer();
		   		if ( jeu->getJoueurCourant()->getMain()->at(choixcarte-1).getCoutmana() <= pdmn)
		   		{
		   			jeu->getJoueurCourant()->ajouterBoard(jeu->getJoueurCourant()->getMain()->at(choixcarte-1));
		   			pdmn = pdmn - jeu->getJoueurCourant()->getMain()->at(choixcarte-1).getCoutmana();
		   			jeu->getVue().afficherPdmnRestant(pdmn);
		   		 	jeu->getJoueurCourant()->supprimerMain(choixcarte);
		   		 	
		   		 	if (jeu->testNoMana() == true )
		   		 	{
		   		 		jeu->setEtat(jeu->getEtatNoMana());
		   		 	}		   		 
		   		 	
		   		}else{
		   			
		   			jeu->getVue().afficherPasAssezDeMana();
		      	}
		      break;
		    }
		    case 3: {	
				  jeu->getVue().afficherBoard(jeu->getJoueurCourant());
				  break;
    		}
    		case 4:
    		{
					jeu->getVue().afficher2Board(jeu->getJoueurCourant(),jeu->getJoueurAutre());
    				break;
    		}
    		case 5:
    		{
					jeu->getVue().afficherPersonnage(jeu->getJoueurCourant());
					jeu->getVue().afficherPersonnageAutre(jeu->getJoueurAutre());
    				break;
    		}
    		case 6:
    		{		
    				jeu->getVue().afficherChoixCvC();
    				choixcarte1 = jeu->getVue().getChoixCarteAJouer();
    				choixcarte2 = jeu->getVue().getChoixCarteAJouer();
    				jeu->attaqueCvC(choixcarte1, choixcarte2);
    				
    				if (jeu->testNoAttaque() == true )
    				{
    					jeu->setEtat(jeu->getEtatNoAttaque());
		   		 	}		   		 
    				break;	
    		}
    		case 7:
    		{
    				cout << "POUVOIR" << endl;
    				break;
    		}
    		
    		case 8:
    		{		
    				jeu->getVue().afficherChoixCvJ();
    				choixcarte1 = jeu->getVue().getChoixCarteAJouer();
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

