#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Jeu.h"
#include "interface.h"
#include "toucher.h"
#include "zone.h"
#include "parametre.h"
#include "air.h"
#include "ligne.h"
#include <math.h>
#include "Menu.h"
#include "resultat.h"

#include "Fin.h"
#include <ctime>
#include <time.h>
#include <unistd.h>

#include "basededonnees.h"
#include <sqlite3.h> 

using namespace std;
using namespace sf;

int main()
{
	//on crée toutes les varibles necéssaires aux fonction
	int gamemode=0;
	int points[nbzonemax], erreurs[nbzonemax];
	int x, y,E,k, Dessin;
	tabpoint tab_point;
	tabpoint tab_erreur;
	int e;
	int ligneX, ligneY;
	int* airetotale;
	int aire;
	sf::Texture background;
	sf::Sprite sprite;
	point p1;
	ligne l1(0,0), l2(0,0);
	string Nom, Age, Formation, Niveau, Prenom, Prenom2, Endoscope;
	string temps;
	string erreurstr[nbzonemax];
	time_t temps_simul;
	int n[nbzonemax];
	int ind=1, ecran=1, fin=1;
	int R, condition80, condition95, nbzone, tempsmax;
	string etat;
	
	SQLBASE objet1;
	SQLBASE2 objet2;
	
	
	
	//on crée la fenetre
	RenderWindow window(VideoMode(L,l), "SFML works!"/*,Style::Fullscreen*/);
	
	//Boucle principale
	int i=0;
	if (window.isOpen())
	{
	
		window.clear();
		
		while (gamemode <10)
		{
		//selon la valeur de gamemode, on change de phase de jeu
		if (gamemode==0)
		{
			menu(window, Prenom, Prenom2, Nom, Age, Formation, Niveau, Endoscope, gamemode, ind, ecran);
			fin=1;
			
			//initialisation de la base de données
			objet1.SQLinitialisation(Nom,Prenom,Prenom2);
			objet2.SQLinitialisation2(Age,Formation,Niveau,Endoscope);
		}
		if (gamemode==1)	
		{
			//on initialise les variables liées a la parties simulation
			
			Initpara(nbzone, R, condition80, condition95, tempsmax);
			
			/******************/
			airetotale= new int[nbzone];
			/*****************/
			
			init_jeu( window, x, y, E, k, Dessin, e, ligneX, ligneY, airetotale, aire, points, erreurs, background, sprite, l1, l2, nbzone, R);
			
			/*********************************/
			int **tab_pixel = new int* [E];
			for (int i = 0; i < E; i++)
			{tab_pixel[i] = new int[L];}
			/*********************************/
			etat="Reussi";
			simulation(window,x,y,E,k,Dessin,e,ligneX,ligneY, airetotale, aire, points, erreurs, tab_point, tab_erreur, tab_pixel, background, sprite, p1, l1, l2, gamemode, temps_simul, R, condition80, condition95, nbzone, tempsmax, etat, fin);
		}
		
		 if (gamemode==2)	
		{
			if(fin==1)
			{
				affichage_fin(window, nbzone, gamemode, erreurs, points, n, temps_simul);
				sleep(10);
			}
			//remplissage des résultats et des incrémentations de test de la base de données
			objet1.SQLcompteur(ind);
			objet1.SQLrequete(ind);

			
			temps=nbToStr(temps_simul);
			for(int i=0; i<nbzone;i++);
				{erreurstr[i]=nbToStr(n[i]);}

			objet2.SQLrecupererResults(temps,erreurstr[0],"fini");
			objet2.SQLrecupererid(objet1);
			objet2.SQLrecupererCompteur(ind,objet1);
			objet2.SQLrequete2();
			
			menufin(window, gamemode, ecran);
		}
		
		if (gamemode==10)
		{return 0;}
		}
		window.display();
		
		
	}
	return 0;
}
