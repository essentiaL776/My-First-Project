#include "mylib.h"

int main() {
    ifstream fd("studentai.txt");
    ofstream fr("Rez.txt");
    vector<Student> students;
    string firstName, lastName, line;
    int grade, finalExamGrade;
    int option3;
    cout<<"If you want to read from a file type 2 or type 1 if you want to do it manually: ";
    cin>>option3;
    switch(option3){
        case 1:
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
                break;
        case 2:
            string header;
            getline(fd, header);

            while (getline(fd, line)) {
                stringstream ss(line);
                ss >> firstName >> lastName;
                Student student;
                student.firstName = firstName;
                student.lastName = lastName;

                int grade;
                while (ss >> grade) {
                    student.grades.push_back(grade);
                }

                student.finalExamGrade = grade;
                student.grades.pop_back();
                students.push_back(student);
            }
            break;
    }
            sort(students.begin(), students.end(), compareStudents);
            fr << fixed << setw(10) << "Name" << setw(20) << "LastName" << setw(25) << "Final (Avg.)" << setw(25) << "Final (Med.)\n";
            fr<<"--------------------------------------------------------------------------------------------\n";
            for (auto& student : students) {
                fr << fixed << setw(10) << student.firstName << setw(20) << student.lastName;
                fr << fixed << setw(20) << setprecision(1)<< calculateAverage(student)*0.4+student.finalExamGrade*0.6;
                fr << fixed << setw(25) << setprecision(1)<< calculateMedian(student)*0.4+student.finalExamGrade*0.6 << '\n';
            }




    return 0;
}


