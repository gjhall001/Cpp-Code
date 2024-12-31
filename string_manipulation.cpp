// Author: Gregory Hall
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cstring>

using namespace std;

void get_scores(vector<int> &v);
// get integer scores from keyboard and store in v.
// we assume that the user will input scores in range
// of 0 to 100, inclusive. User enter a negative
// number to stop the input and end the function
void print_stats(vector<int> &v);
// print out the stats of data that are stored in v
// includes: max, min, total number of data,
// and the average

void swap(char &v1, char &v2);
// Precondition: Take two char values
// Postcondition: Swaps the two char values

string reverse(const string &s);
// Precondition: Takes a string value as input
// Postcondition: Returns the string reversed

string removePunct(const string &s);
// Precondition: Takes a string value as input
// Postcondition: Removes any non-alpha characters and any blank spaces
// and returns a string with only English characters

string toLower(const string &s);
// Precondition: Takes a string value as input
// Postcondition: Returns the string all lower case

bool isPal(const string &s);
// Precondition: Takes a string value as input
// Postcondition: Returns true if the string is a palindrome
// otherwise returns false

int main()
{

    vector<int> v;
    char response;
    string str;

    do
    {
        get_scores(v);
        print_stats(v);

        cout << "\nDo you want to try another set of scores? (Y/N): ";
        cin >> response;

        v.resize(0);
        cin.ignore(1000, '\n');

    } while ((response == 'Y') || (response == 'y'));

    cout << endl;

    do
    {
        cout << "Enter a sentence: \n";
        getline(cin, str);

        if (isPal(str))
        {
            cout << str << " is a palindrome.\n";
        }
        else
        {
            cout << "\"" << str << "\" is not a palindrome.\n";
        }

        cout << "\nDo you want to try another sentence? (Y/N): ";
        cin >> response;
        cin.ignore(1000, '\n');

    } while ((response == 'Y') || (response == 'y'));

    return 0;
}

void get_scores(vector<int> &v)
{
    int next;
    cout << "Enter scores, enter -1 to stop:\n";
    cin >> next;
    while (next >= 0)
    {
        v.push_back(next);
        cin >> next;
    }
}

void print_stats(vector<int> &v)
{
    int maxScore = 0, minScore = 0, sum = 0;

    for (unsigned int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }

    if (v.size() > 0)
    {
        cout << "There are a total of " << v.size() << " scores.\n";
        maxScore = v[0];

        for (unsigned int i = 0; i < v.size(); i++)
        {
            if (v[i] > maxScore)
            {
                maxScore = v[i];
            }
        }
        cout << "The highest score is: " << maxScore << endl;

        minScore = v[0];
        for (unsigned int i = 0; i < v.size(); i++)
        {
            if (v[i] < minScore)
            {
                minScore = v[i];
            }
        }
        cout << "The lowest score is: " << minScore << endl;

        for (unsigned int i = 0; i < v.size(); i++)
        {
            sum += v[i];
        }
        cout << "The average score is: " << (static_cast<double>(sum) / v.size()) << endl;
    }
    else
    {
        cout << "There are no scores.\n";
    }
}

void swap(char &v1, char &v2)
{
    char temp = v1;
    v1 = v2;
    v2 = temp;
}

string reverse(const string &s)
{
    int start = 0;
    int end = s.length();
    string temp(s);

    while (start < end)
    {
        end--;
        swap(temp[start], temp[end]);
        start++;
    }

    return temp;
}

string removePunct(const string &s)
{
    string removedChar;
    for (char next : s)
    {
        if (isalpha(next))
        {
            removedChar += next;
        }
    }

    return removedChar;
}

string toLower(const string &s)
{
    string temp(s);
    for (int i = 0; i < s.length(); i++)
    {
        temp[i] = tolower(s[i]);
    }

    return temp;
}

bool isPal(const string &s)
{
    string temp = reverse(s);

    string test1 = removePunct(s);
    string test2 = removePunct(temp);

    test1 = toLower(test1);
    test2 = toLower(test2);

    return (test1 == test2);
}