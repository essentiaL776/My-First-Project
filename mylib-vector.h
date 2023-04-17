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
#include <chrono>
#include <deque>
#include <list>

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
using std::deque;
using std::list;



struct Student {
    string firstName;
    string lastName;
    vector<int> grades;
    int finalExamGrade;
    double median, average;
};

class Timer {
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> start;
    public:
        Timer() : start{std::chrono::high_resolution_clock::now()} {}
        void reset() {
        start = std::chrono::high_resolution_clock::now();
        }
        double elapsed() const {
            return std::chrono::duration<double>
            (std::chrono::high_resolution_clock::now() - start).count();
    }
};

double calculateAverage(Student& student);
double calculateMedian(Student& student);
void randomGradeGenerator(int number, Student& student);
bool compareStudentsMED(const Student& studentA, const Student& studentB);
bool compareStudentsAVG(const Student& studentA, const Student& studentB);
void createFile(int fileSize, int gradeAmount);
void filterStudents(vector<Student>& students, vector<Student>& vargsiukai, bool sortByMedian);



#endif // MYLIB_H_INCLUDED
