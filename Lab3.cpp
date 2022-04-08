#include<iostream>
#include<fstream>
#include<string>
using namespace std;

/**
 * Sammak Ahmed - 100747439
 * Lab 3 - String Searcher
 * Asks user for an input of a bit sequence. Program then reads through a file and identifies if the user input is in the "packets".
 * If the user input is in the packets, it will add that packet into an array heap. It will then output the array of packets
 * as well as the size of the array or the "total occurrence".
 */

class Bits // creating a class, Bits, with 2 private variables: sequence and packet as well as their respective getters and setters
{
    private:
        string sequence; 
        string packet;
    public:
        string getSequence()
        {
            return this->sequence;
        };
        string getPacket() 
        {
            return this->packet;
        };
        void setSequence(string s)
        {
            this->sequence = s;
        };
        void setPacket(string p)
        {
            this->packet = p;
        };
        Bits() //default constructor
        {
            this->packet = "";
            this->sequence = "";
        };

        void toString() // class function which outputs the sequence and packet
        {
            cout << sequence << ": " << packet << endl;
        };
        bool isEmpty() //class function which checks to see if the sequence or packet is empty
        {
            if (sequence == "" || packet == "")
            {
                return true;
            }
            return false;
        }
};

void toString(); //function declaration
bool isEmpty();
Bits getBitsObject(string word, string user_sequence);
Bits* resize(Bits* arr, int* size);
void display(Bits* arr, int size);


int main() //main function which prompts user for input, reads file, and checks to see if user input is in file and if so,
           // outputs an array of all the sequences that contained the user input.
{
    string user_sequence; // variable declaration
    string word;
    int size = 0;
    Bits* bitArr = new Bits[size];

    cout << "Enter a bit sequence (e.g. 1001): "; 
    cin >> user_sequence; //prompts user to input a bit sequence and stores it in user_sequence

    ifstream datafile;
    datafile.open("bits.txt"); //opens the file bits.txt

    while (!datafile.eof()) 
    {
        datafile >> word; //stores each line in word

        
        Bits bit = getBitsObject(word,user_sequence); //calls the getBitsObject function and stores that value in bit.
        
        if(!bit.isEmpty()) //checks to see if the bit value is empty.
        {   
            bitArr = resize(bitArr, &size); //calls the resize method and stores the new "bigger" array
            bitArr[size - 1] = bit; // adds the sequence into the array
            
        }
    }
    display(bitArr, size); //calls the display function to output the final result

    return 0;
}

Bits getBitsObject(string word, string user_sequence) //function checks to see if the user input is in "word" and also parses
                                                      // the string to get the sequence value and the packet. It then stores
                                                      //those values into a bit object.
{
    string delim = ","; //charcter used to parse
    size_t pos = 0;
    Bits bit;
    if (word.find(user_sequence) != string::npos)
    {
        while((pos = word.find(delim)) != string::npos) //looks for the pos of the delim
        {
            bit.setSequence(word.substr(0,pos)); //gets the string from beginning until delim and stores it in objects Sequence
            word.erase(0, pos + delim.length()); // erases everything before the delim
            bit.setPacket(word); // stores the rest of the string into objects Packet
        }
    }
    return bit;
}

Bits* resize(Bits* arr, int* size) //function which creates a new array 1 size bigger and copies the old array into the new array
                                   // It then deletes the old array and converts it into the bigger array.
{
    Bits* bitArr = new Bits[*size + 1];
    for (int i = 0; i < *size; i++)
    {
        bitArr[i] = arr[i];
    }
    delete []arr;
    arr = bitArr;
    *size += 1;
    return arr;
}

void display(Bits* arr, int size) //function which outputs the array of all the bits that contained the user input as well as
                                 // how many objects are in the array
{
    cout << "******************* Bit Sequences Found ****************************\n" << endl;

    for (int i = 0; i < size; i++)
    {
        arr[i].toString();
    }
    cout << "\nTotal Occurrences: " << size << endl;
    cout << "**************************************************************" << endl;
}