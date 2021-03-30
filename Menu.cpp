#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "Menu.h"
#include "toucher.h"
#include "ExceptionPara.h"
#include <sstream>

using namespace sf;
using namespace std;


void menu(RenderWindow& window, string& Prenom, string& Prenom2, string& Nom, string& Age, string& Formation, string& Niveau, string& Endoscope, int& gamemode, int& ind, int& ecran)
{
	
	Font font;
	if (!font.loadFromFile("Arimo-Regular.ttf"))
	{
	// erreur...
	}
	
	Text text, text2, text3, text4;
	
	text.setFont(font);
	text.setCharacterSize(24); // exprimée en pixels, pas en points !
	text.setFillColor(Color::White);
	
	text2.setFont(font);
	text2.setCharacterSize(24); // exprimée en pixels, pas en points !
	text2.setFillColor(Color::Red);
	text2.setPosition(10, 150);
	
	text3.setFont(font);
	text3.setString(L"Non défini");
	text3.setFillColor(Color::Black);
	text3.setCharacterSize(24);
	text3.setPosition(610,335);
	
	text4.setFont(font);
	text4.setString(L"Retour");
	text4.setFillColor(Color::Black);
	text4.setCharacterSize(24);
	text4.setPosition(60,410);
	
	
	Text text5;
	text5.setFont(font);
	text5.setString(L"Chirurgien");
	text5.setFillColor(Color::Black);
	text5.setCharacterSize(24);
	text5.setPosition(340,160);
	
	Text text6;
	text6.setFont(font);
	text6.setString(L"Expert");
	text6.setFillColor(Color::Black);
	text6.setPosition(205,180);
	text6.setCharacterSize(24);
	

	while (gamemode==0)
	{
	
		switch (ecran)
		{
		
		case 0:
		menu0( window, text, text2, ecran, Prenom, Nom);
		break;
		
		
		case 1:
		text.setString(L"Bienvenue dans la simulation\nVeuillez entrer votre prénom (sans accents)");
		menuprenom( window, text, text2, text3, text4, Prenom, ecran);
		break;
		
		case 2:
		text.setString(L"Bienvenue dans la simulation\nVeuillez entrer votre deuxième prénom \n(sans accents)");
		menuprenom2(window, text, text2, text3, text4, Prenom2, ecran);
		
		case 3:
		menunom( window, text, text2, text3, text4, Nom, ecran);
		if (recherche(Prenom,Prenom2,Nom))
		{
			ind=1;
			ecran=0;
		}
		
		break;
		
		case 4:
		menu3( window, text, text2, text3, text4, Age, ecran);
		break;
		
		case 5:
		menu4( window, text, text2, text3, text4, text5, Formation, ecran);
		break;
		
		case 6:
		menu5( window, text, text2, text3, text4, text5, text6, Niveau, ecran);
		break;
		
		case 7:
		menu6( window, text, text2, text3, text4, text5, Endoscope, ecran);
		break;
		
		case 8:
		menu7(window, Prenom, Prenom2, Nom, Age, Formation, Niveau, Endoscope, ecran);
		break;
		
		case 9:
		gamemode=1;
		break;
		
		case 10:
		gamemode=10;
		break;
		
		case 15:
		reglage(window, font, ecran);
		break;
		}
		
		
	}
}

/**********************************************************************************/

