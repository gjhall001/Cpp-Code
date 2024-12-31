// Author: Gregory Hall
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int sum(int n);
// Precondition: Integer is provided as input.
// Postcondition: Recursive version to calculate the sum
// of 1 + 2 + ... + n

int str_length(char s[], int counter);
// str_length: option 1:
// Precondition: C string and integer variable counter
// is provided as input.
// Postcondition: It returns the length of the string s[].
// (the null character, '\0', is not counted in the length)

int main()
{

    int value = 0, counter = 0;
    char response = 'y';
    char someText[200];

    do
    {
        cout << "Enter a positive integer: ";
        cin >> value;

        cout << "The sum of 1 + 2 ... + " << value << " is: " << sum(value) << endl
             << endl;

        // ignores the '\n' that was not read by the (cin >> value;) line
        cin.ignore(1, '\n');

        cout << "Enter a sentence: ";
        cin.getline(someText, 200);

        cout << "It contains " << str_length(someText, counter) << " chars, including white spaces.\n"
             << endl;

        cout << "Do you want to have another run? (Y/N): ";
        cin >> response;

        cout << endl;

        // condition to end loop
    } while ((response != 'n') && (response != 'N'));

    return 0;
}

int sum(int n)
{

    if (n > 0)
    {
        // recursion to add sum of numbers
        return n + sum(n - 1);
    }

    return 0;
}

int str_length(char s[], int counter)
{
    int i = 0;

    // loop through each char and keeps count of number of chars
    while (s[i] != '\0')
    {
        i++;
        counter++;
    }

    return counter;
}