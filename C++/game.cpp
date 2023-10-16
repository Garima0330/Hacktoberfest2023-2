#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

string getUserChoice() {
    string userChoice;
    cout << "Choose rock, paper, or scissors: ";
    cin >> userChoice;

    while (userChoice != "rock" && userChoice != "paper" && userChoice != "scissors") {
        cout << "Invalid choice. Please choose rock, paper, or scissors: ";
        cin >> userChoice;
    }

    return userChoice;
}

string getComputerChoice() {
    string choices[] = {"rock", "paper", "scissors"};
    int randomIndex = rand() % 3;
    return choices[randomIndex];
}

string determineWinner(string userChoice, string computerChoice) {
    if (userChoice == computerChoice) {
        return "It's a tie!";
    }
    if ((userChoice == "rock" && computerChoice == "scissors") ||
        (userChoice == "scissors" && computerChoice == "paper") ||
        (userChoice == "paper" && computerChoice == "rock")) {
        return "You win!";
    } else {
        return "Computer wins!";
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0));
    cout << "Welcome to Rock, Paper, Scissors!" << endl;

    while (true) {
        string userChoice = getUserChoice();
        string computerChoice = getComputerChoice();

        cout << "You chose " << userChoice << "." << endl;
        cout << "The computer chose " << computerChoice << "." << endl;

        string result = determineWinner(userChoice, computerChoice);
        cout << result << endl;

        cout << "Do you want to play again? (yes/no): ";
        string playAgain;
        cin >> playAgain;

        if (playAgain != "yes") {
            cout << "Thanks for playing! Goodbye!" << endl;
            break;
        }
    }

    return 0;
}
