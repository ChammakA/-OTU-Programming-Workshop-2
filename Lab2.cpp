#include<iostream>
#include<fstream>
#include<string>
#include <vector>
using namespace std; // Calling libraries and namespace

/**
 * Sammak Ahmed - 100747439
 * Lab 2 - Word Counter
 * Reads through a text file and records each unique word and how many times that word occurs in the text
 */

class WordCounter //creating a class WordCounter which has 2 private variables: word and count. Also has getters and setters for those variables
                  // as well as a constructor
{
    private: 
        string word;
        int count;
    public:
        string getWord()
        {
            return this->word;
        };
        int getCount()
        {
            return this->count;
        };
        void setWord(string s)
        {
            this->word = s;
        };
        void setCount(int n)
        {
            this->count = n;
        };
        WordCounter(string s, int n)
        {
            this->word = s;
            this->count = n;
        };
};

bool isFound(vector<WordCounter> &v, string word);
void incrementWordCount(vector<WordCounter> &v, int i);
void printReport(vector<WordCounter> &v); //declaring these functions

int main() //main function which opens the file and records each unique word and its occurrence and then outputs it
{
    string text;
    vector<WordCounter> word; // declaring the variables

    ifstream datafile;
    datafile.open("data-1.txt"); //opening the text file

    while (!datafile.eof()) // iterates through each "word" in the file. A word is a mix of symbols/letters that are separated by a space
    {
        datafile >> text; 
        
        if (!isFound(word, text)) //if the word isn't found then it will add the word to the list of unique words and start it with a count of 1
        {
            word.push_back(WordCounter(text,1));
        }
        else // if the word is found then it'll call the incrementWordCount function and increase it's count by 1.
        {
            for (int i = 0; i < word.size(); i++)
            {
                if (word[i].getWord() == text) //looks for where the word is located in the vector list
                {
                    incrementWordCount(word, i); //calls the incrementWordCount function and sends it the vector as well as the words location
                }
            }
        }
    }
    printReport(word); //output statement which declares the unique words as well as how many times they occurred

    datafile.close();
    return 0;
}

bool isFound(vector<WordCounter> &v, string word) //This function iterates through the vector to see if the word is in the list or not
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].getWord() == word) // if the word is in the list, it'll return true, else false
        {
            return true;
        }
    }
    return false;
}

void incrementWordCount(vector<WordCounter> &v, int i) // this function will increase the count of the word by 1
{
    int temp = v[i].getCount() + 1;
    v[i].setCount(temp);
}

void printReport(vector<WordCounter> &v) // goes through the vector and outputs the unique words and how many times they occurred
{
    for (int i = 0; i < v.size();i++)
    {
        cout << v[i].getWord() << ": " << v[i].getCount() << endl;
    }
}