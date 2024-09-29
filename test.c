#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int main(void) {
	char recommencer;
	do {
		srand(time(0));
		int random_number = rand() % 100 + 1;
		int resultat_user;
		int essais = 0;

		printf("Trouve le bon numéro entre 1 et 100\n");

		while (1) {
			printf("Tape un numéro : ");
			if (scanf("%d", &resultat_user) != 1) {
			    printf("Veuillez entrer un nombre valide.\n");
			    while (getchar() != '\n');
			    continue;
		}

		essais++;
		if (resultat_user < random_number) {
		printf("C'est + !\n");
		} else if (resultat_user > random_number) {
		printf("C'est - !\n");
		} else {
		printf("C'est gagné en %d essais !\n", essais);
		break;
		}
	}

	printf("Veux-tu jouer encore ? (o/n) ");
	scanf(" %c", &recommencer);
	}while (recommencer == 'o' || recommencer == 'O');

return 0;
}
