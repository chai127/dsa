#include <iostream>
#include <vector>

class Account{
    private:
    int account_number= -1;
    double* balance = nullptr; // pointer points to nothing initially
    public:
    Account() {
    account_number = 0;
    balance = new double(0.0);
}
    
    Account(int a, double b){
        account_number = a;
        balance = new double(b);
    }
    Account(double b){
        balance = new double(b);
    }

    //copy constructor
    Account(const Account& other) {
    account_number = other.account_number;            // copy the int
    balance = new double(*other.balance);             // copy the VALUE of the pointer
    }


    // Copy assignment operator from gpt obv
    Account& operator=(const Account& other) {
    if (this != &other) {  // check for self-assignment
        account_number = other.account_number;

        delete balance;  // clean up old memory
        balance = new double(*other.balance);  // deep copy
    }
    return *this;  // return the current object
    }


    void print() const {
    std::cout << "Account #" << account_number
              << " | Balance: $" << *balance << std::endl;
    }

    void deposit(double amount) { 
        std::cout<<"\ndeposit\n";
        *balance += amount; }
    void withdraw(double amount) { 
        std::cout<<"\nwithdraw\n";
        if (amount <= *balance) *balance -= amount; }
    ~Account() {
    delete balance;
    }

};

int main() {

    //This means putting the object in the heap 
    Account* a = new Account(123, 1000.00); //instead of just Account a

    Account b(101, 500.0);
    Account c = b;  // invokes your copy constructor, a and c are independent
    
    *a = c;  // This is NOT the copy constructor! It’s assignment.

    b.print();
    c.print();
    a->print();

    a->deposit(250.00);     
    b.withdraw(100.00); 

    a->print();  
    b.print();  

    b.withdraw(500.00);

    b.print();
    delete a;
    // ❌ DON'T delete b or c — they clean up automatically when they go out of scope
    //ie- b and c are stack objects, cleaned up automatically when main() ends.
    return 0;
}

// * Overloading constructors
// * Dynamic memory allocation (`new`, `delete`)
// * Rule of Three (Destructor, Copy Constructor, Copy Assignment Operator)

// * Class `Account`: account number, balance
// * Overloaded constructors
// * Dynamically allocate accounts
// * Copy constructor and destructor

// 🎯 Understand deep vs. shallow copies and safe memory management.


// copy constructor a special constructor in C++ that runs when you create a new object as a copy of another.
//If you don’t write your own, C++ gives you a default copy constructor.
//This does a shallow copy — it just copies the pointer balance, not the value it points to.

//example:
// Account a(101, 500.0); // a.balance → 500.0
// Account b = a;         // b.balance → also points to a's 500.0
// // Later...
// delete a;  // deletes balance
// delete b;  // tries to delete the SAME balance → CRASH!

//theres also a rule of five!