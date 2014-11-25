/**
*Fichier ComportementPouvoirJXR.cpp
* @author Pierre Gaultier & Theo Dolez
*/


#include <iostream>
#include <sstream> // pour les conversions en chaine
#include <typeinfo>

using namespace std; // seulement dans le .cpp !

/**
* Constructeur.
*/
ComportementPouvoirJXR::ComportementPouvoirJXR(Joueur* j)
{
  this->joueur = j;
	this->vue =new VueConsole();;
}


/**
* Methode qui applique le pouvoir heroique du Mage
*/
void ComportementPouvoirJXR::pouvoir()
{

	this->vue->afficherChoixPouvoirInduction();
    int choix = this->vue->getChoixJoueur();
    bool bonnecarte = false;
   	int size = this->joueur->getJoueurAutre()->getBoard()->size();  
   while ( bonnecarte == false )
   {
  	 if ( choix > 0 && choix <= size)
     {
   		bonnecarte = true;
 	 }
	 else
     {	
		choix = this->vue->getChoixJoueur();
     }   				
   }   
	
	this->joueur->getJoueurAutre()->supprimerBoard(choix);

		
}


