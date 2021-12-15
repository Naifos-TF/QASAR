// Qasar.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <random>

void StartQasar(int* const Credits, const size_t* const QasarCost);
void Quit();
void DisplayGameOver();
void DisplayMenu(const int* const Credits, const size_t* const QasarCost);
int  RandomNumber(const size_t& a, const size_t& b);//rand between 2 values
int  Payout(const int& score);
void UpdateCredits(int* const Credits_Ptr, const int& amount);
void UpdateScoreWithRandomNumber(int& score, const int& num1, const int& num2);

int main()
{

    int Choice = 0;
    int Credits = 200;
    int* Credits_Ptr = nullptr;
    Credits_Ptr = &Credits;

    const size_t QasarCost = 20;
    const size_t* QasarCost_Ptr = nullptr;
    QasarCost_Ptr = &QasarCost;
    bool NotEnoughtCredits = 0;

    do {
        if (Credits < QasarCost) {
            DisplayGameOver();
            NotEnoughtCredits = 1;
        }
        else {
            DisplayMenu(Credits_Ptr, QasarCost_Ptr);
            std::cout << "Your choice : ";
            std::cin >> Choice;

            switch (Choice) {
            case 1: {
                StartQasar(Credits_Ptr, QasarCost_Ptr);
                break;
            }
            case 2: {
                Quit();
                break;
            }
            }
        }
        
    } while (Choice != 2 && Credits > 0 && NotEnoughtCredits == 0);



}


void StartQasar(int* const Credits, const size_t* const QasarCost)
{
    UpdateCredits(Credits, -((int) *(QasarCost)));
    int StartingNumber = 0;
    bool End = 0;
    StartingNumber = RandomNumber(1, 8);
    std::cout << "Try getting the total to twenty or as close as possible without going over ! " << std::endl;
    std::cout << "14 or less -> 0 Credits" << std::endl;
    std::cout << "15 -> 5 Credits" << std::endl;
    std::cout << "16 -> 10 Credits" << std::endl;
    std::cout << "17 -> 20 Credits" << std::endl;
    std::cout << "18 -> 25 Credits" << std::endl;
    std::cout << "19 -> 30 Credits" << std::endl;
    std::cout << "20 -> 40 Credits" << std::endl;
    std::cout << "21 or more -> 0 Credits" << std::endl;
    std::cout << std::endl;

    do {
        int Choice = 0;
        std::cout << "________________________________________"<< std::endl;
        std::cout << "Your score : [" << StartingNumber <<"]" << std::endl;
        std::cout << "------------------------------" << std::endl;
        std::cout << "Your choice : " <<std::endl;
        std::cout  << std::endl;
        std::cout << "1. 4 - 7  " << std::endl;
        std::cout << "2. 1 - 8  " << std::endl;
        std::cout << "3. Payout  " << std::endl;

        std::cin >> Choice;

        switch (Choice) {
            case 1: {
                UpdateScoreWithRandomNumber(StartingNumber, 4, 7);
                break;
            }
            case 2: {
                UpdateScoreWithRandomNumber(StartingNumber, 1, 8);
                break;
            }
            case 3: {
                End = 1;
                break;
            }

        }
        
    } while (End == 0 && StartingNumber <20);

    std::cout << std::endl;

    if (StartingNumber > 20)
        std::cout << "You went over 20 ("<< StartingNumber <<").You lost." << std::endl;
    else if (StartingNumber == 20)
        std::cout << "20 ! Congratulations ! " << std::endl;
    else 
        std::cout << "Your final score is : " << StartingNumber << std::endl;

    int PlayerPayout = Payout(StartingNumber);
    UpdateCredits(Credits, PlayerPayout);
    std::cout << "Your payout is : " << PlayerPayout << std::endl;
    std::cout << std::endl;

}

void Quit()
{
    std::cout << "\n" << "See you soon ! "<< std::endl;
}

void DisplayGameOver()
{
    std::cout << std::endl;
    std::cout << "You dont have enough credits for a new game ! Game Over ! " << std::endl;
    std::cout << std::endl;
}

void DisplayMenu(const int* const Credits, const size_t* const QasarCost)
{
    std::cout << "Welcome to Casino Robespierre ! " << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "You have " << *Credits << " credits"<< std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "1. Start a QASAR game (" << *QasarCost << " credits) " << std::endl;
    std::cout << "2. Exit" << std::endl;
    std::cout << "------------------------------" << std::endl;
}

int RandomNumber(const size_t& a, const size_t& b)
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<int> distribution(a, b);
    return distribution(gen);
}

int Payout(const int& score) {

    if (score < 15 || score >20)
        return 0;
    else if (score == 15) 
        return 5;
    else if (score == 16) 
        return 10;
    else if (score == 17) 
        return 20;
    else if (score == 18) 
        return 25;
    else if (score == 19) 
        return 30;
    else if (score == 20) 
        return 40;
    else
        return 0;

}


void UpdateCredits(int* const Credits_Ptr, const int& amount) {
    *Credits_Ptr += amount;
}

void UpdateScoreWithRandomNumber(int& score, const int& num1, const int& num2) {
    int tmp = RandomNumber(num1, num2);
    std::cout << "You got the number " << tmp << std::endl;
    score += tmp;
}