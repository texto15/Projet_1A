#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 
#include <fstream>
#include <string.h>
#include <iostream>
#include <ctime>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

string nbToStr(int nombre)
{
    ostringstream a;
    a << nombre;
    return a.str();
}

	
int main(int argc, char* argv[]) {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;
   
 
   
   /* Open database = verifier si bonne ouverture*/
   rc = sqlite3_open("chirurgie_endoluminale.db", &db);
   
   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   } else {
      fprintf(stdout, "Opened database successfully\n");
   }

   /*Create SQL statement pour créer une table avec les parametres suivants*/


   //table DB1
 //sql = "CREATE TABLE SIMULATIONIDENTIFICATION( id INTEGER PRIMARY KEY,NOM TEXT NOT NULL, PRENOM TEXT NOT NULL,DEUXPRENOM TEXT NOT NULL, TENTATIVES INT NOT NULL);";

   //table DB2
 //sql = "CREATE TABLE SIMULATIONDONNEES(id INT NOT NULL,AGE INT NOT NULL,FORMATION TEXT NOT NULL,NIVEAU TEXT NOT NULL,ENDOSCOPE TEXT NOT NULL,TEMPS INT NOT NULL,POURCENTAGEERREUR INT NOT NULL, NUMEROTENTATIVE INT NOT NULL, DATE TEXT NOT NULL, ETAT TEXT NOT NULL);";

   //table DB3
 //sql = "CREATE TABLE ADMINISTRATEUR(NOM TEXT NOT NULL, PRENOM TEXT NOT NULL,DEUXPRENOM TEXT NOT NULL);";
  // sql="DROP TABLE SIMULATIONDONNEES;";

// sql="SELECT * FROM SIMULATIONIDENTIFICATION;";
 sql="SELECT * FROM SIMULATIONDONNEES;";

 //sql="DELETE FROM SIMULATIONDONNEES";
   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "creation successfully\n");
   }
   sqlite3_close(db);

          

         

   return 0;
}