void menu0(RenderWindow& window, Text& text, Text& text2, int& ecran, string& Prenom, string& Nom)
{
	
	Event event;
	Text text3;
	string s="Bonjour administrateur "+Prenom+" "+Nom;
	
	Font font;
	if (!font.loadFromFile("Arimo-Regular.ttf"))
	{
	// erreur...
	}
	
	text3.setFont(font);
	text3.setString(s);
	text3.setPosition(40,20);
	text3.setFillColor(Color::White);
	text3.setCharacterSize(24);
	
	text.setString(L"Débuter la simulation");
	text.setFillColor(Color::Black);
	text.setPosition(280,150);
	
	text2.setString(L"Réglage");
	text2.setPosition(355, 300);
	text2.setFillColor(Color::Black);
	
	RectangleShape rectangle1(Vector2f(300, 50));
	rectangle1.setPosition(250,140);
	rectangle1.setFillColor(Color::White);
	
	RectangleShape rectangle2(Vector2f(300, 50));
	rectangle2.setPosition(250,290);
	rectangle2.setFillColor(Color::White);
	
	while (ecran==0)
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
						ecran=9;
					}
					
					if (Button(window,250,290,300,50))
					{
						ecran=15;
					}
				}
			}
			
			
			if (event.type == Event::Closed)
			{
				window.close();
				ecran=10;
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


/**********************************************************************************/

void menuprenom(RenderWindow& window, Text& text, Text& text2, Text& text3, Text& text4, string& Prenom, int& ecran)
{
	
	Event event;
	
	Text text5;
	Font font;
	
	if (!font.loadFromFile("Arimo-Regular.ttf"))
	{
	// erreur...
	}
	
	
	text.setCharacterSize(24); // exprimée en pixels, pas en points !
	text.setFillColor(Color::White);
	text.setPosition(40,20);
	
	text2.setCharacterSize(24); // exprimée en pixels, pas en points !
	text2.setString(Prenom);
	text2.setFillColor(Color::Red);
	text2.setPosition(300, 220);
	
	text3.setPosition(610,335);
	
	text4.setFillColor(Color::Black);
	text4.setCharacterSize(24);
	text4.setPosition(60,410);
	
	text5.setFont(font);
	text5.setString(L"Suivant");
	text5.setFillColor(Color::Black);
	text5.setCharacterSize(24);
	text5.setPosition(620,410);
	
	RectangleShape rectangle1(Vector2f(140, 50));
	rectangle1.setPosition(600,325);
	rectangle1.setFillColor(Color::White);
	
	RectangleShape rectangle2(Vector2f(140, 50));
	rectangle2.setPosition(40,400);
	rectangle2.setFillColor(Color::White);
	
	RectangleShape rectangle3(Vector2f(140, 50));
	rectangle3.setPosition(600,400);
	rectangle3.setFillColor(Color::White);
	
	while (ecran==1)
	{
		if (window.pollEvent(event))
		{
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					Button(window, Prenom, ecran, "Non_defini", 600, 325, 140, 50);
					//Retour(window, ecran, 40, 400);
					if (Button(window,600,400,140,50))
					{
						if (Prenom.size() !=0 )
						{
							ecran+=1;
						}
					}
				}
			}
			if (event.type == Event::Closed)
			{
				window.close();
				ecran=10;
			}
			
			
			if (event.type == sf::Event::TextEntered)
			{
				Champtxt(event, Prenom);
			}
		}
	
	text2.setString(Prenom);
	
	window.clear();
	window.draw(rectangle1);
	//window.draw(rectangle2);
	window.draw(rectangle3);
	window.draw(text);
	window.draw(text2);
	window.draw(text3);
	//window.draw(text4);
	window.draw(text5);
	window.display();
	}
}
/**********************************************************************************/

void menuprenom2(RenderWindow& window, Text& text, Text& text2, Text& text3, Text& text4, string& Prenom, int& ecran)
{
	
	Event event;
	Text text5;
	Font font;
	
	if (!font.loadFromFile("Arimo-Regular.ttf"))
	{
	// erreur...
	}
	
	text.setCharacterSize(24); // exprimée en pixels, pas en points !
	text.setFillColor(Color::White);
	text.setPosition(40,20);
	
	text2.setCharacterSize(24); // exprimée en pixels, pas en points !
	text2.setString(Prenom);
	text2.setFillColor(Color::Red);
	text2.setPosition(300, 220);
	
	text3.setPosition(610,335);
	
	text4.setFillColor(Color::Black);
	text4.setCharacterSize(24);
	text4.setPosition(60,410);
	
	text5.setFont(font);
	text5.setString(L"Suivant");
	text5.setFillColor(Color::Black);
	text5.setCharacterSize(24);
	text5.setPosition(620,410);
	
	RectangleShape rectangle1(Vector2f(140, 50));
	rectangle1.setPosition(600,325);
	rectangle1.setFillColor(Color::White);
	
	RectangleShape rectangle2(Vector2f(140, 50));
	rectangle2.setPosition(40,400);
	rectangle2.setFillColor(Color::White);
	
	RectangleShape rectangle3(Vector2f(140, 50));
	rectangle3.setPosition(600,400);
	rectangle3.setFillColor(Color::White);
	
	while (ecran==2)
	{
		if (window.pollEvent(event))
		{
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					Button(window, Prenom, ecran, "Non_defini", 600, 325, 140, 50);
					Retour(window, ecran, 40, 400);
					if (Button(window,600,400,140,50))
					{
						if (Prenom.size() !=0 )
						{
							ecran+=1;
						}
					}
				}
			}
			if (event.type == Event::Closed)
			{
				window.close();
				ecran=10;
			}
			
			if (event.type == sf::Event::TextEntered)
			{
				Champtxt(event, Prenom);
			}
		}
	
	text2.setString(Prenom);
	
	window.clear();
	window.draw(rectangle1);
	window.draw(rectangle2);
	window.draw(rectangle3);
	window.draw(text);
	window.draw(text2);
	window.draw(text3);
	window.draw(text4);
	window.draw(text5);
	window.display();
	}
}

