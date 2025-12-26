#include <stdio.h>
#include <conio.h>
#include <windows.h>

int playerY = 0;
int obstacleX = 20;
int score = 0;

void draw() {
    system("cls");
    printf("Score: %d\n\n", score);

    if (playerY)
        printf("@\n");
    else
        printf("\n");

    for (int i = 0; i < obstacleX; i++)
        printf("_");

    printf("|");
    printf("\n");
}

int main() {
    while (1) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == ' ')
                playerY = 1;
            if (ch == 'q')
                break;
        } else {
            playerY = 0;
        }

        obstacleX--;
        if (obstacleX < 0)
            obstacleX = 20;

        if (obstacleX == 0 && playerY == 0) {
            system("cls");
            printf("GAME OVER\nFinal Score: %d\n", score);
            break;
        }

        draw();
        score++;
        Sleep(120);
    }
    return 0;
}
