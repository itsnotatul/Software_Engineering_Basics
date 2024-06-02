#include <iostream>
#include <string>
#include<memory>
using namespace std;

class Student
{
private:
 int rollNo;
 int age;
 string name;
public:
    Student(){cout<<"Student object CREATED"<<endl;}
    ~Student(){cout<<"Student object DESTROYED"<<endl;}
    Student(const Student& _student):rollNo(_student.rollNo),age(_student.age),name(_student.name){cout<<"COPY CONSTRUCTOR"<<endl;}
    void setRollNo(int rollNo){ this->rollNo = rollNo;}
    void setAge(int Age){ this->age = Age;}
    void setName(string Name){ this->name = Name;}
    int getRollNo(){ return rollNo;}
    int getAge(){return age;}
    string getName(){return name;}
    void printDetails(){cout<<rollNo<<" "<<age<<" "<<name<<endl;}
};

void funByValue(Student _student ){
    _student.setAge(15); _student.setName("SACHIN"); _student.setRollNo(22);
    _student.printDetails();

}

void funByReference(Student& _student){
    _student.setAge(11); _student.setName("ATUL"); _student.setRollNo(43);
    _student.printDetails();
}

void funByPointer(Student* _student){
    _student = new Student();
    _student->setAge(12); _student->setName("ATUL"); _student->setRollNo(44);
    _student->printDetails();
    delete _student;
}

void funByDoublePointer(Student** _student){
    (*_student) = new Student();
    (*_student)->setAge(13); (*_student)->setName("ATUL"); (*_student)->setRollNo(45);
    (*_student)->printDetails();
}

void funByPointerAndReference(Student* & _student){
    _student = new Student();
    _student->setAge(14); _student->setName("ATUL"); _student->setRollNo(46);
    _student->printDetails();
}

int main(){
    

    Student* stu2 = nullptr;

    // ## THIS WILL NOT WORK FOR NULLPTR
    // cout<<"#################"<<endl;
    // funByValue(*stu1);
    // stu1->printDetails();

    // ## THIS WILL NOT WORK FOR NULLPTR
    // cout<<"#################"<<endl;
    // funByReference(*stu2);
    // stu2->printDetails();

 
    cout<<"#################"<<endl;
    funByPointer(stu2);
    if(stu2)
        stu2->printDetails();
    else cout<<"nullptr"<<endl;


    cout<<"#################"<<endl;
    funByDoublePointer(&stu2);
    if(stu2)
       { 
            stu2->printDetails();
            delete stu2;
            stu2 = nullptr;
       }
    else cout<<"nullptr"<<endl;

    cout<<"#################"<<endl;
    funByPointerAndReference(stu2);
     if(stu2)
       { 
            stu2->printDetails();
            delete stu2;
            stu2 = nullptr;
       }
    else cout<<"nullptr"<<endl;

    if(stu2 !=nullptr)
        delete (stu2);
    return 0;
}



