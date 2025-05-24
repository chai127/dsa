// we cannot initialize the static data member inside the
// class due to class rules and the fact that we cannot
// assign it a value using constructor

#include<iostream>

using namespace std;

class A{
   protected:
    static int count; // Shared across all A objects 
    //No matter how many objects you create, they all access the same count.
//If one object changes count, all others see the change immediately.
public:
        A() { count++; }
    static int getCount() { return count; } //You can call it without creating an object of the class.

};
int A::count = 0; //static, intialized outside the class


int main(){
     A a1, a2, a3;
    cout << "Number of A instances: " << A::getCount() << endl;
    return 0;

    return 0;
}