/**********************************************************************************/

void menunom(RenderWindow& window, Text& text, Text& text2, Text& text3, Text& text4, string& Nom, int& ecran)
{
	
	Event event;
	Text text5;
	Font font;
	
	if (!font.loadFromFile("Arimo-Regular.ttf"))
	{
	// erreur...
	}
	
	text.setString(L"Bienvenue dans la simulation\nVeuillez entrer votre nom (sans accents)");
	text.setCharacterSize(24); // exprimée en pixels, pas en points !
	text.setFillColor(Color::White);
	text.setPosition(40,20);
	
	text2.setCharacterSize(24); // exprimée en pixels, pas en points !
	text2.setFillColor(Color::Red);
	text2.setPosition(300, 220);
	
	text3.setPosition(610,335);
	
	text4.setFillColor(Color::Black);
	text4.setCharacterSize(24);
	text4.setPosition(60,410);
	
	text5.setFont(font);
	text5.setString(L"Suivant");
	text5.setFillColor(Color::Black);
	text5.setCharacterSize(24);
	text5.setPosition(620,410);
	
	RectangleShape rectangle1(Vector2f(140, 50));
	rectangle1.setPosition(600,325);
	rectangle1.setFillColor(Color::White);
	
	RectangleShape rectangle2(Vector2f(140, 50));
	rectangle2.setPosition(40,400);
	rectangle2.setFillColor(Color::White);
	
	RectangleShape rectangle3(Vector2f(140, 50));
	rectangle3.setPosition(600,400);
	rectangle3.setFillColor(Color::White);
	
	while (ecran==3)
	{
		if (window.pollEvent(event))
		{
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					Button(window, Nom, ecran, "Non_defini", 600, 325, 140, 50);
					Retour(window, ecran, 40, 400);
					if (Button(window,600,400,140,50))
					{
						if (Nom.size() !=0 )
						{
							ecran+=1;
						}
					}
				}
			}
			if (event.type == Event::Closed)
			{
				window.close();
				ecran=10;
			}
			
			
			
			if (event.type == sf::Event::TextEntered)
			{
				Champtxt(event, Nom);
			}
		}
	
	text2.setString(Nom);
	
	window.clear();
	window.draw(rectangle1);
	window.draw(rectangle2);
	window.draw(rectangle3);
	window.draw(text);
	window.draw(text2);
	window.draw(text3);
	window.draw(text4);
	window.draw(text5);
	window.display();
	}
}

/*****************************************************************************/

void menu3(RenderWindow& window, Text& text, Text& text2, Text& text3, Text& text4, string& Age, int& ecran)
{
	
	Event event;
	Text text5;
	Font font;
	
	if (!font.loadFromFile("Arimo-Regular.ttf"))
	{
	// erreur...
	}
	
	text.setString(L"Veuillez rentrer votre âge :");
	
	text.setCharacterSize(24); // exprimée en pixels, pas en points !
	text.setFillColor(Color::White);
	text.setPosition(40,20);
	
	text2.setCharacterSize(24); // exprimée en pixels, pas en points !
	text2.setString(Age);
	text2.setFillColor(Color::Red);
	text2.setPosition(300, 220);
	
	text3.setPosition(610,335);
	
	text4.setFillColor(Color::Black);
	text4.setCharacterSize(24);
	text4.setPosition(60,410);
	
	text5.setFont(font);
	text5.setString(L"Suivant");
	text5.setFillColor(Color::Black);
	text5.setCharacterSize(24);
	text5.setPosition(620,410);
	
	RectangleShape rectangle1(Vector2f(140, 50));
	rectangle1.setPosition(600,325);
	rectangle1.setFillColor(Color::White);
	
	RectangleShape rectangle2(Vector2f(140, 50));
	rectangle2.setPosition(40,400);
	rectangle2.setFillColor(Color::White);
	
	RectangleShape rectangle3(Vector2f(140, 50));
	rectangle3.setPosition(600,400);
	rectangle3.setFillColor(Color::White);
	
	while (ecran==4)
	{
		if (window.pollEvent(event))
		{
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					Button(window, Age, ecran, "Non_defini", 600, 325, 140, 50);
					Retour(window, ecran, 40, 400);
					if (Button(window,600,400,140,50))
					{
						if (Age.size() !=0 )
						{
							ecran+=1;
						}
					}
				}
			}
			
			
			if (event.type == Event::Closed)
			{
				window.close();
				ecran=10;
			}
			
			
			if (event.type == sf::Event::TextEntered)
			{
				Champtxt(event, Age);
			}
		}
	
	text2.setString(Age);
	
	window.clear();
	window.draw(rectangle1);
	window.draw(rectangle2);
	window.draw(rectangle3);
	window.draw(text);
	window.draw(text2);
	window.draw(text3);
	window.draw(text4);
	window.draw(text5);
	window.display();
	}

}

