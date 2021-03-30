#include <SFML/Graphics.hpp>
#include <iostream>
#include "toucher.h"
#include "interface.h"
#include <math.h>

using namespace std;
using namespace sf;



/********************************************************************************/

void Grand_cercle(RenderWindow& window)/*Permet de trace le cercle représentant la tumeur*/
{
	CircleShape shape(150);
	shape.setFillColor(Color(255,214,246,150));
	shape.setOutlineThickness(20);
	shape.setOutlineColor(sf::Color(253,108,158));
	shape.setPosition(100,20);
	window.draw(shape);

}

/********************************************************************************/

void Position_ligne(int x, int y,RenderWindow& window)/*Permet de mettre la ligne à la position (x,y)*/
{
	RectangleShape line(Vector2f(450,5));
	line.rotate(90);
	line.setPosition(x,y);
	line.setFillColor(Color::Red);
	window.draw(line);

}

/********************************************************************************/

void Dessine_point(point p, RenderWindow& window, int R)/*Dessine un point de taille Rpx à la position (x,y)*/
{
	int x, y;
	p.get(x,y);
	RectangleShape carre(Vector2f(R, R));
	carre.setFillColor(Color(255,150,0));
	carre.setPosition(x-int(R/2),y-int(R/2));
	window.draw(carre);

}

/********************************************************************************/
	void Dessine_erreur(point p, RenderWindow& window, int R)/*Dessine un point de taille Rpx à la position (x,y)*/
{
	int x,y;
	p.get(x,y);
	RectangleShape carre(Vector2f(R, R));
	carre.setFillColor(Color(255,0,0));
	carre.setPosition(x-int(R/2),y-int(R/2));
	window.draw(carre);

}

/*******************************************************************************/
/**dessine les pixels restants en verts pour mieux les reperer**/

void Dessine_restant(int k,int l,int e, int r,int R, int xcentre, int **tab_pixel,RenderWindow& window)
{
	int x, y;
	for (int i=0;i<e;i++)
		{
		for (int j=0;j<l;j++)
			{
			if (tab_pixel[i][j]==0)
				{
				x=(xcentre+r-e*(k+1))+i;
				y=j;
				RectangleShape carre(Vector2f(R, R));
				carre.setFillColor(Color(0,0,255));
				carre.setPosition(x-int(R/2),y-int(R/2));
				window.draw(carre);
				}
			}
		}
}


void Dessine_restant(int k,int i, int y, int e, int r,int R, int xcentre, RenderWindow& window)
{
	int x=(xcentre+r-e*(k+1))+i;
	RectangleShape carre(Vector2f(3, 3));
	carre.setFillColor(Color(0,255,0));
	carre.setPosition(x,y);
	window.draw(carre);
			
}

/*******************************************************************************/
void Dessine_plus_points(tabpoint tab,tabpoint erreur, RenderWindow& window,int cote)
{
	point p1;
	int taille=tab.gettaille(), taille2=erreur.gettaille(), i;
	
	for (i=0; i<taille; i++)
	{
		tab.get(p1,i);
		Dessine_point(p1, window, cote);
	}
	for (i=0;i<taille2;i++)
	{
		erreur.get(p1,i);
		Dessine_erreur(p1, window, cote);
	}
}


/*******************************************************************************/
/**dessine les zones déjà coloriées et finies**/
void ZoneFinie(RenderWindow& window, int k, int e, int xcentre, int ycentre, int r)
{

    
    int i; float y;
    int nbpoint=k*e*2;
    int xdepart=xcentre+r-(k)*e;
    int ite=nbpoint/2;
    int xbout=xcentre+r;


    ConvexShape polygon;
	polygon.setPointCount(nbpoint);
	for (i=0;i<ite;i++)
	{ y= sqrt(r*r - (i+xdepart-xcentre)*(i+xdepart-xcentre))+ycentre;
	polygon.setPoint(i, sf::Vector2f(i+xdepart, y));
	y= -sqrt(r*r - (xbout-i-xcentre)*(xbout-i-xcentre))+ycentre;
	polygon.setPoint(i+ite, sf::Vector2f(xbout-i, y));
	} 
	
	// setPoint ( indice du point, sf::Vector2f(x,y))
	polygon.setFillColor(Color(244,100,27));
	
	
    window.draw(polygon);
}
