#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "interface.h"
#include "toucher.h"
#include "zone.h"
#include <vector>
/*#define diametre 350*/
#define nbzone 5

using namespace std;
using namespace sf;


/*tableau aire de taille [diametre/nbzone] x largeurecran */
/*pour calculer aire pas besoin de tableau juste besoin nombre pixels
  ds le tableau et enlever les pixels (i,j) qui sont pas ds cercle*/
  
//k va de 0 à 4

int calculaire(int k,int e,int largeur,int a,int b,int r, int R)
{
	int i,j,l,aire,sup,inf,diametre, compteur1=0, compteur2=0;
	aire=(e-R/2-R/2)*largeur;
	sup=a+r-k*e-R/2; //borne sup de la zone
	inf=a+r-(k+1)*e+R/2; //born inf de la zone
	i=inf;
	while (i>=inf && i<sup)
	{ 	j=0;
		l=largeur;
		while(zone(k,i,j,a,b,r,R,e)!=1)
		{	
			j+=1;
			aire=aire-1; 
		}  
		while (zone(k,i,l,a,b,r,R,e)!=1)
		{
			l-=1;
			aire=aire-1; 
		}
		i+=1;
	}
	return aire;
}


