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
   this->obs = new vector<Observer*>();
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
* Methode qui renvoie l'etat courant
* @return tourCourant l'etat courant
*/
Etat* Jeu::getEtatCourant()
{
  return this->etatCourant;  
}


/////////////////////////////////////////////////////////////////////////
/**
* Methode qui renvoie l'etat DebutTour
* @return etatDebutTour l'etat DebutTour
*/
Etat* Jeu::getEtatDebutTour()
{
  return this->etatDebutTour;  
}	

/////////////////////////////////////////////////////////////////////////
/**
* Methode qui renvoie l'etat NoMana
* @return etatNoMana l'etat no mana
*/
Etat* Jeu::getEtatNoMana()
{
  return this->etatNoMana;  
}	

/////////////////////////////////////////////////////////////////////////
/**
* Methode qui renvoie l'etat NoAttaque
* @return etatNoAttaque l'etat NoAttaque
*/
Etat* Jeu::getEtatNoAttaque()
{
  return this->etatNoAttaque;  
}	

/////////////////////////////////////////////////////////////////////////
/**
* Methode qui renvoie l'etat DoubleNo
* @return etatDoubleNo l'etat DoubleNo
*/
Etat* Jeu::getEtatDoubleNo()
{
  return this->etatDoubleNo;  
}	

/////////////////////////////////////////////////////////////////////////
/**
* Methode qui change l'etat courant
* @param e le nouvel etat
*/
void Jeu::setEtat(Etat* e)
{
	this->etatCourant = e;
}

/////////////////////////////////////////////////////////////////////////
/**
* Methode qui retourne la vue
* @return vue la vue
*/
VueConsole Jeu::getVue()
{
	return this->vue;
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
	if (system("CLS")) system("clear");
	
	
	if (this->joueurCourant->getPdm() == 0)
	{
		this->joueurCourant->ajouterMain(this->joueurCourant->getDeck()->tirerCarte());
		this->joueurCourant->ajouterMain(this->joueurCourant->getDeck()->tirerCarte());
	}
	
	if (this->joueurCourant->getPdm() < 10)
	{
		this->joueurCourant->setPDM(this->joueurCourant->getPdm()+1);			
	}
	
	this->joueurCourant->setPDMTour(this->joueurCourant->getPdm());
	
 	this->joueurCourant->ajouterMain(this->joueurCourant->getDeck()->tirerCarte());
  
	enleverMalinvoc();
	
	vue.afficherDebutTour(joueurCourant);
	vue.afficher2Board(joueurCourant,joueurAutre);
		
	int choix = -1;
	
	if (this->testNoMana() == true && this->testNoAttaque() == true )
	{
			this->setEtat(this->getEtatDoubleNo());
	} else {
	
		if (this->testNoMana() == true )
		{
			this->setEtat(this->getEtatNoMana());
		}
		 
		if (this->testNoAttaque() == true )
		{
			this->setEtat(this->getEtatNoAttaque());
		} 
	}  
	
	
	while (choix != 0)
	{	
		choix = etatCourant->afficherChoixEtat();
	}
	vue.afficherFinTour();
	
	usleep(1000000);
	
	this->finTour();
}

/////////////////////////////////////////////////////////////////////////
void Jeu::attaqueCvC(int index1, int index2)
{
	int pdv1,pdv2,attac1,attac2;
	
	if ( joueurCourant->getBoard()->at(index1-1).getMalinvoc() == true )
	{
		cout << "Cette carte ne peut pas attaquer pour l'instant!" << endl;
	} else {
	
		pdv1 = joueurCourant->getBoard()->at(index1-1).getPdv();
		pdv2 = joueurAutre->getBoard()->at(index2-1).getPdv();
		attac1 = joueurCourant->getBoard()->at(index1-1).getPa();
		attac2 = joueurAutre->getBoard()->at(index2-1).getPa();
		
		if ( this->testProvoc() == false ) {			
			
			joueurCourant->getBoard()->at(index1-1).setPdv(pdv1-attac2);
			joueurAutre->getBoard()->at(index2-1).setPdv(pdv2-attac1);
			joueurCourant->getBoard()->at(index1-1).setMalinvoc(true);
			
			
		} else {
		
			if ( joueurAutre->getBoard()->at(index2-1).getProvoc() == false)
			{
				cout << "\nVous devez attaquer les cartes avec Provocation !!\n" << endl;
			} else {
				joueurCourant->getBoard()->at(index1-1).setPdv(pdv1-attac2);
				joueurAutre->getBoard()->at(index2-1).setPdv(pdv2-attac1);
				joueurCourant->getBoard()->at(index1-1).setMalinvoc(true);
			}
				
		}
		
		if ( joueurCourant->getBoard()->at(index1-1).getPdv() <= 0 )
			{	
				joueurCourant->supprimerBoard(index1);
				cout << "Votre carte est tombée au combat !" << endl;
			}
			
			if ( joueurAutre->getBoard()->at(index2-1).getPdv() <= 0 )
			{	
				joueurAutre->supprimerBoard(index2);
				cout << "Vous avez triomphé de votre adversaire !" << endl;
			}
	}
	
	cout << "attaque terminée"<< endl;

}

