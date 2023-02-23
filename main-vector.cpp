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

int main() {
    vector<Student> students;
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
                    Student student = {firstName, lastName};
                    cout<<"Do you want to enter grades manually?(y/n)";
                    string input;
                    cin>>input;
                    if(input == "y"){
                        cout << "Enter grades for " << student.firstName << ' ' << student.lastName << " (type '-1' when finished):\n";
                        while (cin >> grade) {
                            if (grade == -1) {
                                break;
                            }
                            if (cin.fail()) {
                                throw runtime_error("Invalid input");
                            }
                            if(grade <= 10 && grade > 0){
                               student.grades.push_back(grade);
                            }
                            else{
                                cout<<"Enter the number between 1 and 10. Try again: ";
                            }

                        }
                        cout << "Enter final exam grade for " << student.firstName << ' ' << student.lastName << ":\n";
                        if (!(cin >> finalExamGrade)) {
                            throw runtime_error("Invalid input");
                        }
                        if(finalExamGrade <= 10 && finalExamGrade > 0){
                            cout << "Enter the first and last name of the student (type 'done done' when finished):\n";
                            student.finalExamGrade = finalExamGrade;
                            students.push_back(student);
                        }
                        else{
                            cout<<"Final exam grade can only be between 1 and 10. Try again: "; cin >> finalExamGrade;
                            cout << "Enter the first and last name of the student (type 'done done' when finished):\n";
                        }
                    }
                    if(input == "n"){
                        int number;
                        srand(time(NULL));
                        cout<<"How many grades do you want to generate?"; cin>>number;
                        randomGradeGenerator(number,student);
                        students.push_back(student);
                        cout << "Enter the first and last name of the student (type 'done done' when finished):\n";
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
                    cout<<"----------------------------------------------------\n";
                    for (auto& student : students) {
                        cout << fixed << setw(10) << student.firstName << setw(20) << student.lastName;
                        cout << fixed << setw(20) << setprecision(1)<< calculateMedian(student) << '\n';
                }
                    break;
                }
                case 2:{
                    cout << fixed << setw(10) << "Name" << setw(20) << "LastName" << setw(25) << "Final (Avg.)\n";
                    cout<<"----------------------------------------------------\n";
                    for (auto& student : students) {
                        cout << fixed << setw(10) << student.firstName << setw(20) << student.lastName;
                        cout << fixed << setw(20) << setprecision(1)<< calculateAverage(student)*0.4+student.finalExamGrade*0.6 << '\n';
                    }
                    break;
                }
                default:
                    cout<<"Invalid input";
                    break;
            }

    return 0;
}


