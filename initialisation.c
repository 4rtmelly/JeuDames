#include "dames.h"
#define DB 2
#define PB 1
#define DN -2
#define PN -1 

void afficher_pion(pion ma){
	if (ma.etat == PB){
		printf("b");
	}
	else if (ma.etat == PN){
		printf("n"); 
	}
	else if(ma.etat == 0){
		printf(" ");
	}
	else if(ma.etat == DB){
		printf("B");
	}
	else if(ma.etat == DN){
	    printf("N");
	}
}


void jeu_graphique(pion ma[10][10]){
	int i,j;
	printf(" 0 1 2 3 4 5 6 7 8 9\n\n");
	for (i = 0; i < 10; i++){
		printf("+-+-+-+-+-+-+-+-+-+-+\n");			
		for (j = 0; j < 10; j++){	
			printf("|");
			afficher_pion(ma[i][j]);
			if(j >= 9){
				printf("|  %d\n", i);
			}
		}		
	}
}

void initialisation(pion damier[10][10]){
    int i;
    for(i=1;i<10;i=i+2){
        damier[0][i].etat = PN;
        damier[0][i-1].etat=0;
        damier[0][i+1].etat = 0;
    }
    for(i=0;i<10;i=i+2){
        damier[1][i].etat = PN;
        damier[1][i+1].etat = 0;
    }
    for(i=1;i<10;i=i+2){
        damier[2][i].etat=PN;
        damier[2][i-1].etat=0;
        damier[2][i+1].etat = 0;
    }
    for(i=0;i<10;i=i+2){
        damier[3][i].etat = PN;
        damier[3][i+1].etat = 0;
    }
    for(i=1;i<10;i=i+2){
        damier[4][i].etat = 0;
        damier[4][i-1].etat = 0;
        damier[4][i+1].etat = 0;
    }
    for(i=0;i<10;i=i+2){
        damier[5][i].etat=0;
        damier[5][i+1].etat = 0;
    }
    for(i=1;i<10;i=i+2){
        damier[6][i].etat=PB;
        damier[6][i-1].etat = 0;
        damier[6][i+1].etat = 0;
    }
    for(i=0;i<10;i=i+2){
        damier[7][i].etat=PB;
        damier[7][i+1].etat = 0;
    }
    for(i=1;i<10;i=i+2){
        damier[8][i].etat=PB;
        damier[8][i-1].etat = 0;
        damier[8][i+1].etat = 0;
    }
    for(i=0;i<10;i=i+2){
        damier[9][i].etat=PB;
        damier[9][i+1].etat = 0;
    }
}
