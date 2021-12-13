//
//  main1.hpp
//  pendu
//
//  Created by Ranga Gonnage on 13/12/2021.
//

#ifndef main1_hpp
#define main1_hpp

#include <stdio.h>

int tailleMot(char motSecret[]);
void initTableau(int* lettreTrouvee, int taille);
int gagne(int *lettreTrouvee, int nombreLettres);
char lireCaractere();
int rechercheLettre(char lettre, char motSecret[], int* lettreTrouvee);

#endif /* main_h */
