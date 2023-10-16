//  "Rock, Paper, Scissors" game implemented in c:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char* getUserChoice() {
    char userChoice[10];
    printf("Choose rock, paper, or scissors: ");
    scanf("%s", userChoice);

    while (strcmp(userChoice, "rock") != 0 && strcmp(userChoice, "paper") != 0 && strcmp(userChoice, "scissors") != 0) {
        printf("Invalid choice. Please choose rock, paper, or scissors: ");
        scanf("%s", userChoice);
    }

    return strdup(userChoice);
}

char* getComputerChoice() {
    const char* choices[] = {"rock", "paper", "scissors"};
    int randomIndex = rand() % 3;
    return strdup(choices[randomIndex]);
}

char* determineWinner(char* userChoice, char* computerChoice) {
    if (strcmp(userChoice, computerChoice) == 0) {
        return "It's a tie!";
    }
    if ((strcmp(userChoice, "rock") == 0 && strcmp(computerChoice, "scissors") == 0) ||
        (strcmp(userChoice, "scissors") == 0 && strcmp(computerChoice, "paper") == 0) ||
        (strcmp(userChoice, "paper") == 0 && strcmp(computerChoice, "rock") == 0)) {
        return "You win!";
    } else {
        return "Computer wins!";
    }
}

int main() {
    srand(time(NULL));
    printf("Welcome to Rock, Paper, Scissors!\n");

    while (1) {
        char* userChoice = getUserChoice();
        char* computerChoice = getComputerChoice();

        printf("You chose %s.\n", userChoice);
        printf("The computer chose %s.\n", computerChoice);

        char* result = determineWinner(userChoice, computerChoice);
        printf("%s\n", result);

        free(userChoice);
        free(computerChoice);

        printf("Do you want to play again? (yes/no): ");
        char playAgain[5];
        scanf("%s", playAgain);
        if (strcmp(playAgain, "no") == 0) {
            printf("Thanks for playing! Goodbye!\n");
            break;
        }
    }

    return 0;
}
