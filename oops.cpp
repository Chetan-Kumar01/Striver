#include<iostream>
#include<string>
using namespace std;

class Teacher{
private:
    double salary;
public:

    // Teacher(){ // called only at once during object creation.
    //     cout<<"Hi, i am a constructor\n";
    //     dept = "Computer Science\n";
    // }

    Teacher(Teacher &obj){ // pass by reference
        cout<<"I am copy constructor(custom)\n";
        this->name = obj.name;
        this->dept = obj.dept;
        this->sub = obj.sub;
        this->salary = obj.salary;
    }
    Teacher(string name, string dept, string sub, double salary){
        this->name = name;
        this->dept = dept;
        this->sub = sub;
        this->salary = salary;
    };
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

    // double getSalary(){
    //     return salary;
    // }

    void getInfo(){
        cout<<name<<endl;
        cout<<sub<<endl;
    }
};



int main(){
// class.     Object
    Teacher t1("Chetu", "CS", "C++", 25000);
//     t1.name = "Shradha";
//     t1.sub = "C++";
//    // t1.dept = "Computer Science";
//     t1.setSalary(25000);

//     //cout<< t1.getSalary() << endl;
//     cout<<t1.dept<<endl;
    //t1.getInfo();
    Teacher t2(t1); // default copy constructor invoked.
    t2.getInfo();

    return 0;
}


/*
Copy constructor - Special constructor used to copy properties of one object into another.
We can make a custom copy constructor also by using the class name.
*/
