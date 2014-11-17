/**
*Fichier ComportementPouvoirMage.cpp
* @author Pierre Gaultier & Theo Dolez
*/


#include <iostream>
#include <sstream> // pour les conversions en chaine
#include <typeinfo>

using namespace std; // seulement dans le .cpp !

/**
* Constructeur.
*/
ComportementPouvoirMage::ComportementPouvoirMage(Joueur* j)
{
  this->joueur = j;
	this->vue =new VueConsole();;
}


/**
* Methode qui applique le pouvoir heroique du Mage
*/
void ComportementPouvoirMage::pouvoir()
{
  cout << "Vous l'avez cherché!!! blblbblblbblbl LAWL";
	this->vue->afficherChoixPouvoirMage();
	int choix = this->vue->getChoixJoueur();
		switch (choix)
		{
		    case 1: {
					this->joueur->getJoueurAutre()->setPDV(this->joueur->getJoueurAutre()->getPdv()-1);
					break;
		    }
		    default:  {

					choix = this->vue->getChoixJoueur();
					int pdv = this->joueur->getJoueurAutre()->getBoard()->at(choix-1).getPdv();
					this->joueur->getJoueurAutre()->getBoard()->at(choix-1).setPdv(pdv-1);
					if ( this->joueur->getJoueurAutre()->getBoard()->at(choix-1).getPdv() <= 0 )
					{	
						this->joueur->getJoueurAutre()->supprimerBoard(choix);
						cout << "Vous avez triomphé de votre adversaire !" << endl;
					}
				break;
		    }

		}
}


