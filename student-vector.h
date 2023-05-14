#ifndef STUDENT_H
#define STUDENT_H

#include "mylib.h"

class Person
{
protected:
    string firstName, lastName;
public:
    Person(string firstNames, string lastNames)
    {
        firstName = firstNames;
        lastName = lastNames;
    }
    Person()
    {
        firstName = "";
        lastName = "";
    }
    virtual string getFirstName() const = 0;

    ~Person() {
        firstName.clear();
        lastName.clear();
    }

};

class Student: public Person {
private:
    vector<int> grades;
    int finalExamGrade;
    double median, average;
public:
    Student() {
        firstName = "John";
        lastName = "Doe";
        finalExamGrade = 0;
        median = 0;
        average = 0;
    }
    Student(string firstNames, string lastNames, vector<int> gradess, int finalex, double med, double ave) : Person(firstNames, lastNames){
        firstName = firstNames ;
        lastName = lastNames  ;
        grades = gradess ;
        finalExamGrade = finalex ;
        median = med ;
        average = ave ;
    }
    friend std::ostream& operator<<(std::ostream &out, const Student &st){
            out<<left<<setw(15)<<st.firstName<<setw(20)<<st.lastName;
            for (const auto &j: st.grades)
                out << setw(5) << j << " ";
            out << setw(5) << st.finalExamGrade << " | "<<setw(3)<<fixed<<setprecision(2)<<st.median<<" / "<<st.average<<"\n";
            return out;
        }

    Student(const Student& other): Person(other.firstName, other.lastName) ,
        grades(other.grades), finalExamGrade(other.finalExamGrade),
        median(other.median), average(other.average) {}

    Student(Student&& other) : Person(std::move(other.firstName), std::move(other.lastName)), grades(std::move(other.grades)),
        finalExamGrade(std::move(other.finalExamGrade)), median(std::move(other.median)),
        average(std::move(other.average)) {}


    Student& operator=(const Student& other) {
        if (this != &other) {
            firstName = other.firstName;
            lastName = other.lastName;
            grades = other.grades;
            finalExamGrade = other.finalExamGrade;
            median = other.median;
            average = other.average;
        }
        return *this;
    }

    Student& operator=(Student&& other) {
        if (this != &other) {
            firstName = std::move(other.firstName);
            lastName = std::move(other.lastName);
            grades = std::move(other.grades);
            finalExamGrade = std::move(other.finalExamGrade);
            median = std::move(other.median);
            average = std::move(other.average);
        }
        return *this;
    }

    ~Student() {
        grades.clear();
    }

    string getFirstName() const {
        return firstName;
    }

    void setFirstName(string newfirstName) {
        firstName = std::move(newfirstName);
    }

    string getLastName() const {
        return lastName;
    }

    void setLastName(string newlastName) {
        lastName = std::move(newlastName);
    }

    int getFinalExamGrade() const {
        return finalExamGrade;
    }

    void setFinalExamGrade(int newfinalExamGrade) {
        finalExamGrade = newfinalExamGrade;
    }

    double getMedian() const {
        return median;
    }

    void setMedian(double newMedian) {
        median = newMedian;
    }

    double getAverage() const {
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
};


#endif // STUDENT_H
