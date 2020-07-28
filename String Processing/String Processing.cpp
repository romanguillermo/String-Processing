// String Processing

/* Pseudocode:
   Prompt user to enter string
   Display menu of options for user to choose that manipulate or print string
   Repeat until user chooses to quit */

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX = 81;

void inverseString(char[]);
void reverseString(char[]);
void toUppercase(char[]);
void jumbleString(char[]);
int countWords(char[]);
int countConsonants(char[]);

int main()
{
    int selection;
    char userString[MAX];
    
    cout << "Enter a string: " << endl;
    cin.getline(userString, MAX, '\n');

        do
        { 
label1: cout << "---------------------------------------" << endl
            << "1) Inverse String" << endl
            << "2) Reverse String" << endl
            << "3) To Uppercase" << endl
            << "4) Jumble String" << endl
            << "5) Count Number Words" << endl
            << "6) Count Consonants" << endl
            << "7) Enter a Different String" << endl
            << "8) Print the String" << endl
            << "9) Quit" << endl;
        cin >> selection;

        switch (selection)
        {
        case 1:
            inverseString(userString);
            break;
        case 2:
            reverseString(userString);
            break;
        case 3:
            toUppercase(userString);
            break;
        case 4:
            jumbleString(userString);
            break;
        case 5:
            cout << "The string has " << countWords(userString) << " words." << endl;
            break;
        case 6:
            cout << "The string has " << countConsonants(userString) << " consonants." << endl;
            break;
        case 7:
            cin.clear();
            cin.ignore();
            cin.sync();
            cin.getline(userString, MAX, '\n');
            break;
        case 8:
            cout << userString << endl;
            break;
        case 9:
            exit(0);
            break;
        default:
            cout << "Invalid selection" << endl;
            goto label1;
        }

    } while (selection != 9);

    return 0;
}

void inverseString(char arr[])
{
    for (int i=0;i<strlen(arr);i++)
    {
        if (islower(arr[i]))
        {
            arr[i] = toupper(arr[i]);
        }
        else if (isupper(arr[i]))
        {
            arr[i] = tolower(arr[i]);
        }
    }
}

void reverseString(char arr[])
{
    char array[MAX];
    int i = 0;
    for (int j = strlen(arr) - 1;j >= 0;j--)
    {
        array[i] = arr[j];
        i++;
    }
    for (int k = 0;k < strlen(arr);k++)
    {
        arr[k] = array[k]; // putting into array passed in instead of trying to return new array
    }
}

void toUppercase(char arr[])
{
    for (int i=0;i<strlen(arr);i++)
    {
        arr[i] = toupper(arr[i]);
    }
}

void jumbleString(char arr[])
{
    int j;
    for (int i=0;i<strlen(arr);i++)
    {
        srand(time(NULL));
        j = (rand() % strlen(arr));
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int countWords(char arr[])
{
    int count = 1;

    for (int i=0;i<strlen(arr);i++)
    {
        if (arr[i] == ' ') // only way i could think of
        {
            count++;
        }
    }
    return count;
}

int countConsonants(char arr[])
{
    int count = 0;
    char consonant[] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z',
        'B','C','D','F','G','H','J','K','L','M','N','O','Q','R','S','T','V','W','X','Y','Z'};

    for (int i = 0;i < strlen(arr);i++)
    {
        for (int j = 0;j < strlen(consonant);j++) 
        {
            if (arr[i] == consonant[j])
            {
                count++;
            }
        }
    }
    return count;
}