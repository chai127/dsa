#include <iostream>
#include <cmath>

using namespace std;

class Distance{
  int feet;
    float inches;
    public:
     Distance() {
        feet = 0;
        inches = 0;
    }
    Distance(float num){
        //converts float(num) to int 
        feet = static_cast<int>(num);
        inches = (num - feet) * 12;
    }

    Distance operator+(const Distance& other) {
       Distance result;
        result.inches = this->inches + other.inches;
        result.feet = this->feet + other.feet;
       if (result.inches >= 12) {
          result.feet += static_cast<int>(result.inches) / 12;
          //Returns floating point remainder
            result.inches = fmod(result.inches, 12);
        }
        return result;
    }

void display() const {
      cout << feet << " feet " << round(inches * 100) / 100 << " inches" << endl;
    }
   
    
};



int main(){
    float num1, num2;
    cout<<"Enter the distances in decimal format eg: (feet.inches)\n";
    cout<<"Enter first distance";
    cin>>num1;
    cout<<"Enter second distance";
    cin>>num2;
    
    Distance d1(num1);
    Distance d2(num2);
    Distance c;
    
    c =  d1+d2;  

    c.display();
   

    return 0;
}