/********************************************************************************/

void menu4(RenderWindow& window, Text& text, Text& text2, Text& text3, Text& text4, Text& text5, string& Formation, int& ecran)
{
	
	Event event;
	
	text.setString(L"Veuillez selectionner votre formation :");
	
	text2.setString(L"Endoscopiste");
	text2.setPosition(325, 290);
	text2.setFillColor(Color::Black);
	
	text3.setPosition(610,410);
	
	text5.setString(L"Chirurgien");
	text5.setFillColor(Color::Black);
	text5.setCharacterSize(24);
	text5.setPosition(340,160);
	
	RectangleShape rectangle1(Vector2f(140, 50));
	rectangle1.setPosition(40,400);
	rectangle1.setFillColor(Color::White);
	
	RectangleShape rectangle2(Vector2f(140, 50));
	rectangle2.setPosition(600,400);
	rectangle2.setFillColor(Color::White);
	
	RectangleShape rectangle3(Vector2f(160, 50));
	rectangle3.setPosition(320,280);
	rectangle3.setFillColor(Color::White);
	
	RectangleShape rectangle4(Vector2f(160, 50));
	rectangle4.setPosition(320,150);
	rectangle4.setFillColor(Color::White);
	
	while (ecran==5)
	{
		if (window.pollEvent(event))
		{
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					Button(window, Formation, ecran, "Chirurgien", 320, 150, 160, 50);
					Button(window, Formation, ecran, "Endoscopiste", 320, 280, 160, 50);
					Button(window, Formation, ecran, "Non_defini", 600, 400, 140, 50);
					Retour(window, ecran, 40, 400);
				}
			}
			
			
			if (event.type == Event::Closed)
			{
				window.close();
				ecran=10;
			}
		
		}
	
	window.clear();

	window.draw(rectangle1);
	window.draw(rectangle2);
	window.draw(rectangle3);
	window.draw(rectangle4);
	window.draw(text);
	window.draw(text2);
	window.draw(text3);
	window.draw(text4);
	window.draw(text5);
	window.display();
	}
}


/*******************************************************************************/

void menu5(RenderWindow& window, Text& text, Text& text2, Text& text3, Text& text4, Text& text5,Text& text6, string& Niveau, int& ecran)
{
	Event event;
	
	text.setString(L"Veuillez selectionner votre formation :");
	
	text2.setString(L"Intermédiaire");
	text2.setPosition(325, 225);
	text2.setFillColor(Color::Black);
	
	text3.setPosition(610,410);
	
	text5.setString(L"Novice");
	text5.setPosition(365, 135);
	
	text6.setPosition(365, 315);
	
	RectangleShape rectangle1(Vector2f(140, 50));
	rectangle1.setPosition(40,400);
	rectangle1.setFillColor(Color::White);
	
	RectangleShape rectangle2(Vector2f(140, 50));
	rectangle2.setPosition(600,400);
	rectangle2.setFillColor(Color::White);
	
	RectangleShape rectangle3(Vector2f(160, 50));
	rectangle3.setPosition(320,305);
	rectangle3.setFillColor(Color::White);
	
	RectangleShape rectangle4(Vector2f(160, 50));
	rectangle4.setPosition(320,125);
	rectangle4.setFillColor(Color::White);
	
	RectangleShape rectangle5(Vector2f(160, 50));
	rectangle5.setPosition(320,215);
	rectangle5.setFillColor(Color::White);
	
	while (ecran==6)
	{
		if (window.pollEvent(event))
		{
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					Button(window, Niveau, ecran, "Novice", 320,125, 160, 50);
					Button(window, Niveau, ecran, "Intermediaire", 320,215, 160, 50);
					Button(window, Niveau, ecran, "Expert", 320,305, 160, 50);
					Button(window, Niveau, ecran, "Non_defini", 600, 400, 140, 50);
					Retour(window, ecran, 40, 400);
				}
			}
			
			
			if (event.type == Event::Closed)
			{
				window.close();
				ecran=10;
			}
		
		}
	
	window.clear();

	window.draw(rectangle1);
	window.draw(rectangle2);
	window.draw(rectangle3);
	window.draw(rectangle4);
	window.draw(rectangle5);
	window.draw(text);
	window.draw(text2);
	window.draw(text3);
	window.draw(text4);
	window.draw(text5);
	window.draw(text6);
	window.display();
	}
}
/********************************************************************************/

