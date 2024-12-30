// Guessing Game
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void play(int guess, int lives, int random, int lowerLimit, int upperLimit);
// Pre-condition: A random number is generated and the player attempts to guess the random number.
// Post-condition: The program checks to see if the player's guess matches the random number.

int main()
{
    srand(time(0));

    int random = 0, lives = 7, guess = 0, lowerLimit = 1, upperLimit = 100;
    char resp;

    do
    {
        // random number between 1 and 100
        random = (rand() % 100) + 1;

        cout << "Let's play a guessing game.\n";

        play(guess, lives, random, lowerLimit, upperLimit);

        cout << "\nDo you want to play again? (Y/N) ";
        cin >> resp;
        // input validation
        while ((resp != 'y') && (resp != 'Y') && (resp != 'n') && (resp != 'N'))
        {
            cout << "Incorrect input. Please enter Y or N: ";
            cin >> resp;
        }

        cout << endl;

    } while ((resp == 'Y') || (resp == 'y'));

    cout << "Game over, thanks for playing!";

    return 0;
}

void play(int guess, int lives, int random, int lowerLimit, int upperLimit)
{
    int count = 0;

    do
    {

        cout << "Please guess a number between " << lowerLimit << " and " << upperLimit << ".\n";
        cout << "You have " << lives << " attempts remaining. Enter your guess: ";
        cin >> guess;
        cout << endl;

        // user input must be within the lower and upper limit
        while ((guess < lowerLimit) || (guess > upperLimit))
        {
            cout << "Guess is outside of range. You have " << lives << " attempts remaining. Please guess again. ";
            cin >> guess;
        }

        // either lower or upper limit is updated, based upon player's guess
        if (guess < random)
        {
            lowerLimit = guess;
        }
        else if (guess > random)
        {
            upperLimit = guess;
        }

        lives--;
        count++;

    } while ((guess != random) && (lives > 0));

    if (guess == random)
    {
        cout << "Congrats, you win! Your guess " << guess << " is correct! Good job, it only took you " << count << " attempts to guess the correct number.\n";
    }
    else if ((lives == 0) && !(guess == random))
    {
        cout << "You have " << lives << " lives remaining. Game over, please try again.\n";
    }
}