/////////////////////////////////////////////////////////////////////////
void Jeu::attaqueCvJ(int index1)
{
	if ( joueurCourant->getBoard()->at(index1-1).getMalinvoc() == true )
	{
		cout << "Cette carte ne peut pas attaquer pour l'instant!" << endl;
	} else {
		if ( this->testProvoc() == false ) {	
		
			
			int ataq = joueurCourant->getBoard()->at(index1-1).getPa();
			int arm =  joueurAutre->getArmure();
			
			if (arm == 0)
			{					
				joueurAutre->setPDV(joueurAutre->getPdv()- ataq);
			}
			else
			{
				if (ataq <= arm)
				{
					joueurAutre->setARMURE(arm-ataq);
				}
				else
				{
					int ataq2 = ataq - arm;
					joueurAutre->setARMURE(0);
					joueurAutre->setPDV(joueurAutre->getPdv()- ataq2);
				}
			}
					
			joueurCourant->getBoard()->at(index1-1).setMalinvoc(true);
		} 
		else {
			cout << "\nVous devez attaquer les cartes avec Provocation !!\n" << endl;				
		}
	}
	cout << "attaque terminée"<< endl;
	notifierObs();
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
		if ( joueurAutre->getBoard()->at(j).getMalinvoc() == true )
		{
			joueurAutre->getBoard()->at(j).setMalinvoc(false);
		}
	}

	
	joueurCourant->setPouvoirUtilise(false);

}
		
		
/////////////////////////////////////////////////////////////////////////		
bool Jeu::testNoMana()
{
	int pmr;
	bool nomana = true;
	pmr = joueurCourant->getPdmTour();
	for ( int i = 0; i < joueurCourant->getMain()->size() ; i++ )
	{
		if ( joueurCourant->getMain()->at(i).getCoutmana() <= pmr )
		{
			nomana = false;
		}
	} 
	

	if (pmr>=2 && joueurCourant->getPouvoirUtilise() == false)
	{
		return false;
	} 
	else
	{
		return nomana;
	}
	
}
		
/////////////////////////////////////////////////////////////////////////
bool Jeu::testNoAttaque()
{
	
	bool noatt = true;
	
	for ( int i = 0; i < joueurCourant->getBoard()->size() ; i++ )
	{
		if ( joueurCourant->getBoard()->at(i).getMalinvoc() == false )
		{
			noatt = false;
		}
	} 
	
	return noatt;
}

/////////////////////////////////////////////////////////////////////////
bool Jeu::testProvoc()
{
	bool provoc = false;
	
	for ( int i = 0; i < joueurAutre->getBoard()->size() ; i++ )
	{
		if ( joueurAutre->getBoard()->at(i).getProvoc() == true )
		{
			provoc = true;
		}
	} 
	
	return provoc;
}

/////////////////////////////////////////////////////////////////////////
void Jeu::enregistrerObs(Observer* O)
{
  obs->push_back(O);
}

/////////////////////////////////////////////////////////////////////////
void Jeu::supprimerObs(Observer* O)
{
  int i = 0;
  for(i;i<obs->size()-1;i++){
	if (obs->at(i) == O){
		obs->erase(obs->begin()+i);
		}
	}
}

