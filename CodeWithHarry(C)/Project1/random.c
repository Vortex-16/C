#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main() {
    int n,guessed_number;
    int count=1;
    // printf("Enter a number between 0 and 99: ");
    // scanf("%d", &n);
    // Seed the random number generator
    srand(time(0));

    // printf("Random numbers: ");
        int random_number = rand() % 100; // Generate a random number between 0 and 99
        // printf("%d ", random_number);
        do {
            printf("Guess the number: ");
            scanf("%d", &guessed_number);
            if (guessed_number < random_number) {
                printf("❗ Too low! Try again.\n"); //icon from google to make it more interactive
                // count++;
            } else if (guessed_number > random_number) {
                printf("😯 Too high! Try again.\n");
                // count++;
            } else {
                printf("🎉 Congratulations! You've guessed the number %d correctly!\n", random_number);
                 //using reactions to fell the user happy
                //  count++;
                break; // Exit the loop when the guess is correct
            } count++; // Increment the count for each guess
        } while (1); // Infinite loop until the correct guess is made
    printf("You took %d attempts to guess the number.\n", count);
    }