void menu6(RenderWindow& window, Text& text, Text& text2, Text& text3, Text& text4, Text& text5, string& Formation, int& ecran)
{
	
	Event event;
	
	text.setString(L"Veuillez selectionner le type\nd'endoscope utilisé :");
	
	text2.setString(L"Robot");
	text2.setPosition(350, 290);
	text2.setFillColor(Color::Black);
	
	text3.setPosition(610,410);
	
	text5.setString(L"Manuel");
	text5.setPosition(350,160);
	
	RectangleShape rectangle1(Vector2f(140, 50));
	rectangle1.setPosition(40,400);
	rectangle1.setFillColor(Color::White);
	
	RectangleShape rectangle2(Vector2f(140, 50));
	rectangle2.setPosition(600,400);
	rectangle2.setFillColor(Color::White);
	
	RectangleShape rectangle3(Vector2f(160, 50));
	rectangle3.setPosition(320,280);
	rectangle3.setFillColor(Color::White);
	
	RectangleShape rectangle4(Vector2f(160, 50));
	rectangle4.setPosition(320,150);
	rectangle4.setFillColor(Color::White);
	
	
	while (ecran==7)
	{
		if (window.pollEvent(event))
		{
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					Button(window, Formation, ecran, "Manuel", 320, 150, 160, 50);
					Button(window, Formation, ecran, "Robot", 320, 280, 160, 50);
					Button(window, Formation, ecran, "Non_defini", 600, 400, 140, 50);
					Retour(window, ecran, 40, 400);
				}
			}
			
			
			if (event.type == Event::Closed)
			{
				window.close();
				ecran=10;
			}
		
		}
	
	window.clear();

	window.draw(rectangle1);
	window.draw(rectangle2);
	window.draw(rectangle3);
	window.draw(rectangle4);
	window.draw(text);
	window.draw(text2);
	window.draw(text3);
	window.draw(text4);
	window.draw(text5);
	window.display();
	}
}

/*******************************************************************************/

