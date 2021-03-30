#ifndef RESULTAT_H
#define RESULTAT_H
#include "toucher.h"
#include <SFML/Graphics.hpp>

#include <ctime>
#include <time.h>


using namespace sf;
using namespace std;

void compt_erreur( int& points, int& erreurs,tabpoint tab, tabpoint erreur);

void affichage_erreur(int, int*, int*, RenderWindow&, int*, time_t&);
void Envoi(String, String, String, String, time_t&, int&);

int chronosimul(time_t temps_debut);


#endif
