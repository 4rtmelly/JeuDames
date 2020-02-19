#include "dames.h"
#define DB 2
#define PB 1
#define DN -2
#define PN -1 

int depl_valide(pion ma[10][10],int depart[2], int arrivee[2]){
    if(ma[arrivee[0]][arrivee[1]].etat == 0){
    //PION BLANC
		if(ma[depart[0]][depart[1]].etat == PB){
		    if(arrivee[0] == depart[0]-1){
		        if(arrivee[1] == depart[1]-1 || arrivee[1] == depart[1]+1){
		            return 1;
		        }
		    }
		    //Si mange, tester s'il y a bien un pion adverse sur la case entre le départ et l'arrivée
		    else if(arrivee[0] == depart[0]-2){
		    	if(arrivee[1] == depart[1]-2){
		    		if(ma[depart[0]-1][depart[1]-1].etat == PN || ma[depart[0]-1][depart[1]-1].etat == DN){
		            	return 2;
		            }
				}
		    	else if(arrivee[1] == depart[1]+2){
		    		if(ma[depart[0]-1][depart[1]+1].etat == PN || ma[depart[0]-1][depart[1]+1].etat == DN){
		            	return 2;
		            }
		        }
		        return 0;
		    }
		    else if(arrivee[0] == depart[0]+2){
		    	if(arrivee[1] == depart[1]-2){
		    		if(ma[depart[0]+1][depart[1]-1].etat == PN || ma[depart[0]+1][depart[1]-1].etat == DN){
		            	return 2;
		            }
				}
		        else if(arrivee[1] == depart[1]+2){
		    		if(ma[depart[0]+1][depart[1]+1].etat == PN || ma[depart[0]+1][depart[1]+1].etat == DN){
		            	return 2;
		            }
		        }
		        return 0;
		    }
		    return 0;
		}
		//PION NOIR
		else if(ma[depart[0]][depart[1]].etat == PN){
			if(arrivee[0] == depart[0]+1){
		        if(arrivee[1] == depart[1]-1 || arrivee[1] == depart[1]+1){
		            return 1;
		        }
		    }
		    //Si mange, tester s'il y a bien un pion adverse sur la case entre le départ et l'arrivée
		    else if(arrivee[0] == depart[0]-2){
		    	if(arrivee[1] == depart[1]-2){
		    		if(ma[depart[0]-1][depart[1]-1].etat == PB || ma[depart[0]-1][depart[1]-1].etat == DB){
		            	return 2;
		            }
				}
		    	else if(arrivee[1] == depart[1]+2){
		    		if(ma[depart[0]-1][depart[1]+1].etat == PB || ma[depart[0]-1][depart[1]+1].etat == DB){
		            	return 2;
		            }
		        }
		        return 0;
		    }
		    else if(arrivee[0] == depart[0]+2){
		    	if(arrivee[1] == depart[1]-2){
		    		if(ma[depart[0]+1][depart[1]-1].etat == PB || ma[depart[0]+1][depart[1]-1].etat == DB){
		            	return 2;
		            }
				}
		        else if(arrivee[1] == depart[1]+2){
		    		if(ma[depart[0]+1][depart[1]+1].etat == PB || ma[depart[0]+1][depart[1]+1].etat == DB){
		            	return 2;
		            }
		        }
		        return 0;
		    }
		    return 0;
		}
	}
    else {
    	return 0;
    }
}


int depl_diagonale(pion ma[10][10],int depart[2], int arrivee[2]){   
    if(ma[arrivee[0]][arrivee[1]].etat == 0){
    	if(ma[depart[0]][depart[1]].etat == DB){
            if(arrivee[1] == depart[1]-arrivee[0] || arrivee[1] == depart[1]+arrivee[0]){
                return 1;
            }
        	return 0;
    	}
    	else if(ma[depart[0]][depart[1]].etat == DN){
            if(arrivee[1] == depart[1]-arrivee[0] || arrivee[1] == depart[1]+arrivee[0]){
                return 1;
            }
        	return 0;
    	}
    	else if(ma[depart[0]][depart[1]].etat == 0){
        	return 0;
    	}
    }
}


