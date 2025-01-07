
#include <stdio.h>
int main() {
    // Definimi i bordit 3x3 për lojën, i inicializuar me hapësira (' ').
    char board[3][3] = {
        {' ', ' ', ' '}, 
        {' ', ' ', ' '}, 
        {' ', ' ', ' '}
    };

    // Definimi i simboleve të qëndrueshme për dy lojtarët.
    const char playerX = 'X'; // 'X' përfaqëson lojtarin e parë.
    const char playerO = 'O'; // 'O' përfaqëson lojtarin e dytë.
    char currentPlayer = playerX; // Nis me lojtarin 'X'.
    int r = -1; // Indeksi i rreshtit për lëvizjen e lojtarit.
    int c = -1; // Indeksi i kolonës për lëvizjen e lojtarit.
    char winner = ' '; // Variabël për të ruajtur fituesin ('X', 'O', ose ' ' në rastin e barazimit).

    // Cikli që menaxhon deri në 9 lëvizje (sepse ka 9 hapësira në bord).
    for (int i = 0; i < 9; i++) {
        // Shfaqja e bordit të lojës.
        printf("   |   |   \n");
        printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
        printf("___|___|___\n");
        printf("   |   |   \n");
        printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
        printf("___|___|___\n");
        printf("   |   |   \n");
        printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
        printf("   |   |   \n");

        // Nëse është gjetur fituesi, ndërprejmë ciklin.
        if (winner != ' ') {
            break;
        }

        // Kërko për lëvizjen nga lojtari aktual.
        printf("Lojtari aktual është %c\n", currentPlayer);
        while (1) {
            // Merr input nga përdoruesi për rreshtin dhe kolonën (nga 0 deri në 2).
            printf("Shkruani r c nga 0-2 për rreshtin dhe kolonën: ");
            if (scanf("%d %d", &r, &c) != 2) {
                printf("Input i pavlefshëm, provo përsëri.\n");
                while (getchar() != '\n'); // Pastro çdo input të pavlefshëm
                continue;
            }
            // Validimi i koordinatave të inputit.
            if (r < 0 || r > 2 || c < 0 || c > 2) {
                printf("Input i pavlefshëm, provo përsëri.\n");
            } else if (board[r][c] != ' ') {
                printf("Vendosja është e zënë, provo përsëri.\n");
            } else {
                break;
            }
        }

        // Vendos simbolin e lojtarit aktual në bord.
        board[r][c] = currentPlayer;
        // Kaloni te lojtari tjetër.
        currentPlayer = (currentPlayer == playerX) ? playerO : playerX;

        // Kontrollo për fituesin pas çdo lëvizjeje.

        // Kontrollo për fitues në rreshta.
        for (int r = 0; r < 3; r++) {
            if (board[r][0] != ' ' && board[r][0] == board[r][1] && board[r][1] == board[r][2]) {
                winner = board[r][0];
                break;
            }
        }

        // Kontrollo për fitues në kolona.
        for (int c = 0; c < 3; c++) {
            if (board[0][c] != ' ' && board[0][c] == board[1][c] && board[1][c] == board[2][c]) {
                winner = board[0][c];
                break;
            }
        }

        // Kontrollo për fitues në diagonalen nga maja në majtas poshtë.
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            winner = board[0][0];
        } 
        // Kontrollo për fitues në diagonalen nga djathtas lart në majtas poshtë.
        else if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            winner = board[0][2];
        }
    }

    // Shfaq rezultatet pas përfundimit të ciklit.
    if (winner != ' ') {
        printf("Lojtari %c është fituesi!\n", winner); // Njofto fituesin.
    } else {
        printf("Barazim!\n"); // Nëse nuk ka fitues pas 9 lëvizjeve, është barazim.
    }

    return 0; // Përfundon programin.
}
