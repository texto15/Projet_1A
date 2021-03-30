#include <SFML/Graphics.hpp>
#include <iostream>
#include "Fin.h"
#include "resultat.h"
#include "Menu.h"


using namespace sf;
using namespace std;


void affichage_fin(RenderWindow& window,int nbzone, int& gamemode, int* erreurs, int* points, int* n, time_t& temps)
{
	
	Event event;
	window.clear();
	while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				{window.close();}
			
			if (event.type == Event::KeyPressed)
			{
				if ((event.key.code == Keyboard::Q) or (event.key.code == Keyboard::N))
				{
					window.close();
				}
			}
		}
	window.clear();
	affichage_erreur(nbzone, points, erreurs, window, n, temps);
	window.display();
}

/*************************************************************************************************/

void menufin(RenderWindow& window, int& gamemode, int& ecran)
{
	Event event;
	Text text, text2, text3;
	int fin=0;
	
	Font font;
	if (!font.loadFromFile("Arimo-Regular.ttf"))
	{
	// erreur...
	}
	
	text3.setFont(font);
	text3.setString(L"La simulation est terminée, que voulez vous faire ?");
	text3.setPosition(40,20);
	text3.setFillColor(Color::White);
	text3.setCharacterSize(24);
	
	text.setFont(font);
	text.setCharacterSize(24);
	text.setString(L"Recommencer");
	text.setFillColor(Color::Black);
	text.setPosition(300,150);
	
	text2.setFont(font);
	text2.setCharacterSize(24);
	text2.setString(L"Quitter");
	text2.setPosition(355, 300);
	text2.setFillColor(Color::Black);
	
	RectangleShape rectangle1(Vector2f(300, 50));
	rectangle1.setPosition(250,140);
	rectangle1.setFillColor(Color::White);
	
	RectangleShape rectangle2(Vector2f(300, 50));
	rectangle2.setPosition(250,290);
	rectangle2.setFillColor(Color::White);
	
	while (fin==0)
	{
		if (window.pollEvent(event))
		{
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					int x, y;
					Position_Curseur(x, y, window);
					if (Button(window,250,140,300, 50))
					{
						gamemode=0;
						ecran=8;
						fin=1;
					}
					
					if (Button(window,250,290,300,50))
					{
						gamemode=10;
						fin=1;
					}
				}
			}
			
			
			if (event.type == Event::Closed)
			{
				window.close();
				gamemode=10;
				fin=1;
			}
		
		}
	
	window.clear();
	window.draw(rectangle1);
	window.draw(rectangle2);
	window.draw(text);
	window.draw(text2);
	window.draw(text3);
	window.display();
	}
}
