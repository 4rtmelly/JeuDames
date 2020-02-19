#include "dames.h"
#define DB 2
#define PB 1
#define DN -2
#define PN -1 

int main(){
    pion ma[10][10];     
    int i,depart[2], arrivee[2];
    int a,b,c,d;
    char tour, ab;
    tour = 'b';
    ab = 'n';
    initialisation(ma);
    jeu_graphique(ma);
    
    while(!PartieFinie(ma) && !PartieEgale(ma)){
     	printf("Abandonner ? (o/n)\n");
     	scanf("%c",&ab);
     	if(ab == 'o'){
     		return 0;
     	}
     	else {
		    if(tour == 'b'){
		        printf("\n> Aux Blancs de jouer.\n");
		        printf("> Quelle est la position de depart ?\n");
		        scanf(" %d  %d",&a,&b);
		        depart[0]=a;
		        depart[1]=b;
		        if(ma[depart[0]][depart[1]].etat == PN || ma[depart[0]][depart[1]].etat == DN){
		            printf("Pas de pion blanc sur cette case.\n");
		        }
		        else {
				    printf("> Quelle est la position d'arrivee ?\n");
			        scanf(" %d  %d",&c,&d); 
			        if(a < 0 || a > 9 || b < 0 || b > 9 || c < 0 || c > 9 || d < 0 || d > 9){
			        	printf("Déplacement invalide.\n");
			        }
			        else {
					    arrivee[0]=c;
					    arrivee[1]=d;
					    if(deplacement(ma,depart,arrivee)){
					        deplacement(ma,depart,arrivee);
					        jeu_graphique(ma);
					        tour = 'n';/*
					        if(!remanger(ma, arrivee)){
					    		
					    	}
					    	*/
						}
						else {
							printf("Déplacement invalide.\n");
						}
	    			}
		    	}
		    }
		    else if(tour == 'n'){
		        printf("\n> Aux Noirs de jouer.\n");
		        printf("> Quelle est la position de depart ?\n");
		        scanf(" %d  %d",&a,&b);
		        depart[0]=a;
		        depart[1]=b;
		        if(ma[depart[0]][depart[1]].etat == PB || ma[depart[0]][depart[1]].etat == DB){
		            printf("Pas de pion noir sur cette case.");
		        }
		        else {  
				    printf("> Quelle est la position d'arrivee ?\n");
				    scanf(" %d  %d",&c,&d); 
			        arrivee[0]=c;
			        arrivee[1]=d;
			        if(a < 0 || a > 9 || b < 0 || b > 9 || c < 0 || c > 9 || d < 0 || d > 9){
				        printf("Déplacement invalide.\n");
				    }
				    else {
					    if(deplacement(ma,depart,arrivee)){
					        deplacement(ma,depart,arrivee);
					    	jeu_graphique(ma);
					    	tour = 'b';
					    	/*
					    	if(!remanger(ma, arrivee)){
					    		
					    	}
					    	*/
						}
						else {
							printf("Déplacement invalide.\n");
						}
		    		}
				}   
			}
		}
	}
	return 0;
}
