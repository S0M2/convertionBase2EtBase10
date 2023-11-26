#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NBCHIFFRES 500

void decimalVersBinaire(double nbDecimal, int tabDecimal[]) {
    int reste;
    int indice = 0;
    

    while (nbDecimal != 0) {
        reste = (int)nbDecimal % 2;
        tabDecimal[indice] = reste;
        indice++;
        nbDecimal = (int)nbDecimal / 2;
    }

    printf("\033[1;32mLe résultat en binaire = ");

    for (int i = indice - 1; i >= 0; i--) {
        printf("%d", tabDecimal[i]);
    }
    printf("\033[0m\n");
}

double binaireVersDecimal(char *tabBinaire) {
    int indice = 0;
    int partieEntiere = 0;
    double partieFractionnaire = 0.0;
    int estPartieEntiere = 1;

    // Convertir la partie entière
    while (tabBinaire[indice] != '\0' && tabBinaire[indice] != '.') {
        partieEntiere = partieEntiere * 2 + (tabBinaire[indice] - '0');
        indice++;
    }

    // Si on rencontre une virgule, passer à la partie fractionnaire
    if (tabBinaire[indice] == '.') {
        estPartieEntiere = 0;
        indice++;
    }

    // Convertir la partie fractionnaire
    double poidsFractionnaire = 0.5;
    while (tabBinaire[indice] != '\0') {
        partieFractionnaire += (tabBinaire[indice] - '0') * poidsFractionnaire;
        poidsFractionnaire /= 2.0;
        indice++;
    }

    // Calculer le résultat final
    double resultat = partieEntiere + partieFractionnaire;

    // Appliquer le signe négatif si nécessaire
    if (tabBinaire[0] == '-') {
        resultat = -resultat;
    }

    printf("\033[1;32mLe nombre en décimal est : %.20f\n\033[0m", resultat);
}

int main(void) {
    double nbDecimal;
    char operation;
    int tabDecimal[NBCHIFFRES];
    char tabBinaire[NBCHIFFRES];

    printf("\033[1;34mBinaire = b \nDecimal = d\033[0m \n\033[1;31mPour sortir = e  \033[0m\nQuelle opération : ");
    scanf(" %c", &operation);

    int couleurErreur = 31; // Code de couleur pour les messages d'erreur (rouge)

    while (operation != 'e') {
        switch (operation) {
            case 'd':
                printf("Nombre décimal : ");
                scanf("%lf", &nbDecimal);
                decimalVersBinaire(nbDecimal, tabDecimal);
                break;

            case 'b':
                printf("Entrez un nombre binaire : ");
                scanf("%s", tabBinaire);
                binaireVersDecimal(tabBinaire);
                break;

            case 'e':
                printf("\033[1;32mAu revoir.\033[0m\n");
                break;

            default:
                // Changement de couleur cyclique pour l'effet arc-en-ciel des messages d'erreur
                couleurErreur = (couleurErreur + 1) % 8 + 31;
                printf("\033[1;%dmOpération invalide.\033[0m\n", couleurErreur);
                break;
        }

        printf("Quelle opération : ");
        scanf(" %c", &operation);
    }
}