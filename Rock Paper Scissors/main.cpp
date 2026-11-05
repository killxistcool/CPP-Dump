#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <algorithm>

std::mt19937& getRandom()
{
    static std::random_device random{};
    static std::mt19937 gen(random());
    return gen; 
}

std::string getUserChoice()
{
    std::cout << "Enter your choice (Rock, Paper, Scissors): ";
    std::string input{};
    std::getline(std::cin >> std::ws, input);

    return input;
}

std::string getComputerChoice()
{
    std::vector<std::string> choices{"Rock", "Paper", "Scissors"};
    std::string computerChoice{};
    std::sample(choices.begin(), choices.end(), &computerChoice, 1, getRandom());


    return computerChoice;
}

void infiniteGame(char playForever)
{
    while (playForever == 'y' || playForever == 'Y')
    {
        std::string computerChoice{getComputerChoice()};
        std::string userChoice{getUserChoice()};

        std::cout << "Computer chose: " << computerChoice << '\n';
        std::cout << "You chose: " << userChoice << '\n';

        if (computerChoice == userChoice)
            std::cout << "It's a tie!\n";
        else if (computerChoice == "Rock" && userChoice == "Scissors")
            std::cout << "Computer won!\n";
        else if (computerChoice == "Rock" && userChoice == "Paper")
            std::cout << "You won!\n";
        else if (computerChoice == "Paper" && userChoice == "Rock")
            std::cout << "Computer won!\n";
        else if (computerChoice == "Paper" && userChoice == "Scissors")
            std::cout << "You won!\n";
        else if (computerChoice == "Scissors" && userChoice == "Paper")
            std::cout << "Computer won\n";
        else if (computerChoice == "Scissors" && userChoice == "Rock")
            std::cout << "You won!\n";
        else
            std::cout << "Invalid input, try again!\n";
    }
}

void singularGame()
{
    std::string computerChoice{getComputerChoice()};
    std::string userChoice{getUserChoice()};

    std::cout << "Computer chose: " << computerChoice << '\n';
    std::cout << "You chose: " << userChoice << '\n';

    if (computerChoice == userChoice)
        std::cout << "It's a tie!\n";
    else if (computerChoice == "Rock" && userChoice == "Scissors")
        std::cout << "Computer won!\n";
    else if (computerChoice == "Rock" && userChoice == "Paper")
        std::cout << "You won!\n";
        else if (computerChoice == "Paper" && userChoice == "Rock")
        std::cout << "Computer won!\n";
    else if (computerChoice == "Paper" && userChoice == "Scissors")
        std::cout << "You won!\n";
    else if (computerChoice == "Scissors" && userChoice == "Paper")
        std::cout << "Computer won\n";
    else if (computerChoice == "Scissors" && userChoice == "Rock")
        std::cout << "You won!\n";
    else
        std::cout << "Invalid input, try again!\n";
}

int main()
{
    std::cout << "Play forever? (y/n: ";
    char playForever{};
    std::cin >> playForever;
    
    if (playForever == 'y' || playForever == 'Y')
        infiniteGame(playForever);
    else if (playForever == 'n' || playForever == 'N')
        singularGame();

    return 0;
}
