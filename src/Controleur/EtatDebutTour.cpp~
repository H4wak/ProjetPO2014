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
	choix = jeu->getVue().getChoixJoueur();
		switch (choix)
		{
		    case 1: {
					jeu->getVue().afficherMain(jeu->getJoueurCourant());
					break;
		    }
		    case 2:  {
		   		jeu->getVue().afficherJouerCarte();
		   		while(choixcarte>0 && choixcarte < jeu->getJoueurCourant()->getMain()->size()){
		   			choixcarte = jeu->getVue().getChoixJoueur();
		   		}
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
    				while(choixcarte1 > 0 && choixcarte1 < jeu->getJoueurCourant()->getBoard()->size()){
		   				choixcarte1 = jeu->getVue().getChoixJoueur();
		   			}
    				while(choixcarte2 > 0 && choixcarte2 < jeu->getJoueurAutre()->getBoard()->size()){
		   				choixcarte2 = jeu->getVue().getChoixJoueur();
		   			}
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
    				while(choixcarte1 > 0 && choixcarte1 < jeu->getJoueurCourant()->getBoard()->size()){
		   				choixcarte1 = jeu->getVue().getChoixJoueur();
		   			}
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

