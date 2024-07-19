#include<iostream>
#include<string>
using namespace std;

class Student{
private:
string* name;
int* age;
public:

Student(){      //default constructor
   cout<< "Default Constructor called"<<endl;
   name = new string;
   *name = "Student";
   age = new int;
   *age = 00;
}
 Student(string sname, int sage){     // parameterized constructor
    cout<<"Paramertised constructor called"<< endl;
    name = new string;
    age = new int;
    *name = sname;
    *age = sage;
 };

 Student(Student& t){       // copy constructor
    cout<<"Copy constructor called"<< endl;
    age = new int;
    name = new string;
    *name = *t.name;
    *age = *t.age;
 };

 Student(Student&& other) noexcept{   //move constructor
   cout<<"Move constructor called"<< endl;
   age = other.age;
   name = other.name;
   other.name = nullptr;
   other.age = nullptr;
   }

   ~Student(){
      delete name;
      delete age;
   }


 void display(){
    cout<<"This is the object of "<< *name << " whose age is "<< *age<<endl;
 }
};

int main(){
    Student s("Abhinav Choudhary",19),s2("ajay",20),s3;
    Student ajay(s2);
    s.display(); // calling parameterized constructor
    ajay.display(); // calling copy constructor
    s3.display(); // calling default constructor
    Student newS(move(s));
    newS.display();

}