#include <SFML/Graphics.hpp>
#include <iostream>
#include "resultat.h"

#include <fstream>

#include <ctime>


using namespace std;
using namespace sf;


void compt_erreur( int& points, int& erreurs,tabpoint tab, tabpoint erreur)
{
	points+=tab.gettaille();
	erreurs+=erreur.gettaille();
	
}

void affichage_erreur(int nbzones, int* points, int* erreurs, RenderWindow& window, int* n, time_t& temps)
{
	//calcul le pourcentage d'incisions a l'interieur de la zone
	int erreurstot=0,pointstot=0;
		
	for(int i=0;i<nbzones;i++)
		{
		n[i+1]=100*float((points[i]-erreurs[i])/float(points[i]+erreurs[i]));
		erreurstot+=erreurs[i];
		pointstot+=points[i];
		}
	
	n[0]=100*abs(float(pointstot-erreurstot)/float(pointstot+pointstot));
	
	// Conversion de l'entier
	char nb[4], tps[4];
	sprintf(tps, "%ld", temps); 
 	
 	Font font;//chargement de la police
	if (!font.loadFromFile("Arimo-Regular.ttf"))
		{cout<<"erreur chargement police"<<endl;}
	
	Text text,text2;
	
	for(int i=0;i<nbzones;i++)
	{
	text.setFont(font);
	text.setString("Pourcentage d'incisions a l'interieur de la zone ");
	text.setCharacterSize(16);
	text.setFillColor(Color::White);
	text.setPosition(0,i*20);
	window.draw(text);
	
	sprintf(nb, "%d", i+1);
	text.setString(nb);
	text.setPosition(360,i*20);
	window.draw(text);
	
	sprintf(nb, "%d", n[i]);
	text.setString(nb);
	text.setPosition(390,i*20);
	window.draw(text);
	}
	text2.setFont(font);
	text2.setString("temps de simulation");
	text2.setCharacterSize(16);
	text2.setFillColor(Color::White);
	//text2.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text2.setPosition(0,160);
	window.draw(text2);
	text2.setString(tps);
	text2.setPosition(390,160);
	window.draw(text2);
}

/**************************************************************************/

void Envoi(String Nom, String Age, String Formation, String Niveau, time_t& chrono, int& n)
{
	ofstream Res ("RESULTAT.txt",ios::app);
	//Nom.erase(Nom.getSize()-1,1);
	//Age.erase(Age.getSize()-1,1);
	
	string text=Nom, age=Age, formation=Formation, niveau=Niveau;
	if (Res)
	{
	Res << text << "	" << age << "	" << formation << "	" << niveau <<"	" << chrono << "s	" << n << "%" << endl;
	}
	
	else
	{
		cout << "impossibe d'ouvrir le fichers" << endl;
	}
}






int chronosimul(time_t temps_debut)
{
//temps en secondes
time_t temps_fin; 
time_t temps_operation;  

time(&temps_fin); 
temps_operation = temps_fin-temps_debut;


return temps_operation;
}



