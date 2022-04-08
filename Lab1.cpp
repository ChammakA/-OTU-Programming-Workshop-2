/**
 * @file Lab1.cpp
 * @author Sammak Ahmed - 100747439
 * @brief First Programming Workshop lab. Read file and record all the unique words and how many times they occur.
 * @version 0.1
 * @date 2022-01-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
//calling libraries

bool isFound(vector<string> v, string word);
void printReport(vector<string> words, vector<int> counts); //declaring methods


int main() //main method that opens a file and stores each unique word in a vector as well as count how many times a word occurs in the file
{
    string word;
    int temp = 0;
    vector<int> count;
    vector<string> words; //declaring different variables

    ifstream datafile;
    datafile.open("data.txt"); // opening the file "data.txt"

    while (!datafile.eof()) //iterates through each word in the file. a "word" is any mix of characters separated by a space.
    {
        datafile >> word; // stores the current word into a string

        if (words.size() == 0) //the initial value is stored into the vector of strings and also adds a counter for that word
        {
            words.push_back(word);
            count.push_back(0);
        }
        if (!isFound(words, word)) //if the current word isn't found, it will add it to the list of words and it's counter
        {
            words.push_back(word);
            count.push_back(1);
        }
        else // if the word IS found, it will iterate through the list of words until it finds that word and increase its counter by 1
        {
            for (int j = 0; j < words.size(); j++)
            {
                if (words[j] == word)
                {
                    count[j]++;
                }
            }
        }    
    }
    printReport(words, count); //calls the printReport to display the output

    datafile.close(); //closes the file
    return 0;
}

bool isFound(vector<string> v, string word) //method that iterates through the string vector to see if the word is currently in the list.
                                            //If so, return true. ELse, false.
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == word)
        {
            return true;
        }
    }
    return false;
}

void printReport(vector<string> words, vector<int> counts) //method that will iterate through each word in the string vector and output
                                                           // the unique word as well as how many times it occurred in the file
{
    for (int i = 0; i < words.size(); i++)
    {
        cout << words[i] << ": " << counts[i] << endl;
    }
}