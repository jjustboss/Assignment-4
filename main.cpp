#include <iostream>
#include <stdlib.h>
#include "ACM.h"
#include "IEEE.h"
#include "algorithm"
using namespace std;

struct Course{
    string nameOfCourse;
    int numberOfStudents;
    string lecturer = "Palenshe Tugenshe";
};

template <class T>
class Student{
private:
    T nameOfStudent;
    T ID;
    T age;
    T Course;
    T Activity = "IEEE";
    friend ostream &operator<<( ostream &output, const Student<T> &student ) {
        cout << "Name" << "            " << "ID" << "            " << "Age" << "            " << "Courses" << "            " << "Activities" <<endl;
        cout << "--------------------------------------------------------------------------------------------------------" << endl;
        output << student.nameOfStudent <<"          "<<student.ID<<"          "<<student.age<<"            "<<student.Course<<"            "<<student.Activity<< endl;
        return output;
    }
    friend istream &operator>>( istream &input, Student<T> &student ) {
        input >> student.nameOfStudent >> student.ID >> student.age >> student.Course >> student.Activity;
        return input;
    }
    Student& operator=(const Student& other){
        if (this->nameOfStudent != other.nameOfStudent && this->Course!= other.Course && this->age != other.age &&
            this->ID!=other.ID && this->Activity!=other.Activity){
            this->nameOfStudent = other.nameOfStudent;
            this->Course = other.Course;
            this->age = other.age;
            this->ID = other.ID;
            this->Activity = other.Activity;
        }
    }

public:
    Student(T nameOfStudent, T ID, T age, T Course, T Activity): nameOfStudent(nameOfStudent), ID(ID), age(age), Course(Course),
                                                                 Activity(Activity){}
    Student(){}

    T getNameOfStudent() const {
        return nameOfStudent;
    }

    T getId() const {
        return ID;
    }

    T getAge() const {
        return age;
    }

    T getCourse() const {
        return Course;
    }

    T getActivity() const {
        return Activity;
    }

    void setNameOfStudent(T nameOfStudent) {
        Student::nameOfStudent = nameOfStudent;
    }

    void setId(T id) {
        ID = id;
    }

    void setAge(T age) {
        Student::age = age;
    }

    void setCourse(T course) {
        Course = course;
    }

    void setActivity(T activity) {
        Activity = activity;
    }

    bool operator==(const string other){
        return this->nameOfStudent==other;
    }
};

void setDefault(Student<string> &student){
    student.setActivity("?");
    student.setAge("?");
    student.setCourse("?");
    student.setId("?");
    student.setNameOfStudent("?");
}

bool isAdult(Student<string> student){return student.getAge() > "18";}

int main() {
    vector <Student<string>> student_objects[15];
    for (int i=0; i<6; i++) {
        student_objects->push_back(Student<string>("Bigali", "123123", "19", "Math", "IEEE"));
        student_objects->push_back(Student<string>("Baktybay", "123123", "20", "Math", "IEEE"));
    }

    cout <<"The number of adult students is: " << count_if(student_objects->begin(), student_objects->end(), isAdult);



    return 0;
}