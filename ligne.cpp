#include "ligne.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

void ligne::Position_ligne(RenderWindow& window)
//Permet de mettre la ligne à la position (x,y)
{
	int x, y;
	get(x,y);
	RectangleShape line(Vector2f(450,5));
	line.rotate(90);
	line.setPosition(x,y);
	line.setFillColor(Color::Red);
	window.draw(line);
}

ligne::ligne(int x, int y)
{
	set(x,y);
}
