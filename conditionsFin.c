#include "dames.h"
#define DB 2
#define PB 1
#define DN -2
#define PN -1 

// > CONDITION 1 DE PARTIE PERDUE : QUAND UN DES JOUEURS N'A PLUS DE PIECES SUR LE PLATEAU MA
int PartieFinie(pion ma[10][10]){

    int i,j; //Compteur
    int CompteurBlanc = 0;
    int CompteurNoir = 0;

    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if(ma[i][j].etat == PN || ma[i][j].etat == DN){
                CompteurNoir++;
            }
            else if(ma[i][j].etat == PB || ma[i][j].etat == DB){
                CompteurBlanc++;
            }
        }
    }

    if(CompteurBlanc == 0){
        printf("\nLes blancs n'ont plus de pièces, vous avez perdu !\n");
        return 1;
    }

    else if (CompteurNoir == 0){
        printf("\nLes noirs n'ont plus de pièces, vous avez perdu !\n");
        return 1;
    }
   	return 0;
}

// > CONDITION 2 DE PARTIE EGALE : SELON LE NOMBRE DE PIECES DES DEUX ADVERSAIRES (Dames/Pion)
int PartieEgale(pion ma[10][10]){
    int i,j;
    int CompteurDamesNoir = 0;
    int CompteurPionNoir = 0;

    int CompteurDamesBlanc = 0;
    int CompteurPionBlanc = 0;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if(ma[i][j].etat == PN){
                CompteurPionNoir++;
            }
            else if(ma[i][j].etat == DN){
                CompteurDamesNoir++;
            }

            else if(ma[i][j].etat == PB){
                CompteurPionBlanc++;
            }
            else if(ma[i][j].etat == DB){
                CompteurDamesBlanc++;
            }
            
        }
    }

    if(CompteurDamesBlanc == 3 && CompteurDamesNoir == 2 && CompteurPionNoir == 1){
    	printf("La partie est finie, il y a une égalité !\n");
        return 1; 
    }

    else if(CompteurDamesNoir == 3 && CompteurDamesBlanc == 2 && CompteurPionBlanc == 1){
    	printf("La partie est finie, il y a une égalité !\n");
        return 1; 
    }

    else if(CompteurDamesNoir == 1 && CompteurDamesBlanc == 1 && CompteurPionBlanc == 2){
    	printf("La partie est finie, il y a une égalité !\n");
        return 1; 

    }
    else if(CompteurDamesNoir == 1 && CompteurDamesBlanc == 1 && CompteurPionBlanc == 2){
    	printf("La partie est finie, il y a une égalité !\n");
        return 1; 
    }
    else if(CompteurDamesNoir == 1 && CompteurDamesBlanc == 1){
    	printf("La partie est finie, il y a une égalité !\n");
        return 1; 
    }
    return 0;
}
