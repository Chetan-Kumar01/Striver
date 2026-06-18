#include<iostream>
#include<string>
using namespace std;

class Student{
public:
    string name;
    double* cgpaPtr;

    //constructor
    Student(string name, double cgpa){
        this->name = name;
        cgpaPtr = new double;
        *cgpaPtr = cgpa;
    }

    // destructor
    ~Student(){
        cout<<"Hi, i delete everything\n";
        delete cgpaPtr; // memory leak.
    }
    void getInfo(){
        cout<<name<<endl;
        cout<<*cgpaPtr<<endl;
    }
};

int main(){
    Student s1("Chetu", 8.9);
    s1.getInfo();
    return 0;
}