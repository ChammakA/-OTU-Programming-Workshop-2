#include <iostream>
#include <cstring>

using namespace std; //Calling libraries
/**
 * @Sammak Ahmed - 100747439
 * Lab 6: Virtual Functions
 * Creates two separate objects. One of parent class Cd and one of child class Classic. It then makes a pointer to those objects.
 * Using both the object and the pointer, the program will output the Performers, label, selections, and playtime both directly
 * and by using the pointer.
 * 
 */

class Cd // Creating Cd parent class
{
    private:
        const char * performers; 
        const char * label;
        int selections;
        double playtime;   //declaring private variables for Cd object
    public:
    Cd() //default constructor
    {
        performers = new char[8]; // initializing pointer to heap memory of size 8
        performers = {"Unknown"}; // declaring initital value

        this->label = new char[8];
        label = {"Unknown"}; // declaring initital value

        selections = 0; // declaring initital value
        playtime = 0.0; // declaring initital value

    };
    Cd(const char * performers, const char * label, int selections, double playtime) // parametrized constructor
    {
        this->performers = new char[strlen(performers) + 1]; // creating a pointer to heap memory of size of performers + 1
        this->performers = performers;

        this->label = new char[strlen(label) + 1];
        this->label = label; 

        this->selections  = selections;  
        this->playtime = playtime;
    };
    virtual void Report() //method that will display the result
    {
        cout << "Performer(s): " << performers << endl;
        cout << "Label: " << label << endl;
        cout << "Number of selections: " << selections << endl;
        cout << "Play time: " << playtime << endl;

    };
    ~Cd() // destructor to clear up the space created by the memory allocation above
    {
        delete[] performers;
        delete[] label;
        performers = nullptr;
        label = nullptr;
    };
};

class Classic: public Cd // child class Classic of parent class Cd
{
    private:
        const char * primaryWork; // private variable primaryWork for Classic
    public: 
        Classic() // default Constructor
        {
            primaryWork = new char[8]; // allocating memory of size 8 to the pointer
            primaryWork = {"Unknown"}; // delcaring initial value
        };
        Classic(const char * primaryWork, const char* performers, const char* labels, int selections, double playtime): Cd(performers,labels,selections,playtime)
                                        // Parameterized constructor that maps the constructor of parent class
        {
            this->primaryWork = new char[strlen(primaryWork) + 1]; // allocating memory of length of array + 1 and assigning pointer
            this->primaryWork = primaryWork; // declaring it's value
        };
        virtual void Report() // report method that outputs the result 
        {
            cout << "Primary work: " << primaryWork << endl;
            Cd::Report(); // calls the report function of parent class
        };
        ~Classic() // destructor that cleans up the memory that was allocateda above
        {
            delete[] primaryWork;
            primaryWork = nullptr;
        };
};

int main() // main method that creates the objects and calls functions to output result
{
    Cd c1("Beatles", "Capitol", 14, 35.5); //Creating c1 object of parent class Cd
    Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 52.17); ////Creating c2 object of child class Classic

    Cd * c; // creating a pointer of the parent class
    c = &c1; // having it point to the object's address

    cout << "\nUsing object directly:\n";
    cout << "***************************" << endl;

    c1.Report(); // calling report method using the object
    c2.Report();
    
    cout << "\nUsing type cd * pointer to objects:\n";
    cout << "****************************************" << endl;

    c->Report(); // using the pointer to get the object's result
    c = &c2;
    c->Report();

    return 0;
}