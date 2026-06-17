#include<iostream>
#include<string>
using namespace std;

// class Student{
//     public:
//     string name;
//     double* cgpaPtr;

//     Student(string name, double cgpa){
//         this -> name = name;
//         cgpaPtr = new double;
//         *cgpaPtr = cgpa;
//     }
       
    //    Student(Student &obj){ // copy constructor
    //     this->name = obj.name;
    //     this->cgpaPtr = obj.cgpaPtr;
    //    }
//     void getInfo(){
//         cout<<name<<endl;
//         cout<<*cgpaPtr<<endl;
//     }
// };

// int main(){
//     Student s1("rahul", 8.8);
//     s1.getInfo();

//     Student s2(s1);
//     *(s2.cgpaPtr) = 9.2;
//     s1.getInfo(); // here we change the cgpea in s2 but it gets reflected in s1 also due to limitation of shallow
//     return 0;
// }





///////////////////////////////////////////////////////////
// how deep copy handles this problem.
class Student{
    public:
    string name;
    double *cgpaPtr;

    Student(string name, double cgpa){
        this -> name = name;
        cgpaPtr = new double;
        *cgpaPtr = cgpa;
    }

    Student(Student &obj){ // deep copy
        this -> name = obj.name;
        cgpaPtr = new double;
        *cgpaPtr = *obj.cgpaPtr;
    }

    void getInfo(){
        cout<<name<<endl;
        cout<<*cgpaPtr<<endl;
    }
};

int main(){
        Student s1("rahul", 8.8);

        Student s2(s1);
        *(s2.cgpaPtr) = 9.2;
        s2.name = "neha";
        s1.getInfo();
        s2.getInfo();
        return 0;
    }