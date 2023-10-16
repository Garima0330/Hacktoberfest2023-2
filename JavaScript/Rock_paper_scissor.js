///* "Rock, Paper, Scissors" game implemented in JavaScript:*/
function getUserChoice() {
  let userChoice = prompt("Choose rock, paper, or scissors: ").toLowerCase();
  while (!["rock", "paper", "scissors"].includes(userChoice)) {
    alert("Invalid choice. Please choose rock, paper, or scissors.");
    userChoice = prompt("Choose rock, paper, or scissors: ").toLowerCase();
  }
  return userChoice;
}

function getComputerChoice() {
  const choices = ["rock", "paper", "scissors"];
  const randomIndex = Math.floor(Math.random() * 3);
  return choices[randomIndex];
}

function determineWinner(userChoice, computerChoice) {
  if (userChoice === computerChoice) {
    return "It's a tie!";
  }
  if (
    (userChoice === "rock" && computerChoice === "scissors") ||
    (userChoice === "scissors" && computerChoice === "paper") ||
    (userChoice === "paper" && computerChoice === "rock")
  ) {
    return "You win!";
  } else {
    return "Computer wins!";
  }
}

function playGame() {
  const userChoice = getUserChoice();
  const computerChoice = getComputerChoice();

  console.log(`You chose ${userChoice}.`);
  console.log(`The computer chose ${computerChoice}.`);

  const result = determineWinner(userChoice, computerChoice);
  console.log(result);
}

console.log("Welcome to Rock, Paper, Scissors!");
while (true) {
  playGame();
  const playAgain = prompt("Do you want to play again? (yes/no): ").toLowerCase();
  if (playAgain !== "yes") {
    console.log("Thanks for playing! Goodbye!");
    break;
  }
}
