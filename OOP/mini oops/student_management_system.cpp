#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;



class Student{
    string name;
    int id;
    int totalSubjects = 3;
    vector<float> marks;
    public:

    Student(){
        
        cout<<"Enter Student Name: ";
        getline(cin, name); //cin>>name doesnt handle spaces
        cout<<"Enter Student Id: ";
        cin>>id;
        for(int i = 0; i < totalSubjects; i++)
        {   float mark;
            cout<<"Enter Student Marks for subject "<<i+1<<" : ";
            cin>>mark;
            marks.push_back(mark);}
            cin.ignore();
    }

    //only const functions can be called inside a const fnction!!!
    string grade() const{
        float sum = 0;
        for(int i = 0; i < totalSubjects; i++){
            sum += marks[i];
        }
        if(sum > (totalSubjects*100)/2)
        return "Pass"; 
        else{
            return "Fail";
        }
    }

    void printDetails() const {
        cout << "Student Name: " << name << "\n";
        cout << "Student Id: " << id << "\n";
        cout << "Student Grade: " << grade() << "\n";
    }


   friend class StudentManager;
};

class StudentManager {
private:
    vector<Student> students;

public:
    void enterDetails() {
        int n;
        cout << "Enter number of students: ";
        cin >> n;
        cin.ignore();// clear input buffer before getline
        //since i use cin so it will create a newline and the constructor has getline, which will cause an error
        for (int i = 0; i < n; i++) {
            cout << "\nEntering details for student " << (i + 1) << ":\n";
            students.push_back(Student());
        }
        //function to sort students according to their ids
        sortStudents();
    }

    void sortStudents() {
        //used gpt for whole sort is in algorithm  [] is a lambda comparison function
        //It compares two Student objects, a and b, based on their id field. its necessary other wise we need to over load < operato even for ascending 
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.id < b.id; // Sort by id in ascending order
    });
    }

    void getStudentDetails() const{
        cout<<"Enter Student Id: ";
        int id;
        cin>>id;
        int studentsLength = students.size();
        for (int i = 0; i < studentsLength; i++) {
            if (students[i].id == id){
                students[i].printDetails();
                cout<<"\n";
                return;
            }
        }
         cout << "Student with Id " << id << " not found.\n";

    }
    void removeStudentById() {
        cout<<"Enter Student Id: ";
        int id;
        cin>>id;
        int studentsLength = students.size();
         for (int i = 0; i < studentsLength; i++) {
           if (students[i].id == id){
            students.erase(students.begin() + i); // .begin() is the first
            //pop back removes the last
            cout << "Student with Id " << id << " has been removed.\n";
                 return;
            }
        }
         cout << "Student with Id " << id << " not found.\n";
    }

    void displayAll(){
        int studentsLength = students.size();
        for (int i = 0; i < studentsLength; i++) {
            cout<<"Details of Student "<<i+1<<"\n";
            students[i].printDetails();
            cout<<"\n";
        }
    }
   
};

int main(){
    StudentManager manager;
int choice;
while(true){
cout << "Enter \n"
     << "1- To enter Student details \n"
     << "2- To get Student details \n"
     << "3 - To remove a Student \n"
     << "4 - To display all Students detials \n"
     << "5- Exit Program \n";
cin >> choice;
cin.ignore();

switch(choice) {
    case 1: manager.enterDetails(); break;
    case 2: manager.getStudentDetails(); break;
    case 3: manager.removeStudentById(); break;
    case 4: manager.displayAll(); break;
    case 5: cout << "Exiting...\n"; return 0;
    default: cout << "Invalid input\n"; break;
}

}

    return 0;
}



//if same id, then also i have to handle that error
//if some error then there should be an undo function,,, maybe it will work only when program takes details of a single student at once

