//
//  main.cpp
//  pendu
//
//  Created by Ranga Gonnage on 11/12/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "main.h"

int main(int argc, char* argv[])
{
    char lettre = 0; // Stocke la lettre proposée par l'utilisateur (retour du scanf)
    char motSecret[] = "ROUGE"; // C'est le mot à trouver
    int coupsRestants = 10; // Compteur de coups restants (0 = mort)
    int nombreLettres = tailleMot(motSecret);
    int *lettreTrouvee = NULL;// Tableau de booléens. Chaque case correspond à une lettre du mot secret. 0 = lettre non trouvée, 1 = lettre trouvée //Q1
    lettreTrouvee = malloc(nombreLettres * sizeof(int)); //Q2
    initTableau(lettreTrouvee, nombreLettres); //Q3

    printf("Bienvenue dans le Pendu !\n\n");
    
    while (coupsRestants > 0 && !gagne(lettreTrouvee, nombreLettres))
    {
        printf("\n\nIl vous reste %d coups a jouer", coupsRestants);
        printf("\nQuel est le mot secret ? ");

        /* On affiche le mot secret en masquant les lettres non trouvées
                Exemple : *A**ON */
        for (int i = 0 ; i < nombreLettres ; i++)
        {
            if (lettreTrouvee[i])
                printf("%c", motSecret[i]);
            else
                printf("*");
        }
        
        printf("\nProposez une lettre : ");
        lettre = lireCaractere();
        
        // Si ce n'était PAS la bonne lettre
        if (!rechercheLettre(lettre, motSecret, lettreTrouvee))
        {
            coupsRestants--; // On enlève un coup au joueur
        }
    }

    if (gagne(lettreTrouvee, nombreLettres))
        printf("\n\nGagne ! Le mot secret etait bien : %s\n", motSecret);
    else
        printf("\n\nPerdu ! Le mot secret etait : %s \n", motSecret);

    return 0;
}

int tailleMot(char motSecret[])
{
    int nombreLettre = 0;
    for(int i = 0; motSecret[i] != '\0'; i++)
    {
        nombreLettre++;
    }
    return nombreLettre;
}

char lireCaractere()
{
    char caractere = 0;
 
    caractere = getchar(); // On lit le premier caractère
    caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas déjà
 
    // On lit les autres caractères mémorisés un à un jusqu'au \n (pour les effacer)
    while (getchar() != '\n') ;
 
    return caractere; // On retourne le premier caractère qu'on a lu
}

void initTableau(int* lettreTrouvee, int taille)
{
    for(int i = 0; i < taille; i++)
    {
        lettreTrouvee[i] = 0;
    }
}

int gagne(int *lettreTrouvee, int nombreLettres)
{
    int i = 0;
    int joueurGagne = 1;

    for (i = 0 ; i < nombreLettres ; i++)
    {
        if (lettreTrouvee[i] == 0)
            joueurGagne = 0;
    }

    return joueurGagne;
}


int rechercheLettre(char lettre, char motSecret[], int* lettreTrouvee)
{
    int i = 0;
    int bonneLettre = 0;

    // On parcourt motSecret pour vérifier si la lettre proposée y est
    for (i = 0 ; motSecret[i] != '\0' ; i++)
    {
        if (lettre == motSecret[i]) // Si la lettre y est
        {
            bonneLettre = 1; // On mémorise que c'était une bonne lettre
            lettreTrouvee[i] = 1; // On met à 1 la case du tableau de booléens correspondant à la lettre actuelle
        }
    }

    return bonneLettre;
}
