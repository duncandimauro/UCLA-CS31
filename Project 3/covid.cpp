#include <iostream>
#include <string>
using namespace std;


//Function to calculate a number in a string given the string and the location of the first character in the number
string CalculateNumberInString(string number, int CharLocation)
{
    string StrNumber;

    //While loop to store a number in a string as an int
    while (isdigit(number[CharLocation]) && (CharLocation < number.length())) //while the next character in the number is still a digit and while the string hasn't ended, extract that character and place it into a string
    {
        StrNumber += number[CharLocation];
        CharLocation += 1;
    }
    return StrNumber;

}



bool isValidResultString(string results)
{

    //Checking if first character is R
    if (results[0] != 'R')
    {
        return false;
    }

    //Initializing future variables
    int Num1;
    int Num2;
    int NumTests;
    string StrNumTests;
    string StrNum1;
    string StrNum2;
    int k = 0;


    //This loop says "run this code to check every character in the string until the string is complete, i.e., until k (the variable representing the character location) is not < the size of the string)"
    while (k < results.size())
    {
        //If a new batch starts, begin checking to see if batch is formatted properly, starting with the letter "R"
        if (results[k] != 'R')
        {
            return false;
        }
        k = k + 1;

        //Checking if next character is a digit and is also not 0
        if (!isdigit(results[k]) || (results[k] == '0'))
        {
            return false;
        }

        //Calculating the number of tests in a batch 
        StrNumTests = CalculateNumberInString(results, k);
        NumTests = stoi(StrNumTests); //stoi converts a string containing only numbers into an int.

        k += StrNumTests.length(); //making k equal the next character's location after the number for number of tests ends

        //Initializing the number of existing plus signs and minus signs in a batch to equal 0. They will reset to 0 for each batch/each iteration of the while loop.
        int PlusSigns = 0;
        int MinusSigns = 0;

        //Keeping track of whether or not a "+" sign or "-" sign appears as the next character. If they do not, the results string is invalid.
        //Additionally, the string is invalid if the string ends on a "+" or "-"
        if (results[k] == '+')
            PlusSigns = 1;
        else if (results[k] == '-')
            MinusSigns = 1;
        else
        {
            return false;
        }

        k += 1; //making k equal the next character's location after the + or - sign

        if (!isdigit(results[k]))  //returning false if a value following the + or - sign is not a digit
        {
            return false;
        }

        //Calculating either the number of positive or negative tests in batch
        //Note: It doesn't matter that we know if the tests are positive or negative, so long as we know there are both positive and negative tests.
        StrNum1 = CalculateNumberInString(results, k);
        Num1 = stoi(StrNum1);
        k += StrNum1.size(); //making k equal the next character's location after the number is complete

        //Keeping track of whether or not a "+" sign or "-" sign appears as the next character. If they do not, the results string is invalid.        
        if (results[k] == '+')
            PlusSigns = 1;
        else if (results[k] == '-')
            MinusSigns = 1;
        else
        {
            return false;
        }

        k += 1; //making k equal the next character's location after the + or - sign

        //If there is not both a plus sign and a minus sign in the batch, the results string is invalid
        if ((MinusSigns != 1) || (PlusSigns != 1))
        {
            return false;
        }

        //Calculating either the number of positive or negative tests in batch
        //Note: It doesn't matter that we know if the tests are positive or negative, so long as we know there are both positive and negative tests.
        StrNum2 = CalculateNumberInString(results, k);
        Num2 = stoi(StrNum2);
        k += StrNum2.length(); //making k equal the next character's location after the number is complete

        //If the sum of the number of positive and negative results does not equal the number of tests in a batch, the results string is invalid
        if (Num1 + Num2 != NumTests)
        {
            return false;
        }
        //Batch is now complete, so go to the beginning of the while loop again, where it will start by checking if the next character is "R"
    }
    //If there are no errors after checking every character in the string, then the results string is valid
    return true;
}




