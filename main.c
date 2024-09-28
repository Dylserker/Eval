#include <stdlib.h>
#include <stdio.h>

int main(void) {
	char operateur;
	double nombre1, nombre2, resultat;

	printf("Choisir un signe (+, -, /, *, %%) : "),
	scanf(" %c", &operateur);

	printf("Choisir le premier nombre: ");
	scanf("%lf", &nombre1);
	printf("Choisir le deuxieme nombre: ");
	scanf("%lf", &nombre2);

	 switch (operateur) {
        case '+':
            resultat = nombre1 + nombre2;
            printf("Résultat: %.2lf\n", resultat);
            break;
        case '-':
            resultat = nombre1 - nombre2;
            printf("Résultat: %.2lf\n", resultat);
            break;
        case '*':
            resultat = nombre1 * nombre2;
            printf("Résultat: %.2lf\n", resultat);
            break;
        case '/':
            if (nombre2 != 0) {
                resultat = nombre1 / nombre2;
                printf("Résultat: %.2lf\n", resultat);
            } else {
                printf("Erreur: Division par zéro.\n");
            }
            break;
        case '%':
            if ((int)nombre2 != 0) {
                resultat = (int)nombre1 % (int)nombre2;
                printf("Résultat: %.2lf\n", resultat);
            } else {
                printf("Erreur: Division par zéro.\n");
            }
            break;
        default:
            printf("Erreur: Opérateur invalide.\n");
            break;
    }

    return 0;
}


