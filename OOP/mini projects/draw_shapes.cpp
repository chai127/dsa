#include <iostream>
#include <vector>
#include <cmath>

class Shape{
    public:
    Shape(){
        std::cout<<"getting pen readyy ...\n";
       
    }

    virtual void getNum() = 0;  // pure virtual
    virtual void draw() = 0;    // pure virtual

    
};

class Circle: public Shape{
    int radius;
    public:
    void getNum() override{
        std::cout<<"\nFor circle\n";
        std::cout<<"enter radius: ";
        std::cin>>radius;
    }
    void draw() override{
        //got this from gpt as the one i made was more like a diamond than a circle
   float aspect_ratio = 1.0; // Adjusts for terminal character proportions

    for (int y = radius; y >= -radius; y--) {
        for (int x = -radius; x <= radius; x++) {
            float dist = std::sqrt((x * aspect_ratio) * (x * aspect_ratio) + y * y);
            if (dist > radius - 0.5 && dist < radius + 0.5) {
                std::cout << "+++"; // Edge of circle
            } else {
                std::cout << "   "; // Empty space
            }
        }
        std::cout << "\n";
    }
}

};

class Rectangle: public Shape{
    int breadth, length;
    public:
    void getNum() override{
        std::cout<<"\nFor rectangle\n";
        std::cout<<"enter length: ";
        std::cin>>length;
    
        std::cout<<"enter breadth: ";
        std::cin>>breadth;
    }

    void draw() override{
        //first row
        for(int i = 0; i< length; i++){
            std::cout<<"+++";
        }
        std::cout<<"\n";
        //mid section
        for(int j = 0; j< breadth-2; j++){
            std::cout<<"+++";

            for(int i = 0; i< length-2; i++){
                std::cout<<"   ";
            }
            std::cout<<"+++";
            std::cout<<"\n";
        }
        //last row
        for(int i = 0; i< length; i++){
            std::cout<<"+++";
        }
    }
};

class Triangle: public Shape{
    int height;
    public:
    void getNum() override{
        std::cout<<"\nFor isoceles triangle\n";
        std::cout<<"enter height: ";
        std::cin>>height;
    }
    void draw() override{
        //full pyramid code
    for(int i = 0; i<height;i++){
        for(int k = height-i; k > 0;k--){
            printf(" ");
        }
        for(int j=0; j<=i;j++){
            printf("*");
        }
         for(int j=0; j<=i-1;j++){
            printf("*");
        }
            printf("\n");
    }}

};

int main() {
    // Shape s1; cannot intialize abstract class
    Circle c;
    Rectangle r;
    Triangle t;
    Shape *i_point_circle = &c;
    Shape *i_point_rectangle = &r;
    Shape *i_point_triangle = &t;

    i_point_circle -> getNum();
    i_point_circle -> draw();

    i_point_rectangle -> getNum();
    i_point_rectangle -> draw();

    i_point_triangle -> getNum();
    i_point_triangle-> draw();

    return 0;
}

// * Inheritance (`public`, `private`)
// * Virtual Functions
// * Abstract Classes
// * Function Overriding
// * Polymorphism (base class pointer → derived class object)
