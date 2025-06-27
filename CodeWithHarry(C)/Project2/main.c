#include <stdio.h>

int main(){
    int player,computer;

    /*
    0---> Snake
    1---> Water
    2---> Gun
    */
    printf("Enter 0 for Snake, 1 for Water, 2 for Gun\n");
    scanf("%d", &player);
    printf("Computer has made its choice\n");
    computer = rand() % 3; // Random choice for computer
    printf("Player chose: %d\n", player);
    printf("Computer chose: %d\n", computer);
    if (player == computer) {
        printf("It's a draw!\n");
    } else if ((player == 0 && computer == 1) || (player == 1 && computer == 2) || (player == 2 && computer == 0)) {
        printf("Player wins!\n");
    } else {
        printf("Computer wins!\n");
    }
    return 0;
}