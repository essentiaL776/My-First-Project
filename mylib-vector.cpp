#include "mylib.h"

double calculateAverage(Student& student){
    double sum = 0;
    for(const auto& grade : student.grades){
        sum += grade;
    }

    double average = sum / student.grades.size();

    return average;
}
double calculateMedian(Student& student){

    sort(student.grades.begin(),student.grades.end());
    if(student.grades.size() % 2 != 0){
        return (double)student.grades[student.grades.size() / 2];
    }
    return (double)(student.grades[(student.grades.size() - 1) / 2] + student.grades[student.grades.size() / 2]) / 2.0;

}
void randomGradeGenerator(int number, Student& student){
    for(int i = 0; i < number; i++){
        int grade = rand() % 11;
        student.grades.push_back(grade);
    }
}
bool compareStudents(const Student& studentA, const Student& studentB) {
    if (studentA.firstName == studentB.firstName) {
        return studentA.lastName < studentB.lastName;
    }
    return studentA.firstName < studentB.firstName;
}