void menu7(RenderWindow& window,string& Prenom,string& Prenom2,string& Nom,string& Age,string& Formation,string& Niveau,string& Endoscope, int& ecran)
{
	Text prenom, age, formation, niveau, endoscope, nbzone, r, c80, c95, temps, text1, text2, retour, Commencer;
	Event event;
	
	Font font;
	if (!font.loadFromFile("Arimo-Regular.ttf"))
	{
	// erreur...
	}
	
	string Nbzones, R, Condition80, Condition95, Temps;
	ifstream Para("PARAMETRE.txt");
	if (Para)
	{
		Para >> Nbzones >> R >> Condition80 >> Condition95 >> Temps;
	}
	Para.close();
	
	text1.setFont(font);
	text1.setFillColor(Color::White);
	text1.setPosition(40,20);
	text1.setString(L"Récapitulatif");
	text1.setCharacterSize(24);
	
	text2.setFont(font);
	text2.setFillColor(Color::White);
	text2.setPosition(350,120);
	text2.setString(L"Paramètres :");
	text2.setCharacterSize(24);
	
	prenom.setFont(font);
	prenom.setFillColor(Color::White);
	prenom.setPosition(40,60);
	prenom.setString(Prenom+" "+Prenom2+" "+Nom);
	prenom.setCharacterSize(24);
	
	age.setFont(font);
	age.setFillColor(Color::White);
	age.setPosition(40,100);
	age.setString(Age+" ans");
	age.setCharacterSize(24);
	
	formation.setFont(font);
	formation.setFillColor(Color::White);
	formation.setPosition(40,140);
	formation.setString(Formation);
	formation.setCharacterSize(24);
	
	niveau.setFont(font);
	niveau.setFillColor(Color::White);
	niveau.setPosition(40,180);
	niveau.setString(Niveau);
	niveau.setCharacterSize(24);
	
	endoscope.setFont(font);
	endoscope.setFillColor(Color::White);
	endoscope.setPosition(40,220);
	endoscope.setString(Endoscope);
	endoscope.setCharacterSize(24);
	
	nbzone.setFont(font);
	nbzone.setFillColor(Color::White);
	nbzone.setPosition(350,160);
	nbzone.setString("Nombre de zone : "+Nbzones);
	nbzone.setCharacterSize(24);
	
	r.setFont(font);
	r.setFillColor(Color::White);
	r.setPosition(350,200);
	r.setString("Taille du pixel : "+R);
	r.setCharacterSize(24);
	
	c80.setFont(font);
	c80.setFillColor(Color::White);
	c80.setPosition(350,240);
	c80.setString("% de la zone avant d'afficher\nles pixels restants : "+Condition80+"%");
	c80.setCharacterSize(24);
	
	c95.setFont(font);
	c95.setFillColor(Color::White);
	c95.setPosition(350,310);
	c95.setString(L"% de la zone avant de passer \nà la zone suivante : "+Condition95+"%");
	c95.setCharacterSize(24);
	
	temps.setFont(font);
	temps.setFillColor(Color::White);
	temps.setPosition(350,380);
	temps.setString("Temps maximal de la simulation : "+Temps+"s");
	temps.setCharacterSize(24);
	
	retour.setFont(font);
	retour.setString(L"Retour");
	retour.setFillColor(Color::Black);
	retour.setCharacterSize(24);
	retour.setPosition(60,335);
	
	Commencer.setFont(font);
	Commencer.setString(L"Commencer");
	Commencer.setFillColor(Color::Black);
	Commencer.setCharacterSize(24);
	Commencer.setPosition(45,410);
	
	RectangleShape rectangle1(Vector2f(140, 50));
	rectangle1.setPosition(40,400);
	rectangle1.setFillColor(Color::White);
	
	RectangleShape rectangle2(Vector2f(140, 50));
	rectangle2.setPosition(40,325);
	rectangle2.setFillColor(Color::White);
	
	while (ecran==8)
	{
		if (window.pollEvent(event))
		{
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					Retour(window, ecran, 40, 325);
					
					if(Button(window, 40, 400, 140, 50))
					{
						ecran+=1;
					}
				}
			}
			
			
			if (event.type == Event::Closed)
			{
				window.close();
				ecran=10;
			}
		
		}
	
	window.clear();
	window.draw(rectangle1);
	window.draw(rectangle2);
	window.draw(text1);
	window.draw(text2);
	window.draw(prenom);
	window.draw(age);
	window.draw(formation);
	window.draw(niveau);
	window.draw(endoscope);
	window.draw(r);
	window.draw(nbzone);
	window.draw(c80);
	window.draw(c95);
	window.draw(temps);
	window.draw(retour);
	window.draw(Commencer);
	window.display();
	}
}




/*******************************************************************************/

void Button(RenderWindow& window, string& text, int& ecran, string string,int coordx,int coordy,int taillex,int tailley)
{
	int x, y;
	Position_Curseur(x, y, window);
	if (x>coordx and x<(coordx+taillex))
	{
		if (y>coordy and y<(coordy+tailley))
		{
			text=string;
			ecran += 1;
		}
	}
}

/******************************************************************************/

void Retour(RenderWindow& window, int& ecran,int coordx,int coordy)
{
	int x, y;
	Position_Curseur(x, y, window);
	
	if (x>coordx and x<(coordx+140))
	{
		if (y>coordy and y<(coordy+50))
		{
			ecran -= 1;
		}
	}
}

/******************************************************************************/

bool Button(RenderWindow& window, int coordx, int coordy, int taillex,int tailley)
{
	int x, y;
	Position_Curseur(x, y, window);
	if (x>coordx and x<(coordx+taillex))
	{
		if (y>coordy and y<(coordy+tailley))
		{
			return(true);
		}
	}
	
	return(false);
}

/******************************************************************************/

void Champtxt(Event& event, string& string)
{
	if (event.text.unicode==8)
	{
		if (string.size() != 0)
		{
			string.erase(string.size()-1,1);
		}
	}
	else
	{
		string+=event.text.unicode;
	}
}

/******************************************************************************/

