#include "mylib.h"



double calculateAverage(Student* student){
    double sum = 0;
    for(int i = 0; i < student->numGrades; i++){
        sum += student->grades[i];
    }

    double average = sum / student->numGrades;

    return average;
}

double calculateMedian(Student& student){
    int* gradesCopy = new int[student.numGrades];
    for(int i = 0; i < student.numGrades; i++){
        gradesCopy[i] = student.grades[i];
    }

    sort(gradesCopy, gradesCopy + student.numGrades);
    double median = 0;
    if(student.numGrades % 2 != 0){
        median = (double)gradesCopy[student.numGrades / 2];
    }
    else{
        median = (double)(gradesCopy[(student.numGrades - 1) / 2] + gradesCopy[student.numGrades / 2]) / 2.0;
    }

    delete[] gradesCopy;

    return median;
}

void randomGradeGenerator(int number, Student& student){
    srand(time(NULL));
    student.grades = new int[number];
    student.numGrades = number;
    for(int i = 0; i < number; i++){
        student.grades[i] = rand() % 11;
    }
    student.finalExamGrade = rand() % 11;
}


int main() {
    Student* students = new Student[100];
    int numStudents = 0;
    string firstName, lastName;
    int grade, finalExamGrade;
    int option1;

    cout << "Enter the first and last name of the student (type 'done done' when finished):\n";
    try {
        while (cin >> firstName >> lastName) {
            if (firstName == "done" && lastName == "done") {
                break;
            }
            if (cin.fail()) {
                throw runtime_error("Invalid input");
            }
            Student temp = {firstName, lastName};
            cout<<"Do you want to enter grades manually?(y/n)";
            string input;
            cin>>input;
            if(input == "y"){
                cout << "Enter grades for " << temp.firstName << ' ' << temp.lastName << " (type '-1' when finished):\n";
                temp.grades = new int[100];
                temp.numGrades = 0;
                while (cin >> grade) {
                    if (grade == -1) {
                        break;
                    }
                    if (cin.fail()) {
                        throw runtime_error("Invalid input");
                    }
                    if(grade <= 10 && grade > 0){
                        temp.grades[temp.numGrades] = grade;
                        temp.numGrades++;
                    }
                    else{
                        cout<<"Grades can only be between 1 and 10. Try again: ";
                    }

                }
                cout << "Enter final exam grade for " << temp.firstName << ' ' << temp.lastName << ":\n";
                if (!(cin >> finalExamGrade)) {
                    throw runtime_error("Invalid input");
                }
                if(finalExamGrade <= 10 && finalExamGrade > 0){
                    temp.finalExamGrade = finalExamGrade;
                    students[numStudents] = temp;
                    numStudents++;
                    cout << "Enter the first and last name of the student (type 'done done' when finished):\n";
                }
                else{
                    cout<<"Final exam grade can only be between 1 and 10. Try again: "; cin >> finalExamGrade;
                    cout << "Enter the first and last name of the student (type 'done done' when finished):\n";
                }

            }
            else if(input == "n"){
                int number;
                srand(time(NULL));
                cout<<"How many grades do you want to generate?"; cin>>number;
                randomGradeGenerator(number,temp);
                students[numStudents] = temp;
                numStudents++;
                cout << "Enter the first and last name of the student (type 'done done' when finished):\n";
            }
            else{
                cout<<"Invalid input try again";
            }
        }

            }catch (const exception& e) {
                cerr << "Error: " << e.what() << endl;
                return 1;
            }

            int option;
            cout<<"1 for median and 2 for average\n";
            cin>> option;
            switch(option){
            case 1:{
                cout << fixed << setw(10) << "Name" << setw(20) << "LastName" << setw(20) << "Final (Med.)\n";
                cout << "----------------------------------------------------\n";
                for (int i = 0; i < numStudents; i++) {
                    cout << fixed << setw(10) << students[i].firstName << fixed << setw(20) << students[i].lastName;
                    cout << fixed << setw(20)  << setprecision(1) << calculateMedian(*students) << '\n';
                }
                break;
            }
            case 2:{
                cout << fixed << setw(10) << "Name" << setw(20) << "LastName" << setw(25) << "Final (Avg.)\n";
                cout << "----------------------------------------------------\n";
                for (int i = 0; i < numStudents; i++) {
                    cout << fixed << setw(10) << students[i].firstName << fixed << setw(20) << students[i].lastName;
                    cout << fixed << setw(20)<< setprecision(1) << calculateAverage(students) * 0.4 + students[i].finalExamGrade * 0.6 << '\n';
                }
                break;
            }
        }


    return 0;
}
