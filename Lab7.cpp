#include<iostream>
#include<array> //calling libraries

using namespace std;
/**
 * @Sammak Ahmed - 100747439
 * Lab 7 - STLs
 * This program will ask the user for 10 integer values between 10 and 100 and enforce that the inputs are correct. If the 
 * inputted value is not in the array, then the program will add it to the array. However, if the inputted value is in the array
 * the program will let the user know that it is a duplicate number and not add that value to the array. The final output will
 * be all the values that were not duplicates.
 * 
 */

const int SIZE = 10; //declaring global variable called SIZE

bool duplicateCheck(const array<int, SIZE> &checkArr, int dupe); //declaring duplicateCheck function

int main()
{
    array<int, SIZE> arr{}; //declaring array
    int userInput; // declaring userInput variable
    int counter = 0; // counter for location at where to input the userInputs

    cout << "Enter 10 integers between 10 and 100: " << endl;
    for (int i = 0; i < 10; i++) //for loop to ask user to input 10 intger numbers
    {
        cout << "Enter a number: ";
        cin >> userInput; // asks user to input number and stores it in userInput

        if (userInput < 10 || userInput > 100) // if the userInput is less than 10 or greater than 100, then it will output 
                                               // that the number is invalid and lower the for loop counter by 1
        {
            cout << "Invalid Number. Please enter a number between 10 and 100.\n" << endl;
            i = i - 1;
        }
        else // else it will call the duplicateCheck function or add the userInput to the array
        {
            if (!duplicateCheck(arr, userInput)) // calls the duplicateCheck function and if false, outputs that it is a duplicate number
            {
                cout << "Duplicate number.\n" << endl;
            }
            else // else it adds the userInput to the array and increases counter by 1
            {   
                arr[counter] = userInput;
                counter = counter + 1;
            }
        }
    }

    cout << "The nonduplicate values are: " << endl;
    for (auto k = arr.begin(); k != arr.end(); k++) // for loop to iterate through the array and output the elements inside
    {
        if (*k != 0) // as the array is size 10 any value not recorded will be 0 so to cancel that output, this if statement exists 
        {
            cout << *k << " "; // outputs the values in array
        }    
    }
    return 0;
}

bool duplicateCheck(const array<int, SIZE> &checkArr, int dupe) //function to check if the userInput value is already in array
{
    for (auto i = checkArr.begin(); i != checkArr.end(); i++) // for loop to go through each value in array
    {
        if (*i == dupe) // if that value is in array, it will return false
        {   
            return false;
        }
    }
    return true; //return true otherwise
}
