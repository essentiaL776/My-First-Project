#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <random>
#include <fstream>
#include <limits>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::fixed;
using std::setw;
using std::setprecision;
using std::string;
using std::vector;
using std::sort;
using std::accumulate;
using std::runtime_error;
using std::exception;
using std::cerr;
using std::ifstream;
using std::numeric_limits;
using std::streamsize;
using std::stringstream;
using std::ofstream;

struct Student {
    string firstName;
    string lastName;
    vector<int> grades;
    int finalExamGrade;
};

double calculateAverage(Student& student);
double calculateMedian(Student& student);
void randomGradeGenerator(int number, Student& student);
bool compareStudents(const Student& studentA, const Student& studentB);


#endif // MYLIB_H_INCLUDED
