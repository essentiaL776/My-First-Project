#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <random>

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

struct Student {
    string firstName;
    string lastName;
    vector<int> grades;
    int finalExamGrade;
};

#endif // MYLIB_H_INCLUDED
