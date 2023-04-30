#include "mylib.h"

double calculateAverage(Student& student){
    double sum = 0;
    for(const auto& grade : student.getGrades()){
        sum += grade;
    }
    double average = sum / student.getGrades().size();
    return average;
}
double calculateMedian(Student& student){
    sort(student.getGrades().begin(),student.getGrades().end());
    if(student.getGrades().size() % 2 != 0){
        return (double)student.getGrades()[student.getGrades().size() / 2];
    }
    return (double)(student.getGrades()[(student.getGrades().size() - 1) / 2] + student.getGrades()[student.getGrades().size() / 2]) / 2.0;
}
void randomGradeGenerator(int number, Student& student){
    for(int i = 0; i < number; i++){
        int grade = rand() % 11;
        student.addGrade(grade);
    }
}
bool compareStudentsMED(Student& studentA, Student& studentB) {
    if (studentA.getMedian() <= studentB.getMedian()) {
        return studentA.getMedian() > studentB.getMedian();
    }
    return true;
}

bool compareStudentsAVG(Student& studentA, Student& studentB) {
    if (studentA.getAverage() <= studentB.getAverage()) {
        return studentA.getAverage() > studentB.getAverage();
    }
    return true;
}

void createFile(int fileSize, int gradeAmount){
    ofstream fg("students.txt");
    fg << "\n";
    for(int i = 0; i <= fileSize; i++){
        fg << "Name" << i <<" "<< "LastName" << i <<" ";
        for(int j = 0; j <= gradeAmount; j++){
            fg << rand() % 11 << " ";
        }
        fg<<"\n";
    }
}

