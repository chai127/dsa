# Classes

---

## Classes
Classes are a user-defined data type.  
They consist of **data members** (variables) and **member functions** (methods) that operate on those data members.



## Access Specifiers
| Specifier   | Access Level                                                    |
| ----------- | --------------------------------------------------------------- |
| `private`   | Accessible **only within the same class**                       |
| `protected` | Accessible in **same class + derived classes** (NOT by objects) |
| `public`    | Accessible **from anywhere**, including by objects              |



## Objects
An object is an **instance** of a class.  
It represents a concrete implementation of the class blueprint.

---

## Abstraction
Only essential information is shown to the user; implementation details are hidden.  
**Example**: A car driver knows how to drive (interface), not how the engine works (implementation).



## Encapsulation
Wrapping data and methods into a single unit (class) and **restricting access** to some components using access specifiers.  
Helps enforce **data hiding**.



## Polymorphism
"Many forms" – the ability of functions or objects to behave differently in different contexts.  
Includes:
- **Compile-time polymorphism** (function overloading, operator overloading)
- **Run-time polymorphism** (via `virtual` functions and inheritance)



## Inheritance 
- (Base class constructor is called before derived class constructor.)
### Types of Inheritance (C++)

- Single Inheritance  
- Multiple Inheritance  
- Multilevel Inheritance  
- Hierarchical Inheritance  
- Hybrid Inheritance  

---

## Copy Constructor 
- **Copy Constructor**: A copy constructor is a special constructor used to create a new object as a copy of an existing object.
```cpp
ClassName(const ClassName& other);
```
- It’s called when:
- You initialize a new object with an existing object, e.g., ClassName obj2 = obj1;
- You pass an object by value to a function.
- A function returns an object by value.



## Static Members
- **Shared across all objects** of the class.
- **Static data members** retain their value between instances.
- **Static member functions**:
  - Can only access static data members.
  - Cannot access non-static (instance) members.
  - Can be accessed using `ClassName::functionName()` (no object needed).



## Friend
- A `friend` allows another class or function to access its private and protected members.
- **Not mutual** — if class A declares B as a friend, B can access A's members, but not the other way around.
- Friendship breaks encapsulation but is sometimes necessary (e.g., operator overloading).



## Virtual Destructors
- When using inheritance and polymorphism, base classes should declare destructors as `virtual`.
- Ensures derived class destructors are called properly during object destruction via base pointers.



## Abstract Classes & Pure Virtual Functions
- Abstract class contains at least one pure virtual function (`virtual void func() = 0;`).
- Cannot instantiate abstract classes directly.
- Used to define interfaces that derived classes must implement.

---

## Operator Overloading
- Allows customizing behavior of operators (`+`, `=`, `<<`, etc.) for user-defined types.
- Often used with friend functions to access private members.

---

## this Pointer
- The `this` pointer is an **implicit pointer** passed to all **non-static member functions** of a class.
- It points to the **current object** calling the member function.
- Used to resolve ambiguity between **member variables** and **function parameters**.
- Can be used for **method chaining** by returning `*this`.
### Example:

```cpp
class MyClass {
    int x;
public:
    MyClass(int x) {
        this->x = x;  // Resolving ambiguity
    }

    MyClass& setX(int val) {
        this->x = val;
        return *this;  // Enables method chaining
    }
};
```
---

## Virtual
- Enables **run-time polymorphism** (dynamic dispatch).
- Declaring a base class function as `virtual` allows derived classes to **override** it.
- When a base class pointer or reference is used, the **derived class’s version** is called at runtime if it exists.

```cpp
Base* b = new Derived(); // 'new' allocates memory dynamically
b->show();               // Calls Derived::show() if show() is virtual

MyClass* obj = new MyClass();  // Constructor is called
delete obj;                    // Destructor is called
```
## Diamond Problem in C++

- The **diamond problem** occurs in **multiple inheritance** when two classes inherit from the same base class, and a fourth class inherits from both of them.
- This creates **ambiguity**, as the derived-most class ends up with **two copies** of the base class members.

### Problem Diagram:
```
  A
 / \
B   C
 \ /
  D
```
- Class `D` inherits from both `B` and `C`, which both inherit from `A`.
- Without precautions, class `D` will have **two copies** of class `A`, causing ambiguity.

### Problem Example (Without Virtual Inheritance):

```cpp
class A {
public:
    void display() { cout << "A"; }
};

class B : public A { };
class C : public A { };

class D : public B, public C { };

int main() {
    D obj;
    // obj.display();  // ❌ Error: Ambiguous – compiler doesn't know whether to call B::A::display or C::A::display
}
```
- solved
```cpp

class A {
public:
    void display() { cout << "A"; }
};

class B : virtual public A { };
class C : virtual public A { };

class D : public B, public C { };

int main() {
    D obj;
    obj.display();  // ✅ No ambiguity – only one A Derived class has one shared copy of the base
}

```