void reglage(RenderWindow& window, Font font,int& ecran)
{
	int var=-1;
	ifstream Para("PARAMETRE.txt");
	string Nbzones, R, Condition80, Condition95, temps;
	if (Para)
	{
		Para >> Nbzones >> R >> Condition80 >> Condition95 >> temps;
	}
	Para.close();
	Event event;
	
	Text text, text2, text3, text4, text5, text6, text7, text8, text9, text10, text11, text12, text13, text14, Except;
	
	text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(Color::White);
	text.setString(L"Appuyer sur le rectangle blanc correspondant au paramètre à changer,\npuis taper au clavier.");
	
	text2.setFont(font);
	text2.setCharacterSize(24);
	text2.setFillColor(Color::White);
	text2.setString(L"Nombre de zones :");
	text2.setPosition(20,90);
	
	text3.setFont(font);
	text3.setCharacterSize(24);
	text3.setFillColor(Color::White);
	text3.setString(L"Taille du pixel de\ncoloriage :");
	text3.setPosition(20,180);
	
	text4.setFont(font);
	text4.setCharacterSize(24);
	text4.setFillColor(Color::White);
	text4.setString(L"% de la zone\ndevant être coloriée\navant de passer à\nla zone suivante :");
	text4.setPosition(300,90);
	
	text5.setFont(font);
	text5.setCharacterSize(24);
	text5.setFillColor(Color::White);
	text5.setString(L"% de la zone\ndevant être coloriée\navant d'afficher\nles pixels restants:");
	text5.setPosition(300,280);
	
	text6.setFont(font);
	text6.setCharacterSize(24);
	text6.setFillColor(Color::Black);
	text6.setString(L"Annuler");
	text6.setPosition(625,335);
	
	text7.setFont(font);
	text7.setCharacterSize(24);
	text7.setFillColor(Color::Black);
	text7.setString(L"Enregistrer");
	text7.setPosition(610,410);
	
	text8.setFont(font);
	text8.setCharacterSize(24);
	text8.setFillColor(Color::Black);
	text8.setString(L"Par défaut");
	text8.setPosition(620,260);
	
	text9.setFont(font);
	text9.setCharacterSize(24);
	text9.setFillColor(Color::Red);
	text9.setString(Nbzones);
	text9.setPosition(70,140);
	
	text10.setFont(font);
	text10.setCharacterSize(24);
	text10.setFillColor(Color::Red);
	text10.setString(R);
	text10.setPosition(70,270);
	
	text11.setFont(font);
	text11.setCharacterSize(24);
	text11.setFillColor(Color::Red);
	text11.setString(Condition95);
	text11.setPosition(360,220);
	
	text12.setFont(font);
	text12.setCharacterSize(24);
	text12.setFillColor(Color::Red);
	text12.setString(Condition95);
	text12.setPosition(360,410);
	
	text13.setFont(font);
	text13.setCharacterSize(24);
	text13.setString("Limite de temps\n(en s)");
	text13.setFillColor(Color::White);
	text13.setPosition(20,330);
	
	text14.setFont(font);
	text14.setCharacterSize(24);
	text14.setFillColor(Color::Red);
	text14.setString(Condition95);
	text14.setPosition(70,410);
	
	Except.setFont(font);
	Except.setCharacterSize(24);
	Except.setFillColor(Color::Red);
	Except.setString(Condition95);
	Except.setPosition(600,90);
	Except.setString("");
	
	RectangleShape rectangle(Vector2f(50,40));
	rectangle.setPosition(60,130);
	rectangle.setFillColor(Color::White);
	
	RectangleShape rectangle2(Vector2f(50,40));
	rectangle2.setPosition(60,260);
	rectangle2.setFillColor(Color::White);
	
	RectangleShape rectangle3(Vector2f(50,40));
	rectangle3.setPosition(350,210);
	rectangle3.setFillColor(Color::White);
	
	RectangleShape rectangle4(Vector2f(50,40));
	rectangle4.setPosition(350,400);
	rectangle4.setFillColor(Color::White);
	
	RectangleShape rectangle5(Vector2f(150,50));
	rectangle5.setPosition(600, 325);
	rectangle5.setFillColor(Color::White);
	
	RectangleShape rectangle6(Vector2f(150,50));
	rectangle6.setPosition(600, 250);
	rectangle6.setFillColor(Color::White);
	
	RectangleShape Enr(Vector2f(150,50));
	Enr.setPosition(600, 400);
	Enr.setFillColor(Color::White);
	
	RectangleShape time(Vector2f(70,40));
	time.setPosition(60, 400);
	time.setFillColor(Color::White);
	
	while (ecran==15)
	{
		if (window.pollEvent(event))
		{
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					if (Button(window, 600, 325, 150, 50))
					{
						ecran=0;
					}
					
					if (Button(window, 60, 130, 50, 40))
					{
						var=1;
					}
					
					if (Button(window, 60, 260, 50, 40))
					{
						var=2;
					}
					
					if (Button(window, 350, 210, 50, 40))
					{
						var=3;
					}
					
					if (Button(window, 350, 400, 50, 40))
					{
						var=4;
					}
					
					if (Button(window, 60, 400, 70, 40))
					{
						var=5;
					}
					
					if (Button(window, 600, 250, 150, 50))
					{
						ecran=0;
						Defaut(Nbzones, R, Condition80, Condition95, temps);
						try
						{
							Enregistrer(Nbzones, R, Condition80, Condition95, temps);
						}
						
						catch (ExceptionPara& e)
						{
							Except.setString(e.message());
							ecran=15;
						}
					}
					
					if (Button(window, 600, 400, 150, 50))
					{
						ecran=0;
						try
						{
							Enregistrer(Nbzones, R, Condition80, Condition95, temps);
						}
						
						catch (ExceptionPara& e)
						{
							Except.setString(e.message());
							ecran=15;
						}
					}
				}
			}
			
			if (event.type == sf::Event::TextEntered)
			{
				switch (var)
				{
					case 1:
					Champtxt(event, Nbzones);
					break;
					
					case 2:
					Champtxt(event, R);
					break;
					
					case 3:
					Champtxt(event, Condition95);
					break;
					
					case 4:
					Champtxt(event, Condition80);
					break;
					
					case 5:
					Champtxt(event, temps);
					break;
				}
			}
			
			
			if (event.type == Event::Closed)
			{
				window.close();
				ecran=10;
			}
		
		}
	
	text9.setString(Nbzones);
	text10.setString(R);
	text11.setString(Condition95);
	text12.setString(Condition80);
	text14.setString(temps);
	
	window.clear();
	window.draw(rectangle);
	window.draw(rectangle2);
	window.draw(rectangle3);
	window.draw(rectangle4);
	window.draw(rectangle5);
	window.draw(rectangle6);
	window.draw(time);
	window.draw(Enr);
	window.draw(text);
	window.draw(text2);
	window.draw(text3);
	window.draw(text4);
	window.draw(text5);
	window.draw(text6);
	window.draw(text7);
	window.draw(text8);
	window.draw(text9);
	window.draw(text10);
	window.draw(text11);
	window.draw(text12);
	window.draw(text13);
	window.draw(text14);
	window.draw(Except);
	window.display();
	
	}
}


