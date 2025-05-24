#include <iostream>
using namespace std;

class Time {
    int hours, min, sec;

public:
    Time(){
        hours = 0;
        min = 0;
        sec = 0;
    }

    Time(int h){
        hours = h;
        min = 0;
        sec = 0;
    }

    Time(int h, int m){
        hours = h;
        min = m;
        sec = 0;
    }

    Time(int h, int m, int s){
        hours = h;
        min = m;
        sec = s;
    }

    void print() {
        //format 00:00:00
        cout <<"Time is: ";
        cout << (hours < 10 ? "0" : "" )<<hours<< ":"
             <<(min < 10 ? "0" : "" )<<min<<":"
             <<(sec < 10 ? "0" : "" )<<sec<<endl;
    }
};

int main() {
    Time t1;            
    Time t2(10);        
    Time t3(23, 20);   
    Time t4(23, 43, 55);

    t1.print();
    t2.print();
    t3.print();
    t4.print();

    return 0;
}
