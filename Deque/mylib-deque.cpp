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
bool compareStudentsMED(const Student& studentA, const Student& studentB) {
    if(studentA.median <= studentB.median){
        return studentA.median > studentB.median;
    }
    return true;
}
bool compareStudentsAVG(const Student& studentA, const Student& studentB) {
    if(studentA.average <= studentB.average){
        return studentA.average > studentB.average;
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

