#include <iostream>
#include <string>
#include <cassert>

using namespace std;


bool identicalValuesTogether(const string array[], int n)
{
    if (n <= 0)
        return false;

    for (int k = 0; k <= (n - 1); k++) //Looping through array values to compare against other array values
    {

        int difference = 0;

        for (int i = 0; (i <= (n - 1)); i++) //checking one array value against the rest of the array
        {
            if ((array[k] == array[i]) && (k != i)) //if there is a duplicate value
            {
                difference = i - k; //find the difference in indexes
                
                if (difference < 0)
                {
                    for (int j = -1; (j >= difference); j--) //if difference is < 0, check if all duplicate values leading up to array[k] from array[i]
                        if (array[k] != array[k + j])
                            return false;
                }
                
                if (difference > 0)
                {
                    for (int j = 1; (j <= difference); j++)  //if difference is > 0, check if all duplicate values leading up to array[i] from array[k]
                        if (array[k] != array[k + j])
                            return false;
                }
            }
        }
    }
        return true; //return true if all of the checks are passed
}


bool hasTwoOrMoreDuplicates(const string array[], int  n)
{
    if (n <= 0)
        return false;

    int duplicates = 0;

    for (int k = 0; k <= (n - 1); k++) //Looping through array values to compare against other array values
    {

        for (int i = 0; (i <= (n - 1)); i++) //checking one array value against the rest of the array
        {
            if ((array[k] == array[i]) && (k != i))
                duplicates += 1; //adding a value if a duplicate is found
        }
    }
    if (duplicates >= 4) //the way my code is set up, the number of duplicates will be doubled. We require 2 duplicates, or int duplicates = 4.
        return true;
    else
        return false;
}

int countFloatingPointValues(const string array[], int  n)
{
    if (n <= 0)
        return -1;

    int AmtFloatingPointValues = 0;

    for (int k = 0; k <= (n - 1); k++) //Looping through the entire array
    {
        int l = array[k].length(); //Getting the length of a single element
        int validity = 1;
        int numPeriods = 0;

        // loop to traverse a single element 
        for (int i = 0; i < l; i++)
        {
            //
            if ((!isdigit(array[k][i])) && (array[k][i] != '.')) //if a character is not a digit or a period, the string is invalid
                validity = 0;
            else if ((validity == 1) && (array[k][i] == '.'))
                numPeriods += 1;
        }
        if ((validity == 1) && (numPeriods < 2))
            AmtFloatingPointValues += 1;
    }
    return AmtFloatingPointValues;
}

bool hasNoCapitals(const string array[], int n)
{
    if (n <= 0)
        return true;

    for (int k = 0; k <= (n - 1); k++) //Looping through the entire array
    {
        int l = array[k].length(); //Getting the length of a single element
        int validity = 1;

        // loop to traverse a single element 
        for (int i = 0; i < l; i++)
        {
            //if there is a capital letter
            if ((array[k][i] == 'A') || (array[k][i] == 'B') || (array[k][i] == 'C') || (array[k][i] == 'D') || (array[k][i] == 'E') || 
                (array[k][i] == 'F') || (array[k][i] == 'G') || (array[k][i] == 'H') || (array[k][i] == 'I') || (array[k][i] == 'J') ||
                (array[k][i] == 'K') || (array[k][i] == 'L') || (array[k][i] == 'M') || (array[k][i] == 'N') || (array[k][i] == 'O') ||
                (array[k][i] == 'P') || (array[k][i] == 'Q') || (array[k][i] == 'R') || (array[k][i] == 'S') || (array[k][i] == 'T') ||
                (array[k][i] == 'U') || (array[k][i] == 'V') || (array[k][i] == 'W') || (array[k][i] == 'X') || (array[k][i] == 'Y') || (array[k][i] == 'Z')) 
                return false;
        }
    }
    return true;
}

int locateMaximum( const string array[ ], int n )
{

    if (n <= 0) // can't have size of array be equal to or less than 0
        return -1;
    
    int maximum = 0;

    for (int k = n-1; k>=0; k--) // cycling through array backwards
    {

        if (array[k] >= array[n - 1])// if we find an element greater than or equal to the current maximum value
        {
            array[(n - 1)] == array[k]; // change maximum value to new element
            maximum = k; //storing index of maximum value
        }
    }
    return maximum;
}






int shiftLeft(string array[], int n, int amount, string placeholder)
{

    if (n <= 0)
        return -1;
    if (amount < 0) // can't have amount parameter be 0
        return -1;
    
    int TimesPlaceholderUsed = 0;

    if (amount > n) // If amount > n, we don't want to consider the values in the array past n
    {
        amount = n;
    }

    for (int k = 1; k <= amount; k++) //Shift each element in the array left once per loop, and there are amount # of loops
    {
            for (int i = 0; i < (n-1); i++) //Shift all element in the array left
            {
                array[i] = array[i + 1]; //Shifting a single element
            }
            
            TimesPlaceholderUsed += 1; // tracks how many times an array element has been replaced
    }

    for (int j = 1; j <= amount; j++) //Replaces empty array values
    {
        array[n - j] = placeholder;
    }

    return TimesPlaceholderUsed;
}


int replaceFirstAndLastOccurrences(string array[], int n, char charToFind, char charToReplace)
{

    if (n <= 0)
    return -1;

    int timesReplaced = 0;

    for (int k = 0; k <= n-1; k++) //Going through each element of the array
    {

        int l = array[k].length(); //Getting the length of the element

        int FoundFirst = 0;
        int FoundLast = 0;
        int posFirst = l + 1;
        int posLast = l + 2;

        // loop to traverse a single element 
        for (int i = 0; i < l; i++)
        {
            //Finding the first charToFind in the element
            if ((array[k][i] == charToFind) && (FoundFirst == 0))
            {
                array[k][i] = charToReplace;
                FoundFirst = 1;
                posFirst = i;
                timesReplaced += 1;
            }

            if ((array[k][(l - 1) - i] == charToFind) && (FoundLast == 0))
            {
                array[k][(l - 1) - i] = charToReplace; //replacing the character in the input array
                FoundLast = 1;
                posLast = (l-1)-i;
                timesReplaced += 1;
            }
        }
        if (posFirst == posLast) //Just in case the first found character and last found character were the same character
        timesReplaced -= 1;
    }
    return timesReplaced;
}






int main()
{

    // test cases for locateMaximum


    string  c[1] = { "1" };
    string a[5] = { "aaaa", "aa", "a", "aaaa", "a" };
    string b[7] = { "aaa", "bbb", "aa", "bbbb", "a", "bb", "aaaaaa" };

    cout << locateMaximum(a, 5);
    cout << locateMaximum(b, 7);

    cout << "test";

    // test cases for shiftLeft

    string q[10] = { "a", "b", "c", "d", "e", "f", "g", "h", "iii", "j" };

    cout << "originally: " << q[1];

    cout << "      Output: " << shiftLeft(q, 10, 11, "$");

    cout << "      New: " << q[1];  

    // test for replaceFirstAndLastOcurrences

    string folks[8] = { "samwell", "jon", "margaery", "daenerys", "tyrion", "sansa", "magdalena", "jon" };

    cout << folks[6];

    int hi = replaceFirstAndLastOccurrences(folks, 8, 'a', 'Z');

    cout << "      answer is:" << hi;

    cout << folks[6];

    string meme[7] = { "AA", "BB", "aa", "bb", "cc", "dd", "ee" };

    cout << "          " << replaceFirstAndLastOccurrences(meme, 5, 'A', 'Z');

    cout << meme[0];

    return(0);

}