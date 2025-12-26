#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <stdlib.h>

// Terminal control
void disableBuffering() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

void enableBuffering() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag |= ICANON | ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

int kbhit() {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}

// Game variables
int playerY = 0;
int jump = 0;
int obstacleX = 20;
int score = 0;

void draw() {
    system("clear");
    printf("Score: %d\n\n", score);

    // Air
    if (playerY > 0)
        printf("@\n");
    else
        printf("\n");

    // Ground
    for (int i = 0; i < obstacleX; i++)
        printf("_");

    printf("|");
    printf("\n");
}

int main() {
    disableBuffering();

    while (1) {
        // Input
        if (kbhit()) {
            char ch = getchar();
            if (ch == ' ')
                jump = 1;
            if (ch == 'q')
                break;
        }

        // Jump logic
        if (jump) {
            playerY = 1;
            jump = 0;
        } else {
            playerY = 0;
        }

        // Obstacle movement
        obstacleX--;
        if (obstacleX < 0)
            obstacleX = 20;

        // Collision
        if (obstacleX == 0 && playerY == 0) {
            system("clear");
            printf("💀 GAME OVER 💀\n");
            printf("Final Score: %d\n", score);
            break;
        }

        draw();
        score++;
        usleep(120000);
    }

    enableBuffering();
    return 0;
}


//Chat Gpt Nhi: Win + . 