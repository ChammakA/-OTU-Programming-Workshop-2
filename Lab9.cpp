#include <iostream>
#include <string> //calling libraries

using namespace std;

/**
 * @Sammak Ahmed - 100747439
 * Lab 9 - Recursion
 * Asks user for an integer and stores that input into a char array. It then passes that array into class Converision which
 * then converts that number to binary and outputs the result.
 */

class Conversion
{
    private:
        char* char_number; // private variable of pointer char_number
    public:
        Conversion(const char* number) //default constructor that allocates char_number to point to a heap of the size of number + 1
                                // it then copies the value in number to char_number
        {
            
            this->char_number = new char[sizeof(number) + 1];

            int i = 0; //  create counter
            while (number[i] != '\0') //iterates unti find null space and then copies values from number into char_number
            {
                this->char_number[i] = number[i]; 
                i++;
            }
            this->char_number[i] = '\0'; // adds an end of line delimiter after all values are copied
            
            //this->char_number = number;
        };
        void DecimalToBinary(int n) // function that converts the given integer, n, into a binary number and stores it in
                                    // outputBinary array. Once all the digits have been added, it will output the array in reverse
        {
            int outputBinary[64];
            int counter = 0;
            
            if (n == 0) // if n == 0, then it will output 0.
            {
                cout << "0";
            }
            while (n > 0) //otherwise it will use the formula to convert to binary. Due to multiple digits, it will call itself
                         // in a recursive manner so it can get all the conversion.
            {
                outputBinary[counter] = n % 2;
                n = n / 2;
                counter++;
            }
            for (int j = counter - 1; j >= 0; j--)
            {
                cout << outputBinary[j];
            }

        };
        void convert()
        {
           DecimalToBinary(atoi(char_number)); // converts the char_number into an integer value and calls the DecimalToBinary function

        };
        ~Conversion() //delete constructor that will delete char_number and makes it point to NULL
        {
            delete[] char_number; 
            char_number = NULL;

        };
};

int main()
{
    char number[10]; // creates char array
    cout << "Enter an integer to convert to binary: "; // asks user for an integer to convert
    cin >> number; //stores that value in number

    Conversion conversion = Conversion(number); //creates an object, conversion, and calls the default constructor with number as the variable
    conversion.convert(); //calls the convert function with object.

    return 0;
}