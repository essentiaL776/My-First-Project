#ifndef STUDENT_H
#define STUDENT_H

#include "mylib.h"

class Student {
private:
    string firstName;
    string lastName;
    vector<int> grades;
    int finalExamGrade;
    double median, average;
public:
    Student(){
        firstName = "John";
        lastName = "Doe";
        finalExamGrade = 0;
        median = 0;
        average = 0;
    }
    //
    string getFirstName() {
        return firstName;
    }

    void setFirstName(string newfirstName) {
        firstName = newfirstName;
    }

    string getLastName() {
        return lastName;
    }

    void setLastName(string newlastName) {
        lastName = newlastName;
    }

    int getFinalExamGrade() {
        return finalExamGrade;
    }

    void setFinalExamGrade(int newfinalExamGrade) {
        finalExamGrade = newfinalExamGrade;
    }

    double getMedian() {
        return median;
    }

    void setMedian(double newMedian) {
        median = newMedian;
    }

    double getAverage() {
        return average;
    }

    void setAverage(double newAverage) {
        average = newAverage;
    }

    void addGrade(int grade) {
        grades.push_back(grade);
    }

    vector<int>& getGrades() {
        return grades;
    }

    ~Student() {grades.clear();}
};

#endif // STUDENT_H
