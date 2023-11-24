#include <stdio.h>
#include <stdlib.h>
#include<math.h>

#define NBCHIFFRES 500

int decimalbinaire(double nbDecimal, int nombreBinaire[] ) {
    int reste ;
    int indice = 0;


    while (nbDecimal != 0) {
        reste = (int)nbDecimal % 2;
        nombreBinaire[indice] = reste;
        indice ++;
        nbDecimal = (int)nbDecimal /2;
    }
    return indice;
}

void binairedecimal(long double nbBinaire) {
    int nbDecimal = 0;
    int indice = 0, reste;
    double apresVirgule = nbBinaire - (int)nbBinaire;

    // Avant la virgule
    while ((int)nbBinaire != 0) {
        reste = (int)nbBinaire % 10;
        nbBinaire /= 10;
        nbDecimal += reste * (1 << indice); // Utiliser << pour la puissance de 2
        ++indice;
    }

    // Après la virgule
    double decimalFraction = 0.0;
    int base = 2;
    int i = -1;  
    while (apresVirgule > 0.000000001 && i >= -10) {
        int digit = (int)(apresVirgule * 10);
        apresVirgule = apresVirgule * 10 - digit;
        decimalFraction += digit * pow(base, i);
        --i;
    }

    // Affichage du résultat
    printf("%d,%f\n", nbDecimal, decimalFraction);
}

int main(void) {
    double nbDecimal;
    long double binaire;
    char operation;
    int nbChiffresBinaires;
    int nombreBinaire[NBCHIFFRES];
    printf("\033[1;34mBinaire = b \nDecimal = d\033[0m \n\033[1;31mPour sortir = e  \033[0m\nQuelle opération : ");
    scanf(" %c", &operation);

    while (operation != 'e') {
        switch (operation) {
            case 'd':
                printf("Nombre décimal : ");
                scanf("%lf", &nbDecimal);
                nbChiffresBinaires = decimalbinaire(nbDecimal, nombreBinaire);
                printf("Le résultat de %.0f en binaire = ", nbDecimal);
                for (int i = nbChiffresBinaires -1; i>= 0; i--)
                {
                    printf("%d", nombreBinaire[i]);
                }
                printf("\n");
                
                break;

            case 'b':
                printf("Nombre binaire : ");
                scanf("%Lf", &binaire);
                binairedecimal(binaire);
                break;

            case 'e':
                printf("Au revoir.\n");
                break;

            default:
                printf("Opération invalide.\n");
                break;
        }

        printf("Quelle opération : ");
        scanf(" %c", &operation);
    }
}