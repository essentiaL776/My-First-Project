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
    student.grades.sort();
    int size = student.grades.size();
    int median;

    if (size % 2 == 0)
    {
        auto it1 = student.grades.begin();
        advance(it1, size / 2 - 1);

        auto it2 = student.grades.begin();
        advance(it2, size / 2);

        return median = (*it1 + *it2) / 2;
    }
    else
    {
        auto it = student.grades.begin();
        advance(it, size / 2);

        return median = *it;
    }
}

void randomGradeGenerator(int number, Student& student){
    for(int i = 0; i < number; i++){
        int grade = rand() % 11;
        student.grades.push_back(grade);
    }
}
bool compareStudentsMED(const Student& studentA, const Student& studentB) {
    if(studentA.median <= studentB.median){
        return studentA.median < studentB.median;
    }
    return false;
}
bool compareStudentsAVG(const Student& studentA, const Student& studentB) {
    if(studentA.average <= studentB.average){
        return studentA.average < studentB.average;
    }
    return false;
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

