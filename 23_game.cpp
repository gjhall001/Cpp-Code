// Author: Gregory Hall
// Game of "23" where a player competes against the computer selecting sticks and
// rotating turns until either the player or the computer takes the last stick and
// loses the game.
#include <iostream>
#include <cstdlib>
using namespace std;

void playerTurn(int &numOfSticks, int minStick, int maxStick, int &playerPick);
// Pre-condition: The player goes first and selects between minStick and maxStick
// Post-condition: The player selects a number of sticks and the playerPick is
// subtracted from the numOfSticks. Now it is the computer's turn to select.

void computerTurn(int &numOfSticks, int playerPick);
// Pre-condition: The computer selects a certain number of sticks based upon
// various conditions. minStick and maxStick
// Post-condition: The computer selects a number of sticks and the computerPick is
// subtracted from the numOfSticks. Now it is the player's turn to select.

int main()
{
    int numOfSticks = 0;
    int minStick = 1, maxStick = 3;
    char resp;
    int playerPick = 0;

    do
    {

        cout << "Let's play a game of \"23\"!\n";
        numOfSticks = 23;
        playerPick = 0;
        char turn = 'p';

        do
        {
            if (turn == 'p')
            // Player's turn
            {
                playerTurn(numOfSticks, minStick, maxStick, playerPick);
                if (numOfSticks != 0)
                {
                    turn = 'c';
                }
            }
            else if (turn == 'c')
            // Computer's turn
            {
                computerTurn(numOfSticks, playerPick);
                if (numOfSticks != 0)
                {
                    turn = 'p';
                }
            }

        } while (numOfSticks != 0);

        if (turn == 'p')
        {
            cout << "\nYou picked the last stick. The computer beat you.\n";
        }
        else
        {
            cout << "The computer picked the last stick. You beat the computer.\n";
        }

        cout << "\nGame over. Do you want to play another game? (Y/N) ";
        cin >> resp;
        cout << endl;
        while ((resp != 'Y') && (resp != 'y') && (resp != 'n') && (resp != 'N'))
        {
            cout << "Incorrect input, please enter Y or N: ";
            cin >> resp;
        }

    } while ((resp != 'N') && (resp != 'n'));

    cout << "Thank you for playing. Goodbye!";

    return 0;
}

void playerTurn(int &numOfSticks, int minStick, int maxStick, int &playerPick)
{
    // max number of sticks is updated if numOfSticks < 3
    if (numOfSticks < 3)
    {
        maxStick = numOfSticks;
    }

    if (minStick != maxStick)
    {
        cout << "Pick between " << minStick << " and " << maxStick << " sticks: ";
        cin >> playerPick;
    }
    else
    {
        cout << maxStick << " stick remaining, please pick it: ";
        cin >> playerPick;
    }
    // input validation
    while ((playerPick < minStick) || (playerPick > maxStick))
    {
        cout << "Please enter a valid number of sticks: ";
        cin >> playerPick;
    }

    numOfSticks = numOfSticks - playerPick;

    cout << "You picked " << playerPick << " sticks. " << numOfSticks << " left.\n";
}

void computerTurn(int &numOfSticks, int playerPick)
{
    int computerPick = 0;

    if (numOfSticks > 4)
    {
        computerPick = 4 - playerPick;
    }
    else if ((numOfSticks > 1) && (numOfSticks < 5))
    {
        if (numOfSticks == 4)
        {
            computerPick = numOfSticks - 3;
        }
        else if (numOfSticks == 3)
        {
            computerPick = numOfSticks - 2;
        }
        else if (numOfSticks == 2)
        {
            computerPick = numOfSticks - 1;
        }
    }
    else if (numOfSticks == 1)
    {
        computerPick = 1;
    }

    numOfSticks = numOfSticks - computerPick;

    cout << "Computer picked " << computerPick << " sticks. " << numOfSticks << " left.\n\n";
}