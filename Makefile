CXX=g++
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system -lm -l sqlite3
EXEC=Test_V1

all: $(EXEC)

Test_V1: main.o interface.o toucher.o zone.o air.o ligne.o Jeu.o Menu.o resultat.o Fin.o basededonnees.o ExceptionPara.o
	$(CXX) -o $@ $^ $(LDFLAGS)

main.o: interface.h toucher.h zone.h parametre.h ligne.h Jeu.h Menu.h resultat.h Fin.h basededonnees.h
%.o: %.c
	$(CXX) -o $@ -c $< $(CFLAGS)

toucher.o: toucher.h interface.h parametre.h
%.o : %.c
	$(CXX) -o $@ -c $< $(CFLAGS)

interface.o: toucher.h interface.h parametre.h
%.o : %.c
	$(CXX) -o $@ -c $< $(CFLAGS)

zone.o: toucher.h zone.h parametre.h
%.o : %.c
	$(CXX) -o $@ -c $< $(CFLAGS)

air.o: air.h
%.o : %.c
	$(CXX) -o $@ -c $< $(CFLAGS)

ligne.o: ligne.h toucher.h
%.o : %.c
	$(CXX) -o $@ -c $< $(CFLAGS)

Jeu.o: interface.h toucher.h zone.h parametre.h ligne.h Jeu.h
%.o : %.c
	$(CXX) -o $@ -c $< $(CFLAGS)

Menu.o: Menu.h ExceptionPara.h
%.o : %.c
	$(CXX) -o $@ -c $< $(CFLAGS)

resultat.o: resultat.h
%.o : %.c
	$(CXX) -o $@ -c $< $(CFLAGS)
	
Fin.o: Fin.h
%.o : %.c
	$(CXX) -o $@ -c $< $(CFLAGS)

basededonnees.o: basededonnees.h
%.o : %.c
	$(CXX) -o $@ -c $< $(CFLAGS)

ExceptionPara.o: ExceptionPara.h
%.o : %.c
	$(CXX) -o $@ -c $< $(CFLAGS)






