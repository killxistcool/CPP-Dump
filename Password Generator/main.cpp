#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

// Dieses Programm generiert dir ein zufälliges Passwort, basierend auf vier Kriterien: Tier, Essen, Fahrzeug und Zahl
// This program generates you a random password, based on four criteria: Animal, Food, Vehicle and Number
// Ce programme génère un mot de passe aléatoire basé sur quatre critères : un animal, un aliment, un véhicule et un nombre.

std::mt19937& getRandom()
{
    static std::random_device random{};
    static std::mt19937 gen(random());

    return gen;
}

std::string getLanguage()
{
    std::cout << "Choose your passwords language: \n";
    std::cout << "(German, English, French)\n";

    std::string language{};
    std::cin >> language;

    return language;
}

std::string getAnimal(std::string language)
{
    if (language == "German")
    {
        std::vector<std::string> animals{"KuH", "SchWeIN", "AfFe", "BuLlE", "GAnS", "MaUs", "SEemOeWe", "PfErD", "GIraffe"};
        std::string choice{};
        std::sample(animals.begin(), animals.end(), &choice, 1, getRandom());
        return choice;
    }

    else if (language == "English")
    {
        std::vector<std::string> animals{"cOW", "PIG", "MOnkEy", "bUlL", "GOoSe", "MoUSe", "SEaGUll", "HORsE", "GiRAfFe"};
        std::string choice{};
        std::sample(animals.begin(), animals.end(), &choice, 1, getRandom());
        return choice;
    }

    else if (language == "French")
    {
        std::vector<std::string> animals{"VOicHe", "CoCHoN", "TAuREaU", "OIe", "soURiS", "mouEtTe", "cHeVAl", "GiRAfE"};
        std::string choice{};
        std::sample(animals.begin(), animals.end(), &choice, 1, getRandom());
        return choice;
    }

}

std::string getFood(std::string language)
{
    if (language == "German")
    {
        std::vector<std::string> foods{"toRTe", "KUcHen", "dONuT", "CuPCakE", "MufFiN", "NUDelN", "SaNDWhiCh", "EiS", "JoGhUrT"};
        std::string choice{};
        std::sample(foods.begin(), foods.end(), &choice, 1, getRandom());
        return choice;
    }

    else if (language == "English")
    {
        std::vector<std::string> foods{"pIE", "caKE", "doNuT", "cUPCaKe", "MuFFin", "paStA", "SaNdWhicH", "iCe", "YoGHUrt"};
        std::string choice{};
        std::sample(foods.begin(), foods.end(), &choice, 1, getRandom());
        return choice;
    }

    else if (language == "French")
    {
        std::vector<std::string> foods{"TARte", "GatEAu", "BeiGnEt", "cUpCaKE", "muFfIn", "pAtEs", "sAnDWhIch", "GLaCe", "YAOurT"};
        std::string choice{};
        std::sample(foods.begin(), foods.end(), &choice, 1, getRandom());
        return choice;
    }
}

std::string getVehicle(std::string language)
{
    if (language == "German")
    {
        std::vector<std::string> vehicles{"AuTo", "rakEtE", "fLugZeuG", "buS", "faHrrAd", "zUG"};
        std::string choice{};
        std::sample(vehicles.begin(), vehicles.end(), &choice, 1, getRandom());
        return choice;
    }

    else if (language == "English")
    {
    std::vector<std::string> vehicles{"cAR", "RocKeT", "AirPlaNe", "BUs", "BycIcLe", "trAin"};
    std::string choice{};
    std::sample(vehicles.begin(), vehicles.end(), &choice, 1, getRandom());
    return choice;
    }

    else if (language == "French")
    {
        std::vector<std::string> vehicles{"VoItuRE", "fuSeE", "aVIOn", "BUs", "veLO", "TrAin"};
        std::string choice{};
        std::sample(vehicles.begin(), vehicles.end(), &choice, 1, getRandom());
        return choice;
    }
}

int generateRandomNumber()
{
    return getRandom()() % 101;
}

void printResult(std::string animal, std::string food, std::string vehicle, int number, std::string language)
{
    if (language == "German")
        std::cout << "\nDein Passwort: " << animal << "-" << food << "-" << vehicle << "-" << number;
    else if (language == "English")
        std::cout << "\nYour pasword: " << animal << "-" << food << "-" << vehicle << "-" << number;
    else if (language == "French")
        std::cout << "\nvoitre mot de passe: " << animal << "-" << food << "-" << vehicle << "-" << number;
}

int main()
{
    std::string language{getLanguage()};
    if (language == "German" || language == "English" || language == "French")
    {
        int input{};

        if (language == "German")
        {
            std::cout << "Anzahl der Passwörter: ";
            std::cin >> input;
        }
        else if (language == "English")
        {
            std::cout << "Amount of passwords: ";
            std::cin >> input;
        }
        else if (language == "French")
        {
            std::cout << "Nombre de mots de passe: ";
            std::cin >> input;
        }

        for (int i = input; i--; input > 0)
            {
                std::string animal{getAnimal(language)};
                std::string food{getFood(language)};
                std::string vehicle{getVehicle(language)};
                int number{generateRandomNumber()};
                printResult(animal, food, vehicle, number, language);
            }
    }

    return 0;
}
