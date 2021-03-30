#include <SFML/Graphics.hpp>
#include <iostream>
#include "interface.h"
#include "toucher.h"
#include "zone.h"
#include "parametre.h"
#include "air.h"
#include <vector>
#include "ligne.h"
#include <math.h>
#include <unistd.h>
#include "resultat.h"
#include <ctime>
#include <time.h>

using namespace std;
using namespace sf;

//Contient la partie de l'ancien main qui était dans la boucle principale
void simulation(RenderWindow& window,int& x,int& y,int& E,int& k,int& Dessin,int& e,int& ligneX,int& ligneY,int* airetotale,int& aire,int& points, int& erreurs, tabpoint& tab_point,tabpoint& tab_erreur,int** tab_pixel,Texture& texture,Sprite& sprite,point& p1, ligne& l1, ligne& l2, int& gamemode)
{
		time_t temps_debut; int H,m;
		time(&temps_debut); 
		Event event;


		Grand_cercle(window);
		l1.Position_ligne(window);
		l2.Position_ligne(window);
		window.display();	



	while(k<nbzone)
	{
		
		
		if (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				{window.close();}
			
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::B)
				{
					Dessin = true;
				}
				
				if ((event.key.code == Keyboard::Q) or (event.key.code == Keyboard::N))
				{
					window.close();
				}
			}
			
			
			if (event.type == Event::KeyReleased)
			{
				if (event.key.code == Keyboard::B)
				{
					Dessin = false ;
				}
				
				if(event.key.code == Keyboard::Comma)
				{
					restart(tab_point, tab_erreur, k, temps_debut);
				}
			}
		}
		
			if (Dessin)
			{	
				Position_Curseur(&x, &y, window);
				p1.set(x,y); 
				if (zone(k, x, y, xcentre, ycentre, r, R, e)==1)
					{
					tab_point.append(p1);
					points++;
					remplissage(k,x, y, xcentre,ycentre, r, R, e, aire, tab_pixel); 
					}
				if (zone(k, x, y, xcentre, ycentre, r, R, e)==2)
					{
					tab_erreur.append(p1);
					erreurs++;
					}
				Dessine_plus_points(tab_point, tab_erreur, window, R);
				window.display();
				}
				
				switch ( aire_completee(aire, airetotale[k], condition80, condition95) )   //en fonction de l'aire on fait telle action mais on teste pas les autres
				{
					case 2: //95%
					k+=1;
					compt_erreur( points, erreurs,tab_point, tab_erreur);
					l1.set(xcentre+r-(k+1)*e, ligneY);
					l2.set(xcentre+r-(k+1)*e+e, ligneY);
					//réinitialisation des tableaux
					aire=0;
					ligneX= xcentre +r-(k+1)*e;
					tab_point.reset();
					tab_erreur.reset();
					for (int i = 0; i < e; i++)
					for(int j = 0; j < L; j++)
							{tab_pixel[i][j]=0;}
					
					
					ZoneFinie(window, k, e, xcentre, ycentre, r);
					
					window.display();
					sleep(1);
					break;
					case 1 : 
					//80%
					for (int i=0;i<e;i++){
						for (int y=0;y<l;y++){
							if (tab_pixel[i][y]==0){
								H=(xcentre-(i+(xcentre+r-e*(k+1))))*(xcentre-(i+(xcentre+r-e*(k+1))))+(ycentre-y)*(ycentre-y);
								if (i+(xcentre+r-e*(k+1)>=xcentre+r-(k+1)*e) && (i+(xcentre+r-e*(k+1))<=xcentre+r-k*e-R/2) && (H<=r*r-R/2))
									{
									Dessine_restant(k,i,y, e, r, R, xcentre, window);
									}
							}
						}
					break;
					
				}
			
			
}


		
		
		
		
		if (aire_completee(aire, airetotale[k], condition80, condition95)==1 )
		{
			for (int i=0;i<e;i++){
				for (int y=0;y<l;y++)
				{
					
					
					if (tab_pixel[i][y]==0)
					{
						 H=(xcentre-(i+(xcentre+r-e*(k+1))))*(xcentre-(i+(xcentre+r-e*(k+1))))+(ycentre-y)*(ycentre-y);
						if (i+(xcentre+r-e*(k+1)>=xcentre+r-(k+1)*e) && (i+(xcentre+r-e*(k+1))<=xcentre+r-k*e-R/2) && (H<=r*r-R/2))
						{
								Dessine_restant(k,i,y, e, r, R, xcentre, window);
								
						}
						
					}
				}
			
			}
			window.display();
		}
		
		
		if (k>=nbzone) {  cout << chrono(temps_debut) << endl;}
		
		/*test_fin(aire_completee(aire,airetotale[nbzone],condition95,condition80),temps_debut);*/
}
	
}


/******************************************************************************/

//Contient la partie de l'ancien main avant la boucle principale

void init_jeu(RenderWindow& window,int& x,int& y,int& E,int& k,int& Dessin,int& e,int& ligneX,int& ligneY,int* airetotale,int& aire, int& points, int& erreurs, Texture& texture,Sprite& sprite, ligne& l1, ligne& l2)

{
	k=0;
	Dessin = false;
	
	e=2*int(r/nbzone);
	ligneX= xcentre +r-(k+1)*e;
	ligneY=20;
	airetotale[nbzone];
	aire=0;
	E = e+1;
	
	for (int i = 0; i < nbzone; i++)
	{airetotale[i] = calculaire(i,e,l,xcentre, ycentre, r, R);} 
	
	l1.set(xcentre+r-(k+1)*e, ligneY);
	l2.set(xcentre+r-(k+1)*e+e, ligneY);
	
	if (!texture.loadFromFile("background_im22.jpg", sf::IntRect(0,0,480,320)))
	{ /* Erreur*/ }
	
	sprite.setTexture(texture);
	sprite.setScale(sf::Vector2f(1.5f,1.5f));

}

/*********************************************************************************/




