#include <iostream>
#include <string>
using namespace std;

class Employee {
    // base class
    protected:
    string name;
    int id;
    float salary;
    public:
    Employee() {
    name = "";
    id = 0;
    salary = 0.0;
    }
    Employee(string n){
        name = n;
    }
    Employee(string n, int i){
        name = n;
        id = i;
    }
    Employee(string n, int i, float s){
        name = n;
        id = i;
        salary = s;
    }

   virtual void displayDetails(){
        cout<<"\nEmployee Name: "<<name;
        cout<<"\nEmployee Id: "<<id;
        cout<<"\nEmployee Salary: "<<salary;
    }
};

class Manager : public Employee {
    // derived from Employee
    public: 
    string teamName;
    //intitailizer list the part (: Employee(etc))
    Manager(string n, int i = 0, float s = 0.0, string t = "") //constructor with default arguments
        : Employee(n, i, s) // call the base constructor
    {
        teamName = t;
    }
    //best practice to mention override
    void displayDetails()  override{
        cout<<"\n\nEmployee Name: "<<name;
        cout<<"\nEmployee Id: "<<id;
        cout<<"\nEmployee Salary: "<<salary;
        cout<<"\nEmployee Team: "<<teamName;
    }


};

class Developer : public Employee {
    public:
    string role;
    Developer(string n, int i = 0, float s = 0.0, string r = "") 
        : Employee(n, i, s) 
    {
        role = r;
    }
    void displayDetails()  override{
        cout<<"\n\nEmployee Name: "<<name;
        cout<<"\nEmployee Id: "<<id;
        cout<<"\nEmployee Salary: "<<salary;
        cout<<"\nEmployee Role: "<<role;
    }
};

int main() {

    Manager mgr("A", 101, 95000, "Sales");
Developer dev("B", 102, 160000, "Backend Developer");

    Employee* empPtr1 = &mgr;
    Employee* empPtr2 = &dev;
    empPtr1->displayDetails();  // calls Manager ()
    empPtr2->displayDetails(); // calls Developer ()

// Or using references:

Employee& empRef1 = mgr;
Employee& empRef2 = dev;

empRef1.displayDetails();  
empRef2.displayDetails();

    return 0;
}


// // Virtual functions cannot be static.
// Virtual functions should be accessed using a pointer or reference of base class type to achieve runtime polymorphism.
// A class may have a virtual destructor, but it cannot have a virtual constructor.