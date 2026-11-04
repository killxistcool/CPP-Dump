#include <iostream>
#include <random>

// This program makes you guess a random number from 1 to 1000. Can you guess the number correctly?

std::mt19937& getRandom()
{
    static std::random_device random{};
    static std::mt19937 gen(random());
    return gen;
}

int randomNumber()
{
    return getRandom()() % 1001;
}

int numberGuess()
{
    std::cout << "Guess the number: ";
    int guess{};
    std::cin >> guess;
    return guess;
}

int main()
{
    const int number{randomNumber()};
    int guess{numberGuess()};

    while (guess != number)
    {
        if (guess > number)
        {
            std::cout << "Lower!\n";
            guess = numberGuess();
        }
        else if (guess < number)
        {
            std::cout << "Higher!\n";
            guess = numberGuess();
        }
    }

    if (guess == number)
    {
        std::cout << "You guessed the number!\n";
    }
    
}
