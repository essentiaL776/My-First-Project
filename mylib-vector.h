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
#include <utility>

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
using std::left;

#include "student.h"

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
bool compareStudentsMED( Student& studentA,  Student& studentB);
bool compareStudentsAVG( Student& studentA,  Student& studentB);
void createFile(int fileSize, int gradeAmount);




#endif // MYLIB_H_INCLUDED
