#include <iostream>
#include<string>
#include "Complex.h"
using namespace std; //include libraries

/**
 * @Sammak Ahmed
 * Lab 4 - Complex Number Calculator
 * Overload functions so that you can add, subtract, multiply, and compare two complex numbers inputted by th user
 */

double extractReal(string str);
double extractImaginary(string str); //declaring functions

int main() // main function which asks user for 2 complex numbers in form (a,b) and then displayes them being added, subtracted
           // multiplied, and compared to each other.
{   
    string userInp, userInp2;
    cout << "Enter First complex number in the form (a,b): ";
    cin >> userInp;
    cout << "Enter Second complex number in the form (a,b): ";
    cin >> userInp2; // asks user for both inputs and stores them in 2 seperate strings. 

    Complex comp1;
    Complex comp2; // declaring 2 objects for each complex number

    comp1.setReal(extractReal(userInp));
    comp1.setImaginary(extractImaginary(userInp));
    comp2.setReal(extractReal(userInp2));
    comp2.setImaginary(extractImaginary(userInp2)); //calling the extractReal and extractImaginary function to set the values
                                                    // for the real and imaginary values of the object.

    Complex add = comp1 + comp2; // adding the 2 complex numbers and storing result in add
    Complex sub = comp1 - comp2; // subtracting the 2 complex numbers and storing result in object sub
    Complex mult = comp1 * comp2; // multiplying the 2 complex numbers and storing result in object mult
    

    cout << "************************************" << endl;
    cout << "       Results of Calculations      " << endl;
    cout << "************************************" << endl;
    cout << comp1 << " + " << comp2 << " = " << add << endl;
    cout << comp1 << " - " << comp2 << " = " << sub << endl;
    cout << comp1 << " * " << comp2 << " = " << mult << endl;
    if (comp1 == comp2)
    {
        cout << comp1 << " == " << comp2 << endl;
    }
    else
    {
        cout << comp1 << " != " << comp2 << endl;
    }
    cout << "\n\n************************************" << endl; // outputting the resultsS
    return 0;
}

double extractReal(string str) //extracting method that gets the string from the userinput and parses it to to get the 
                               // 'a' from (a,b) as a real number
{   
    string delim = ",";
    int pos = str.find(delim);
    double temp = std::stod(str.substr(1,pos));
    return temp;
}

double extractImaginary(string str)//extracting method that gets the string from the userinput and parses it to to get the 
                               // 'a' from (a,b) as an imaginary number
{
    string delim = ",";
    int pos = str.find(delim);
    double temp = std::stod(str.substr(pos + 1,str.length()));
    return temp;
}