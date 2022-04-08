#include <iostream>
#include <algorithm> //calling libraries

using namespace std;
/**
 * @Sammak Ahmed - 100747439
 * Lab 8: Function Templates
 * Creates 3 arrays of types: int, float, string. The program then outputs all the values inside the array as well as the largest
 * value inside the arrays. For the int and float arrays, it will output the largest value and for the string array it will
 * output the longest word.
 */

template<class T> //using template
T max_numbers(T arr[], int size) // gets an array of type T and a size. It then iterates through the array and returns the max value
{   
    T maximum = arr[0];
    for (int i = 0; i < size; i++)
    {
        maximum = max(maximum,arr[i]);
    }
    return maximum;
}

int main() // the function creates 3 different areas of types: int, float, string. It then outputs the contents of each array
           // as well as the largest value of each array.
{   
    int int_array[6] = {2, 3, 81, 1, 9, 22};
    float float_array[4] = {-3.4, 58.1, -76.4, 34.4};
    string string_array[5] = {"Ontario", "Tech", "University", "Oshawa", "Canada"}; //creating the arrays

    // all the output statements.
    cout << "Array of decimals..." << endl;
    for_each(begin(float_array), end(float_array), [](float y){cout << y << ", ";}); //lambda function to go through each
                                                                                     // element in array and output
    cout << "\nThe largest double is: " << max_numbers(float_array, 4) << endl;

    cout << "\n\nArray of integers..." << endl;
    for_each(begin(int_array), end(int_array), [](int x){cout << x << ", ";});
    cout << "\nThe largest integer is: " << max_numbers(int_array,6) << endl;

    cout << "\n\nArray of Characters..." << endl;
    for_each(begin(string_array), end(string_array), [](string z){cout << z << ", ";});
    cout << "\nThe largest character sequence: " << max_numbers(string_array, 5) << endl;
    
    return 0;
}