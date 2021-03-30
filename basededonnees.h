#ifndef BASEDEDONNEES_H
#define BASEDEDONNEES_H


#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 
#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
using namespace std;




string nbToStr(int nombre);

int StrTonb(string texte);

void plusun(string &texte);


static int callback(void *data, int argc, char **argv, char **azColName);


class SQLBASE { public : 
     sqlite3 *db;
     sqlite3_stmt *stmt;
     char *zErrMsg = 0;
     string prenom,nom,deuxprenom;
     string compteur;
     int rc;
     string sql;
     string truesql;
     string id;

    public :
    void SQLinitialisation(string,string,string);
    int isExist();
    //tring SQLid();
    string getid();
    string getcompteur(int);
    string SQLcompteur(int);
    void SQLrequete(int);

    

};


class SQLBASE2 {
   public :
      string age;
      string formation,endoscope,niveau,date;
      string temps,pourcentagerreur,etat;
      sqlite3 *db;
      sqlite3_stmt *stmt;
      char *zErrMsg = 0;
      string tentative;
      int rc;
      string sql;
      string truesql;
      string id;
   public :
      void SQLinitialisation2(string,string,string,string);
      //~SQLBASE();
      void SQLrecupererResults(string,string,string);
      void SQLrecupererid(SQLBASE);
      void SQLrecupererCompteur(int,SQLBASE);
      void SQLrequete2();
};




#endif