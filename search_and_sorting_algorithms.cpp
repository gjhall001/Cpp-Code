// Author: Gregory Hall
#include <iostream>

using namespace std;

void menu();
// post-condition: The menu is displayed so users can make a selection.

void fill_array(int arr[], int size);
// pre-condition: The arr has actual size that is greater than or equal to size
// post-condition: arr[0], ..., arr[size-1] is filled from keyboard

void print_array(int arr[], int size);
// pre-condition: The arr has actual size that is greater than or equal to size
// post-condition: arr[0], ..., arr[size-1] is printed to screen with 5
// elements per line

int linear_search(int arr[], int size, int key);
// pre-condition: arr has given size
// post-condition: The index of first occurrence of key in arr is returned. If
// the key cannot be found in arr, -1 is returned

void select_sort(int arr[], int size);
// pre-condition: arr has given size
// post-condition: the elements in arr are rearranged from least to largest

void swapValues(int &v1, int &v2);
// Precondition: Takes two integer values as input.
// Postcondition: Interchanges the values of v1 and v2.

int indexOfSmallest(const int arr[], int startIndex, int size);
// Precondition: 0 <= startIndex < numberUsed. Referenced array
// elements have values.
// Postcondition: Returns the index i such that arr[i] is the smallest
// of the values arr[startIndex], arr[startIndex + 1], ..., arr[numberUsed - 1].

void insert_sort(int arr[], int size);
// pre-condition: arr has given size
// post-condition: the elements in arr are rearranged from least to largest

void bubble_sort(int arr[], int size);
// pre-condition: arr has given size
// post-condition: the elements in arr are rearranged from least to largest

int main()
{

    int choice;
    int a[9];
    do
    {
        menu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            fill_array(a, 9);
            cout << "Enter the key you want to search: ";
            int key;
            cin >> key;
            int index = linear_search(a, 9, key);
            if (index == -1)
            {
                cout << "The key " << key << " is not in array\n";
            }
            else
            {
                cout << "The key " << key << " is #" << (index + 1)
                     << " element in array.\n";
            }
            break;
        }
        case 2:
        {
            fill_array(a, 9);
            select_sort(a, 9);
            cout << "After sort, the array is:\n";
            print_array(a, 9);
            break;
        }
        case 3:
        {
            fill_array(a, 9);
            insert_sort(a, 9);
            cout << "After sort, the array is:\n";
            print_array(a, 9);
            break;
        }
        case 4:
        {
            fill_array(a, 9);
            bubble_sort(a, 9);
            cout << "After sort, the array is:\n";
            print_array(a, 9);
            break;
        }
        case 5:
        {
            cout << "Thank you for using the array functions!\n";
            break;
        }
        default:
        {
            cout << "Wrong choice. Please choose from menu:\n";
            break;
        }
        }
    } while (choice != 5);

    return 0;
}

void menu()
{
    cout << "\n\t***************************************************";
    cout << "\n\t*                   Menu                          *";
    cout << "\n\t* 1. Linear Search                                *";
    cout << "\n\t* 2. Selection Sort                               *";
    cout << "\n\t* 3. Insertion Sort                               *";
    cout << "\n\t* 4. Bubble Sort                                  *";
    cout << "\n\t* 5. Quit                                         *";
    cout << "\n\t***************************************************";
    cout << endl;
}

void fill_array(int arr[], int size)
{
    cout << "Enter " << size << " numbers:\n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << endl;
}

void print_array(int arr[], int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int linear_search(int arr[], int size, int key)
{
    int index = 0;
    bool found = false;
    while ((!found) && (index < size))
    {
        if (key == arr[index])
        {
            found = true;
        }
        else
        {
            index++;
        }
    }

    if (found)
    {
        return (index);
    }
    else
    {
        return (-1);
    }
}

void select_sort(int arr[], int size)
{
    int indexOfNextSmallest;

    for (int index = 0; index < size - 1; index++)
    { // Place the correct value in arr[index]:
        indexOfNextSmallest = indexOfSmallest(arr, index, size);
        swapValues(arr[index], arr[indexOfNextSmallest]);
    }
}

void swapValues(int &v1, int &v2)
{
    int temp;
    temp = v1;
    v1 = v2;
    v2 = temp;
}

int indexOfSmallest(const int arr[], int startIndex, int size)
{
    int min = arr[startIndex], indexOfMin = startIndex;
    for (int index = startIndex + 1; index < size; index++)
    {
        if (arr[index] < min)
        {
            min = arr[index];
            indexOfMin = index;
            // min is the smallest of a[startIndex] through a[index]
        }
    }

    return (indexOfMin);
}

void insert_sort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while ((j >= 0) && (arr[j] > key))
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

void bubble_sort(int arr[], int size)
{
    // Bubble largest number toward the right
    int i, j;
    for (i = size - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap numbers
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}