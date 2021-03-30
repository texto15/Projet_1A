#include <SFML/Graphics.hpp>
#include <iostream>
#include "toucher.h"
#include "interface.h"
#include <ctime>
#include <time.h>



using namespace std;
using namespace sf;

void Position_Curseur(int& x, int& y, RenderWindow& window)/*Récupère la postion de la souris relative à la fenêtre*/
{
	Vector2i localPosition = Mouse::getPosition(window);
	x = localPosition.x;
	y = localPosition.y;
}

/*******************************************************************************/

void Ajoute_point(vector<point> tab_point, int* taille, RenderWindow& window)
{
	int x, y;
	point p1;
	Position_Curseur(x, y, window);
	p1.set(x,y);
	
	tab_point.push_back(p1);
	*taille = *taille + 1 ;
	tab_point.push_back(p1);
}

/*********************************************************************************/

void point::set(int x, int y)
{
	this->x=x;
	this->y=y;
}

void point::get(int& x, int& y)
{
	x=this->x;
	y=this->y;
}

point::point(){}

point::point(int x, int y)
{
	this->x=x;
	this->y=y;
}

/*******************************************************************************/

tabpoint::tabpoint(){taille=0;}

void tabpoint::append(point& p)
{
	this->tab.push_back(p);
	taille++;
}

void tabpoint::get(point& p, int i)
{
	int x,y;
	tab[i].get(x, y);
	p.set(x, y);
}

int tabpoint::gettaille()
{
	return(taille);
}


/*****************************************************************************/

void tabpoint::reset()
{
	this->tab.clear();
	this->taille=0;
}

/********************************************************************************/