/////////////////////////////////////////////////////////////////////////
void Jeu::notifierObs()
{ 
  int i = 0;
  
  for( i ; i < obs->size() ; i++){
	obs->at(i)->actualiser();
	}
}
/////////////////////////////////////////////////////////////////////////
void Jeu::fonctionsCarte(int f)
{
	switch (f)
	{
		case 1:
		{
			cout << "VOUS ALLEZ MOURIR" << endl;
			break;
		}
		
		
		/////// Intelligence des Arcanes
		case 10:
		{
			joueurCourant->ajouterMain(joueurCourant->getDeck()->tirerCarte());
			joueurCourant->ajouterMain(joueurCourant->getDeck()->tirerCarte());
			break;
		}
		
		
		////// Tir des Arcanes
		case 20:
		{
			vue.afficherChoixPouvoirMage();
			int choix = vue.getChoixJoueur();
			switch (choix)
			{
		  	  case 1: {
						joueurAutre->setPDV(joueurAutre->getPdv()-2);
						break;
		    	}
		     default:  {
	
	    				choix = vue.getChoixJoueur();
	    				bool bonnecarte = false;	
    					int size = joueurAutre->getBoard()->size();  
    					while ( bonnecarte == false )
    					{
    						if ( choix > 0 && choix <= size)
    						{
    							bonnecarte = true;
    						}
    						else
    						{	
								choix = vue.getChoixJoueur();
      						}   				
    					}   
						int pdv = joueurAutre->getBoard()->at(choix-1).getPdv();
						joueurAutre->getBoard()->at(choix-1).setPdv(pdv-2);
						if ( joueurAutre->getBoard()->at(choix-1).getPdv() <= 0 )
						{	
							joueurAutre->supprimerBoard(choix);
							cout << "Vous avez triomphé de votre adversaire !" << endl;
						}
					break;
		    }
		}				
			break;
		}
		
		///////// Voile de Mort
		case 21: {
		
			vue.afficherChoixCarte();
			int choix = vue.getChoixJoueur();
	    	bool bonnecarte = false;	
    		int size = joueurAutre->getBoard()->size();  
    		while ( bonnecarte == false )
    		{
    			if ( choix > 0 && choix <= size)
    			{
    				bonnecarte = true;
    			}
    			else
    			{	
					choix = vue.getChoixJoueur();
      			}   				
    		}   
			int pdv = joueurAutre->getBoard()->at(choix-1).getPdv();
			joueurAutre->getBoard()->at(choix-1).setPdv(pdv-1);
			if ( joueurAutre->getBoard()->at(choix-1).getPdv() <= 0 )
			{	
				joueurAutre->supprimerBoard(choix);
				joueurCourant->ajouterMain(joueurCourant->getDeck()->tirerCarte());
			}
				
			break;
		}
		
		///////// Drain de Vie
		case 22: {
		
			vue.afficherChoixPouvoirMage();
			int choix = vue.getChoixJoueur();
			switch (choix)
			{
		  	  case 1: {
						joueurAutre->setPDV(joueurAutre->getPdv()-2);
						break;
		    	}
		     default:  {
	
	    				choix = vue.getChoixJoueur();
	    				bool bonnecarte = false;	
    					int size = joueurAutre->getBoard()->size();  
    					while ( bonnecarte == false )
    					{
    						if ( choix > 0 && choix <= size)
    						{
    							bonnecarte = true;
    						}
    						else
    						{	
								choix = vue.getChoixJoueur();
      						}   				
    					}   
						int pdv = joueurAutre->getBoard()->at(choix-1).getPdv();
						joueurAutre->getBoard()->at(choix-1).setPdv(pdv-2);
						if ( joueurAutre->getBoard()->at(choix-1).getPdv() <= 0 )
						{	
							joueurAutre->supprimerBoard(choix);
							cout << "Vous avez triomphé de votre adversaire !" << endl;
						}
					break;
		    	}
			}		
			
			joueurCourant->setPDV(joueurCourant->getPdv()+2);		
			break;
			
		}
		
		
		////// Boule de Feu
		case 23:
		{
			vue.afficherChoixPouvoirMage();
			int choix = vue.getChoixJoueur();
			switch (choix)
			{
		  	  case 1: {
						joueurAutre->setPDV(joueurAutre->getPdv()-6);
						break;
		    	}
		     default:  {
	
	    				choix = vue.getChoixJoueur();
	    				bool bonnecarte = false;	
    					int size = joueurAutre->getBoard()->size();  
    					while ( bonnecarte == false )
    					{
    						if ( choix > 0 && choix <= size)
    						{
    							bonnecarte = true;
    						}
    						else
    						{	
								choix = vue.getChoixJoueur();
      						}   				
    					}   
						int pdv = joueurAutre->getBoard()->at(choix-1).getPdv();
						joueurAutre->getBoard()->at(choix-1).setPdv(pdv-6);
						if ( joueurAutre->getBoard()->at(choix-1).getPdv() <= 0 )
						{	
							joueurAutre->supprimerBoard(choix);
							cout << "Vous avez triomphé de votre adversaire !" << endl;
						}
					break;
		    }
		}				
			break;
		}
		
		
		////// Choc de Flammes
		case 24: {
			
			int size1,size2,pdv;
			size1 = joueurAutre->getBoard()->size();
			
			
			for ( int i = 0; i < size1 ; i++ )
			{
				
				pdv = joueurAutre->getBoard()->at(i).getPdv();
				joueurAutre->getBoard()->at(i).setPdv(pdv-4);
				
				if ( joueurAutre->getBoard()->at(i).getPdv() <= 0 )
					{	
						joueurAutre->supprimerBoard(i+1);
						i--;
						size1--;
					}
			} 
			
			
			break;
		}
		
		//// Nova Sacrée
		case 25: {
			
			int size1,size2,pdv,pdvmax,arm,ataq2;
			size1 = joueurAutre->getBoard()->size();
			size2 = joueurCourant->getBoard()->size();
			
			for ( int i = 0; i < size1 ; i++ )
			{
				pdv = joueurAutre->getBoard()->at(i).getPdv();
				joueurAutre->getBoard()->at(i).setPdv(pdv-2);
				
				if ( joueurAutre->getBoard()->at(i).getPdv() <= 0 )
					{	
						joueurAutre->supprimerBoard(i+1);
						i--;
						size1--;
					}
			} 
			
			for ( int j = 0; j < size2 ; j++ )
			{
				pdv = joueurCourant->getBoard()->at(j).getPdv();
				pdvmax = joueurCourant->getBoard()->at(j).getPdvmax();
				
				joueurCourant->getBoard()->at(j).setPdv(pdv+2);
					if ( pdv+2 > pdvmax )
					{	
						joueurCourant->getBoard()->at(j).setPdv(pdvmax);
					}
			} 
			
			
			arm = joueurAutre->getArmure();
			
  			 if (arm == 0)
  			 {					
				joueurAutre->setPDV(joueurAutre->getPdv()-2);
  			 }
  			 else
   			{
				if (2 <= arm)
				{
					joueurAutre->setARMURE(arm-2);
				}
				else
				{
					ataq2 = 2 - arm;
					joueurAutre->setARMURE(0);
					joueurAutre->setPDV(joueurAutre->getPdv()-ataq2);
				}
			
			}
			
			joueurCourant->setPDV(joueurCourant->getPdv()+2);
			if(joueurCourant->getPdv()>30)
			{
				joueurCourant->setPDV(30);
			}
			break;
		}
		
		////// Attaque mentale
		case 26: {
			
			int arm =  joueurAutre->getArmure();
			if (arm == 0)
			{					
				joueurAutre->setPDV(joueurAutre->getPdv()-5);
			}
			else
			{
				if (5 <= arm)
				{
					joueurAutre->setARMURE(arm-5);
				}
				else
				{
					int ataq2 = 5 - arm;
					joueurAutre->setARMURE(0);
					joueurAutre->setPDV(joueurAutre->getPdv()- ataq2);
				}
			}
			
			break;	
   		}
		
		
		////// Néant Distordu
		case 40: {
			
			int size1,size2;
			size1 = joueurAutre->getBoard()->size();
			size2 = joueurCourant->getBoard()->size();
			
			for ( int i = 0; i < size1 ; i++ )
			{
				joueurAutre->supprimerBoard(1);
			} 
			
			for ( int j = 0; j < size2 ; j++ )
			{
				joueurCourant->supprimerBoard(1);
			} 
		
			break;
		}
		
		
		////// Courroux Bestial
		case 60: {
		
			vue.afficherChoixCarte();
			int choix = vue.getChoixJoueur();
			bool bonnecarte = false;
			int size = joueurCourant->getBoard()->size(); 
			while ( bonnecarte == false )
    		{
    			if ( choix > 0 && choix <= size)
    			{
    				bonnecarte = true;
    			}
    			else
    			{	
					choix = vue.getChoixJoueur();
      			}   				
    		}
    		
    		joueurCourant->getBoard()->at(choix-1).setPa(joueurCourant->getBoard()->at(choix-1).getPa()+2);
    	
    		break;
    	}
    	
    	////// Esprit Divin
		case 61: {
		
			vue.afficherChoixCarte();
			int pdv1,pdv2;
			int choix = vue.getChoixJoueur();
			bool bonnecarte = false;
			int size = joueurCourant->getBoard()->size(); 
			while ( bonnecarte == false )
    		{
    			if ( choix > 0 && choix <= size)
    			{
    				bonnecarte = true;
    			}
    			else
    			{	
					choix = vue.getChoixJoueur();
      			}   				
    		}
    		
    		pdv1 = joueurCourant->getBoard()->at(choix-1).getPdv();
    		pdv2 = pdv1*2;
    		joueurCourant->getBoard()->at(choix-1).setPdv(pdv2);
    	
    		break;
    	}
    		
    		
		////// Marque du chasseur
		case 80:
		{
			vue.afficherChoixCarte();
			int choix = vue.getChoixJoueur();
	    	bool bonnecarte = false;	
    		int size = joueurAutre->getBoard()->size();  
    		while ( bonnecarte == false )
    		{
    			if ( choix > 0 && choix <= size)
    			{
    				bonnecarte = true;
    			}
    			else
    			{	
					choix = vue.getChoixJoueur();
      			}   				
    		}
    		   
			joueurAutre->getBoard()->at(choix-1).setPdv(1);
			
		
			break;
		}
	}
		



}

