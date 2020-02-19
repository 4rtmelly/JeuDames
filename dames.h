
#include <stdio.h>
#include <stdlib.h>

#define DB 2
#define PB 1
#define DN -2
#define PN -1 


struct pion{
	int etat; 
	int x;
	int y;
};
typedef struct pion pion; 
//Prototype de fonction

//Initialisation de notre matrice ma qui definit le damier

void afficher(pion ma);
void jeu_graphique(pion ma[10][10]);
void initialisation(pion ma[10][10]);

//Deplacement -> Pion -> Dames

int depl_valide(pion ma[10][10], int depart[2], int arrivee[2]);
int depl_diagonale(pion ma[10][10],int depart[2], int arrivee[2]);
int depl_valide_dames(pion ma[10][10],int depart[2], int arrivee[2]);
int deplacement(pion ma[10][10], int depart[2], int arrivee[2]);

//Manger -> Pion -> Dames

int remanger(pion ma[10][10], int depart[2]);



//Condition Partie Finie :

int PartieFinie(pion ma[10][10]);
int PartieEgale(pion ma[10][10]);