int depl_valide_dames(pion ma[10][10],int depart[2], int arrivee[2]){
    int resultat[2];
    pion p; 
    resultat[0] = arrivee[0]-depart[0];
    resultat[1] = arrivee[1]-depart[1];
    //DEPLACEMENT  HAUT DROITE 
        if(resultat[0]<0 && resultat[1]>0){
            p.x = depart[0]; 
            p.y = depart[1]; 
            while(p.x != arrivee[0] || p.y != arrivee[1]){
                p.x--;
                p.y++;
                //printf("il va dans la boucle\n");
                if(ma[depart[0]][depart[1]].etat == PN || ma[depart[0]][depart[1]].etat == DN){
                    if(ma[p.x][p.y].etat == PN || ma[p.x][p.y].etat == DN){
                        return 0;
                    }
                    (depl_diagonale(ma, depart, arrivee));
                    if (ma[p.x][p.y].etat == PB || ma[p.x][p.y].etat == DB){
                        printf("je suis un pion noir\n");
                        ma[p.x][p.y].etat = 0;
                    } 
                }
		      	else if(ma[depart[0]][depart[1]].etat == PB || ma[depart[0]][depart[1]].etat == DB){
				    printf("je suis la dame blanche\n");
				    if(ma[p.x][p.y].etat == PB || ma[p.x][p.y].etat == DB){
			            printf("je suis pion intermediaire blanc\n");
			            return 0;
			        }
				    depl_diagonale(ma, depart, arrivee);
				    if (ma[p.x][p.y].etat == PN || ma[p.x][p.y].etat == DN){
				        printf("je suis un pion noir\n");
				        ma[p.x][p.y].etat = 0;
				    }
				}
        	}
    	}
    	
        // DEPLACEMENT BAS DROITE 
        else if(resultat[0]>0 && resultat[1]>0){
		   // printf("ok"); 
		    p.x = depart[0];
		    p.y = depart[1]; 
            while(p.x != arrivee[0] || p.y != arrivee[1]){
                //printf("je suis la");
                p.x++;
                p.y++;  
                if(ma[depart[0]][depart[1]].etat == PN || ma[depart[0]][depart[1]].etat == DN){
                    if(ma[p.x][p.y].etat == PN || ma[p.x][p.y].etat == DN){
                        return 0;
                    }
                    depl_diagonale(ma, depart, arrivee);
                    if (ma[p.x][p.y].etat == PB || ma[p.x][p.y].etat == DB){
		                printf("je suis un pion noir\n");
		                ma[p.x][p.y].etat = 0;
		            }

            	}
		        else if(ma[depart[0]][depart[1]].etat == PB || ma[depart[0]][depart[1]].etat == DB){
		            if(ma[p.x][p.y].etat == PB || ma[p.x][p.y].etat == DB){
		                return 0;
		            }
		            depl_diagonale(ma, depart, arrivee);
		            if (ma[p.x][p.y].etat == PN || ma[p.x][p.y].etat == DN){
				        printf("je suis un pion noir\n");
				        ma[p.x][p.y].etat = 0;
		            }
		        }
            }
        }
        
        // DEPLACEMENT HAUT GAUCHE 
        else if (resultat[0]<0 && resultat[1]<0){
		    p.x = depart[0];
		    p.y = depart[1]; 
		    while(p.x != arrivee[0] || p.y != arrivee[1]){
		        p.x--; 
		        p.y--; 
		        if(ma[depart[0]][depart[1]].etat == PN || ma[depart[0]][depart[1]].etat == DN){
		            if(ma[p.x][p.y].etat == PN || ma[p.x][p.y].etat == DN){
		                return 0;
		            }
		            depl_diagonale(ma, depart, arrivee);
		                if (ma[p.x][p.y].etat == PB || ma[p.x][p.y].etat == DB){
		                printf("je suis un pion noir\n");
		                ma[p.x][p.y].etat = 0;
		            }
		        }
		        else if(ma[depart[0]][depart[1]].etat == PB || ma[depart[0]][depart[1]].etat == DB){
		            if(ma[p.x][p.y].etat == PB || ma[p.x][p.y].etat == DB){
		                return 0;
		            }
		            depl_diagonale(ma, depart, arrivee);
		            if (ma[p.x][p.y].etat == PN || ma[p.x][p.y].etat == DN){
		            	printf("je suis un pion noir\n");
		            	ma[p.x][p.y].etat = 0;
		        	}
		        }
		    }
		}

        // DEPLACEMENT BAS GAUCHE 
        else if(resultat[0]>0 && resultat[1]<0){
		    p.x = depart[0];
		    p.y = depart[1]; 
		    while(p.x != arrivee[0] || p.y != arrivee[1]){
		    	p.x++; 
		        p.y--;
		        if(ma[depart[0]][depart[1]].etat == PN || ma[depart[0]][depart[1]].etat == DN){
		            if(ma[p.x][p.y].etat == PN || ma[p.x][p.y].etat == DN){
		                return 0;
		            }
		            depl_diagonale(ma, depart, arrivee);
		            if (ma[p.x][p.y].etat == PB || ma[p.x][p.y].etat == DB){
		            printf("je suis un pion noir\n");
		            ma[p.x][p.y].etat = 0;
		        }
		        else if(ma[depart[0]][depart[1]].etat == PB || ma[depart[0]][depart[1]].etat == DB){
		            if(ma[p.x][p.y].etat == PB || ma[p.x][p.y].etat == DB){
		                return 0;
		            }
		            depl_diagonale(ma, depart, arrivee);
		            if (ma[p.x][p.y].etat == PN || ma[p.x][p.y].etat == DN){
		            printf("je suis un pion noir\n");
		            ma[p.x][p.y].etat = 0;
		        	}
		    	}
			}
		}
	}
    return 1; 
}


