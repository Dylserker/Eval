#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PLAYER 'X'
#define COMPUTER 'O'

// Prototypes des fonctions
void initBoard(char board[3][3]);
void displayBoard(char board[3][3]);
int checkWin(char board[3][3], char symbol);
int checkDraw(char board[3][3]);
void playerMove(char board[3][3]);
void computerMove(char board[3][3]);

int main() {
    char board[3][3];
    int winner = 0;
    char currentPlayer = PLAYER; // Le joueur commence

    initBoard(board);
    srand(time(0)); // Initialiser la génération aléatoire pour l'ordinateur
    printf("Tic-Tac-Toe : Vous (X) contre l'ordinateur (O)\n");

    // Boucle principale du jeu
    while (1) {
        displayBoard(board);

        if (currentPlayer == PLAYER) {
            playerMove(board);
            if (checkWin(board, PLAYER)) {
                winner = 1;
                break;
            }
        } else {
            computerMove(board);
            if (checkWin(board, COMPUTER)) {
                winner = 2;
                break;
            }
        }

        if (checkDraw(board)) {
            break;
        }

        // Changer de joueur
        currentPlayer = (currentPlayer == PLAYER) ? COMPUTER : PLAYER;
    }

    displayBoard(board);

    if (winner == 1) {
        printf("Félicitations ! Vous avez gagné !\n");
    } else if (winner == 2) {
        printf("L'ordinateur a gagné.\n");
    } else {
        printf("Match nul.\n");
    }

    return 0;
}

// Initialiser le plateau
void initBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Afficher le plateau
void displayBoard(char board[3][3]) {
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

// Vérifier si un joueur a gagné
int checkWin(char board[3][3], char symbol) {
    // Vérifier les lignes
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return 1;
        }
    }

    // Vérifier les colonnes
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) {
            return 1;
        }
    }

    // Vérifier les diagonales
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return 1;
    }
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
        return 1;
    }

    return 0;
}

// Vérifier s'il y a un match nul
int checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0; // Il reste des cases vides
            }
        }
    }
    return 1; // Plateau plein, match nul
}

// Mouvement du joueur
void playerMove(char board[3][3]) {
    int row, col;
    do {
        printf("Entrez votre mouvement (ligne et colonne) : ");
        scanf("%d %d", &row, &col);
        row--; col--; // Ajuster pour l'indice 0
    } while (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ');

    board[row][col] = PLAYER;
}

// Mouvement de l'ordinateur (aléatoire)
void computerMove(char board[3][3]) {
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != ' ');

    board[row][col] = COMPUTER;
    printf("L'ordinateur a joué en %d %d\n", row + 1, col + 1);
}






























