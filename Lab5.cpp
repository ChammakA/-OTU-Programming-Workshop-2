#include<iostream>
#include<vector>

using namespace std; // calling librarires

/**
 * @Sammak Ahmed - 100747439
 * Lab 5 - Inheritance and Polymorphism
 * Asks user for 10 inputs of a study level (undergraduate or graduate) and then makes an object of each input with a pointer to it.
 * It then uses the pointer to add those values to a separate vector and counts how many of each level occurred and outputs that.
 */

class Student // creating class Student
{
    protected:
        vector<string> levels; //creating 
    public:
        Student() // default constructor
        {
        };
        vector<string>& getStudyLevels() // gets the study level
        {   
            return this->levels;
            
        };
        void addToVector(string level) // adds the level(undergraduate or graduate) to list of levels
        {
            this->levels.push_back(level);
        };
        
};

class Undergraduate: public Student // creates a child class called Undergraduate which takes from parent class Student
{   
    public:
        Undergraduate() //default constructor
        {
              
        };
};

class Graduate: public Student // creates a child class called Graduate which takes from parent class Student
{
    public:
        Graduate() //default constructor
        {
            
        };
};

void assignStudents(vector<Student*>& v);
string askUser(string input); //initializing assignStudents and askUser function

int main() //main function
{   
    vector<Student*> v; //creates a vector for the pointers
    assignStudents(v); //calls the assignStudents function
    return 0;
}

string askUser(vector<Student*>& v) //asks user to input what study level 
{   
    string userInput;
    for (int i = 0; i < 10; i++) // makes an iteration to get the user input 10x
    {
        cout << "Enter a study level: (undergraduate or graduate) ";
        cin >> userInput; //asks user for study level then stores it in userInput

        if (userInput == "undergraduate") //if the user inputted "undergraduate"/"graduate", then makes an object of that class.
                                          // It then adds a pointer for that object and adds it to the list.
        {
            v.push_back(new Undergraduate());
            return userInput; // returns what the user inputted
        }
        else if (userInput == "graduate")
        {
            v.push_back(new Graduate());
            return userInput;
        }
        else //if the user did not input either "undergraduate" or "graduate", will keep asking until the user has inputted correctly
        {
            cout << "Please enter a valid input!" << endl; 
            if (i != 0)
            {
                i = i - 1;
            }
        }
    }
}
void assignStudents(vector<Student*>& v) // goes through every iteration in the pointer vector list and adds the values
                                         // to the list of levels in the Student class
{   
    for (int i = 0; i < 10; i++)
    {     
        v[i]->addToVector(askUser(v));
    }

    int underGrad = 0,grad = 0;
    string check;

    for (int j = 0; j < v.size(); j++) //iterates through each pointer and gets the study level in the list and then counts
                                       // how many of each level there was
    {   
        check = v[j]->getStudyLevels().at(0);
        if (check == "graduate")
        {
            grad++;
        }
        else{underGrad++;}
    }
    cout << "undergraduate: " << underGrad << endl;
    cout << "graduate: " << grad << endl; //outputs the results.

}