int positiveTests(string results)
{
    //Checking if the string is valid and returning -1 if it is invalid
    if (isValidResultString(results) == false)
    {
        return -1;
    }

    //Initializing future variables
    string StrNumTests;
    int Num1;
    int Num2;
    string StrNum1;
    string StrNum2;
    int k = 0;
    int posPositive = 0;
    int posNegative = 0;
    int TotPositive = 0;
    int TotNegative = 0;

    //This loop says "run this code to check every character in the string until the string is complete, i.e., until k (the variable representing the character location) is not < the size of the string)"
    while (k < results.size())
    {
        k = k + 1; //moving character past the R

        //Running code to move k to the next character after the number of tests
        StrNumTests = CalculateNumberInString(results, k);
        k += StrNumTests.length(); //making k equal the next character's location after the number for number of tests ends


        if (results[k] == '+') //If if the next character is '+', posPositive = 1
        {
            posPositive = 1;
            posNegative = 2;
        }
        else if (results[k] == '-') //If if the next character is '-', posNegative = 1
        {
            posNegative = 1;
            posPositive = 2;
        }

        k += 1; //making k equal the next character's location after the + or - sign

        StrNum1 = CalculateNumberInString(results, k);
        Num1 = stoi(StrNum1); //Calculating the first the number of either positive or negative tests in batch

        k += StrNum1.size(); //making k equal the next character's location after the number is complete

        k += 1; //making k equal the next character's location after the + or - sign

        StrNum2 = CalculateNumberInString(results, k);
        Num2 = stoi(StrNum2); //Calculating the second the number of either positive or negative tests in batch

        k += StrNum2.length(); //making k equal the next character's location after the number is complete

        if (posPositive == 1) //If the "+" comes first in the batch, add the first found number to the total number of positive tests
        {
            TotPositive += Num1;
            TotNegative += Num2;
        }
        else if (posNegative == 1) //If the "-" comes first in the batch, add the first found number to the total number of positive tests
        {
            TotNegative += Num1;
            TotPositive += Num2;
        }

        //Batch is now complete, so go to the beginning of the while loop again, where it will start checking the next batch
    }
    //After the loop is complete, return the total number of positive tests
    return TotPositive;
}








int negativeTests(string results)
{
    //Checking if the string is valid and returning -1 if it is invalid
    if (isValidResultString(results) == false)
    {
        return -1;
    }

    //Initializing future variables
    string StrNumTests;
    int Num1;
    int Num2;
    string StrNum1;
    string StrNum2;
    int k = 0;
    int posPositive = 0;
    int posNegative = 0;
    int TotPositive = 0;
    int TotNegative = 0;

    //This loop says "run this code to check every character in the string until the string is complete, i.e., until k (the variable representing the character location) is not < the size of the string)"
    while (k < results.size())
    {
        k = k + 1; //moving character past the R

        //Running code to move k to the next character after the number of tests
        StrNumTests = CalculateNumberInString(results, k);
        k += StrNumTests.length(); //making k equal the next character's location after the number for number of tests ends


        if (results[k] == '+') //If if the next character is '+', posPositive = 1
        {
            posPositive = 1;
            posNegative = 2;
        }
        else if (results[k] == '-') //If if the next character is '-', posNegative = 1
        {
            posNegative = 1;
            posPositive = 2;
        }

        k += 1; //making k equal the next character's location after the + or - sign

        StrNum1 = CalculateNumberInString(results, k);
        Num1 = stoi(StrNum1); //Calculating the first the number of either positive or negative tests in batch

        k += StrNum1.size(); //making k equal the next character's location after the number is complete

        k += 1; //making k equal the next character's location after the + or - sign

        StrNum2 = CalculateNumberInString(results, k);
        Num2 = stoi(StrNum2); //Calculating the second the number of either positive or negative tests in batch

        k += StrNum2.length(); //making k equal the next character's location after the number is complete

        if (posPositive == 1) //If the "+" comes first in the batch, add the first found number to the total amount of positive tests and second number to the total amount of negative tests
        {
            TotPositive += Num1;
            TotNegative += Num2;
        }
        else if (posNegative == 1) //If the "-" comes first in the batch, add the first found number to the total number of negative tests and second number to the total amount of positive tests
        {
            TotNegative += Num1;
            TotPositive += Num2;
        }

        //Batch is now complete, so go to the beginning of the while loop again, where it will start checking the next batch
    }
    //After the loop is complete, return the total number of negative tests
    return TotNegative;
}




