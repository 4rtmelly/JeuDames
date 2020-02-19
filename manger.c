#include "dames.h"
#define DB 2
#define PB 1
#define DN -2
#define PN -1 

//Fonction sur laquelle nous avons travaillé pour que l'on puisse remanger plusieurs fois
/*
int remanger(pion ma[10][10], int depart[2]){
	int i;
	//PION BLANC
	if (ma[depart[0]][depart[1]].etat == PB){
		if(ma[depart[0]+1][depart[1]+1].etat == PN || ma[depart[0]+1][depart[1]+1].etat == DN){ //Si la case suivante est un pion noir
			if(ma[depart[0]+2][depart[1]+2].etat == 0){ //Si la case d'encore après est libre
				return 1; //On peut manger à nouveau
			}
		}
		else if(ma[depart[0]-1][depart[1]-1].etat == PN || ma[depart[0]-1][depart[1]-1].etat == DN){ //Même chose pour les autres directions
			if(ma[depart[0]-2][depart[1]-2].etat == 0){
				return 1;
			}
		}
		else if(ma[depart[0]+1][depart[1]-1].etat == PN || ma[depart[0]+1][depart[1]-1].etat == DN){
			if(ma[depart[0]+2][depart[1]-2].etat == 0){
				return 1;
			}
		}
		else if(ma[depart[0]-1][depart[1]+1].etat == PN || ma[depart[0]-1][depart[1]+1].etat == DN){
			if(ma[depart[0]-2][depart[1]+2].etat == 0){
				return 1;
			}
		}
	}
	//PION NOIR
	else if (ma[depart[0]][depart[1]].etat == PN){
		if(ma[depart[0]+1][depart[1]+1].etat == PB || ma[depart[0]+1][depart[1]+1].etat == DB){
			if(ma[depart[0]+2][depart[1]+2].etat == 0){
				return 1;
			}
		}
		else if(ma[depart[0]-1][depart[1]-1].etat == PB || ma[depart[0]-1][depart[1]-1].etat == DB){
			if(ma[depart[0]-2][depart[1]-2].etat == 0){
				return 1;
			}
		}
		else if(ma[depart[0]+1][depart[1]-1].etat == PB || ma[depart[0]+1][depart[1]-1].etat == DB){
			if(ma[depart[0]+2][depart[1]-2].etat == 0){
				return 1;
			}
		}
		else if(ma[depart[0]-1][depart[1]+1].etat == PB || ma[depart[0]-1][depart[1]+1].etat == DB){
			if(ma[depart[0]-2][depart[1]+2].etat == 0){
				return 1;
			}
		}
	}
	//DAME BLANCHE 
	else if (ma[depart[0]][depart[1]].etat == DB){
		for(i=0; i < 10; i++){
				if(ma[depart[0]+i][depart[1]+i].etat == PN || ma[depart[0]+i][depart[1]+i].etat == DN){
				return 1;
			}
			else if(ma[depart[0]-i][depart[1]-i].etat == PN || ma[depart[0]-i][depart[1]-i].etat == DN){
				return 1;
			}
			else if(ma[depart[0]+i][depart[1]-i].etat == PN || ma[depart[0]+i][depart[1]-i].etat == DN){
				return 1;
			}
			else if(ma[depart[0]+i][depart[1]-i].etat == PN || ma[depart[0]+i][depart[1]-i].etat == DN){
				return 1;
			}
		}
	}
	//DAME NOIRE
	else if (ma[depart[0]][depart[1]].etat == DN){
		for(i=0; i < 10; i++){
				if(ma[depart[0]+i][depart[1]+i].etat == PB || ma[depart[0]+i][depart[1]+i].etat == DB){
				return 1;
			}
			else if(ma[depart[0]-i][depart[1]-i].etat == PB || ma[depart[0]-i][depart[1]-i].etat == DB){
				return 1;
			}
			else if(ma[depart[0]+i][depart[1]-i].etat == PB || ma[depart[0]+i][depart[1]-i].etat == DB){
				return 1;
			}
			else if(ma[depart[0]+i][depart[1]-i].etat == PB || ma[depart[0]+i][depart[1]-i].etat == DB){
				return 1;
			}
		}
	}
	else {
		return 0;
	}
}

*/

