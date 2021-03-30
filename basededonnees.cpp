#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 
#include <fstream>
#include <iostream>
#include <sstream>
#include <string.h>

#include <ctime>
#include <string>
#include <iomanip>

#include "basededonnees.h"

string nbToStr(int nombre)
{
    ostringstream a;
    a << nombre;
    return a.str();
}

int StrTonb(string texte)
{
   int nombre;
   istringstream iss( texte );
   iss >> nombre;
   return nombre;
}

void plusun(string &texte)
{
   int nombre;
   nombre=StrTonb(texte);
   nombre=nombre+1;
   texte=nbToStr(nombre);
}


static int callback(void *data, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}




        
        
int SQLBASE::isExist(){        
        int booleen=1;
       
        rc = sqlite3_open("chirurgie_endoluminale.db", &db);
         sql = "SELECT ID FROM SIMULATIONIDENTIFICATION WHERE PRENOM='"+prenom+"'AND NOM='"+nom+"' AND DEUXPRENOM='"+deuxprenom+"';";
        rc = sqlite3_prepare_v2( db,  sql.c_str(), -1, &stmt, NULL);

        do {
            rc = sqlite3_step(stmt);
            if ( rc == SQLITE_ROW) { //can read data
                id=(char *)sqlite3_column_text(stmt,0);
                
                } 
            
	    } while ( rc == SQLITE_ROW);
        
        if (id.empty()){
            booleen=0;
        }
        
        
        sqlite3_close( db);
    return booleen;
}    







  
void SQLBASE::SQLinitialisation(string prenomprojet, string nomprojet, string deuxprenomprojet) {
        nom=nomprojet;
        prenom=prenomprojet;
        deuxprenom=deuxprenomprojet;
        
        isExist();

       
}
     


string SQLBASE::SQLcompteur(int menu){
            rc = sqlite3_open("chirurgie_endoluminale.db", &db);
            
                sql = "SELECT TENTATIVE FROM SIMULATIONIDENTIFICATION WHERE ID="+id;
                rc = sqlite3_prepare_v2( db,  sql.c_str(), -1, &stmt, NULL);

                do {
                    rc = sqlite3_step( stmt);
                    if ( rc == SQLITE_ROW) { //can read data
                        compteur=(char *)sqlite3_column_text( stmt,0);
                       
                    }  
                } while ( rc == SQLITE_ROW);

                

            if (menu==1){
                
                if (compteur.empty()){ compteur="0";}
                plusun(compteur);

                sqlite3_close( db);
                return compteur;
            }
            
            
            
            
           
           
        
        }

string SQLBASE::getid(){
    return id;
}
string SQLBASE::getcompteur(int menu){
    if (menu==1){
        return compteur;
    }
    
    
}
void SQLBASE::SQLrequete(int menu){

    truesql="INSERT INTO SIMULATIONIDENTIFICATION(NOM,PRENOM,DEUXPRENOM,TENTATIVES) VALUES('";
    rc = sqlite3_open("chirurgie_endoluminale.db", &db);
    if (isExist()){
        if (menu==1){
            sql="UPDATE SIMULATIONIDENTIFICATION SET TENTATIVE="+compteur+" WHERE ID="+id+";";
        }
        
    }
    else {
        sql=truesql+nom+"','"+prenom+"','"+deuxprenom+"',"+compteur+");";
    }
    
    
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
   
    if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "requete done successfully\n");
   }
   sqlite3_close(db);
}


/* TABLE SIMULATIONDONNEES
valeurs : ID,AGE,FORMATION,ENDOSCOPE,TEMPS,POURCENTAGE ERREUR,TENTATIVE,TENTATIVE2
*/

void SQLBASE2::SQLinitialisation2( string ageprojet,string formationprojet, string niveauprojet, string endoscopeprojet){
            age=ageprojet;
            formation=formationprojet;
            niveau=niveauprojet;
            endoscope=endoscopeprojet;

            string annee,mois,jour;
            struct tm Today;
            time_t maintenant; 
            time(&maintenant); 
            Today = *localtime(&maintenant); 
            annee=nbToStr(Today.tm_year+1900);
            mois=nbToStr(Today.tm_mon+1);
            jour=nbToStr(Today.tm_mday);
            date=annee+"/"+mois+"/"+jour;
             cout << date;
            

        }

void SQLBASE2::SQLrecupererResults(string tempsprojet, string pourcentagerreurprojet, string etatprojet){
          temps=tempsprojet;
          pourcentagerreur=pourcentagerreurprojet;
          etat=etatprojet;
}

void SQLBASE2::SQLrecupererid(SQLBASE objet){
    if (objet.isExist()){
        id=objet.getid();
    }
   
}

void SQLBASE2::SQLrecupererCompteur(int menu, SQLBASE objet){
    if (menu==1){
        tentative=objet.getcompteur(menu);
        
    }
    
}

void SQLBASE2::SQLrequete2(){

    truesql="INSERT INTO SIMULATIONDONNEES(ID,AGE,FORMATION,NIVEAU,ENDOSCOPE,TEMPS,POURCENTAGEERREUR,NUMEROTENTATIVE,DATE,ETAT) VALUES(";
    rc = sqlite3_open("chirurgie_endoluminale.db", &db);

    sql=truesql+id+","+age+",'"+formation+"','"+niveau+"','"+endoscope+"',"+temps+","+pourcentagerreur+","+tentative+",'"+date+"','"+etat+"'"+");";
    
    
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
   
    if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "requete done successfully\n");
   }
   sqlite3_close(db);
}





      /*  int main(){
        string Prenom="Guigui", Nom="Deschamps", Prenom2="Remi", age="21", formation="ÉTUDIANTE", niveau="Novice", endoscope="MANUEL";
        
        SQLBASE objet;
        objet.SQLinitialisation(Prenom, Nom, Prenom2);
        objet.SQLcompteur(2);
        objet.SQLrequete(2);

        SQLBASE2 obj;
        obj.SQLinitialisation2(age,formation,niveau,endoscope);
        obj.SQLrecupererid(objet);
        obj.SQLrecupererCompteur(2,objet);
        obj.SQLrequete2();


        }
*/


//creer string nom prenom deuxprenom
