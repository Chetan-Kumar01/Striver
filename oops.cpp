#include<iostream>
#include<string>
using namespace std;

class Teacher{
private:
    double salary;
public:
    // properties / attributes
    string name;
    string dept;
    string sub;

    // methods / member functions
    void changeDept(string newDept){
        dept = newDept;
    }

    void setSalary(double s){
        salary = s;
    }

    double getSalary(){
        return salary;
    }
};

class Student {
public:
    string name;

};

int main(){
// class.     Object
    Teacher t1;
    t1.name = "Shradha";
    t1.sub = "C++";
    t1.dept = "Computer Science";
    t1.setSalary(25000);

    cout<< t1.getSalary() << endl;
    return 0;
}