int totalTests(string results)
{
    //Checking if the string is valid and returning -1 if it is invalid
    if (isValidResultString(results) == false)
    {
        return -1;
    }

    //Initializing future variables
    string StrNumTests;
    int NumTests = 0;
    string StrNum1;
    string StrNum2;
    int k = 0;

    //This loop says "run this code to check every character in the string until the string is complete, i.e., until k (the variable representing the character location) is not < the size of the string)"
    while (k < results.size())
    {
        k = k + 1; //moving character past the R

        //Running code to move k to the next character after the number of tests
        StrNumTests = CalculateNumberInString(results, k);
        NumTests += stoi(StrNumTests); //Calculating the number of tests found so far by the code
        k += StrNumTests.length(); //making k equal the next character's location after the number for number of tests ends

        k += 1; //making k equal the next character's location after the + or - sign

        StrNum1 = CalculateNumberInString(results, k);
        k += StrNum1.size(); //making k equal the next character's location after the number is complete

        k += 1; //making k equal the next character's location after the + or - sign

        StrNum2 = CalculateNumberInString(results, k);
        k += StrNum2.length(); //making k equal the next character's location after the number is complete

        //Batch is now complete, so go to the beginning of the while loop again, where it will start checking the next batch
    }
    //After the loop is complete, return the total number of Tests
    return NumTests;
}

int batches(string results)
{
    //Checking if the string is valid and returning -1 if it is invalid
    if (isValidResultString(results) == false)
    {
        return -1;
    }

    //Initializing future variables
    string StrNumTests;
    int NumTests = 0;
    string StrNum1;
    string StrNum2;
    int k = 0;
    int Batches = 0;

    //This loop says "run this code to check every character in the string until the string is complete, i.e., until k (the variable representing the character location) is not < the size of the string)"
    while (k < results.size())
    {
        k = k + 1; //moving character past the R

        //Running code to move k to the next character after the number of tests
        StrNumTests = CalculateNumberInString(results, k);
        k += StrNumTests.length(); //making k equal the next character's location after the number for number of tests ends

        k += 1; //making k equal the next character's location after the + or - sign

        StrNum1 = CalculateNumberInString(results, k);
        k += StrNum1.size(); //making k equal the next character's location after the number is complete

        k += 1; //making k equal the next character's location after the + or - sign

        StrNum2 = CalculateNumberInString(results, k);
        k += StrNum2.length(); //making k equal the next character's location after the number is complete

        Batches += 1;

        //Batch is now complete, so go to the beginning of the while loop again, where it will start checking the next batch
    }
    //After the loop is complete, return the total number of Tests
    return Batches;
}


int main()
{
    string results;

    cout << "Please enter a results string: ";
    getline(cin, results);

    bool valid = isValidResultString(results);

    if (valid == true)
        cout << "\nThe string is valid!";
    else if (valid == false)
        cout << "\nThe string is invalid.";

    int AmountPos = positiveTests(results);
    int AmountNeg = negativeTests(results);
    int NumTests = totalTests(results);
    int AmountBatches = batches(results);

    cout << "\nThe number of batches is: " << AmountBatches;
    cout << "\nThe number of total tests is: " << NumTests;
    cout << "\nThe number of positive tests is: " << AmountPos;
    cout << "\nThe number of negative tests is: " << AmountNeg;

}