int deplacement(pion ma[10][10], int depart[2], int arrivee[2]){
	int resultat[2];
    resultat[0] = arrivee[0]-depart[0];
    resultat[1] = arrivee[1]-depart[1];
    int dp = depl_valide(ma, depart, arrivee);
    if(ma[depart[0]][depart[1]].etat == PB || ma[depart[0]][depart[1]].etat == PN){
		if (dp == 1){ //Si le pion avance normalement
			if(ma[depart[0]][depart[1]].etat == PB && arrivee[0] == 0){
				ma[arrivee[0]][arrivee[1]].etat = DB;
			}
			else if (ma[depart[0]][depart[1]].etat == PN && arrivee[0] == 9){
				ma[arrivee[0]][arrivee[1]].etat = DN;
			}
			else {
		    	ma[arrivee[0]][arrivee[1]].etat = ma[depart[0]][depart[1]].etat;
		    }
		    ma[depart[0]][depart[1]].etat = 0;
		    return 1;
		    
		}
		else if (dp == 2){ //Si le pion mange
			
			if (resultat[0]<0 && resultat[1]<0){
				 ma[arrivee[0]][arrivee[1]].etat = ma[depart[0]][depart[1]].etat;
				 ma[arrivee[0]+1][arrivee[1]+1].etat = 0;
			}
			else if (resultat[0]<0 && resultat[1]>0){
				ma[arrivee[0]][arrivee[1]].etat = ma[depart[0]][depart[1]].etat;
				ma[arrivee[0]+1][arrivee[1]-1].etat = 0;
			}
			else if (resultat[0]>0 && resultat[1]<0){
				ma[arrivee[0]][arrivee[1]].etat = ma[depart[0]][depart[1]].etat;
				ma[arrivee[0]-1][arrivee[1]+1].etat = 0;
			}
			else if (resultat[0]>0 && resultat[1]>0){
				ma[arrivee[0]][arrivee[1]].etat = ma[depart[0]][depart[1]].etat;
				ma[arrivee[0]-1][arrivee[1]-1].etat = 0;
			}
			ma[depart[0]][depart[1]].etat = 0;
			return 1;
		}
		else {
		    return 0;
		}
    }
    else if(ma[depart[0]][depart[1]].etat == DB || ma[depart[0]][depart[1]].etat == DN){
		if (depl_valide_dames(ma, depart, arrivee) == 1){ //Si c'est une dame
		    ma[arrivee[0]][arrivee[1]].etat = ma[depart[0]][depart[1]].etat;
		    ma[depart[0]][depart[1]].etat = 0;
		    return 1;
		}
		else {
		    return 0;
		}
    }
}   