/*
Fonction qui trouve automatiquement si un pion peut manger depuis sa position de départ, ainsi que depuis sa position d'arrivée, jusqu'à ce qu'il ne puisse plus manger.
Comme nous n'avons pas réussi à faire en sorte qu'elle trouve le meilleur cas, nous ne nous en servirons pas.

int manger(pion ma[10][10], int depart[2], int compteur){
    int depart2[2];
     
    //PION BLANC
    if (ma[depart[0]][depart[1]].etat == PB){
        if(ma[depart[0]+1][depart[1]+1].etat == PN || ma[depart[0]+1][depart[1]+1].etat == DN){
            compteur++;   
            depart2[0] = depart[0]+2;
            depart2[1] = depart[1]+2;
            if(depart2[0] <= 0 || depart2[1] <= 0){
                return 0;
            }
            printf("\nPion noir mangé en : %d, %d\n", depart2[0], depart2[1]);
            ma[depart2[0]][depart2[1]].etat = PB;
            ma[depart[0]+1][depart[1]+1].etat = 0;
            ma[depart[0]][depart[1]].etat = 0;
            jeu_graphique(ma);  
            manger(ma, depart2, compteur);
        } 
        
        else if(ma[depart[0]-1][depart[1]-1].etat == PN || ma[depart[0]-1][depart[1]-1].etat == DN){
            compteur++;   
            depart2[0] = depart[0]-2;
            depart2[1] = depart[1]-2; 
            if(depart2[0] <= 0 || depart2[1] <= 0){
                return 0;
            }
            printf("\nPion noir mangé en : %d, %d\n", depart2[0], depart2[1]);
            ma[depart2[0]][depart2[1]].etat = PB;
            ma[depart[0]-1][depart[1]-1].etat = 0;
            ma[depart[0]][depart[1]].etat = 0;
            jeu_graphique(ma);  
            manger(ma, depart2, compteur); 
        }
        
        else if(ma[depart[0]+1][depart[1]-1].etat == PN || ma[depart[0]+1][depart[1]-1].etat == DN){
            compteur++;   
            depart2[0] = depart[0]+2;
            depart2[1] = depart[1]-2;
            if(depart2[0] <= 0 || depart2[1] <= 0){
                return 0;
            }
            printf("\nPion noir mangé en : %d, %d\n", depart2[0], depart2[1]);
            ma[depart2[0]][depart2[1]].etat = PB;
            ma[depart[0]+1][depart[1]-1].etat = 0;
            ma[depart[0]][depart[1]].etat = 0; 
            jeu_graphique(ma);   
            manger(ma, depart2, compteur); 
       }

        else if(ma[depart[0]-1][depart[1]+1].etat == PN || ma[depart[0]-1][depart[1]+1].etat == DN){
            compteur++;   
            depart2[0] = depart[0]-2;
            depart2[1] = depart[1]+2;
            if(depart2[0] <= 0 || depart2[1] <= 0){
                return 0;
            }
            printf("\nPion noir mangé en : %d, %d\n", depart2[0], depart2[1]);
            ma[depart2[0]][depart2[1]].etat = PB;
            ma[depart[0]-1][depart[1]+1].etat = 0;
            ma[depart[0]][depart[1]].etat = 0;  
            jeu_graphique(ma);  
            manger(ma, depart2, compteur);         
        }
    }
    
    //PION NOIR
    if (ma[depart[0]][depart[1]].etat == PN){
        if(ma[depart[0]+1][depart[1]+1].etat == PB || ma[depart[0]+1][depart[1]+1].etat == DB){
            compteur++;   
            depart2[0] = depart[0]+2;
            depart2[1] = depart[1]+2;
            if(depart2[0] <= 0 || depart2[1] <= 0 || ma[depart2[0]][depart2[1]].etat != 0){
                return 0;
            }
            printf("\nPion blanc mangé en : %d, %d\n", depart2[0], depart2[1]);
            ma[depart2[0]][depart2[1]].etat = PN;
            ma[depart[0]+1][depart[1]+1].etat = 0;
            ma[depart[0]][depart[1]].etat = 0;
            jeu_graphique(ma);  
            manger(ma, depart2, compteur);
        } 
        
        else if(ma[depart[0]-1][depart[1]-1].etat == PB || ma[depart[0]-1][depart[1]-1].etat == DB){
            compteur++;   
            depart2[0] = depart[0]-2;
            depart2[1] = depart[1]-2; 
            if(depart2[0] <= 0 || depart2[1] <= 0 || ma[depart2[0]][depart2[1]].etat != 0){
                return 0;
            }
            printf("\nPion blanc mangé en : %d, %d\n", depart2[0], depart2[1]);
            ma[depart2[0]][depart2[1]].etat = PN;
            ma[depart[0]-1][depart[1]-1].etat = 0;
            ma[depart[0]][depart[1]].etat = 0;
            jeu_graphique(ma);  
            manger(ma, depart2, compteur); 
        }
        
        else if(ma[depart[0]+1][depart[1]-1].etat == PB || ma[depart[0]+1][depart[1]-1].etat == DB){
            compteur++;   
            depart2[0] = depart[0]+2;
            depart2[1] = depart[1]-2;
            if(depart2[0] <= 0 || depart2[1] <= 0 || ma[depart2[0]][depart2[1]].etat != 0){
                return 0;
            }
            printf("\nPion blanc mangé en : %d, %d\n\n", depart2[0], depart2[1]);
            ma[depart2[0]][depart2[1]].etat = PN;
            ma[depart[0]+1][depart[1]-1].etat = 0;
            ma[depart[0]][depart[1]].etat = 0; 
            jeu_graphique(ma);   
            manger(ma, depart2, compteur); 
       }

        else if(ma[depart[0]-1][depart[1]+1].etat == PB || ma[depart[0]-1][depart[1]+1].etat == DB){
            compteur++;   
            depart2[0] = depart[0]-2;
            depart2[1] = depart[1]+2;
            if(depart2[0] <= 0 || depart2[1] <= 0 || ma[depart2[0]][depart2[1]].etat != 0){
                return 0;
            }
            printf("\nPion blanc mangé en : %d, %d\n", depart2[0], depart2[1]);
            ma[depart2[0]][depart2[1]].etat = PN;
            ma[depart[0]-1][depart[1]+1].etat = 0;
            ma[depart[0]][depart[1]].etat = 0;  
            jeu_graphique(ma);  
            manger(ma, depart2, compteur);         
        }
    }
    //printf("Compteur %d\n", compteur);
    return compteur;
}*/
