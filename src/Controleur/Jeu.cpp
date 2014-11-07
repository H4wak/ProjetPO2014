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
   this->etatDebutTour = new EtatDebutTour(this);
   this->etatNoMana = new EtatNoMana(this);
   this->etatNoAttaque = new EtatNoAttaque(this);
   this->etatDoubleNo = new EtatDoubleNo(this);  
   this->etatCourant = this->etatDebutTour;
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
Tour* Jeu::getEtatCourant()
{
  return this->EtatCourant;  
}


/////////////////////////////////////////////////////////////////////////
/**
* Methode qui renvoie le tour du joueur2
* @return tourCourant le tour du joueur2
*/
Tour* Jeu::getEtatDebutTour()
{
  return this->etatDebutTour;  
}	

/////////////////////////////////////////////////////////////////////////
/**
* Methode qui renvoie le tour du joueur2
* @return tourCourant le tour du joueur2
*/
Tour* Jeu::getEtatNoMana()
{
  return this->etatNoMana;  
}	

/////////////////////////////////////////////////////////////////////////
/**
* Methode qui renvoie le tour du joueur2
* @return tourCourant le tour du joueur2
*/
Tour* Jeu::getEtatNoAttaque()
{
  return this->etatNoAttaque;  
}	

/////////////////////////////////////////////////////////////////////////
/**
* Methode qui renvoie le tour du joueur2
* @return tourCourant le tour du joueur2
*/
Tour* Jeu::getEtatDoubleNo()
{
  return this->etatDoubleNo;  
}	

/////////////////////////////////////////////////////////////////////////
/**
* Methode qui change le tourCourant
* @param t le nouveau tour
*/
void Jeu::setEtat(Etat* e)
{
	this->etatCourant = e;
}

/////////////////////////////////////////////////////////////////////////
/**
* Methode qui appelle la methode finTour() sur le tour courant
*/
void Jeu::finTour()
{
	this->etatCourant->finTour();
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
	
	
	
	while (choix != 0) {	
	
	choix = etatCourant.afficherChoixEtat();
	
	
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
		
		
/////////////////////////////////////////////////////////////////////////		
bool Jeu::testNoMana()
{
	int pmr;
	bool nomana = true;
	pmr = joueurCourant->gtPersonnage()->getPdm()
	for ( i = 0; i < joueurCourant->getMain()->size() ; i++ )
	{
		if ( joueurCourant->getMain()->at(i).getCoutmana() <= pmr )
		{
			nomana = false;
		}
	} 
	
	return nomana;
	
}
		
/////////////////////////////////////////////////////////////////////////
bool Jeu::testNoAttaque()
{
	
	bool noatt = true;
	
	for ( i = 0; i < joueurCourant->getBoard()->size() ; i++ )
	{
		if ( joueurCourant->getBoard()->at(i).getMalinvoc() == false )
		{
			noatt = false;
		}
	} 
	
	return noatt;
}

