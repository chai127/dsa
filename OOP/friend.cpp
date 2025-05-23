// A friend function can be declared in any section of the class i.e. public or private or protected.
// A friend class can access private and protected members of other classes in which it is declared as a friend.

#include<iostream>

using namespace std;

class A{
    private:
    int a = 12;

    protected:
    int c = 31;

    public:
    int b = 21; 

    friend class B;  // B can access all members of A
};

class B {
public:
//since objects contain a lot of data we pass their reference
// and also to avoid copying and const is to ensure the object is not modified
    void show(const A& obj) {
        cout << obj.a << ", " << obj.b << ", " << obj.c << endl;
    }
};

class C; //forward declaration of c

class D {
public:
    void accessC(const C& c);
};

class C {
private:
    int secret = 99;
    friend void D::accessC(const C& c);  // Only this function is a friend
};

void D::accessC(const C& c) {
    cout << "Accessing C's secret: " << c.secret << endl;
}



int main(){

    A obj;
    B b;
    b.show(obj);

    D obj2;
    C obj1;
    obj2.accessC(obj1);

    return 0;
}



// Friendship is not inheritance. 
// Inheritance means one class extends or specializes another (like a Dog inheriting from Animal). Friendship is just access permission

// | Feature              | Friend Classes      | Inherited Classes         |
// | -------------------- | ------------------- | ------------------------- |
// | Share members?       | ❌ No                | ✅ Yes (inherited)         |
// | Same type?           | ❌ No                | ✅ Yes (child is-a parent) |
// | Share memory layout? | ❌ No                | ✅ Partially shared        |
// | Can access privates? | ✅ Yes (with friend) | ✅ Yes (if `protected`)    |
// | Polymorphic?         | ❌ No                | ✅ Yes                     |


//
// class A {
//     friend class B;
//     void foo() { cout << "A's foo\n"; }
// };

// class B {
// public:
//     void foo() { cout << "B's foo\n"; }
//     void accessA(A& a) {
//         a.foo();  // Can call private foo() because B is friend of A
//     }
// };

// A a;
// B b;
// b.foo();       // Calls B's foo()
// b.accessA(a);  // Calls A's foo()
