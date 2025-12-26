#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 

// ===== Game Constants =====
#define WIDTH 50
#define HEIGHT 10
#define GROUND_Y 0
#define PLAYER_X 5
#define JUMP_VELOCITY 2 
#define GRAVITY 1

// ===== Pro Tips =====
const char *TIPS[] = {
    "Don't watch the player! Watch the right edge of the screen.",
    "Jump slightly *before* the obstacle reaches you.",
    "Rhythm is key. Don't panic tap space.",
    "Your jump height is low (2 units). Precision matters!",
    "As speed increases, look further ahead.",
};
#define NUM_TIPS 5

// ===== Global State =====
int playerY = 0;
int velocityY = 0;
int obstacleX = 40;
long score = 0;
int speed = 100000;
int gameOver = 0;

// ===== Terminal input handling =====
struct termios orig_termios;

void resetTerminal() {
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios);
    printf("\033[?25h"); // SC
}

void setRawMode() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &orig_termios);
    atexit(resetTerminal);
    t = orig_termios;
    t.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
    printf("\033[?25l"); // HC
}

int kbhit() {
    int ch;
    int oldf = fcntl(STDIN_FILENO, F_GETFL);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    ch = getchar();
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}

// ===== Logic =====
void resetGame() {
    playerY = 0;
    velocityY = 0;
    obstacleX = WIDTH - 1;
    score = 0;
    speed = 100000;
    gameOver = 0;
}

void draw() {
    printf("\033[H\033[J"); // Home and Clear

    // Stats bar
    printf("Distance: %ldm  |  Speed: %d\n", score, (120000 - speed)/1000);

    char buffer[HEIGHT][WIDTH + 1];

    // Sky
    for (int y = 0; y < HEIGHT; y++) {
        memset(buffer[y], ' ', WIDTH);
        buffer[y][WIDTH] = '\0';
    }

    // Floor
    memset(buffer[HEIGHT-1], '_', WIDTH);

    // Obstacle
    if (obstacleX >= 0 && obstacleX < WIDTH) {
        buffer[HEIGHT-2][obstacleX] = '|';
    }

    // Player (Inverted Y)
    int drawY = (HEIGHT - 2) - playerY;
    if (drawY >= 0 && drawY < HEIGHT) {
        buffer[drawY][PLAYER_X] = '@';
    }

    // Render
    for (int y = 0; y < HEIGHT; y++) {
        printf("%s\n", buffer[y]);
    }
    printf("Controls: SPACE to Jump, Q to Quit\n");
}

void showGameOverScreen() {
    printf("\033[H\033[J"); // Clear screen
    
    // Pick a random tip
    int tipIndex = rand() % NUM_TIPS;

    // Center alignment roughly
    printf("\n\n");
    printf("\t\033[31m=========================\033[0m\n");
    printf("\t\033[31m      GAME OVER          \033[0m\n");
    printf("\t\033[31m=========================\033[0m\n\n");
    
    printf("\tFinal Distance: \033[32m%ld meters\033[0m\n\n", score);
    
    printf("\t\033[33m[PRO TIP]: %s\033[0m\n\n", TIPS[tipIndex]);
    
    printf("\tPlay again? (y/n): ");
}

void runGame() {
    resetGame();
    
    // Small countdown
    printf("\033[H\033[JReady..."); fflush(stdout); usleep(500000);
    printf("GO!"); fflush(stdout); usleep(200000);

    while (!gameOver) {
        if (kbhit()) {
            char ch = getchar();
            if (ch == ' ' && playerY == GROUND_Y) {
                velocityY = JUMP_VELOCITY;
            }
            if (ch == 'q') {
                gameOver = 1;
            }
        }

        // Physics
        playerY += velocityY;
        velocityY -= GRAVITY;
        if (playerY < GROUND_Y) {
            playerY = GROUND_Y;
            velocityY = 0;
        }

        // Obstacle
        obstacleX--;
        if (obstacleX < 0) {
            obstacleX = WIDTH - 1;
            if (speed > 30000) speed -= 1500;
        }

        // Collision
        if (obstacleX == PLAYER_X && playerY == GROUND_Y) {
            gameOver = 1;
        }

        draw();
        score++;
        usleep(speed);
    }
}

int main() {
    srand(time(NULL)); 
    setRawMode();

    int playing = 1;
    while (playing) {
        runGame();

        showGameOverScreen();
    
        while(kbhit()) getchar();

        while (1) {
            if (kbhit()) {
                char ch = getchar();
                if (ch == 'y' || ch == 'Y') {
                    playing = 1;
                    break;
                }
                if (ch == 'n' || ch == 'N' || ch == 'q') {
                    playing = 0;
                    break;
                }
            }
            usleep(10000); 
        }
    }

    printf("\nThanks for playing!\n");
    return 0;
}