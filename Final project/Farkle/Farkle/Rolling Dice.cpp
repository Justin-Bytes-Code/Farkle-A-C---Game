// Rolling dice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib> //included for Random
#include <ctime> //included for Random

//v 0.1
//IT 312 Software Devel w/C++.net
//Justin Perez

int Userinput() {
    int input;
    std::cout << "Please type a number 2-12 to Guess: ";
    std::cout << "\n";
    std::cin >> input;


    while (input < 2 || input > 12) {
        std::cout << "Please do 2-12!: ";
        std::cout << "\n";
        std::cin >> input;
        
    }
    return input;
}

int Tries() {
    static int count = 0; 
    return ++count; //makes the numbers of tries go up by one for every try 
}

int RollDice() {
    // Seed for the rng
    srand(time(0));

    int roll1, roll2;
    int min = 1;
    int max = 6;

    roll1 = rand() % (max - min + 1) + min;
    roll2 = rand() % (max - min + 1) + min;

    std::cout << "Dice 1: " << roll1 << "\n";
    std::cout << "Dice 2: " << roll2 << "\n";

    return roll1 + roll2;
}

int main() {
    // Silly Intro
    std::cout << "Hey welcome to rolling dice!\n";
    std::cout << "Your goal is to guess the number both dice\n";
    std::cout << "Will add up to!\n";
    std::cout << "If you do not you will be stuck here forever!\n";
    std::cout << "Mwahahaahah!\n";
    std::cout << "\n";

    //Converts user input into a guess so it can be compared to the sum
    int Guess = Userinput();


    //not needed but I thought it builds the suspense
    std::cout << "Press enter to roll the dice!\n";
    std::cin.ignore();
    std::cin.ignore();

    int sum = RollDice();
    std::cout << "The sum of the dice is: " << sum << "\n";

    while (sum != Guess) {

        int tries = Tries();

        std::cout << "Incorrect guess! Do you give up yet?\n";
        std::cout << "Go ahead and try to roll the dice again\n";
        std::cout << "If you give up then close the program to accounce me the winner!\n";
        std::cout << "You already tried " << tries << "... so why not give up now?\n";
        std::cout << "\n";

        Guess = Userinput();

        std::cout << "Press enter to roll the dice!\n";
        std::cin.ignore();
        std::cin.ignore();
        sum = RollDice();
        std::cout << "Sum of the dice is: " << sum << "\n";
    }
    int tries = Tries();
    std::cout << "\n";
    std::cout << "Argh!!!\n";
    std::cout << "Congratulations! You guessed the correct sum and you can leave my dungeon now!\n";
    std::cout << "You Win!\n";
    std::cout << "it took " << tries << " to escape\n";
    std::cout << "\n";
    return 0;
}