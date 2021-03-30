
#ifndef INTERFACE_H
#define INTERFACE_H
#include "toucher.h"
#include <math.h>

using namespace sf;
using namespace std;

void Grand_cercle(RenderWindow&);
void Position_ligne(int ,int, RenderWindow&);
void Dessine_point(point ,RenderWindow&, int );
void Dessine_plus_points(tabpoint, tabpoint, RenderWindow&,int );
void Dessine_restant(int ,int , int ,int ,int ,int , int, RenderWindow& );
void Dessine_erreur(int , int , RenderWindow&, int );
void ZoneFinie(RenderWindow&, int , int , int, int, int );


#endif