/************************************************************************************/
void Defaut(string& Nbzones, string& R, string& Condition80, string& Condition95, string& temps)
{
	Nbzones="5";
	R="20";
	Condition80="80";
	Condition95="95";
	temps="300";
}

/************************************************************************************/

void Enregistrer(string& nb, string& r, string& c80, string& c95, string& temps)
{
	stringstream ss;
	int Nb, R, C80, C95, Temps;
	
	ss << nb << " " << r << " " << c80 << " " << c95 << " " << temps << endl;
	ss >> Nb >> R >> C80 >> C95 >> Temps ;
	
	if (Nb<1 or Nb>8)
	{
		throw(ExceptionPara("Le nombre de\nzone doit\netre compris\nentre 1 et 8"));
	}
	
	if (R<5 or R>30)
	{
		throw(ExceptionPara("La taille du\npixels doit\netre comprise\nentre 5 et 30"));
	}
	
	if (C80<10 or C80>100 or C95<10 or C95>100)
	{
		throw(ExceptionPara("Le % de pixels\ncolories doit\netre entre\n10 et 100"));
	}
	
	if (Temps<5)
	{
		throw(ExceptionPara("Le temps\nmaximal de la\nsimulation\ndoit etre au\nmoins de 5s"));
	}
	
	else
	{
		ofstream Res("PARAMETRE.txt");
		
		if (Res)
		{
		Res << nb << " " << r << " " << c80 << " " << c95 << " " << temps << endl;
		}
		Res.close();
	}
	
	
}


/***********************************************************************************/

void Verif(int& ind, int& nbzone, int& R, int& condition80, int& condition95)
{
	if ( nbzone==5 and R==20 and condition80==80 and condition95==95 )
	{
		ind = 2;
	}
	
	else 
	{
		ind = 1;
	}
	
}

/*****************************************************************************************/

bool recherche(string& Prenom, string& Prenom2, string& Nom)
{
	ifstream Id ("IDENTIFIANT.txt");
	string prenom,prenom2,nom, ligne;
	bool admin=false;
	int i=0,j=0;
	
	if(Id)
	{
		while(getline(Id, ligne) and admin==false)
		{
			while(i<ligne.size())
			{
				if (ligne[i]==' ')
				{
					j++;
				}
				
				else if (j==0)
				{
					prenom+=ligne[i];
				}
				
				else if (j==1)
				{
					prenom2+=ligne[i];
				}
				
				else if (j==2)
				{
					nom+=ligne[i];
				}
				
				i++;
			}
			i=0;
			j=0;
			
			admin=(prenom==Prenom and prenom2==Prenom2 and nom==Nom);
			prenom.clear();
			prenom2.clear();
			nom.clear();
		}
	}
	else
	{
		cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	}
	
	return admin;
}



























